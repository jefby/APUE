/*
	File name : test_wait.c
	Description : 测试父进程回收结束的自进程，可以无限制的创建子进程.
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
		}else{//父进程
			printf("father pid.\n\r");
			if(pid == waitpid(pid,&result,0))//等待子进程结束，回收子进程
				printf("child process end.\n\r");
		}
	}
	return 0;

}
