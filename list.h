#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>

typedef struct ListElmt_
{
	void *data;
	ListElmt_ *next;
}ListElmt;

typedef struct List_
{
	int size;
	void (*destroy)(void *data);
	ListElmt_ *head;
	ListElmt_ *tail;
}List;

void list_init(List_ *list,void (*destroy)(void *data));
void list_destroy(List_ *list);
int list_ins_next(List_ *list,ListElmt *element,const void *data);
int list_rem_next(List_ *list,ListElmt *element,void **data);

#define list_size(List_ *list) (list->size)
#define list_head(List_ *list) (list->head)
#define list_tail(List_ *list) (list->tail)
#define list_is_head(List_ *list,ListElmt_ *element) (element==list->head ? 1:0)
#define list_is_tail(ListElmt_ *element) (element->next==NULL ? 1:0)
#define list_data(ListElmt_ *element) (element->data)
#define list_next(ListElmt_ *element) (element->next)

#endif
