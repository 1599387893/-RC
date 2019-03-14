#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef char BTDataTypde;
typedef struct BTNode
{
	BTDataTypde _data;
	struct BTNode* _pleft;
	struct BTNode* _pright;
}BTNode;

BTNode* CreateBinTree(BTDataTypde* array, int size);//创建二叉树
BTNode* CopyBinTree(BTNode* pRoot);//二叉树的拷贝
void Destroy(BTNode* pRoot);//二叉树的销毁
//二叉树的遍历(递归)
void PreOrder(BTNode* pRoot);//前序遍历
void InOrder(BTNode* pRoot);//中序遍历
void PostOrder(BTNode* pRoot);//后序遍历
//二叉树的遍历(非递归)
void PreOrderNor(BTNode* pRoot);//前序遍历
void InOrderNor(BTNode* pRoot);//中序遍历
void PostOrderNor(BTNode* pRoot);//后序遍历
void LevelOrder(BTNode* pRoot);//层序遍历
int HeightBinTree(BTNode* pRoot);//二叉树的深度
int isBalanceTree(BTNode* pRoot);//平衡树
int GetNodeCount(BTNode* pRoot);//树中节点个数
int GetLeafNodeCount(BTNode* pRoot);//叶子节点个数
int GetKLevelNodeCount(BTNode* pRoot,int k);//第K层节点个数
BTNode* GetNodeParent(BTNode* pRoot,BTNode* child);//找到某个节点的双亲结点
BTNode* GetNode(BTNode* pRoot,BTDataTypde data);//找到某个节点
int Mirror(BTNode* pRoot);//镜像树