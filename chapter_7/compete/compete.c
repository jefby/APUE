#include "../../apue.h"
static void charatatime(char *);

int main(void)
{
	pid_t pid;
	TELL_WAIT();
	if((pid=fork()) < 0)
	{
		err_sys("fork error!");
	}
	else if(pid==0)
	{	
	charatatime("output from child\n");
	WAIT_PARENT();//parent goes first 
	}
	else
	{
	charatatime("output from parent\n");
	TELL_CHILD(pid);
	}
	exit(0);
}

void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);//set stdout unbuffered 
	for(ptr=str;(c=*ptr++) != 0;)
		putc(c,stdout);
}
