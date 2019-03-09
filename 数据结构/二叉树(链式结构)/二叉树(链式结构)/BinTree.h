#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef char DateTypedef;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	DateTypedef _data;
}BTNode;


BTNode* CreateBinTree(DateTypedef* array, int size);//������
BTNode* CopyBinTree(BTNode* pRoot);//����һ����
void DestroyBinTree(BTNode** pRoot);
//���ֱ�������
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);

void LevelOrder(BTNode* pRoot);//�������
//���ֱ�������(�ǵݹ�)
void PreOrderNor(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);
int BinTreeHeight(BTNode* pRoot);//���ĸ߶�
int isBalanced1(BTNode* pRoot);				//ƽ����1.0
int isBalanced2(BTNode* pRoot, int* height);//ƽ����2.0
int GetLeafNodeCount(BTNode* pRoot);//����Ҷ�ӽڵ����
int GetNodeCount(BTNode* pRoot);//���нڵ����
int GetKLevelNodeCount1(BTNode* pRoot, int k);//���е�K�������1.0
int GetKLevelNodeCount2(BTNode* pRoot, int k);//���е�K�������2.0
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);//��ȡһ������˫��
BTNode* FindNode(BTNode* pRoot, DateTypedef data);//�ҵ�����ֵΪdata�Ľ��
void Mirror(BTNode*pRoot);//��һ�������о���ת