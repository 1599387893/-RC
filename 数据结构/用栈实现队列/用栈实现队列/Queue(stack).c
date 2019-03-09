#include"Queue(stack).h"

//栈的实现
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
//队列的实现
void QueueInit(Queue* q)
{
	assert(q);
	if (q == NULL)
		return;
	StackInit(&q->_s1);
	StackInit(&q->_s2);
	q->_sizeQueue = 0;
	q->_front = 0;
	q->_rear = 0;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	if (q == NULL)
		return;
	StackDestroy(&q->_s1);
	StackDestroy(&q->_s2);
	q->_sizeQueue = 0;
	q->_front = 0;
	q->_rear = 0;
}
void QueuePush(Queue* q, Datatypedef val)
{
	assert(q);
	if (q == NULL)
		return;

	//判断队列是否存满，当多于max_size时，无法pop
	if (q->_sizeQueue == max_size)
		return;
	//将插入的元素全部放入s1中
	StackPush(&q->_s1, val);
	q->_sizeQueue++;
}
void QueuePop(Queue* q)
{
	assert(q);
	Datatypedef temp = 0;
	if (q == NULL)
		return;
	//判空
	if (0 == q->_sizeQueue)
		return;

	//pop时，将s1的元素放入s2中，再将s2的栈顶元素pop
	while (q->_s1._sizeStack)
	{
		StackPop(&q->_s1, &temp);
		StackPush(&q->_s2, temp);
	}
	StackPop(&q->_s2,&temp);
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
	q->_front = q->_s1._data[0];
	return (q->_front);
}
Datatypedef QueueRear(Queue* q)
{
	assert(q);
	if (q == NULL)
		return -1;
	//判空
	if (0 == q->_sizeQueue)
		return -1;
	return StackTop(&q->_s1);
}
int QueueSize(Queue* q)
{
	assert(q);
	if (q == NULL)
		return -1;
	return q->_sizeQueue;
}