#include"BinTree.h"

void CreateBinTree(BTNode* pRoot, DateTypedef* array, int size)
{
	assert(pRoot);
	while (size--)
	{
		
	}
}
//���ֱ�������
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











//OJ ǰ�����
//1 ��һ�������ռ�(���нڵ�����Ĵ�С---->��������ڵ����GetNodeCount����)  
//2 ������ 


//OJ �������

//OJ �������