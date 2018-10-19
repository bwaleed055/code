#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int data_set[1000];
int chunk_size=100;

void *Sum(void *arg)
{
    int start=(int)arg;
    int end=start+chunk_size;
    int sum=0,i;
    for(i=start; i<end; i++)
    {
        sum=sum+data_set[i];
    }
    return ((void*)sum);
}

int main(){
    int sum=0;
    pthread_t thread[10],status[10];
    
    for(int i=0; i<1000; i++)
    {
        data_set[i]=i+1;
    }
    
    for(int i=0; i<10; i++)
    {
        pthread_create(&thread[i],NULL,Sum,(void*)(i*chunk_size));
        pthread_join(thread[i],(void**) &status[i]);
        sum=sum+status[i];
    }
    
    printf("\nSum= %d\n",sum);
    return 0;
}
