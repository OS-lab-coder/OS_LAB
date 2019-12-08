#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int n;
int *fibseq;
int i;
void *runn(void *arg);

int main()
{
	printf("Enter the number:");
	scanf("%d",&n);
	fibseq = (int *)malloc(n * sizeof(int));
	pthread_t *threads = (pthread_t *) malloc (n * sizeof(pthread_t));
	//int i;
	for(i=0;i<n;i++)
	{
	pthread_create(&threads[i],NULL,runn,(void *)&i);
	pthread_join(threads[i],NULL);
	}
	
	printf("The Fibonacci sequence:");
	int k;
	
	for(k=0;k<n-1;k++)
	{
	printf("%d,",fibseq[k]);
	}
	printf("%d\n",fibseq[n-1]);
	return 0;
}

void *runn(void *arg)
{ 
	int *s=(int *)arg;
	int i=*s;
	if(i==0)
	{
		fibseq[i]=0;
		pthread_exit(0);
	}
	
	if(i==1)
	{
		fibseq[i]=1;
		pthread_exit(1);
	}
	
	else	
	{
		fibseq[i] = fibseq[i-1] + fibseq[i-2];
		pthread_exit(0);
	}
}
