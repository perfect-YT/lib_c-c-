#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a =NULL;
	ps->_top= 0;
	ps->_capacity= 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a= NULL;
	ps->_top= 0;
	ps->_capacity= 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	if(ps->_top == ps->_capacity)
	{
		if(ps->_capacity == 0)
		{
			ps->_capacity = sizeof(STDataType);
		 
		}
		ps->_a = (STDataType*)realloc(ps->_a, 2* ps->_capacity* sizeof(STDataType));
		ps->_capacity *=2;

	}
	ps->_a[ps->_top] = x;
	(ps->_top)++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if(ps->_top == 0)
		return;
	(ps->_top)--;
}
//
STDataType StackTop(Stack* ps)
{
	assert(ps);
	
	return ps->_a[ps->_top-1];
}
//
int StackEmpty(Stack* ps)
{
	assert(ps);
	if(ps->_top == 0)
		return 0;
	return 1;
}
//
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

void stacklook(Stack* ps)
{
	int cur = 0;
	assert(ps);
	cur = ps->_top;
	while(cur > 0)
	{
		printf("%d ",ps->_a[cur-1]);
		(cur)--;
	}
}


void TestStack(){	Stack* ps= (Stack*)malloc(sizeof(Stack));	StackInit(ps);	StackPush(ps, 1);	StackPush(ps, 2);	StackPush(ps, 3);	StackPush(ps, 4);	StackPop(ps);	stacklook(ps);	printf("top%d ",StackTop(ps));	printf("\n");	printf("%d",StackEmpty(ps));	printf("\n");	printf("%d ",StackSize(ps));	StackDestory(ps);	printf("%d",StackEmpty(ps));}