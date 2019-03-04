#pragma once
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int HPDateType;
typedef int(*PFC)(HPDateType left, HPDateType right);//函数指针
//typedef int(*)(HPDateType left, HPDateType right); 这是一个类型  PFC为类型重命名

typedef struct HpNode
{
	HPDateType* _array;
	int _capacity;
	int _size;
	
	// PFC _pFC;
}Heap;

void CreatHeap(Heap* hp, HPDateType* array, int size);
void HeapDestory(Heap* hp);
void InsertHeap(Heap* hp, HPDateType n);
void EraseHeap(Heap* hp);
HPDateType TopHeap(Heap* hp);
int SizeHeap(Heap* hp);
int EmtpyHeap(Heap* hp);

//用函数操作调整为大堆或小堆;
int Less(HPDateType left, HPDateType right);//比较方法
int Greater(HPDateType left, HPDateType right);
//堆排序
void HeapSort(HPDateType* array, int size);