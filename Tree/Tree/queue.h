
#include<stdio.h>

#include<stdlib.h>
#include<assert.h>
typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QUDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* tail;
}Queue;

//≥ı ºªØ
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq,QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void testQueue();



