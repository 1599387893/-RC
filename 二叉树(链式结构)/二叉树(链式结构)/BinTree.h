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

//创建
void CreateBinTree(BTNode* pRoot,DateTypedef* array);
void DestroyBinTree(BTNode* pRoot);
//三种遍历方法
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);
//三种遍历方法(非递归)
void PreOrderNor(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);

int BinTreeHeight(BTNode* pRoot);//树的高度
int isBalanceTree(BTNode* pRoot);//平衡树

