#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int max(int x, int y)
{
	if(x > y)
		x = y;

	return x;
}

int min(int x, int y)
{
	if(x < y)
		x = y;

	return x;
}


int main(int argc, char * argv[]){

	int m,n, test, i, subtest;

	FILE * fptr;
	fptr = fopen("midterm.in","r");

	fscanf(fptr,"%d", &test);
		
	for(i = 1; i <= test; i++){
		fscanf(fptr,"%d",&subtest);
		int j, tmp;
		printf("CASE %d:\n", i);		
		for(j = 1; j <= subtest; j++)
		{
			fscanf(fptr,"%d", &tmp);
			if(j == 1){
				n = m = tmp;				
			}
			n = min(tmp,n);
			m = max(tmp,m);
		}
			int pid = fork();
			if(pid == 0)
			{

				printf("I'm the child (PID %d). MIN = %d.\n",getpid(),m);			
				exit(0);

			}else{
				
				wait(NULL);
				printf("I'm the parent (PID %d). MAX = %d.\n",getpid(),n);
				
			}	



	}	

	


	return 0;
}
