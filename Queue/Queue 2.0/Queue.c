#include"Queue.h"

void QueueInit(Queue* pq)
{
	pq->_front = pq->_rear = (QueueNode*)malloc(sizeof(QueueNode));
	if (pq->_front == NULL)
	{
		perror("QueueInit:");
		return;
	}
	pq->_front->_next = pq->_rear->_next = NULL;
	pq->_front->_data = pq->_rear->_data = 0;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	if (pq->_front->_next == NULL)
	{
		assert(0);
		return;
	}
	QueueNode* ptr = NULL;
	while (pq->_front != NULL)
	{
		ptr = pq->_front->_next;
		free(pq->_front);
		pq->_front = ptr;
	}
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* qN = (QueueNode*)malloc(sizeof(QueueNode));
	if (qN == NULL)
	{
		perror("BuyNewNode:");
		return NULL;
	}
	qN->_data = x;
	qN->_next = NULL;
	return qN;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* qN = BuyQueueNode(x);
	if (qN == NULL)
		return;
	pq->_rear->_next = qN;
	pq->_rear = pq->_rear->_next;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->_front->_next == NULL)
	{
		perror("QueuePop:");
		return;
	}
	QueueNode* ptr = pq->_front;
	pq->_front = pq->_front->_next;
	free(ptr);
	ptr = NULL;
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (pq->_front->_next != NULL)
		return pq->_front->_next->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (pq->_front->_next != NULL)
		return pq->_rear->_data;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->_front->_next == NULL)
		return 1;
	return 0;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode* ptr = pq->_front->_next;
	if (pq->_front->_next == NULL)
		return count;
	while (ptr)
	{
		count++;
		ptr = ptr->_next;
	}
	return count;
}