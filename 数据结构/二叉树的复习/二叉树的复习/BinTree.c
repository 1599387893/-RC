#include"BinTree.h"

//创建二叉树
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
BTNode* CopyBinTree(BTNode* pRoot);//二叉树的拷贝
//二叉树的销毁
void DestroyBinTree(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	DestroyBinTree(pRoot->_pleft);
	DestroyBinTree(pRoot->_pright);
	free(pRoot);
	pRoot = NULL;
}
//二叉树的遍历(递归)
//前序遍历
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c", pRoot->_data);
		PreOrder(pRoot->_pleft);
		PreOrder(pRoot->_pright);
	}
}
//中序遍历
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pleft);
		printf("%c", pRoot->_data);
		InOrder(pRoot->_pright);
	}
}
//后序遍历
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pleft);
		PostOrder(pRoot->_pright);
		printf("%c", pRoot->_data);
	}
}
//二叉树的遍历(非递归)
void PreOrderNor(BTNode* pRoot);//前序遍历
void InOrderNor(BTNode* pRoot);//中序遍历
void PostOrderNor(BTNode* pRoot);//后序遍历
void LevelOrder(BTNode* pRoot);//层序遍历

//二叉树的深度
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
//平衡树
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
//树中节点个数
int GetNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	//可有可无
	//if (NULL == pRoot->_pleft && NULL == pRoot->_pright)
	//	return 1;
	return GetNodeCount(pRoot->_pleft) + GetNodeCount(pRoot->_pright) + 1;
}
//叶子节点个数
int GetLeafNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (NULL == pRoot->_pleft && NULL == pRoot->_pright)
		return 1;

	return GetLeafNodeCount(pRoot->_pleft) + GetLeafNodeCount(pRoot->_pright);
}
//第K层节点个数
int GetKLevelNodeCount(BTNode* pRoot, int k)
{
	if (k > HeightBinTree(pRoot) || NULL == pRoot || k < 0)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(pRoot->_pleft, k - 1) + GetKLevelNodeCount(pRoot->_pright, k - 1);

}
//找到某个节点的双亲结点
BTNode* GetNodeParent(BTNode* pRoot, BTNode* child)
{
	if (NULL == pRoot)
		return NULL;
	if (pRoot == child)
		return NULL;
	if (pRoot->_pleft == child || pRoot->_pright == child)
		return pRoot;
	if (GetNodeParent(pRoot->_pleft, child))
		return GetNodeParent(pRoot->_pleft, child);
	GetNodeParent(pRoot->_pright, child);
}
//找到某个节点
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
//镜像树
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