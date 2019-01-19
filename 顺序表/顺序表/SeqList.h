#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//静态
//typedef MAXSIZE 100
//typedf struct SeqList
//{
//	int data[MAXSIZE];
//	int sz;
//}SeqList;

//动态
typedef int DataType;
typedef struct SeqList
{
	DataType* data;
	int capacity;
	int sz;
}SeqList,*PSeqList;

void InitSeqList(PSeqList ps);//初始化
void DestroySeqList(PSeqList ps);//释放空间
void SeqListPushBack(PSeqList ps, DataType data);//尾插
void SeqListPopBack(PSeqList ps);//尾删
void SeqListPushFront(PSeqList ps, DataType data);//头插
void SeqListPopFront(PSeqList ps);//头删
void SeqListInsert(PSeqList ps, int pos, DataType datda);//任意位置插入
void SeqListErase(PSeqList ps, int pos);//任意位置删除
int SeqListFind(PSeqList ps, DataType data);// 检测data是否在顺序表中 
void SeqListRemove(PSeqList ps, DataType data);// 移除顺序表中第一个值为data的元素 
void SeqListRemoveAll(PSeqList ps, DataType data);// 移除顺序表中所有值为data的元素
int SeqListSize(PSeqList ps);// 获取顺序表有效元素个数 
int SeqListCapacity(PSeqList ps);// 获取顺序表的容量 
int SeqListEmpty(PSeqList ps);// 检测顺序表是否为空
DataType SeqListFront(PSeqList ps);// 获取顺序表中第一个元素 
DataType SeqListBack(PSeqList ps);// 获取顺序表中最后一个元素
////////////////////////////////////// 
void PrintSeqList(PSeqList ps);