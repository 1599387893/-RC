#include"DList.h"
//#include"SeqList.h"
int main()
{
	//TestSeqList();
	//TestDList();
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
	ListDestory(&l);
	return 0;
}