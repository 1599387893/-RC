#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>

typedef char DataType;
typedef struct BTNode
{
	DataType _data;
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
}BTNode;


BTNode* CreateBinTree(DataType* array);//创建树
BTNode* CopyBinTree(BTNode* pRoot);//拷贝一棵树
void PosOrder(BTNode* pRoot);//前序遍历(递归)
void InOrder(BTNode* pRoot);//中序遍历(递归)
void PostOrder(BTNode* pRoot);//后序遍历(递归)
void LevelOrder(BTNode* pRoot);//层序遍历
void PosOrderNor(BTNode* pRoot);//前序遍历
void InOrderNor(BTNode* pRoot);//中序遍历
void PostOrderNor(BTNode* pRoot);//后序遍历
void DestroyBinTree(BTNode** pRoot);//销毁树
int BinTreeHeight(BTNode* pRoot);//二叉树的高度
int isBalanced(BTNode* pRoot);//是不是平衡树
int GetKLevelNodeCount(BTNode* pRoot, int k);//第K层节点个数
int GetLeafNodeCount(BTNode* pRoot);//叶子节点个数
int GetNodeCount(BTNode* pRoot);//树中所有结点的个数
BTNode* FindNode(BTNode* pRoot, DataType data);//找到值为data的结点
BTNode* GetNodeParent(BTNode* pRoot,BTNode* child);//找到某一结点的双亲结点
void Mirror(BTNode* pRoot);//镜像树