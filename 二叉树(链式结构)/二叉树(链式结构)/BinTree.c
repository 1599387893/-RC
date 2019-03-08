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

//创建一个数
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
		//根结点
		pRoot = BuyNewNode(array[*index]);
		(*index)++;
		
		//根节点的左子树
		pRoot->_pLeft = CreateBT(array, size, index);

		//根节点的右子树
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
//复制一棵树
BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* pNew = NULL;
	if (NULL == pRoot)
		return NULL;

	//拷贝根节点
	pNew = BuyNewNode(pRoot->_data);
	
	//拷贝根节点的左子树
	if(pRoot->_pLeft)//（优化）
	pNew->_pLeft = CopyBinTree(pRoot->_pLeft);
	
	//拷贝根节点的右子树
	if(pRoot->_pRight)//（优化）
	pNew->_pRight = CopyBinTree(pRoot->_pRight);
	
	//返回根节点
	return pNew;
}

//销毁树
void DestroyBinTree(BTNode** pRoot)
{
	if ((*pRoot) == NULL)
		return;
	//从叶子节点开始销毁
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
//三种遍历方法(递归)
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
//三种遍历方法(非递归)
void PreOrderNor(BTNode* pRoot)
{
	//利用栈的特性，进行遍历
}
void InOrderNor(BTNode* pRoot)
{
	//利用栈的特性，进行遍历
}
void PostOrderNor(BTNode* pRoot)
{
	//利用栈的特性，进行遍历
}
//层序遍历
void LevelOrder(BTNode* pRoot)
{
	//利用队列的特性，进行遍历
}
//树中节点个数
int GetNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	return (GetNodeCount(pRoot->_pLeft) + GetNodeCount(pRoot->_pRight) + 1);
}
//树中叶子节点个数
int GetLeafNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;
	return (GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight));
}

//树中第K层结点个数
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
//树中第K层结点个数
int GetKLevelNodeCount2(BTNode* pRoot, int k)
{
	if (NULL == pRoot || k < 1)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount2(pRoot->_pRight, k - 1) + GetKLevelNodeCount2(pRoot->_pLeft, k - 1);
}
//获取一个结点的双亲
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
//找到树中值为data的结点
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
//将一颗树进行镜像翻转
void Mirror(BTNode*pRoot)
{

}












