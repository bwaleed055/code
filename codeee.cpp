#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int s[10];
    int ps=0;
    int arr[1000];
    for(int i=1; i<= 1000; i++)
        arr[i-1]=i;
        
    int cpid[10];
	
    for(int i=0 ; i<10; i++)
    {
    	sum[i]=0;
	    cpid[i]=fork();
        
		if (cpid < 0)
        {
           printf("fork Failed" );
           return 1;
        }
        if (cpid == 0 ) // make chid processes
        {
           for(int j=i*100; j<i*100+100; j++)
               s[i]=s[i]+arr[j];
            exit(0);
        }
        
    }
    int i=0;
    while(i<10)
    {
    	wait(Null);
    	i++;
	}
	for(int i=0; i<10; i++)   // parent process
	    ps=ps+sum[i];
	    
	printf("Sum of 1000 No is %d",ps);
	
	return 0;
}
