#include"BinTree.h"

//创建二叉树
BTNode* CreateBT(BTDataTypde* array, int size, int* index)
{
	BTNode* pRoot = NULL;//或者BuyNewNode
	if (array[*index] == '#' || *index >= size)
		return NULL;
	pRoot->_data = array[*index];//BuyNewNode
	(*index)++;
	pRoot->_pleft = CreateBT(array, size, index);
	pRoot->_pright = CreateBT(array, size, index);
}
BTNode* CreateBinTree(BTDataTypde* array, int size)
{
	BTNode* pRoot = NULL;
	int index = 0;
	if (NULL == array)
		return NULL;
	pRoot = CreateBT(array, size, &index);
}
BTNode* CopyBinTree(BTNode* pRoot);//二叉树的拷贝
//二叉树的销毁
void Destroy(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	Destroy(pRoot->_pleft);
	Destroy(pRoot->_pright);
	free(pRoot);
	pRoot = NULL;
}
//二叉树的遍历(递归)
void PreOrder(BTNode* pRoot);//前序遍历
void InOrder(BTNode* pRoot);//中序遍历
void PostOrder(BTNode* pRoot);//后序遍历
//二叉树的遍历(非递归)
void PreOrderNor(BTNode* pRoot);//前序遍历
void InOrderNor(BTNode* pRoot);//中序遍历
void PostOrderNor(BTNode* pRoot);//后序遍历
void LevelOrder(BTNode* pRoot);//层序遍历
int HeightBinTree(BTNode* pRoot);//二叉树的深度
int isBalanceTree(BTNode* pRoot);//平衡树
int GetNodeCount(BTNode* pRoot);//树中节点个数
int GetLeafNodeCount(BTNode* pRoot);//叶子节点个数
int GetKLevelNodeCount(BTNode* pRoot, int k);//第K层节点个数
BTNode* GetNodeParent(BTNode* pRoot, BTNode* child);//找到某个节点的双亲结点
BTNode* GetNode(BTNode* pRoot, BTDataTypde data);//找到某个节点
int Mirror(BTNode* pRoot);//镜像树