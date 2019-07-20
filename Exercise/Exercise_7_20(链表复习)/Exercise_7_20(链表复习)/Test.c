#include"SList.h"

int main()
{
	SList s;
	SListInit(&s);
	printf("Empty = %d\n",SListEmpty(&s));
	SListPushBack(&s,1);
	SListPushBack(&s,2);
	SListPushBack(&s,3);
	SListPushBack(&s,4);
	SListPushBack(&s,10);
	SListPushBack(&s,12);
	Print(&s);
	printf("Empty = %d\n", SListEmpty(&s));

	printf("size = %d\n",SListSize(&s));
	printf("Front = %d\n", SListFront(&s)->_data);

	printf("Back = %d\n", SlistBack(&s)->_data);
	SListInsert(&s, Find(&s, 10), 5);
	Print(&s);

	SListErase(&s, Find(&s, 12));
	Print(&s);

	SListPopBack(&s);
	Print(&s);

	SListPushFront(&s, 0);
	SListPopFront(&s);
	//SListPushFront(&s, -1);
	Print(&s);

	SListPopFront(&s);
	SListPopFront(&s);
	Print(&s);
	SListDestory(&s);
	Print(&s);

	return 0;
}