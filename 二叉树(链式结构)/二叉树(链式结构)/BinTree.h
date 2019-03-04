#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef char DateTypedef;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	DateTypedef _data;
}BTNode;

//创建
void CreateBinTree(BTNode* pRoot,DateTypedef* array,int size);
//三种遍历方法
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);

