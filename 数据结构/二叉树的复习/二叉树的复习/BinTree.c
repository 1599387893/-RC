#include"BinTree.h"

//����������
BTNode* CreateBT(BTDataTypde* array, int size, int* index)
{
	BTNode* pRoot = NULL;//����BuyNewNode
	if (array[*index] == '#' || *index >= size)
		return NULL;
	pRoot->_data = array[*index];//BuyNewNode
	(*index)++;
	pRoot->_pleft = CreateBT(array, size, index);
	pRoot->_pright = CreateBT(array, size, index);
}
BTNode* CreateBinTree(BTDataTypde* array, int size)
{
	BTNode* pRoot = NULL;
	int index = 0;
	if (NULL == array)
		return NULL;
	pRoot = CreateBT(array, size, &index);
}
BTNode* CopyBinTree(BTNode* pRoot);//�������Ŀ���
//������������
void Destroy(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	Destroy(pRoot->_pleft);
	Destroy(pRoot->_pright);
	free(pRoot);
	pRoot = NULL;
}
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
int GetKLevelNodeCount(BTNode* pRoot, int k);//��K��ڵ����
BTNode* GetNodeParent(BTNode* pRoot, BTNode* child);//�ҵ�ĳ���ڵ��˫�׽��
BTNode* GetNode(BTNode* pRoot, BTDataTypde data);//�ҵ�ĳ���ڵ�
int Mirror(BTNode* pRoot);//������