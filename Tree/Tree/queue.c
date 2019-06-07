#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = NULL;
	pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	QueueNode* root= NULL;
	if(pq->front == NULL)
		return;
	while(pq->front != NULL)
	{
		root= pq->front;
		pq->front = pq->front->next;
		
		free(root);

	}
}
void QueuePush(Queue* pq, QUDataType x)
{

	QueueNode* root = BuyQueueNode(x);
	if(pq->front == NULL)
	{
		pq->front= root;
		pq->tail= root;
	}
	else
	{
		pq->tail->next= root;
		pq->tail= root;

	}
	


}
void QueuePop(Queue* pq)
{
	QueueNode* root= pq->front;
	if(root == NULL)
		return;
	
	pq->front = pq->front->next;
		
	free(root);
	

}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	/*if(pq->front == NULL)
		return NULL;*/
	return pq->front->data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->tail->data;
}
int QueueEmpty(Queue* pq)
{
	if(pq->front == NULL)
		return 0;
	return 1;
}
int QueueSize(Queue* pq)
{
	int i=0;
	QueueNode* root = pq->front;         
	if(root == NULL)
		return 0;
	while(root != NULL)
	{
		root = root->next;
		i++;
	}
	return i;
	
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* root= (QueueNode*)malloc(sizeof(QueueNode));
	root->data = x;
	root->next= NULL;
	return root;

}

void Queuelook(Queue* pq)
{
	QueueNode* root;
	if(pq == NULL)
		return;
	
	root=pq->front;

	while(root)
	{

		printf("%d ",root->data);
		root= root->next; 
	}
}
void testQueue()
{
	Queue* pq= (Queue*)malloc(sizeof(Queue));
	QueueInit(pq);
	QueuePush(pq,1);
	QueuePush(pq,2);
	QueuePush(pq,3);
	QueuePush(pq,4);
	Queuelook(pq);
	printf("队节点个数%d ",QueueSize(pq));
	printf("\n");
	printf("头结点%d ",QueueFront(pq));
	printf("\n");
	QueuePop(pq);
	Queuelook(pq);
	printf("队节点个数%d ",QueueSize(pq));
	printf("\n");
	printf("尾节点%d ",QueueBack(pq));
	printf("\n");
	QueueDestory(pq);
	printf("节点个数%d ",QueueSize(pq));






}