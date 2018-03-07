#include<stdio.h>

main ()
{
int pid;
printf("immediately before the fork. this should print once\n");
fflush(stdout);
pid=fork();
printf("immediately after the fork. this should print twice\n");
if(pid>0){
	printf("I am the parent, my PID is %d and my child's PID is %d\n", getpid(), pid);
	sleep(1);
} else if (pid==0) {
	printf("I am the child, my PID is %d and my parent's PID is %d\n", getpid(), getppid());
}
exit(0); }
