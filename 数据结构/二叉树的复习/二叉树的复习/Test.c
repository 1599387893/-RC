#include"BinTree.h"

int main()
{
	BTNode* pRoot = NULL;
	char array[] = "ABD###CE##F";
	pRoot = CreateBinTree(array, sizeof(array) / sizeof(array[0]));
	//printf("ǰ�������"); PreOrder(pRoot);
	//printf("\n���������");InOrder(pRoot);
	printf("\n���������");PostOrder(pRoot);
	//printf("\n");
	//printf("�������ĸ߶���=%d\n", HeightBinTree(pRoot));
	printf("�������ǲ���ƽ����=%d\n", isBalanceTree(pRoot));
	printf("�������ǲ���ƽ����=%d\n", isBalanceTree_p(pRoot));
	//printf("�������Ľ����=%d\n", GetNodeCount(pRoot));
	//printf("��������Ҷ�ӽ����=%d\n", GetLeafNodeCount(pRoot));
	//printf("������K���Ҷ�ӽ����=%d\n", GetKLevelNodeCount(pRoot, 2));
	//printf("������K���Ҷ�ӽ����=%d\n", GetKLevelNodeCount(pRoot, 3));
	//printf("������K���Ҷ�ӽ����=%d\n", GetKLevelNodeCount(pRoot, 4));
	//printf("%p\n", GetNode(pRoot, 'C'));
	//printf("%p\n", GetNodeParent(pRoot, GetNode(pRoot, 'E')));
	Mirror(pRoot);

	DestroyBinTree(pRoot);
	system("pause");
	return 0;
}