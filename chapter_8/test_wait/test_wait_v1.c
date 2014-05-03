/*
	File name : test_wait.c
	Description : 测试如果父进程不回收结束的子进程，会发生什么.
	经测试，如果不回收（使用wait或者waitpid函数），在创建完一些子进程后，再次创建新的子进程会失败。因为内核空间中被很多僵死进程占用了，没有额外的空间来创建新的子进程
	
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid = 0;
	int result = 0;
	while(1){
		if( (pid = fork()) < 0){
			printf("fork error.0x%x\n\r",pid);
			exit(-1);
		}else if(pid == 0){//子进程
			printf("child pid.\n\r");
			exit(0);//子进程退出
		}else{//父进程,只打印消息，而不回收创建的子进程
			printf("father pid.\n\r");
		}
	}
	return 0;

}
