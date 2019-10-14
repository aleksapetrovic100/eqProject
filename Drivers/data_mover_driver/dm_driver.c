#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/platform_device.h>
#include <asm/io.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/io.h>

#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>

#include <linux/version.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/dma-mapping.h>  // dma access
#include <linux/mm.h>  // dma access


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Driver for DataMover output");
#define DEVICE_NAME "dm"
#define DRIVER_NAME "dm_driver"
#define MAX_PKT_LEN 1024*4
#define DM_EN 1024

//*************************************************************************
static int dm_probe(struct platform_device *pdev);
static int dm_open(struct inode *i, struct file *f);
static int dm_close(struct inode *i, struct file *f);
static ssize_t dm_read(struct file *f, char __user *buf, size_t len, loff_t *off);
static ssize_t dm_write(struct file *f, const char __user *buf, size_t count, loff_t *off);
static ssize_t dm_mmap(struct file *f, struct vm_area_struct *vma_s);
static int __init dm_init(void);
static void __exit dm_exit(void);
static int dm_remove(struct platform_device *pdev);

u32 dm_simple_write(dma_addr_t TxBufferPtr, u32 max_pkt_len, void __iomem *base_address); // helper function, defined later

// *********************GLOBAL VARIABLES*************************************
static struct file_operations dm_fops = {
  .owner = THIS_MODULE,
  .open = dm_open,
  .release = dm_close,
  .read = dm_read,
  .write = dm_write,
  .mmap = dm_mmap
};
static struct of_device_id dm_of_match[] = {
  { .compatible = "xlnx,data_helper_1", }, // za upis mm2s
  //{.compatible = "xlnx,data_helper_0 "}, // za citanje s2mm
  { /* end of list */ },
};

static struct platform_driver dm_driver = {
  .driver = {
    .name = DRIVER_NAME,
    .owner = THIS_MODULE,
    .of_match_table = dm_of_match,
  },
  .probe = dm_probe,
  .remove = dm_remove,
};

struct dm_info {
  unsigned long mem_start;
  unsigned long mem_end;
  void __iomem *base_addr;
  int irq_num;
  
};

static struct dm_info *vp = NULL;

MODULE_DEVICE_TABLE(of, dm_of_match);

static struct cdev c_dev;
static dev_t first;
static struct class *cl;
static int int_cnt;

dma_addr_t tx_phy_buffer; // dma_addr_t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
u32 *tx_vir_buffer;
//***************************************************
// PROBE AND REMOVE

static int dm_probe(struct platform_device *pdev) {
  struct resource *r_mem;
  int rc = 0;

  printk(KERN_INFO "Probing\n");

  r_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
  if (!r_mem) {
    printk(KERN_ALERT "invalid address\n");
    return -ENODEV;
  }
  else
    printk(KERN_INFO "platform get resource success\n");
  vp = (struct dm_info *) kmalloc(sizeof(struct dm_info), GFP_KERNEL);
  if (!vp) {
    printk(KERN_ALERT "Cound not allocate data_mover device\n");
    return -ENOMEM;
  }
  else
  {
    printk(KERN_INFO "allocation of space for vp was a success\n");
  }
  vp->mem_start = r_mem->start;
  vp->mem_end = r_mem->end;
  

  if (!request_mem_region(vp->mem_start,
                          vp->mem_end - vp->mem_start + 1, DRIVER_NAME)) {
    printk(KERN_ALERT "Couldn't lock memory region at %p\n",(void *)vp->mem_start);
    rc = -EBUSY;
    goto error1;
  }
  else {
    printk(KERN_INFO "dm_init: Successfully allocated memory region for data_mover\n");
  }
  /* 
   * Map Physical address to Virtual address
   */

  vp->base_addr = ioremap(vp->mem_start, vp->mem_end - vp->mem_start + 1);
  if (!vp->base_addr) {
    printk(KERN_ALERT "dm: Could not allocate iomem\n");
    rc = -EIO;
    goto error2;
  }
  else
    printk(KERN_INFO "ioremap was a success\n");
  
  /* 
   * Geting irq num 
   */
  vp->irq_num = platform_get_irq(pdev, 0);
  printk("irq number is: %d\n", vp->irq_num);
  
  // if (request_irq(vp->irq_num, dm_isr, 0, DEVICE_NAME, NULL)) {
  //   printk(KERN_ERR "dm_init: Cannot register IRQ %d\n", vp->irq_num);
  //   return -EIO;
  // }
  // else {
  //   printk(KERN_INFO "dm_init: Registered IRQ %d\n", vp->irq_num);
  // }

  printk("probing done");
error2:
  release_mem_region(vp->mem_start, vp->mem_end - vp->mem_start + 1);
error1:
  return rc;

}

static int dm_remove(struct platform_device *pdev)
{
  // Exit Device Module
  u32 reset;
  reset = 0;
  iowrite32(reset, vp->base_addr+2); // writing to MM2S_DMACR register. Seting reset bit (3. bit)
  iounmap(vp->base_addr);
  free_irq(vp->irq_num, NULL);
  //release_mem_region(vp->mem_start, vp->mem_end - vp->mem_start + 1);
  return 0;
}

//***************************************************
// IMPLEMENTATION OF FILE OPERATION FUNCTIONS

static int dm_open(struct inode *i, struct file *f)
{
  printk("dm opened\n");
  return 0;
}
static int dm_close(struct inode *i, struct file *f)
{
  printk("dm closed\n");
  return 0;
}
static ssize_t dm_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
  printk("dm read\n");
  return 0;
}
static ssize_t dm_write(struct file *f, const char __user *buf, size_t count, loff_t *off) 
{
  if(count > 0)
  {
    if(buf[0] == 'w')
      dm_simple_write(tx_phy_buffer, MAX_PKT_LEN, vp->base_addr);
  }
	printk("dm write commant sucessfull\n");
  return count;
}

static ssize_t dm_mmap(struct file *f, struct vm_area_struct *vma_s)
{
	int ret = 0;
	long length = vma_s->vm_end - vma_s->vm_start;
	printk(KERN_INFO "DMA TX Buffer is being memory mapped\n");

	if(length > MAX_PKT_LEN)
	{
		return -EIO;
		printk(KERN_ERR "Trying to mmap more space than it's allocated\n");
	}

	ret = dma_mmap_coherent(NULL, vma_s, tx_vir_buffer, tx_phy_buffer, length);
	if(ret<0)
	{
		printk(KERN_ERR "memory map failed\n");
		return ret;
	}
	return 0;
}

u32 dm_simple_write(dma_addr_t TxBufferPtr, u32 max_pkt_len, void __iomem *base_address) {
  
  u32 SADDR = (u32)TxBufferPtr;
  u32 BytesToTransfer = 4*max_pkt_len;

  printk("BytesToTransfer %d SADDR %d \n",BytesToTransfer,SADDR);

  iowrite32(1<<30 | 1<<23 | 23 | BytesToTransfer, base_address);
  iowrite32(SADDR, base_address+1);
  //iowrite32((u32)0, base_address+2);
  iowrite32((u32)DM_EN, base_address+2);
  //iowrite32((u32)0, base_address+2);

  while(ioread32(base_address+3) & (u32)1 == 0)
  {
    printk("Waiting Datamover to send command.... \n");
  }
  return 0;
}

//***************************************************
// INIT AND EXIT FUNCTIONS OF THE DRIVER

static int __init dm_init(void)
{
  int i = 0;
  int_cnt = 0;

  printk(KERN_INFO "dm_init: Initialize Module \"%s\"\n", DEVICE_NAME);

  if (alloc_chrdev_region(&first, 0, 1, "DM_region") < 0)
  {
    printk(KERN_ALERT "<1>Failed CHRDEV!.\n");
    return -1;
  }
  printk(KERN_INFO "Succ CHRDEV!.\n");

  if ((cl = class_create(THIS_MODULE, "chardrv")) == NULL)
  {
    printk(KERN_ALERT "<1>Failed class create!.\n");
    goto fail_0;
  }
  printk(KERN_INFO "Succ class chardev1 create!.\n");
  if (device_create(cl, NULL, MKDEV(MAJOR(first),0), NULL, "dm") == NULL)
  {
    goto fail_1;
  }

  printk(KERN_INFO "Device created.\n");

  cdev_init(&c_dev, &dm_fops);
  if (cdev_add(&c_dev, first, 1) == -1)
  {
    goto fail_2;
  }

  printk(KERN_INFO "Device init.\n");
  
  /*ALLOC COHERENT MEMOERY FOR DMA*/
  tx_vir_buffer = dma_alloc_coherent(NULL, MAX_PKT_LEN, &tx_phy_buffer, GFP_DMA | GFP_KERNEL); //GFP_KERNEL
  if(!tx_vir_buffer){
    printk(KERN_ALERT "Could not allocate dma_alloc_coherent for img");
    goto fail_3;
  }
  else
    printk("dma_alloc_coherent success img\n");
  for (i = 0; i < MAX_PKT_LEN/4;i++)
    tx_vir_buffer[i] = 0x00000000;
  printk(KERN_INFO "DMA memory reset.\n");
  return platform_driver_register(&dm_driver);
 fail_3:
  cdev_del(&c_dev);
 fail_2:
  device_destroy(cl, MKDEV(MAJOR(first),0));
 fail_1:
  class_destroy(cl);
 fail_0:
  unregister_chrdev_region(first, 1);
  return -1;

} 

static void __exit dm_exit(void)  		
{
  
  platform_driver_unregister(&dm_driver);
  cdev_del(&c_dev);
  device_destroy(cl, MKDEV(MAJOR(first),0));
  class_destroy(cl);
  unregister_chrdev_region(first, 1);
  dma_free_coherent(NULL, MAX_PKT_LEN, tx_vir_buffer, tx_phy_buffer);
  printk(KERN_INFO "dm_exit: Exit Device Module \"%s\".\n", DEVICE_NAME);
}

module_init(dm_init);
module_exit(dm_exit);

MODULE_AUTHOR ("FTN");
MODULE_DESCRIPTION("Test Driver for DataMover output.");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("custom:dm");
