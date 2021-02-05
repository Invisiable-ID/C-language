#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<time.h>

#define N 5

int main()
{
	int *ptr=NULL;
	ptr=(int *)malloc(N*sizeof(int));
	if(ptr==NULL) printf("%s","memory allocation failed");
	int range=100;
	for(int i=0;i<N;i++) ptr[i]=i;
	int index=10,num=0;
	if(index<N) printf("%s","INDEX ERROR");
	if(index>=N)
	{
		ptr=(int *)malloc((index+1)*sizeof(int));
		for(int i=0;i<N;i++) ptr[i]=i;
		if(index==N) ptr[index]=num;
		if(index>N)
		{
			srand((int)time(0));
			int range=19;
			for(int i=N;i<index;i++) ptr[i]=rand()%range;
			ptr[index]=num;
		}
		for(int i=0;i<index+1;i++) printf("%d\n",ptr[i]);
	}
	return 0;
}
