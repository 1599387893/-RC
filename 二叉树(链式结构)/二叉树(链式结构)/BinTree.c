#include"BinTree.h"

//BTNode* BuyNewNode(DateTypedef data)
//{
//	BTNode tNew;
//	tNew._data = data;
//	tNew._pLeft = NULL;
//	tNew._pRight = NULL;
//	return &tNew;
//}
//BTNode* CreateBT(DateTypedef* array, int* index,int size)
//{
//	BTNode* NewBT;
//	if (array[*index] == '#' || array[*index] == '\0' || *index > size)
//		return NULL;
//	NewBT = BuyNewNode(array[*index]);
//	(*index)++;
//	NewBT->_pLeft = CreateBT(array, index,size);
//	if (NewBT->_pLeft == NULL)
//		(*index)++;
//	NewBT->_pRight = CreateBT(array, index,size);
//	if (NewBT->_pRight == NULL)
//		(*index)++;
//	return NewBT;
//}
//void CreateBinTree(BTNode* pRoot, DateTypedef* array)
//{
//	assert(pRoot);
//	int index = 0;
//	int size = strlen(array);
//	pRoot = CreateBT(array, &index,size);
//}

//����һ����
BTNode* BuyNewNode(DateTypedef data)
{
	BTNode* New = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == New)
		assert(0);
	New->_data = data;
	New->_pLeft = NULL;
	New->_pRight = NULL;
	return New;
}
BTNode* CreateBT(DateTypedef* array, int size, int* index)
{
	BTNode* pRoot = NULL;
	if (*index < size && array[*index] != '#')
	{
		//�����
		pRoot = BuyNewNode(array[*index]);
		(*index)++;
		
		//���ڵ��������
		pRoot->_pLeft = CreateBT(array, size, index);

		//���ڵ��������
		(*index)++;
		pRoot->_pRight = CreateBT(array, size, index);

	}
	return pRoot;
}
BTNode* CreateBinTree(DateTypedef* array, int size)
{
	int index = 0;
	if (array == NULL)
		return NULL;

	return CreateBT(array, size, &index);
}
//����һ����
BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* pNew = NULL;
	if (NULL == pRoot)
		return NULL;

	//�������ڵ�
	pNew = BuyNewNode(pRoot->_data);
	
	//�������ڵ��������
	if(pRoot->_pLeft)//���Ż���
	pNew->_pLeft = CopyBinTree(pRoot->_pLeft);
	
	//�������ڵ��������
	if(pRoot->_pRight)//���Ż���
	pNew->_pRight = CopyBinTree(pRoot->_pRight);
	
	//���ظ��ڵ�
	return pNew;
}

//������
void DestroyBinTree(BTNode** pRoot)
{
	if ((*pRoot) == NULL)
		return;
	//��Ҷ�ӽڵ㿪ʼ����
	DestroyBinTree(&(*pRoot)->_pLeft);
	DestroyBinTree(&(*pRoot)->_pRight);
	free(*pRoot);
	(*pRoot) = NULL;
}
int BinTreeHeight(BTNode* pRoot)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (pRoot == NULL)
		return 0;
	leftHeight = BinTreeHeight(pRoot->_pLeft);
	rightHeight = BinTreeHeight(pRoot->_pRight);
	return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}
int isBalanced1(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 1;

	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;

	return (abs(BinTreeHeight(pRoot->_pLeft) - BinTreeHeight(pRoot->_pRight)) < 2) && isBalanced1(pRoot->_pLeft) && (isBalanced1(pRoot->_pRight));
}
int isBalanced2(BTNode* pRoot, int* height)
{
	int IsLeftBalance = 0;
	int IsRightBalance = 0;

	int leftHeight = 0;
	int rightHeight = 0;

	if (NULL == pRoot)
		return 1;

	IsLeftBalance = isBalanced2(pRoot->_pLeft, &leftHeight);
	IsRightBalance = isBalanced2(pRoot->_pRight, &rightHeight);

	if (IsLeftBalance && IsRightBalance && abs(rightHeight - leftHeight) < 2)
	{
		*height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return 1;
	}
	return 0;
}
//���ֱ�������(�ݹ�)
void PreOrder(BTNode* pRoot)
{
	//assert(pRoot);
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
void InOrder(BTNode* pRoot)
{
	//assert(pRoot);
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}
void PostOrder(BTNode* pRoot)
{
	//assert(pRoot);
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}
//���ֱ�������(�ǵݹ�)
void PreOrderNor(BTNode* pRoot)
{
	//����ջ�����ԣ����б���
}
void InOrderNor(BTNode* pRoot)
{
	//����ջ�����ԣ����б���
}
void PostOrderNor(BTNode* pRoot)
{
	//����ջ�����ԣ����б���
}
//�������
void LevelOrder(BTNode* pRoot)
{
	//���ö��е����ԣ����б���
}
//���нڵ����
int GetNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	return (GetNodeCount(pRoot->_pLeft) + GetNodeCount(pRoot->_pRight) + 1);
}
//����Ҷ�ӽڵ����
int GetLeafNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;
	return (GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight));
}

//���е�K�������
//void GetkLNC2(BTNode* pRoot, int k, int* l,int* c)
//{
//	if (pRoot == NULL)
//		return ;
//	if (*l == k)
//		(*c)++;
//	(*l)++;
//	GetkLNC(pRoot->_pLeft, k, l, c);
//	GetkLNC(pRoot->_pRight, k, l, c);
//	(*l)--;
//}

void GetkLNC2(BTNode* pRoot, int k, int* c)
{
	if (pRoot == NULL)
		return;
	if (1 == k)
		(*c)++;
	GetkLNC2(pRoot->_pLeft, k-1, c);
	GetkLNC2(pRoot->_pRight, k-1, c);
}
int GetKLevelNodeCount1(BTNode* pRoot, int k)
{
	if (pRoot == NULL || k < 1)
		return 0;
	if (k == 1)
		return 1;
	if (BinTreeHeight(pRoot) < k)
		return 0;
	int l = 1;
	int count = 0;
	//GetkLNC1(pRoot, k, &l, &count);
	GetkLNC2(pRoot, k, &count);
	return count;
}
//���е�K�������
int GetKLevelNodeCount2(BTNode* pRoot, int k)
{
	if (NULL == pRoot || k < 1)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount2(pRoot->_pRight, k - 1) + GetKLevelNodeCount2(pRoot->_pLeft, k - 1);
}
//��ȡһ������˫��
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)
{
	BTNode* parent = NULL;
	if (NULL == pRoot || NULL == pNode || pNode == pRoot)
		return NULL;

	if (pRoot->_pLeft == pNode || pRoot->_pRight == pNode)
		return pRoot;

	//return (GetNodeParent(pRoot->_pLeft, pNode) || GetNodeParent(pRoot->_pRight, pNode));

	if (parent = GetNodeParent(pRoot->_pLeft, pNode))
		return parent;
	return GetNodeParent(pRoot->_pRight, pNode);
}
//�ҵ�����ֵΪdata�Ľ��
BTNode* FindNode(BTNode* pRoot, DateTypedef data)
{
	BTNode* find = NULL;
	if (NULL == pRoot)
		return NULL;
	if (data == pRoot->_data)
		return pRoot;
	
	//return (FindNode(pRoot->_pLeft, data) || FindNode(pRoot->_pRight, data));
	
	if (find = FindNode(pRoot->_pLeft, data))
		return find;
	return FindNode(pRoot->_pRight, data);
}
//��һ�������о���ת
void Mirror(BTNode*pRoot)
{

}












