#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
	int pid = 0;
	if((pid = vfork()) < 0){
		perror("vfork create:");
		return -1;
	}else if(pid == 0){//子进程
		printf("child:\n");
		execlp("/bin/ls","ls","-l",0);
		exit(0);
	}else{//父进程
		printf("father:\n");
		wait(NULL);//等待子进程结束
		printf("terminal child\n");
	}
	return 0;
}
