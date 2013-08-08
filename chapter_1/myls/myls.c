/*
*	ls(1)--only list the file in specified directory
*	usage: a.out directory_name
*	
*/
#include "apue.h"
#include <dirent.h>

int main(int argc,char *argv[])
{
	DIR *dp;		//DIR structure 
	struct dirent *dirp;	//directory entry struct
	if(argc != 2)		
		err_quit("usage: ls directory_name\n");
	if((dp = opendir(argv[1])) == NULL)	//open a specified argv[1] directory 
		err_sys("can't open %s!\n",argv[1]);
	while((dirp=readdir(dp)) != NULL)	//read the entry in directory
		printf("%s\n",dirp->d_name);	
	closedir(dp);
	exit(0);
}
