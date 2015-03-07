/*
	name: test_brk.c
function: 用于测试brk的使用，了解Linux内核的内存分配机制
 */
#include <stdio.h>


int main()
{
	int start = sbrk(0);
	malloc(sizeof(char)*4096*10);
	int end = sbrk(0);
	printf("now malloc %d byte.",end-start);
	return 0;
}
