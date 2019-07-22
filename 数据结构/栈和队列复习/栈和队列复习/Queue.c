#include"Queue.h"

//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_array = (QDataType*)malloc(sizeof(QDataType) * 5);
	q->_capacity = q->_capacity + 5;
	q->_size = ;
}
//入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	CheckCapacity(q);
	*(q->_size) = data;
	q->_size++;
}
//出队列
void QueuePop(Queue* q)
{
	assert(q);
	q->_size--;
}
//队内有效元素个数
int QueueSize(Queue* q)
{
	assert(q);
	return q->_size - q->_array;
}
//判空
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_size == q->_array)
		return 1;
	return 0;
}
//队头元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_size == q->_array)
		return -1;
	return q->_array[0];
}
//队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_size == q->_array)
		return -1;
	return q->_size[0];
}