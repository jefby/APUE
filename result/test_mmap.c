/*
	name: test_brk.c
function: 用于测试malloc申请大容量存储的系统调用是mmap，可以看到是的，不过arm内核3.12似乎使用的是mmap2
 */
#include <stdio.h>


int main()
{
	malloc(sizeof(char)*4096*4096*10);
	return 0;
}
