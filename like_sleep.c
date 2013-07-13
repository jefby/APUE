/*
	write a function like sleep,but it's unit is usec.
	APUE(v2)14.6
	Author:jefby
	Email:jef199006@gmail.com
*/
#include <stdio.h>
#include <sys/select.h>

int sleep_us(long us)
{
	fd_set set;
	FD_ZERO(&set);
	struct timeval tv;
	long wtime;
//	printf("us=%ld\n",us);
	tv.tv_sec = us/1000;
	tv.tv_usec = us%1000;
	wtime = tv.tv_sec*1000+tv.tv_usec;
//	printf("usec=%ld,sec=%ld\n",tv.tv_usec,tv.tv_sec);
	select(1,NULL,NULL,NULL,&tv);
	printf("sleep %ld usec success\n",wtime);
	return 0;
}

int main(int argc,char **argv)
{
	if(argc !=2){
		printf("usage: a.out ..us \n");
		return (-1);
	}
	sleep_us(atoi(argv[1]));
	return 0;
}
