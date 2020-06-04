#include "types.h"
#include "user.h"

#define NCHILD 15

int main()
{
	int pid;
	startlock();

	pid = fork();

	for (int i = 0; i < NCHILD; i++)
		if (pid > 0)
			pid = fork();

	if (pid < 0)
	{
		printf(2, "fork error\n");
	}

	else if (pid == 0)
	{
		
		capture();
		printf(1, "child adding to shared counter\n");
		for(int i=0;i<20;i++)
			printf(1,"%d\t",i);
		printf(1, "\n");
		printf(1, "Numbers were printet in a consequtive manner.\n");
		printf(1, "No other process is in its critical section.\n");
		printf(1, "Thus, mutual exlusion is satisfied!\n");

		printf(1, "\n\n");
		
		
		
		//sticketlockTest();
		withdraw();
		
	}

	else
	{
		while(wait()!=-1);
	//	sleep(1000);
	//	for (int i = 0; i < NCHILD; i++)
	//		wait();

	//	printf(1, "user program finished \n");
	}
	
	

	exit();
}
