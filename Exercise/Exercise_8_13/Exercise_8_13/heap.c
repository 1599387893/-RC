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

//创建堆
void CreateHeap(Heap* hp, HPDataType* array, int size);
//销毁堆
void DestroyHeap(Heap* hp);
//向堆中插入元素
void InsertHeap(Heap* hp, HPDataType data);
//堆删除(删除堆顶元素)
void EraseHeapTop(Heap* hp);
//堆中元素个数
int sizeHeap(Heap* hp);
//判空
int EmptyHeap(Heap* hp);
//返回堆顶元素
HPDataType TopHeap(Heap* hp);
//堆排序
void HeapSort(HPDataType* array, int size);