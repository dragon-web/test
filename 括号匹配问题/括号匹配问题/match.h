#pragma once
#include"common.h"
typedef struct StackNode
{
	DataType data;
	struct StackNode *next;
}StackNode;

typedef StackNode* ListStack;


bool ListStackEmpty(ListStack *pst);
void ListStackInit(ListStack *pst);
DataType ListStackTop(ListStack *pst);
void ListStackPush(ListStack *pst, DataType x);
void ListStackPop(ListStack *pst);
void ListStackShow(ListStack pst);

bool ListStackEmpty(ListStack *pst)
{
	return *pst == NULL;
}

void ListStackInit(ListStack *pst)
{
	*pst = NULL;
}

DataType ListStackTop(ListStack *pst)
{
	assert(*pst != NULL);//
	return (*pst)->data;
}

void ListStackPush(ListStack *pst, DataType x)
{
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;
	node->next = *pst;
	*pst = node;
}

void ListStackPop(ListStack *pst)
{
	StackNode *p = *pst;
	*pst = p->next;
	free(p);
}

///////////////////////////////////////////////////////////
/*bool isValid(char * s)
{
	if (s == NULL)//¼ìÑésÊÇ·ñ´æÔÚ
		return false;
	if (*s == '\0')//¼ìÑé×Ö·û´®ÊÇ·ñÎª¿Õ´®£¬¿Õ´®Âú×ãÀ¨ºÅÆ¥Åä
		return true;

	ListStack st;
	ListStackInit(&st);

	while (*s != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			ListStackPush(&st, *s);
		}
		else
		{
			if (ListStackEmpty(&st))
				return false;

			char topval = ListStackTop(&st);
			if ((*s == ')'&& topval != '(')
				|| (*s == ']'&& topval != '[')
				|| (*s == '}'&& topval != '{'))
				return false;
			ListStackPop(&st);
		}
		s++;
	}

	bool flag = ListStackEmpty(&st);
	free(st);
	st = NULL;
	return flag;
}
*/
void ListStackShow(ListStack pst)
{
	StackNode* p = pst;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
}