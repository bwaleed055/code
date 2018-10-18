#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
   int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];	
   pipe(fd1);pipe(fd2);pipe(fd3);pipe(fd4);pipe(fd5);pipe(fd6);pipe(fd7);pipe(fd8);pipe(fd9);pipe(fd10);
   int arr[1000],sum=0,child=0;
   
   for(int i=0;i<1000;i++){
       arr[i]=i+1;
	}
   int cpid;
   for(int i=0; i<10 ;i++)
   {
      child=child+1;
      cpid=fork();
      if (cpid < 0){
        exit(EXIT_FAILURE);
      }
      else if (cpid == 0){
        break;
      }
   }
   if(cpid == 0){
		if(child==1){
			for(int i=0; i<100; i++)
			    sum+=arr[i];
			write(fd1[1],&sum,sizeof(int));
			close(fd1[1]);
		}
		else if(child==2){
			for(int i=100; i<200; i++)
			    sum+=arr[i];
			write(fd2[1],&sum,sizeof(int));
			close(fd2[1]);
		}
		else if(child==3){
			for(int i=200; i<300; i++)
			    sum+=arr[i];
			write(fd3[1],&sum,sizeof(int));
			close(fd3[1]);
		}
		else if(child==4){
			for(int i=300; i<400; i++)
			    sum+=arr[i];
			write(fd4[1],&sum,sizeof(int));
			close(fd4[1]);
		}
		else if(child==5){
			for(int i=400; i<500; i++)
			    sum+=arr[i];
			write(fd5[1],&sum,sizeof(int));
			close(fd5[1]);
		}
		else if(child==6){
			for(int i=500; i<600; i++)
			    sum+=arr[i];
			write(fd6[1],&sum,sizeof(int));
			close(fd6[1]);
		}
		else if(child==7){
			for(int i=600; i<700; i++)
			    sum+=arr[i];
			write(fd7[1],&sum,sizeof(int));
			close(fd7[1]);
		}
		else if(child==8){
			for(int i=700; i<800; i++)
			    sum+=arr[i];
	                 write(fd8[1],&sum,sizeof(int));
			close(fd8[1]);
		}
		else if(child==9){
			for(int i=800; i<900; i++)
			    sum+=arr[i];		
			write(fd9[1],&sum,sizeof(int));
			close(fd9[1]);
		}
		else if(child==10){
			for(int i=900; i<1000; i++)
			    sum+=arr[i];
			write(fd10[1],&sum,sizeof(int));
			close(fd10[1]);
		}
		exit(0);
	}
	else
	{
		int sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10;
		for(int i=0; i<10; i++)
		   wait(NULL);
		   
		read(fd1[0],&sum1,sizeof(int));
		read(fd2[0],&sum2,sizeof(int));
		read(fd3[0],&sum3,sizeof(int));
		read(fd4[0],&sum4,sizeof(int));
		read(fd5[0],&sum5,sizeof(int));
		read(fd6[0],&sum6,sizeof(int));
		read(fd7[0],&sum7,sizeof(int));
		read(fd8[0],&sum8,sizeof(int));
		read(fd9[0],&sum9,sizeof(int));
		read(fd10[0],&sum10,sizeof(int));
	
		sum=sum+sum1;
		sum=sum+sum2;
		sum=sum+sum3;
		sum=sum+sum4;
		sum=sum+sum5;
		sum=sum+sum6;
		sum=sum+sum7;
		sum=sum+sum8;
		sum=sum+sum9;
		sum=sum+sum10;
		
		printf("Sum is: %d: ",sum);
		close(fd1[0]);close(fd2[0]);close(fd3[0]);close(fd4[0]);close(fd5[0]);close(fd6[0]);close(fd7[0]);close(fd8[0]);close(fd9[0]);close(fd10[0]);
	    exit(0);
	}
   return 0;
}
