#include"Queue.h"

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_rear = pq->_front = (Node*)malloc(sizeof(Node));
	if (pq->_front == NULL)
		assert("malloc faild\n");
	pq->_front->_pNext = pq->_rear->_pNext = NULL;
	pq->_front->data = pq->_rear->data = -1;
}
//����
void QueueDestory(Queue* pq)
{
	assert(pq);
	if (pq->_front->_pNext == NULL)
		return;
	Node* pCur = pq->_front;
	while (pCur)
	{
		pq->_front = pq->_front->_pNext;
		free(pCur);
		pCur = pq->_front;
	}
}
//�����½��
Node* BuyQueueNode(QUDataType x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
		assert("malloc faild\n");
	newNode->data = x;
	newNode->_pNext = NULL;
	return newNode;
}
//�����
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	Node* newNode = BuyQueueNode(x);
	pq->_rear->_pNext = newNode;
	pq->_rear = newNode->_pNext;
}
//������
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->_front->_pNext)
	{
		Node* freeNode = pq->_front;
		pq->_front = freeNode->_pNext;
		free(freeNode);
		freeNode = NULL;
	}
}
//�����ͷԪ��
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (pq->_front->_pNext)
		return pq->_front->_pNext->data;
}
//�����βԪ��
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (pq->_front->_pNext)
		return pq->_rear->data;
}
//�п�
int QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->_front->_pNext)
		return 0;
	return 1;
}
//�����е���ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	if (pq->_front->_pNext == NULL)
		return 0;
	Node* pCur = pq->_front->_pNext;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}