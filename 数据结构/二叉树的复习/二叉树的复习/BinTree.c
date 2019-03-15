#include"BinTree.h"

//����������
BTNode* BuyNewNode(BTDataType data)
{
	BTNode* New = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == New)
		assert("BuyNewNode Fail!");
	New->_data = data;
	New->_pleft = NULL;
	New->_pright = NULL;
	return New;
}
BTNode* CreateBT(BTDataType* array, int size, int* index)
{
	BTNode* pRoot = NULL;
	if (array[*index] == '#' || *index >= size || array[*index] == '\0')
		return NULL;
	pRoot = BuyNewNode(array[*index]);
	(*index)++;
	pRoot->_pleft = CreateBT(array, size, index);
	(*index)++;
	pRoot->_pright = CreateBT(array, size, index);

	return pRoot;
}
BTNode* CreateBinTree(BTDataType* array, int size)
{
	BTNode* pRoot = NULL;
	int index = 0;
	if (NULL == array)
		return NULL;
	pRoot = CreateBT(array, size, &index);
	return pRoot;
}
BTNode* CopyBinTree(BTNode* pRoot);//�������Ŀ���
//������������
void DestroyBinTree(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	DestroyBinTree(pRoot->_pleft);
	DestroyBinTree(pRoot->_pright);
	free(pRoot);
	pRoot = NULL;
}
//�������ı���(�ݹ�)
//ǰ�����
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c", pRoot->_data);
		PreOrder(pRoot->_pleft);
		PreOrder(pRoot->_pright);
	}
}
//�������
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pleft);
		printf("%c", pRoot->_data);
		InOrder(pRoot->_pright);
	}
}
//�������
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pleft);
		PostOrder(pRoot->_pright);
		printf("%c", pRoot->_data);
	}
}
//�������ı���(�ǵݹ�)
//ǰ�����
void PreOrderNor(BTNode* pRoot)
{
	//BTNode* ptr = NULL;
	//Stack s;
	//StackInit(&s);
	////�Ƚ����ڵ���ջ
	//StackPush(&s,pRoot);
	//while (!StackEmpty(&s))
	//{
	//	//�Ƚ�pRoot������������
	//	ptr = pRoot->_pleft;
	//	while (ptr)
	//	{
	//		StackPush(&s, ptr);
	//		ptr = ptr->_pleft;
	//	}
	//	while (!StackEmpty(&s))
	//	{
	//		if (NULL != ptr->_pright)
	//		{
	//			while (ptr)
	//			{
	//				StackPush(&s, ptr);
	//			}
	//		}
	//		ptr = StackTop(&s);
	//		printf("%c ", ptr->_data);
	//		StackPop(&s);
	//	}
	//	//����������
	//	ptr = pRoot->_pright;
	//	while (ptr)
	//	{
	//		StackPush(&s, ptr);
	//		ptr = ptr->_pright;
	//	}
	//	while (!StackEmpty(&s))
	//	{
	//		ptr = StackTop(&s);
	//		printf("%c ", ptr->_data);
	//		StackPop(&s);
	//	}
	//	
	//		


	//}
}
//�������
void InOrderNor(BTNode* pRoot)
{

}
//�������
void PostOrderNor(BTNode* pRoot)
{

}
//�������
void LevelOrder(BTNode* pRoot)
{

}

//�����������
int HeightBinTree(BTNode* pRoot)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (NULL == pRoot)
		return 0;
	leftHeight = HeightBinTree(pRoot->_pleft);
	rightHeight = HeightBinTree(pRoot->_pright);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//2.0ƽ���� O(N)
int isBalanceTree_p(BTNode* pRoot,int* height)
{
	int IsLBalance = 0;//��ƽ�����ķ��ؽ���ֵ
	int IsRBalance = 0;//��ƽ�����ķ��ؽ���ֵ
	int LeftHeight = 0;//�������߶�
	int RightHeight = 0;//�������߶�

	if (NULL == pRoot)
		return 1;

	IsLBalance = isBalanceTree_p(pRoot->_pleft, &LeftHeight);
	IsRBalance = isBalanceTree_p(pRoot->_pright, &RightHeight);
	
	if (IsLBalance && IsRBalance && (abs(RightHeight - LeftHeight) < 2))
	{
		*height = LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
		return 1;
	}

	return 0;
}
//1.0ƽ���� O(N^2)
int isBalanceTree(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 1;
	if (NULL == pRoot->_pleft && NULL == pRoot->_pright)
		return 1;
	return abs(HeightBinTree(pRoot->_pleft) - HeightBinTree(pRoot->_pright)) < 2 \
		&& isBalanceTree(pRoot->_pleft) \
		&& isBalanceTree(pRoot->_pright);
}
//���нڵ����
int GetNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	//���п���
	//if (NULL == pRoot->_pleft && NULL == pRoot->_pright)
	//	return 1;
	return GetNodeCount(pRoot->_pleft) + GetNodeCount(pRoot->_pright) + 1;
}
//Ҷ�ӽڵ����
int GetLeafNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (NULL == pRoot->_pleft && NULL == pRoot->_pright)
		return 1;

	return GetLeafNodeCount(pRoot->_pleft) + GetLeafNodeCount(pRoot->_pright);
}
//��K��ڵ����
int GetKLevelNodeCount(BTNode* pRoot, int k)
{
	if (NULL == pRoot || k < 0)//��K���ڲ���ʱ����������
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(pRoot->_pleft, k - 1) + GetKLevelNodeCount(pRoot->_pright, k - 1);

}
//�ҵ�ĳ���ڵ��˫�׽��
BTNode* GetNodeParent(BTNode* pRoot, BTNode* child)
{
	if (NULL == pRoot || child == NULL)
		return NULL;
	if (pRoot == child)
		return NULL;
	if (pRoot->_pleft == child || pRoot->_pright == child)
		return pRoot;
	if (GetNodeParent(pRoot->_pleft, child))
		return GetNodeParent(pRoot->_pleft, child);
	GetNodeParent(pRoot->_pright, child);
}
//�ҵ�ĳ���ڵ�
BTNode* GetNode(BTNode* pRoot, BTDataType data)
{
	if (pRoot == NULL)
		return NULL;
	if (pRoot->_data == data)
		return pRoot;
	if (GetNode(pRoot->_pleft, data))
		return GetNode(pRoot->_pleft, data);
	return GetNode(pRoot->_pright, data);
}
//������
int Mirror(BTNode* pRoot)
{
	BTNode* temp = NULL;
	if (pRoot)
	{
		temp = pRoot->_pleft;
		pRoot->_pleft = pRoot->_pright;
		pRoot->_pright = temp;
		Mirror(pRoot->_pleft);
		Mirror(pRoot->_pright);
	}
}

int isSameTree();//�������Ƿ���ͬ
//OJ��