/*
 *
 *	目的：驱动程序和用户程序共享内存，用户程序显示内存的前十个字节内容，驱动加载时写内存内容
 *	内存内容也是由驱动来主动申请分配的，
 *
 *
 *
 * */
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

#define PAGE_SIZE 4096

int main()
{
	unsigned char *start = NULL;
	int i = 0;
//打开驱动设备mymap
	int fd = open("/dev/mymap",O_RDWR);
	if(fd < 0){
		printf("open file error");
		exit(1);
	}
//映射文件到内存
	start = (unsigned char *)mmap(NULL,PAGE_SIZE,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
	if(start == MAP_FAILED){
		printf("mmap failed");
		exit(-1);
	}	
	for(i=0;i<10;++i)
		printf("%d ",start[i]);
	printf("\n");
	return 0;
}
