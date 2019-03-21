#include<iostream>
#include<malloc.h>
#include<assert.h>
using namespace std;

class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_array = (int*)malloc(sizeof(int)* capacity);
		assert(_array);
		_capacity = capacity;
		_size = 0;
	}
	~SeqList()
	{
		free(_array);
		_array = NULL;
		_capacity = 0;
		_size = 0;
	}
	int GetCapacity()
	{
		return _capacity;
	}
	int GetSize()
	{
		return _size;
	}
	void SeqListPushBack(int data);//尾插
	void SeqListPopBack();//尾删
	void SeqListPushFront(int data);//头插
	void SeqListPopFront();//头删
	void SeqListInsert(int pos, int data);//任意位置插入
	void SeqListErase(int pos);//任意位置删除
	int SeqListFind(int data);// 检测data是否在顺序表中 
	void SeqListRemove(int data);// 移除顺序表中第一个值为data的元素 
	void SeqListRemoveAll(int data);// 移除顺序表中所有值为data的元素
	int SeqListSize();//获取有效元素个数
	int SeqListCapacity();//获取顺序表的容量
	int SeqListEmpty();//判断顺序表是否为空
	int SeqListFront();//获取顺序表中第一个元素
	int SeqListBack();//获取顺序表中的最后一个元素
private:
	int* _array;
	int _capacity;
	int _size;
};