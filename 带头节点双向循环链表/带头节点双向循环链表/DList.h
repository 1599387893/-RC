#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct DList
{
	DataType data;
	struct DList* pNext;
	struct DList* pPer;
}DList;

void DListInit(DList* s);//初始化
void DListPushBack(DList* s, DataType data);//尾插
void DListPopBack(DList* s);//尾删

void DListPushFront(DList* s,DataType data);//头插
void DLIstPopFront(DList* s);//头删
void DListInsertAfter(DList* pos, DataType data);// 在链表pos位置后插入置为data的节点
void DListErase(DList* s, DataType data);// 删除链表中值为data的节点
void DListEraseALL(DList* s, DataType data);// 删除链表中所有值为data的节点 
DList* DListFind(DList* s, DataType data);// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
int DListSize(DList* s);// 获取链表中有效节点的个数
int DListEmpty(DList* s);// 检测链表是否为空 
DList* DListFront(DList* s);// 获取链表的第一个节点 
DList* DListBack(DList* s);// 获取链表的第二个节点 

void PrintDList(DList* s);//显示链表内容
void DListDestroy(DList* s);//销毁链表