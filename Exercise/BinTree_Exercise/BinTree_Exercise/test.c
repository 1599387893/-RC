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
////�������
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
//	//����һ����
//	pRoot = CreateBinTree(array, size);
//	//�������
//	InOrder(pRoot);
//	system("pause");
//	return 0;
//}
#include"BinTree.h"

int main()
{
	char array[100];
	BTNode* pRoot = NULL;
	printf("��������ǰ�������");
	scanf("%s", array);
	pRoot = CreateBinTree(array);
	InOrder(pRoot);
	printf("\n");
	printf("���ĸ߶ȣ�%d\n", BinTreeHeight(pRoot));
	printf("�����Ƿ�Ϊƽ������%d\n", isBalanced(pRoot));
	printf("�����ܹ��ڵ�����%d\n", GetNodeCount(pRoot));
	printf("����Ҷ�ӽڵ������%d\n", GetLeafNodeCount(pRoot));
	printf("�������������%d\n", GetKLevelNodeCount(pRoot, 3));
	DestroyBinTree(&pRoot);
	system("pause");
	return 0;
}