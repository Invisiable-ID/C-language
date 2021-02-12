#include<malloc.h>
#include"stack.h"
#include<stdlib.h>
#include<time.h>

//licensing
void GenCard()
{
int num;
srand((unsigned)time(NULL));
for(int i=0;i<4;i++)
{
	num=rand()%13;
	printf("The number of the card is: %d",num);
}
}
