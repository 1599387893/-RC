#include"DList.h"

int main()
{
	DList* Dl;
	DListInit(&Dl);//��ʼ��
	//DListPushBack(Dl, 0);//β��
	//DListPushBack(Dl, 1);//β��
	//DListPushBack(Dl, 2);//β��
	//DListPushBack(Dl, 3);//β��
	//PrintDList(Dl);//��ʾ˫����������
	//DListPopBack(Dl);
	//PrintDList(Dl);//��ʾ˫����������
	
	DListPushFront(Dl, 0);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	DListPushFront(Dl, 1);//ͷ��
	//DListPushFront(Dl, 1);//ͷ��
	//DListPushFront(Dl, 1);//ͷ��
	//DListPushFront(Dl, 2);//ͷ��
	//DListPushFront(Dl, 3);//ͷ��
	PrintDList(Dl);//��ʾ˫����������
	//DLIstPopFront(Dl);//ͷɾ
	//PrintDList(Dl);//��ʾ˫����������
	//printf("%p\n", DListFind(Dl, 2));//�ҳ�˫��������ֵΪdata�Ľ��
	//printf("%p\n", Dl->pNext);
	//DListInsertAfter(DListFind(Dl, 2), -1);//��pos֮�����
	//PrintDList(Dl);//��ʾ˫����������
	//DListInsertBefore(DListFind(Dl, 2), -1);//��pos֮ǰ����
	//PrintDList(Dl);//��ʾ˫����������
	//DListErase(Dl, -1);//ɾ��ֵΪdata�Ľ��
	//PrintDList(Dl);//��ʾ˫����������
	//DListEraseALL(Dl, 1);//ɾ������ֵΪdata�Ľ��
	//PrintDList(Dl);//��ʾ˫����������
	//printf("��ЧԪ�ظ���Ϊ%d\n", DListSize(Dl));
	//printf("�Ƿ�Ϊ�գ�%d\n", DListEmpty(Dl));
	//printf("%p\n", DListFront(Dl));
	//printf("%p\n", Dl->pNext);
	//
	//printf("%p\n", DListBack(Dl));
	//printf("%p\n", Dl->pNext->pNext);

	
	DListDestroy(Dl);//����˫������
	system("pause");
	/////////////////////PrintDList(Dl);//��ʾ˫����������

}