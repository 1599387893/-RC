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


BTNode* CreateBinTree(DataType* array);//������
BTNode* CopyBinTree(BTNode* pRoot);//����һ����
void PosOrder(BTNode* pRoot);//ǰ�����(�ݹ�)
void InOrder(BTNode* pRoot);//�������(�ݹ�)
void PostOrder(BTNode* pRoot);//�������(�ݹ�)
void LevelOrder(BTNode* pRoot);//�������
void PosOrderNor(BTNode* pRoot);//ǰ�����
void InOrderNor(BTNode* pRoot);//�������
void PostOrderNor(BTNode* pRoot);//�������
void DestroyBinTree(BTNode** pRoot);//������
int BinTreeHeight(BTNode* pRoot);//�������ĸ߶�
int isBalanced(BTNode* pRoot);//�ǲ���ƽ����
int GetKLevelNodeCount(BTNode* pRoot, int k);//��K��ڵ����
int GetLeafNodeCount(BTNode* pRoot);//Ҷ�ӽڵ����
int GetNodeCount(BTNode* pRoot);//�������н��ĸ���
BTNode* FindNode(BTNode* pRoot, DataType data);//�ҵ�ֵΪdata�Ľ��
BTNode* GetNodeParent(BTNode* pRoot,BTNode* child);//�ҵ�ĳһ����˫�׽��
void Mirror(BTNode* pRoot);//������