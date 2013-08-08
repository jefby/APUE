/*
*	print some error information
*/

#include "apue.h"
#include <errno.h>

int 
main(int argc,char *argv[])
{
	fprintf(stderr,"EACCES: %s\n",strerror(EACCES));//use fprintf function and strerror print the EACCES error
	errno = ENOENT;//set errno to ENOENT
	perror(argv[0]);//use the program name as the parameter
	return 0;
}
