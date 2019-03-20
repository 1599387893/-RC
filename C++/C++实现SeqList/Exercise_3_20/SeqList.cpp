#include"SeqList.h"


void SeqList::SeqListPushBack(int data)
{
	assert(this);
	//检查容量
	//CheckCapacity();
	_array[_size] = data;
	_size++;
	
}
void SeqList::SeqListPopBack()
{
	if (_size > 0)
		_size--;
	else
		return;
}
void SeqList::SeqListPushFront(int data)
{
	//检查容量
	//CheckCapacity();
	int i = 0;
	for (i; i < _size; i++)
		_array[i + 1] = _array[i];
	_array[0] = data;
	_size++;
}
void SeqList::SeqListPopFront()
{
	int i = 0;
	for (i; i < _size - 1; i++)
		_array[i] = _array[i + 1];
	_size--;
}
void SeqListInsert(int pos, int data);//任意位置插入
void SeqListErase(int pos);//任意位置删除
int SeqListFind(int data);// 检测data是否在顺序表中 
void SeqListRemove(int data);// 移除顺序表中第一个值为data的元素 
void SeqListRemoveAll(int data);// 移除顺序表中所有值为data的元素
int SeqListFind(int data)//检测data是否在顺序表中
{
	if (_size == 0)
		return -1;
	int i = 0;
	for (i; i < _size;i++)
		if (_array[i] == data)
			return i;
}
int SeqListSize()
{
	return _size;
}
int SeqListCapacity()//获取顺序表的容量
{
	return _capacity;
}
int SeqListEmpty()//判断顺序表是否为空
{
	if (_size == 0)
		return 1;
	return 0;
}
int SeqListFront()//获取顺序表中第一个元素
{
	//assert(this);
	if (_size != 0)
		return _array[0];
	else
		return -1;
}
int SeqListBack()//获取顺序表中的最后一个元素
{
	//assert(this);
	if (_size != 0)
		return _array[_size];
	return -1;
}


