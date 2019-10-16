#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "coeficients.h"

#define MAX_PKT_SIZE 1024*4

int main(void)
{
	int fd;
	int *p;
	fd = open("/dev/dm_mm2s", O_RDWR|O_NDELAY);
	if (fd < 0)
	{
		printf("Cannot open /dev/dm_mm2s for write\n");
		return -1;
	}
	p=(int*)mmap(0,MAX_PKT_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(p, audio, MAX_PKT_SIZE);
	munmap(p, MAX_PKT_SIZE);
	close(fd);
	if (fd < 0)
	{
		printf("Cannot close /dev/dm_mm2s for write\n");
		return -1;
	}
	return 0;
}

