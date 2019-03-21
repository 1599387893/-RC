#include"SeqList.h"


void CheckCapacity(SeqList* s)
{
	if (_capacity = _size)
	{
		int* NewArr = (int*)malloc(sizeof(int)* _capacity * 2);
		assert(NewArr);
		_capacity *= 2;
		memcpy(_array, NewArr, sizeof(int)* _capacity);
		free(NewArr);
		NewArr = nullptr;
	}
}
void SeqList::SeqListPushBack(int data)
{
	assert(this);
	//�������
	//CheckCapacity(this);
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
	//�������
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
void SeqListInsert(int pos, int data)//����λ�ò���
{
	assert(this);
	CheckCapacity();
	if (_size <= pos)
	{
		_array[_size] = data;
		_size++;
	}
	for (int i = _size; i > pos; i--)
	{
		_array[i] = _array[i - 1];
	}
	_array[pos] = data;
	_size++;
		
}
void SeqListErase(int pos);//����λ��ɾ��
int SeqListFind(int data);// ���data�Ƿ���˳����� 
void SeqListRemove(int data);// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemoveAll(int data);// �Ƴ�˳���������ֵΪdata��Ԫ��
int SeqListFind(int data)//���data�Ƿ���˳�����
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
int SeqListCapacity()//��ȡ˳��������
{
	return _capacity;
}
int SeqListEmpty()//�ж�˳����Ƿ�Ϊ��
{
	if (_size == 0)
		return 1;
	return 0;
}
int SeqListFront()//��ȡ˳����е�һ��Ԫ��
{
	//assert(this);
	if (_size != 0)
		return _array[0];
	else
		return -1;
}
int SeqListBack()//��ȡ˳����е����һ��Ԫ��
{
	//assert(this);
	if (_size != 0)
		return _array[_size];
	return -1;
}


