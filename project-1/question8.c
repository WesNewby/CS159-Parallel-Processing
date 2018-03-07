#include<stdio.h>
#include<stdlib.h>
main() {
	int pid, status, res;
	printf("with parent calling wait(&status):\n");
	fflush(stdout);
	if(pid=fork()==0){
		printf("	child going to sleep\n");
		sleep(5);
		printf("	child finished sleeping\n");
		exit(0);

	} else {
		printf("	parent starting to wait\n");
		res= wait(&status);
		printf("	parent finished waiting\n");
	}
	printf("\nwithout wait(&status):\n");
	fflush(stdout);
	if(pid=fork()==0){
		printf("	child going to sleep\n");
		sleep(5);
		printf("	child finished sleeping\n");
		exit(0);

	} else {
		printf("	parent isn't going to wait, exiting\n");
		exit(0);
	}
}
