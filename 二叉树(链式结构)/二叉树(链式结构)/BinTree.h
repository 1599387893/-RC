#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char DateTypedef;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	DateTypedef _data;
}BTNode;

//����
void CreateBinTree(BTNode* pRoot,DateTypedef* array);
void DestroyBinTree(BTNode* pRoot);
//���ֱ�������
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);
//���ֱ�������(�ǵݹ�)
void PreOrderNor(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);

int BinTreeHeight(BTNode* pRoot);//���ĸ߶�
int isBalanceTree(BTNode* pRoot);//ƽ����

