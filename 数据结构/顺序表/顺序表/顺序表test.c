#include"SeqList.h"

int main()
{
	SeqList s;
	InitSeqList(&s);

	//尾插
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	PrintSeqList(&s);
	//SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	PrintSeqList(&s);
	//尾删
	SeqListPopBack(&s);
	PrintSeqList(&s);
	//头插
	SeqListPushFront(&s, 11);
	PrintSeqList(&s);
	//头删
	SeqListPopFront(&s);
	PrintSeqList(&s);
	
	//任意位置插入
	SeqListInsert(&s, 2, 11);
	PrintSeqList(&s);
	//任意位置删除
	SeqListErase(&s, 2);
	PrintSeqList(&s);

	//检测data是否在顺序表中 
	/*int i = SeqListFind(&s,1);
	printf("\t\t%d\n", i);*/

	// 移除顺序表中第一个值为data的元素
	SeqListRemove(&s, 1);
	PrintSeqList(&s);
	// 移除顺序表中所有值为data的元素
	SeqListRemoveAll(&s, 1);
	PrintSeqList(&s);

	 //获取顺序表有效元素个数
	printf("有效元素%d个\n", SeqListSize(&s));
	// 获取顺序表的容量
	printf("容量：%d\n",SeqListCapacity(&s));
	// 检测顺序表是否为空
	printf("是否为空：%d\n", SeqListEmpty(&s));

	// 获取顺序表中第一个元素 
	printf("第一个：%d\n", SeqListFront(&s));
	// 获取顺序表中最后一个元素
	printf("最后一个%d\n", SeqListBack(&s));





	DestroySeqList(&s);
	system("pause");
	return 0;
}