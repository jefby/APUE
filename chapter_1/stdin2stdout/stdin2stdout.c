/*
*	copy stdin to stdout
*	use read/write function --- no-buffer I/O 
*/
#include "apue.h"

#define BUFFSIZE 4096

int main(void)
{
	int n;							//store the real read or write bytes
	char buf[BUFFSIZE];					//buffer
	while((n=read(STDIN_FILENO,buf,BUFFSIZE)) > 0)		//read from stdin 
		if(write(STDOUT_FILENO,buf,n) != n)
			err_sys("write error!\n");
	if(n < 0)
		err_sys("read error!\n");
	
	exit(0);
}
