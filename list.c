#include<stdlib.h>
#include<string.h>

#include"list.h"

void list_init(List *list,void (*destroy)(void *data))
{
	list->size=0;
	list->destroy=destroy;
	list->head=NULL;
	list->tail=NULL;
}

int list_ins_next(List *list,ListElmt *element,const void *data)
{
	ListElmt *new_element;
	new_element->data=data;
	if((new_element=(ListElmt *)malloc(sizeof(ListElmt)))==NULL) return -1;//allocate memory failed
	if(element==NULL)
	{
		if(list_size==0)
		{
			list->tail=new_element;
			list->head=new_element;
			new_element->next=NULL;
		}
	}
	else
	{
		if(element->next==NULL)//the last one?
		{
			element->next=new_element;
			list->tail=list->tail->next;
			new_element->next=NULL;//list->tail->next=NULL
		}
		else
		{
			new_element->next=element->next;
			element->next=new_element;
		}
	}
	list->size++;
	return 0;
}

int list_rem_next(List *list,ListElmt *element,void **data)
{
	ListElmt *old_element;
	if(list->size==0) return -1;//empty list
	if(element==NULL)
	{
		//remove from the head of the list
		*data=list->head->data;
		old_element=list->head;
		list->head=list->head->next;
		if(list->size==1) list->tail=NULL;
	}
	else
	{
		//remove from somewhere except the head
		if(element->next==NULL) list->tail=element;//the element from the tail of the list
		*data=element->next->data;
		old_element=element->next;
		element->next=element->next->next;
	}
	free(old_element);
	list->size--;
	return 0;
}
