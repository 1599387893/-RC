#include"DList.h"

int main()
{
	DList* Dl;
	Dl = (DList*)malloc(sizeof(DList));
	Dl->data = -1;
	Dl ->pNext = Dl;
	Dl->pPer = Dl;
	//DListInit(Dl);//��ʼ��
	//DListPushBack(Dl, 0);//β��
	//DListPushBack(Dl, 1);//β��
	//DListPushBack(Dl, 2);//β��
	//DListPushBack(Dl, 3);//β��
	//PrintDList(Dl);//��ʾ˫����������
	//DListPopBack(Dl);
	PrintDList(Dl);//��ʾ˫����������
	
	DListPushFront(Dl, 0);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	DListPushFront(Dl, 2);//ͷ��
	DListPushFront(Dl, 3);//ͷ��
	PrintDList(Dl);//��ʾ˫����������
	//DLIstPopFront(Dl);//ͷɾ
	//PrintDList(Dl);//��ʾ˫����������
	//printf("%p\n", DListFind(Dl, 2));//�ҳ�˫��������ֵΪdata�Ľ��
	//printf("%p\n", Dl->pNext);
	//DListInsertAfter(DListFind(Dl, 2), -1);//
	//PrintDList(Dl);//��ʾ˫����������
	//DListErase(Dl, -1);//ɾ��ֵΪdata�Ľ��
	//PrintDList(Dl);//��ʾ˫����������
	//DListEraseALL(Dl, 1);//ɾ������ֵΪdata�Ľ��
	//PrintDList(Dl);//��ʾ˫����������
	printf("��ЧԪ�ظ���Ϊ%d\n", DListSize(Dl));
	printf("�Ƿ�Ϊ�գ�%d\n", DListEmpty(Dl));
	printf("%p\n", DListFront(Dl));
	printf("%p\n", Dl->pNext);
	
	printf("%p\n", DListBack(Dl));
	printf("%p\n", Dl->pNext->pNext);






	system("pause");
	DListDestroy(Dl);//����˫������
	/////////////////////PrintDList(Dl);//��ʾ˫����������

}