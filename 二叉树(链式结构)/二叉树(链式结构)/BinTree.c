#include"BinTree.h"

void CreateBinTree(BTNode* pRoot, DateTypedef* array, int size)
{
	assert(pRoot);
	while (size--)
	{
		
	}
}
//三种遍历方法
void PreOrder(BTNode* pRoot)
{
	assert(pRoot);
	if (pRoot)
	{
		pRoot->_data;
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
void InOrder(BTNode* pRoot)
{
	assert(pRoot);
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		pRoot->_data;
		InOrder(pRoot->_pRight);
	}
}
void PostOrder(BTNode* pRoot)
{
	assert(pRoot);
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		pRoot->_data;
	}
}











//OJ 前序遍历
//1 给一个辅助空间(树中节点个数的大小---->求二叉树节点个数GetNodeCount函数)  
//2 遍历树 


//OJ 中序遍历

//OJ 后序遍历