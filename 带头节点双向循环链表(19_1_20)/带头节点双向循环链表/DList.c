#include"DList.h"

//��ʼ��
void DListInit(DList** s)
{
	//assert(s);
	*s = (DList*)malloc(sizeof(DList));
	(*s)->data = -1;
	(*s)->pNext = (*s);
	(*s)->pPer = (*s);
}
//�����½��
DList* BuyNewNode(DataType data)
{
	DList* sN = (DList*)malloc(sizeof(DList));
	sN->data = data;
	sN->pNext = sN;
	sN->pPer = sN;
	return sN;
}
//β��
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
		printf("β����ɣ�\n");
		return;
	}
	else
	{
		sN->pPer = s->pPer;
		sN->pNext = s;
		s->pPer->pNext = sN;
		s->pPer = sN;
		printf("β����ɣ�\n");
		return;
	}
}
//βɾ
void DListPopBack(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
		return;
	}
	else
	{
		s->pPer->pPer->pNext = s;
		DList* ptr = s->pPer;
		s->pPer = s->pPer->pPer;
		free(ptr);
		ptr = NULL;
		printf("βɾ��ɣ�\n");
		return;
	}
}
//ͷ��
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
		printf("ͷ����ɣ�\n");
		return;
	}
	else
	{
		sN->pNext = s->pNext;
		sN->pPer = s;
		s->pNext->pPer = sN;
		s->pNext = sN;
		printf("ͷ����ɣ�\n");
		return;
	}
}
//ͷɾ
void DLIstPopFront(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
		return;
	}
	else
	{
		DList* ptr = s->pNext;
		s->pNext->pNext->pPer = s;
		s->pNext = s->pNext->pNext;
		free(ptr);
		ptr = NULL;
		printf("ͷɾ��ɣ�\n");
		return;
	}
}
// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
DList* DListFind(DList* s, DataType data)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
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
		printf("˫��������û��ֵΪ%d�Ľ�㣡\n", data);
		return NULL;
	}

}
// ������posλ�ú������Ϊdata�Ľڵ�
void DListInsertAfter(DList* pos, DataType data)
{
	assert(pos);
	DList* sN = BuyNewNode(data);
	if (pos == NULL)
	{
		printf("����Ľ��Ϊ��ָ�룡\n");
		return;
	}
	else
	{
		sN->pNext = pos->pNext;
		sN->pPer = pos;
		pos->pNext->pPer = sN;
		pos->pNext = sN;
		printf("��posλ�ú����ɹ���\n");
		return;
	}
}

// ������posλ��ǰ������Ϊdata�Ľڵ�
void DListInsertBefore(DList* pos, DataType data)
{
	assert(pos);
	DList* sN = BuyNewNode(data);
	if (pos == NULL)
	{
		printf("����Ľ��Ϊ��ָ�룡\n");
		return;
	}
	else
	{
		sN->pNext = pos;
		sN->pPer = pos->pPer;
		pos->pPer->pNext = sN;
		pos->pPer = sN;
		printf("��posλ��ǰ����ɹ���\n");
		return;
	}
}
// ɾ��������ֵΪdata�Ľڵ�
void DListErase(DList* s, DataType data)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
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
				printf("ֵΪ%d�Ľ��ɾ����ɣ�\n", data);
				return;
			}
			ptr = ptr->pNext;
		}
		printf("˫��������û��ֵΪ%d�Ľ�㣡\n", data);
		return;
	}
}
// ɾ������������ֵΪdata�Ľڵ�
void DListEraseALL(DList* s, DataType data)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
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
		printf("ɾ�����!\n");
		return;*/
	}
}
// ��ȡ��������Ч�ڵ�ĸ���
int DListSize(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
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
// ��������Ƿ�Ϊ�� 
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
// ��ȡ����ĵ�һ���ڵ� 
DList* DListFront(DList* s)
{
	assert(s);
	return s->pNext;
}
// ��ȡ����ĵڶ����ڵ� 
DList* DListBack(DList* s)
{
	assert(s);
	return s->pNext->pNext;
}
//��ʾ��������
void PrintDList(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
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
//��������
void DListDestroy(DList* s)
{
	assert(s);
	if (s->pNext == s)
	{
		printf("˫������Ϊ�գ�\n");
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
		printf("˫�����������٣�\n");
	}
}