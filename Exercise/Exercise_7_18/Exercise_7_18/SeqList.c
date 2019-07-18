#include"SeqList.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<memory.h>

//����
void CheckCapacity(PSeqList ps)
{
	assert(ps);
	if (ps->_size < ps->_capacity)
		return ;
	int newCapacity = ps->_capacity * 2;
	DataType* NewArr = (DataType*)malloc(sizeof(DataType)*newCapacity);
	if (NULL == NewArr)
		return;
	for (int i = 0; i < ps->_size; ++i)
		NewArr[i] = ps->_array[i];
	free(ps->_array);
	ps->_array = NewArr;
}
//��ʼ��
void SeqListInit(PSeqList ps)
{
	assert(ps);
	ps->_array = (DataType*)malloc(sizeof(DataType)*10);
	if (NULL == ps->_array)
		assert("malloc Error");
	ps->_capacity = 10;
	ps->_size = 0;
}
//����
void SeqListDestory(PSeqList ps)
{
	assert(ps);
	if (NULL != ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
	}
	ps->_capacity = 0;
	ps->_size = 0;

}
//ͷ��
void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	//����
	CheckCapacity(ps);
	for (int i = ps->_size; i > 0; --i)
		ps->_array[i] = ps->_array[i - 1];
	
	ps->_array[0] = data;
	ps->_size++;
}
//ͷɾ
void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	if (0 == ps->_size)
		return;
	for (int i = 0; i < ps->_size - 1; ++i)
		ps->_array[i] = ps->_array[i + 1];
	ps->_size--;
}
//β��
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
//βɾ
void SeqListPopBack(PSeqList ps)
{
	assert(ps);
	if (ps->_size)
		ps->_size--;
}
//����λ�ò���
void Insert(PSeqList ps, DataType data, int pos)
{
	assert(ps);
	assert(pos < ps->_size);
	for (int i = ps->_size; i >= pos; --i)
		ps->_array[i] = ps->_array[i - 1];
	ps->_array[pos-1] = data;
	ps->_size++;
}
//����λ��ɾ��
void Erase(PSeqList ps, size_t pos)
{
	assert(ps);
	assert(ps->_size > pos);
	for (int i = pos-1; i < ps->_size-1; i++)
		ps->_array[i] = ps->_array[i+1];
	ps->_size--;
}
//�п�
int Empty(PSeqList ps)
{
	assert(ps);
	if (ps->_size > 0)
		return 0;
	return 1;
}
//��ЧԪ�ظ���
size_t Size(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}
//����λ��Ԫ�ط���
DataType find_elem(PSeqList ps,size_t pos)
{
	assert(ps);
	return ps->_array[pos];
}
//��ӡ˳�������
void Print(PSeqList ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
		printf("%d ", ps->_array[i]);
	printf("\n");
}

void TestSeqList()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	Print(&s);
	printf("Size:%d\n",Size(&s));
	//Insert(&s, 3, 3);
	//Erase(&s, 3);
	//Print(&s);
	for (int i = 6; i < 15;++i)
		SeqListPushBack(&s, i-1);

	printf("Size:%d\n", Size(&s));


}