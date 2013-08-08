/*
*	stdin2stdout 
*	copy stdin to stdout
*	use stdio function such as getc,putc.
*/

#include "apue.h"

int main(void)
{
	int c;
	while((c=getc(stdin)) != EOF)
		if(putc(c,stdout) == EOF)
			err_sys("output error!\n");
	if(ferror(stdin))
		err_sys("input error!\n");
	return 0;
}
