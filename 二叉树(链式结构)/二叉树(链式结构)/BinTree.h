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


BTNode* CreateBinTree(DateTypedef* array, int size);//创建树
BTNode* CopyBinTree(BTNode* pRoot);//拷贝一棵树
void DestroyBinTree(BTNode** pRoot);
//三种遍历方法
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);

void LevelOrder(BTNode* pRoot);//层序遍历
//三种遍历方法(非递归)
void PreOrderNor(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);
int BinTreeHeight(BTNode* pRoot);//树的高度
int isBalanced1(BTNode* pRoot);				//平衡树1.0
int isBalanced2(BTNode* pRoot, int* height);//平衡树2.0
int GetLeafNodeCount(BTNode* pRoot);//树中叶子节点个数
int GetNodeCount(BTNode* pRoot);//树中节点个数
int GetKLevelNodeCount1(BTNode* pRoot, int k);//树中第K层结点个数1.0
int GetKLevelNodeCount2(BTNode* pRoot, int k);//树中第K层结点个数2.0
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);//获取一个结点的双亲
BTNode* FindNode(BTNode* pRoot, DateTypedef data);//找到树中值为data的结点
void Mirror(BTNode*pRoot);//将一颗树进行镜像翻转