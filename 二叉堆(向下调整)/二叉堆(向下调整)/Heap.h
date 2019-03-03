#pragma once
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>

typedef int HPDateType;
typedef struct HpNode
{
	HPDateType* _array;
	int _capacity;
	int _size;
}HpNode;

void CreatHeap(HpNode* hp, HPDateType* array, int size);
void HeapDestory(HPDateType* hp);
void InsertHeap(HPDateType* hp, HPDateType n);
void DesrtHeap(HPDateType* hp);
HPDateType TopHeap(HPDateType* hp);
int SizeHeap(HPDateType* hp);
int EmtpyHeap(HPDateType* hp);