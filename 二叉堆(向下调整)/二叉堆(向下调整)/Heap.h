#pragma once
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int HPDateType;
typedef struct HpNode
{
	HPDateType* _array;
	int _capacity;
	int _size;
}Heap;

void CreatHeap(Heap* hp, HPDateType* array, int size);
void HeapDestory(Heap* hp);
void InsertHeap(Heap* hp, HPDateType n);
void EraseHeap(Heap* hp);
HPDateType TopHeap(Heap* hp);
int SizeHeap(Heap* hp);
int EmtpyHeap(Heap* hp);