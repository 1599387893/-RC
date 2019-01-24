#include"DList.h"

//初始化
void DListInit(DList** s)
{
	//assert(s);
	*s = (DList*)malloc(sizeof(DList));
	(*s)->data = -1;
	(*s)->pNext = (*s);
	(*s)->pPer = (*s);
}
//创建新结点
DList* BuyNewNode(DataType data)
{
	DList* sN = (DList*)malloc(sizeof(DList));
	sN->data = data;
	sN->pNext = sN;
	sN->pPer = sN;
	return sN;
}
//尾插
void DListPushBack(DList* s, DataType data )
{
	assert(s);
	DList* sN = BuyNewNode(data);
	if (s->pNext == s)
	{
		sN->pNext = s;
		sN->pPer = s;
		s->pNext = sN;
		s->pPer = sN;
		printf("尾插完成！\n");
		return;
	}
	else
	{
		sN->pPer = s->pPer;
		sN->pNext = s;
		s->pPer->pNext = sN;
		s->pPer = sN;
		printf("尾插完成！\n");
		return;
	}
}
//尾删
void DListPopBack(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return;
	}
	else
	{
		s->pPer->pPer->pNext = s;
		DList* ptr = s->pPer;
		s->pPer = s->pPer->pPer;
		free(ptr);
		ptr = NULL;
		printf("尾删完成！\n");
		return;
	}
}
//头插
void DListPushFront(DList* s, DataType data)
{
	assert(s);
	DList* sN = BuyNewNode(data);
	if (s->pNext == s)
	{
		sN->pNext = s;
		sN->pPer = s;
		s->pNext = sN;
		s->pPer = sN;
		printf("头插完成！\n");
		return;
	}
	else
	{
		sN->pNext = s->pNext;
		sN->pPer = s;
		s->pNext->pPer = sN;
		s->pNext = sN;
		printf("头插完成！\n");
		return;
	}
}
//头删
void DLIstPopFront(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return;
	}
	else
	{
		DList* ptr = s->pNext;
		s->pNext->pNext->pPer = s;
		s->pNext = s->pNext->pNext;
		free(ptr);
		ptr = NULL;
		printf("头删完成！\n");
		return;
	}
}
// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
DList* DListFind(DList* s, DataType data)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return NULL;
	}
	else
	{
		DList* ptr = s->pNext;
		while (ptr != s)
		{
			if (ptr->data == data)
			{
				return ptr;
			}
			ptr = ptr->pNext;
		}
		printf("双向链表中没有值为%d的结点！\n", data);
		return NULL;
	}

}
// 在链表pos位置后插入置为data的节点
void DListInsertAfter(DList* pos, DataType data)
{
	assert(pos);
	DList* sN = BuyNewNode(data);
	if (pos == NULL)
	{
		printf("传入的结点为空指针！\n");
		return;
	}
	else
	{
		sN->pNext = pos->pNext;
		sN->pPer = pos;
		pos->pNext->pPer = sN;
		pos->pNext = sN;
		printf("在pos位置后差入成功！\n");
		return;
	}
}

// 在链表pos位置前插入置为data的节点
void DListInsertBefore(DList* pos, DataType data)
{
	assert(pos);
	DList* sN = BuyNewNode(data);
	if (pos == NULL)
	{
		printf("传入的结点为空指针！\n");
		return;
	}
	else
	{
		sN->pNext = pos;
		sN->pPer = pos->pPer;
		pos->pPer->pNext = sN;
		pos->pPer = sN;
		printf("在pos位置前差入成功！\n");
		return;
	}
}
// 删除链表中值为data的节点
void DListErase(DList* s, DataType data)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return;
	}
	else
	{
		DList* ptr = s->pNext;
		while (ptr != s)
		{
			if (ptr->data == data)
			{
				ptr->pPer->pNext = ptr->pNext;
				free(ptr);
				ptr = NULL;
				printf("值为%d的结点删除完成！\n", data);
				return;
			}
			ptr = ptr->pNext;
		}
		printf("双向链表中没有值为%d的结点！\n", data);
		return;
	}
}
// 删除链表中所有值为data的节点
void DListEraseALL(DList* s, DataType data)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return;
	}
	else
	{

		/*DList* ptr1 = s->pNext;
		while (ptr1 != s)
		{
			if (ptr1->data == data)
			{
				DList* ptr2 = ptr1;
				ptr1 = ptr1->pNext;
				ptr2->pNext->pPer = ptr2->pPer;
				ptr2->pPer->pNext = ptr2->pNext;
				free(ptr2);
				ptr2 = NULL;
				continue;
			}
			ptr1 = ptr1->pNext;
		}
		printf("删除完成!\n");
		return;*/
	}
}
// 获取链表中有效节点的个数
int DListSize(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return 0;
	}
	else
	{
		int count = 0;
		DList* ptr = s->pNext;
		while (ptr != s)
		{
			ptr = ptr->pNext;
			count++;
		}
		return count;
	}
}
// 检测链表是否为空 
int DListEmpty(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		return -1;
	}
	else
		return 1;
}
// 获取链表的第一个节点 
DList* DListFront(DList* s)
{
	assert(s);
	return s->pNext;
}
// 获取链表的第二个节点 
DList* DListBack(DList* s)
{
	assert(s);
	return s->pNext->pNext;
}
//显示链表内容
void PrintDList(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return;
	}
	else
	{
		DList* ptr = s->pNext;
		while (ptr != s)
		{
			printf("%d--->", ptr->data);
			ptr = ptr->pNext;
		}
		printf("NULL\n");
		return;
	}
}
//销毁链表
void DListDestroy(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("双向链表为空！\n");
		return;
	}
	else
	{
		DList* ptr1 = s->pNext;
		DList* ptr2 = s;
		while (ptr1!=ptr2)
		{
			free(s);
			s = NULL;
			s = ptr1;
			ptr1 = ptr1->pNext;
		}
		free(s);
		s = NULL;
		printf("双向链表已销毁！\n");
	}
}