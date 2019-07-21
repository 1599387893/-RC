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
//��ʼ��
void ListInit(List* pl)
{
	assert(pl);
	pl->_head = BuyNewNode(-1);
	pl->_head->_next = pl->_head;
	pl->_head->_prev = pl->_head;
}
//����
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
//ͷ��
void ListPushFront(List* pl, LTDataType data)
{
	assert(pl);
	ListNode* newNode = BuyNewNode(data);
	newNode->_next = pl->_head->_next;
	newNode->_prev = pl->_head;
	pl->_head->_next->_prev = newNode;
	pl->_head->_next = newNode;
}
//ͷɾ
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
//β��
void ListPushBack(List* pl, LTDataType data)
{
	assert(pl);
	ListNode* newNode = BuyNewNode(data);
	newNode->_next = pl->_head->_prev;
	newNode->_next = pl->_head;
	pl->_head->_prev->_next = newNode;
	pl->_head->_prev = newNode;
}
//βɾ
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
//����λ�õĲ���
void ListPushPos(List* pl, LTDataType data)
{
	assert(pl);

}
//����λ�õ�ɾ��
void ListPopPos(List* pl)
{
	assert(pl);

}
//��ӡ��������
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