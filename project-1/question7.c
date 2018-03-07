#include<stdio.h>
#include<stdlib.h>
main() {
	int pid;
	int i =0;
	int c =0;
	printf("%*s%d=me(A)|\n",40,"|",getpid());
	fflush(stdout);
	if(pid=fork()==0){
		printf("%*s%d=me(B), %d=parent|%*s",15, "|", getpid(), getppid(), 15, " ");
		fflush(stdout);
		if(pid=fork()==0){//D
			sleep(1);
			printf("|%d=me(D), %d=parent|%*s", getpid(), getppid(), 24, " ");
			exit(0);
		} else {//B
			sleep(1);
			wait();
			exit(0);
		}
	} else if(pid=fork()==0) {
		sleep(1);
		printf("|%d=me(C), %d=parent|\n", getpid(), getppid());
		fflush(stdout);
		sleep(1);
		if(pid=fork()==0){//E
			printf("|%d=me(E), %d=parent|", getpid(), getppid());
			exit(0);
		} else if(pid=fork()==0) {//F
			sleep(1);
			printf("|%d=me(F), %d=parent|", getpid(), getppid());
			exit(0);
		} else { //C
			sleep(2);
			wait(NULL);
			exit(0);
		}
	} else {
		sleep(5);

	}

	exit(0);
}
