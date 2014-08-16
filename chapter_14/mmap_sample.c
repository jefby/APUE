/*
	使用mmap函数映射文件hello.txt到存储区，修改首字符为H
	 
*/
#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h> //mmap

#include <sys/types.h> //open
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	//打开文件hello.txt
	int fd = open("./hello.txt",O_RDWR);
	char * ptr = NULL;
	if(fd < 0){
		perror("./hello.txt");
		return -1;
	}
	//将文件映射到存储区,系统自动分配地址,读写方式，MAP_SHARED指定存储操作修改映射文件,从文件描述符fd所指示的文件偏移0处开始映射，映射大小为512
	ptr = mmap(0,512,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr == NULL){
		perror("mmap");
		return -1;
	}
	//修改文件的第一个字符为'H'
	ptr[0] = 'H';
	//将内存同步到文件
	msync(ptr,512,MS_SYNC);
	//解除映射关系
	munmap(ptr,512);
	//关闭文件
	close(fd);
		
	return 0;
}
