#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//typedef struct BinTreeNode
//{
//	char _data;
//	struct BinTreeNode* _left;
//	struct BinTreeNode* _right;
//}BTNode;
//BTNode* BuyNewNode(char data)
//{
//	BTNode* New = (BTNode*)malloc(sizeof(BTNode));
//	if (NULL == New)
//		return NULL;
//	New->_data = data;
//	New->_left = NULL;
//	New->_right = NULL;
//	return  New;
//}
//
//BTNode* CreateBinTree_2(char* array, int size, int* index)
//{
//	BTNode* pRoot = NULL;
//	if (*index < size && array[*index] != '#')
//	{
//		pRoot = BuyNewNode(array[*index]);
//		(*index)++;
//
//		pRoot->_left = CreateBinTree_2(array, size, index);
//
//		(*index)++;
//		pRoot->_right = CreateBinTree_2(array, size, index);
//		//return NULL;
//	}
//	return pRoot;
//}
//BTNode* CreateBinTree(char* array, int size)
//{
//	int index = 0;
//	if (array == NULL)
//		return NULL;
//	return CreateBinTree_2(array, size, &index);
//}
//
////中序遍历
//void InOrder(BTNode* pRoot)
//{
//	if (pRoot)
//	{
//		InOrder(pRoot->_left);
//		printf("%c ", pRoot->_data);
//		InOrder(pRoot->_left);
//	}
//
//}
//int main()
//{
//	char array[100];
//	int size = 0;
//	BTNode* pRoot = NULL;
//	scanf("%s", array);
//	size = strlen(array);
//	//创建一棵树
//	pRoot = CreateBinTree(array, size);
//	//中序遍历
//	InOrder(pRoot);
//	system("pause");
//	return 0;
//}
#include"BinTree.h"

int main()
{
	char array[100];
	BTNode* pRoot = NULL;
	printf("输入树的前序遍历：");
	scanf("%s", array);
	pRoot = CreateBinTree(array);
	InOrder(pRoot);
	printf("\n");
	printf("树的高度：%d\n", BinTreeHeight(pRoot));
	printf("该树是否为平衡树：%d\n", isBalanced(pRoot));
	printf("该树总共节点数：%d\n", GetNodeCount(pRoot));
	printf("该树叶子节点个数：%d\n", GetLeafNodeCount(pRoot));
	printf("第三层结点个数：%d\n", GetKLevelNodeCount(pRoot, 3));
	DestroyBinTree(&pRoot);
	system("pause");
	return 0;
}