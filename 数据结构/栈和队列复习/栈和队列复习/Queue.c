#include"Queue.h"

//��ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->_array = (QDataType*)malloc(sizeof(QDataType) * 5);
	q->_capacity = q->_capacity + 5;
	q->_size = ;
}
//�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	CheckCapacity(q);
	*(q->_size) = data;
	q->_size++;
}
//������
void QueuePop(Queue* q)
{
	assert(q);
	q->_size--;
}
//������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	return q->_size - q->_array;
}
//�п�
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_size == q->_array)
		return 1;
	return 0;
}
//��ͷԪ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_size == q->_array)
		return -1;
	return q->_array[0];
}
//��βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_size == q->_array)
		return -1;
	return q->_size[0];
}