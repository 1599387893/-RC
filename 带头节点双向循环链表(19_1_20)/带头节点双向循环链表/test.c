#include"DList.h"

int main()
{
	DList* Dl;
	DListInit(&Dl);//初始化
	//DListPushBack(Dl, 0);//尾插
	//DListPushBack(Dl, 1);//尾插
	//DListPushBack(Dl, 2);//尾插
	//DListPushBack(Dl, 3);//尾插
	//PrintDList(Dl);//显示双向链表内容
	//DListPopBack(Dl);
	//PrintDList(Dl);//显示双向链表内容
	
	DListPushFront(Dl, 0);//头插
	DListPushFront(Dl, 1);//头插
	DListPushFront(Dl, 1);//头插
	DListPushFront(Dl, 1);//头插
	//DListPushFront(Dl, 1);//头插
	//DListPushFront(Dl, 1);//头插
	//DListPushFront(Dl, 2);//头插
	//DListPushFront(Dl, 3);//头插
	PrintDList(Dl);//显示双向链表内容
	//DLIstPopFront(Dl);//头删
	//PrintDList(Dl);//显示双向链表内容
	//printf("%p\n", DListFind(Dl, 2));//找出双向链表中值为data的结点
	//printf("%p\n", Dl->pNext);
	//DListInsertAfter(DListFind(Dl, 2), -1);//在pos之后插入
	//PrintDList(Dl);//显示双向链表内容
	//DListInsertBefore(DListFind(Dl, 2), -1);//在pos之前插入
	//PrintDList(Dl);//显示双向链表内容
	//DListErase(Dl, -1);//删除值为data的结点
	//PrintDList(Dl);//显示双向链表内容
	//DListEraseALL(Dl, 1);//删除所有值为data的结点
	//PrintDList(Dl);//显示双向链表内容
	//printf("有效元素个数为%d\n", DListSize(Dl));
	//printf("是否为空：%d\n", DListEmpty(Dl));
	//printf("%p\n", DListFront(Dl));
	//printf("%p\n", Dl->pNext);
	//
	//printf("%p\n", DListBack(Dl));
	//printf("%p\n", Dl->pNext->pNext);

	
	DListDestroy(Dl);//销毁双向链表
	system("pause");
	/////////////////////PrintDList(Dl);//显示双向链表内容

}