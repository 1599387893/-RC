#include"Stack(queue).h"

//队列初始化
void QueueInit(Queue* q)
{
	assert(q);
	if (q == NULL)
		return;
	q->_head = 0;
	q->_tail = 0;
	q->_size = 0;
}
//销毁队列
void QueueDestory(Queue* q)
{
	assert(q);
	if (q == NULL)
		return;
	q->_head = 0;
	q->_tail = 0;
	q->_size = 0;
}
// 入队列操作函数
void QueuePush(Queue* q, Datatypedef val)
{
	assert(q);
	if (q == NULL)
		return;
	if (q->_size == max_size)
	{
		printf("队满！\n");
		return;
	}
	q->_data[q->_tail++] = val;
	q->_size++;
}
//出队列操作函数
void QueuePop(Queue* q)
{
	assert(q);
	if (q == NULL)
		return;
	if (0 == q->_size)
		return;
	if (q->_head >= max_size)
		q->_head = 0;
	q->_head++;
	q->_size--;
	if (0 == q->_size)
	{
		q->_head = 0;
		q->_tail = 0;
	}
}
//取队首元素函数
int QueueTop(Queue* q,Datatypedef* ret)
{
	assert(q);
	assert(q);
	if (q == NULL)
		return -1;
	if (0 == q->_size)
		return -1;
	*ret = q->_data[q->_head];
	return 0;
}



//栈初始化
void StackInit(Stack* s)
{
	assert(s);
	if (s == NULL)
		return;
	QueueInit(&s->_q1);
	QueueInit(&s->_q2);
	s->_size = 0;
}
//销毁栈
void StackDestroy(Stack* s)
{
	assert(s);
	if (s == NULL)
		return;
	QueueDestory(&s->_q1);
	QueueDestory(&s->_q2);
	s->_size = 0;
}
//入栈
void StackPush(Stack* s, Datatypedef val)
{
	assert(s);
	if (s == NULL)
		return;
	if ((s->_q1._size != 0))
		QueuePush(&s->_q1, val);
	else
		QueuePush(&s->_q2, val);
	s->_size++;
}
//出栈
void StackPop(Stack* s)
{
	assert(s);
	Queue* from = NULL;
	Queue* to = NULL;
	Datatypedef temp = 0;
	if (NULL == s)
		return;
	if (0 == s->_size)
		return;
	
	if (s->_q1._size != 0)
	{
		from = &s->_q1;
		to = &s->_q2;
	}	
	else
	{
		from = &s->_q2;
		to = &s->_q1;
	}
	while (from->_size != 1)
	{
		
		QueueTop(from, &temp);
		QueuePop(from);
		QueuePush(to, temp);
	}
	QueuePop(from);
	s->_size--;
}
//栈内元素个数
int StackSize(Stack* s)
{
	assert(s);
	return s->_size;
}
//栈顶元素
Datatypedef StackTop(Stack* s)
{
	assert(s);
	Queue* from = NULL;
	Queue* to = NULL;
	Datatypedef temp = 0;
	if (NULL == s)
		return -1;
	if (0 == s->_size)
		return -1;
	
	if (s->_q1._size != 0)
	{
		from = &s->_q1;
		to = &s->_q2;
	}
	else
	{
		from = &s->_q2;
		to = &s->_q1;
	}
	
	while (from->_size != 1)
	{
		
		QueueTop(from, &temp);
		QueuePop(from);
		QueuePush(to, temp);
	}
	QueueTop(from, &temp);
	QueuePop(from);
	QueuePush(to, temp);
	return temp;
}