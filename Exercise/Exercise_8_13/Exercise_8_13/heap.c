#pragma once
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>

typedef int HPDataType;
typedef int(*PFC)(HPDataType left, HPDataType right);

typedef struct HeapNode
{
	HPDataType* _array;
	int _capacity;
	int _size;
	PFC _pFC;
}Heap;

//������
void CreateHeap(Heap* hp, HPDataType* array, int size);
//���ٶ�
void DestroyHeap(Heap* hp);
//����в���Ԫ��
void InsertHeap(Heap* hp, HPDataType data);
//��ɾ��(ɾ���Ѷ�Ԫ��)
void EraseHeapTop(Heap* hp);
//����Ԫ�ظ���
int sizeHeap(Heap* hp);
//�п�
int EmptyHeap(Heap* hp);
//���ضѶ�Ԫ��
HPDataType TopHeap(Heap* hp);
//������
void HeapSort(HPDataType* array, int size);