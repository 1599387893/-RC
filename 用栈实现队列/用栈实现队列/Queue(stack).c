#include"Queue(stack).h"

//ջ��ʵ��
void StackInit(Stack* s)
{
	assert(s);
	if (s->_data == NULL)
		return;
	s->_sizeStack = 0;
}
void StackDestroy(Stack* s)
{
	assert(s);
	if (s->_data == NULL)
		return;
	s->_sizeStack = 0;
}
void StackPush(Stack* s,Datatypedef val)
{
	assert(s);
	if (s->_data == NULL)
		return;
	if (s->_sizeStack == max_size)
		return;
	s->_data[s->_sizeStack] = val;
	s->_sizeStack++;
}
void StackPop(Stack* s,Datatypedef* val)
{
	assert(s);
	if (s->_data == NULL)
		return;
	if (0 == s->_sizeStack)
		return;
	*val = s->_data[s->_sizeStack];
	s->_sizeStack--;
}
Datatypedef StackTop(Stack* s)
{
	assert(s);
	if (s == NULL)
		return -1;
	if (0 == s->_sizeStack)
		return -1;
	return s->_data[s->_sizeStack-1];
}
//���е�ʵ��
void QueueInit(Queue* q)
{
	assert(q);
	if (q == NULL)
		return;
	StackInit(&q->_s1);
	StackInit(&q->_s2);
	q->_sizeQueue = 0;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	if (q == NULL)
		return;
	StackDestroy(&q->_s1);
	StackDestroy(&q->_s2);
	q->_sizeQueue = 0;
}
void QueuePush(Queue* q, Datatypedef val)
{
	assert(q);
	if (q == NULL)
		return;

	//�ж϶����Ƿ������������max_sizeʱ���޷�pop
	if (q->_sizeQueue == max_size)
		return;
	
	//�������Ԫ��ȫ������s2��
	if (0 == q->_s2._sizeStack)
	{
		q->_front = val;
	}
	StackPush(&q->_s2, val);
	q->_sizeQueue++;
}
void QueuePop(Queue* q)
{
	assert(q);
	Datatypedef temp = 0;
	if (q == NULL)
		return;
	//�п�
	if (0 == q->_sizeQueue)
		return;
	//popʱ����s1��Ԫ�ط���s2�У�����s1�����һ��pop���ٽ�s2��Ԫ�ط���s1��
	while (q->_s1._sizeStack > 1)
	{
		StackPop(&q->_s1, &temp);
		StackPush(&q->_s2, temp);
	}
	StackPop(&q->_s1, &temp);//��ʱpop��s1�����һ��Ԫ�أ������еĵ�һ��Ԫ��
	temp = 0;
	while (q->_s2._sizeStack)
	{
		StackPop(&q->_s2, &temp);
		StackPush(&q->_s1, temp);
	}
	q->_sizeQueue--;
}
Datatypedef QueueFront(Queue* q)
{
	assert(q);
	if (NULL == q)
		return -1;
	if (0 == q->_sizeQueue)
		return -1;
	return q->_front;
}
Datatypedef QueueRear(Queue* q)
{
	assert(q);
	if (q == NULL)
		return -1;
	//�п�
	if (0 == q->_sizeQueue)
		return -1;
	return StackTop(&q->_s2);
}
int QueueSize(Queue* q)
{
	assert(q);
	if (q == NULL)
		return -1;
	return q->_sizeQueue;
}