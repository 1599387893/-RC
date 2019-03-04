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

//����
void CreateBinTree(BTNode* pRoot,DateTypedef* array,int size);
//���ֱ�������
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);

