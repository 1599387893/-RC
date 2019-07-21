#include"DList.h"

ListNode* BuyNewNode(LTDataType data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newNode)
		return NULL;
	newNode->_data = data;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}
//初始化
void ListInit(List* pl)
{
	assert(pl);
	pl->_head = BuyNewNode(-1);
	pl->_head->_next = pl->_head;
	pl->_head->_prev = pl->_head;
}
//销毁
void ListDestory(List* pl)
{
	assert(pl);
	ListNode* pCur = pl->_head->_next;
	while (pCur != pl->_head)
	{
		pl->_head->_next = pCur->_next;
		free(pCur);
		pCur = pl->_head->_next;
	}
	free(pl->_head);
	pl->_head = NULL;
}
//头插
void ListPushFront(List* pl, LTDataType data)
{
	assert(pl);
	ListNode* newNode = BuyNewNode(data);
	newNode->_next = pl->_head->_next;
	newNode->_prev = pl->_head;
	pl->_head->_next->_prev = newNode;
	pl->_head->_next = newNode;
}
//头删
void ListPopFront(List* pl)
{
	assert(pl);
	if (pl->_head->_next == pl->_head)
		return;
	ListNode* pCur = pl->_head->_next;
	pl->_head->_next = pCur->_next;
	pCur->_next->_prev = pl->_head;
	free(pCur);
	pCur = NULL;
}
//尾插
void ListPushBack(List* pl, LTDataType data)
{
	assert(pl);
	ListNode* newNode = BuyNewNode(data);
	newNode->_next = pl->_head->_prev;
	newNode->_next = pl->_head;
	pl->_head->_prev->_next = newNode;
	pl->_head->_prev = newNode;
}
//尾删
void ListPopBack(List* pl)
{
	assert(pl);
	if (pl->_head->_prev == pl->_head)
		return;
	ListNode* pCur = pl->_head->_prev;
	pl->_head->_prev = pCur->_prev;
	pCur->_prev->_next = pl->_head;
	free(pCur);
	pCur = NULL;
}
//任意位置的插入
void ListPushPos(List* pl, LTDataType data)
{
	assert(pl);

}
//任意位置的删除
void ListPopPos(List* pl)
{
	assert(pl);

}
//打印链表内容
void ListPrint(List* pl)
{
	assert(pl);
	ListNode* pCur = pl->_head->_next;
	printf("Head--->");
	while (pCur != pl->_head)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_next;
	}
	printf("NULL\n");
}

void Test1()
{
	List l;
	ListInit(&l);
	ListPushFront(&l, 5);
	ListPushFront(&l, 4);
	ListPushFront(&l, 3);
	ListPushFront(&l, 2);
	ListPushFront(&l, 1);
	ListPrint(&l);
	ListPopFront(&l);
	ListPrint(&l);

}