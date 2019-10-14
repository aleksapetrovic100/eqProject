#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "coeficients.h"

int main(void)
{
	int fd;
	int *p;
	fd = open("/dev/dm", O_RDWR|O_NDELAY);
	if (fd < 0)
	{
		printf("Cannot open /dev/dm for write\n");
		return -1;
	}
	p=(int*)mmap(0,1024*4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(p, image, MAX_PKT_SIZE);
	munmap(p, MAX_PKT_SIZE);
	fprintf(fp,"%c",'w');
	close(fd);
	if (fd < 0)
	{
		printf("Cannot close /dev/dm for write\n");
		return -1;
	}
	return 0;
}

