#include"SeqList.h"

int main()
{
	SeqList s;
	InitSeqList(&s);

	//β��
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
	//βɾ
	SeqListPopBack(&s);
	PrintSeqList(&s);
	//ͷ��
	SeqListPushFront(&s, 11);
	PrintSeqList(&s);
	//ͷɾ
	SeqListPopFront(&s);
	PrintSeqList(&s);
	
	//����λ�ò���
	SeqListInsert(&s, 2, 11);
	PrintSeqList(&s);
	//����λ��ɾ��
	SeqListErase(&s, 2);
	PrintSeqList(&s);

	//���data�Ƿ���˳����� 
	/*int i = SeqListFind(&s,1);
	printf("\t\t%d\n", i);*/

	// �Ƴ�˳����е�һ��ֵΪdata��Ԫ��
	SeqListRemove(&s, 1);
	PrintSeqList(&s);
	// �Ƴ�˳���������ֵΪdata��Ԫ��
	SeqListRemoveAll(&s, 1);
	PrintSeqList(&s);

	 //��ȡ˳�����ЧԪ�ظ���
	printf("��ЧԪ��%d��\n", SeqListSize(&s));
	// ��ȡ˳��������
	printf("������%d\n",SeqListCapacity(&s));
	// ���˳����Ƿ�Ϊ��
	printf("�Ƿ�Ϊ�գ�%d\n", SeqListEmpty(&s));

	// ��ȡ˳����е�һ��Ԫ�� 
	printf("��һ����%d\n", SeqListFront(&s));
	// ��ȡ˳��������һ��Ԫ��
	printf("���һ��%d\n", SeqListBack(&s));





	DestroySeqList(&s);
	system("pause");
	return 0;
}