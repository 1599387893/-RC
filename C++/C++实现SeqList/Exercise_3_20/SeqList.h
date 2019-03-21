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
	void SeqListPushBack(int data);//β��
	void SeqListPopBack();//βɾ
	void SeqListPushFront(int data);//ͷ��
	void SeqListPopFront();//ͷɾ
	void SeqListInsert(int pos, int data);//����λ�ò���
	void SeqListErase(int pos);//����λ��ɾ��
	int SeqListFind(int data);// ���data�Ƿ���˳����� 
	void SeqListRemove(int data);// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
	void SeqListRemoveAll(int data);// �Ƴ�˳���������ֵΪdata��Ԫ��
	int SeqListSize();//��ȡ��ЧԪ�ظ���
	int SeqListCapacity();//��ȡ˳��������
	int SeqListEmpty();//�ж�˳����Ƿ�Ϊ��
	int SeqListFront();//��ȡ˳����е�һ��Ԫ��
	int SeqListBack();//��ȡ˳����е����һ��Ԫ��
private:
	int* _array;
	int _capacity;
	int _size;
};