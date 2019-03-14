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

BTNode* CreateBinTree(BTDataTypde* array, int size);//����������
BTNode* CopyBinTree(BTNode* pRoot);//�������Ŀ���
void Destroy(BTNode* pRoot);//������������
//�������ı���(�ݹ�)
void PreOrder(BTNode* pRoot);//ǰ�����
void InOrder(BTNode* pRoot);//�������
void PostOrder(BTNode* pRoot);//�������
//�������ı���(�ǵݹ�)
void PreOrderNor(BTNode* pRoot);//ǰ�����
void InOrderNor(BTNode* pRoot);//�������
void PostOrderNor(BTNode* pRoot);//�������
void LevelOrder(BTNode* pRoot);//�������
int HeightBinTree(BTNode* pRoot);//�����������
int isBalanceTree(BTNode* pRoot);//ƽ����
int GetNodeCount(BTNode* pRoot);//���нڵ����
int GetLeafNodeCount(BTNode* pRoot);//Ҷ�ӽڵ����
int GetKLevelNodeCount(BTNode* pRoot,int k);//��K��ڵ����
BTNode* GetNodeParent(BTNode* pRoot,BTNode* child);//�ҵ�ĳ���ڵ��˫�׽��
BTNode* GetNode(BTNode* pRoot,BTDataTypde data);//�ҵ�ĳ���ڵ�
int Mirror(BTNode* pRoot);//������