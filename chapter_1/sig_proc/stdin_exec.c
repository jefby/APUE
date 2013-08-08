/*
*
*	read command from stdin and exec this command
*	add signal process 	
*	Author:jefby
*	Email:jef199006@gmail.com
*/
#include "apue.h"	
#include <sys/wait.h>	//waitpid


static void sig_int(int);//our signal-catching function

int
main(void)
{
	char buf[MAXLINE];//buffer for store the command
	pid_t pid;	//process id
	int status;	//exec's execute status

	if(signal(SIGINT,sig_int)==SIG_ERR)//catch SIGINT signal and call function sig_int to process it ,and check the return value
		err_sys("signal error!\n");

	printf("%% ");//print promt(printf requires %% to print %
	while(fgets(buf,MAXLINE,stdin) != NULL)//read a line and it terminates with char '\n' and  a NULL byte follows with it
	{
		if(buf[strlen(buf)-1] == '\n')//if occurs a '\n' then replace it with '\0'
			buf[strlen(buf)-1]='\0';
		if((pid=fork()) < 0)//fork a new process
		{
			err_sys("fork error!\n");
		}
		else if(pid == 0)
		{
			//child
			execlp(buf,buf,(char*)0);//execlp: from PATH environment var search file and execute ,included in file 'unistd.h'
			//format: execlp(const char *file,const char *arg,....,(char*)0)
			//if success,function will not return;so follow's code will not execute
			err_ret("couldn't execute:%s",buf);
			exit(127);
		}
		//parent
		if((pid=waitpid(pid,&status,0)) < 0)
			err_sys("waitpid error!\n");
		printf("%% ");
	}
	return 0;
}


void 
sig_int(int signo)
{
	printf("interrupt\n%% ");
}
