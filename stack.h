#ifndef _HEAD_H_
#define _HEAD_H_

#include<stdio.h>

typedef struct NODE
{
	void *data;
	NODE *next;
}

typedef struct STACK
{
	int size;
	int StackisEmpty(STACK *top);
	NODE *PushStack(NODE *top,int x);
	NODE *PopStack(NODE *top);
	int GetTop(NODE *top);
	char GetTop(NODE *top);
}

//push element into stack
NODE *PushStack(NODE *top,int x)
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	if(p==NULL) {printf("allocate memory failed\n");exit(0);}
	p->data=x;
	p->next=top;
	top=p;
	return top;
}

//pop element out of stack
NODE *PopStack(NODE *top)
{
	NODE *p;
	p=top;
	top=top->next;
	free(p);
	return top;
}

//read the top element of stack
int GetTop(NODE *top)
{
	if(top==NULL)
	{
		printf("The stack is null\n");
		return 0;
	}
	return top->data;
}
char GetTop(NODE *top)
{
	if(top==NULL)
	{
		printf("The stack is null\n");
		return 0;
	}
	return top->data;
}

//get and delete the top element of stack
NODE *GetDelTop(NODE *top,int *x)
{
	*x=GetTop(top);
	top=PopStack(top);
	return top;
}

//judge the stack is empty or not
int EmptyStack(NODE *top) {top==NULL? return 1:0;}

#endif
