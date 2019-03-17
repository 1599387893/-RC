#include"BinTree.h"

int main()
{
	BTNode* pRoot = NULL;
	char array[] = "ABD###CE##F";
	pRoot = CreateBinTree(array, sizeof(array) / sizeof(array[0]));
	//printf("前序遍历："); PreOrder(pRoot);
	//printf("\n中序遍历：");InOrder(pRoot);
	printf("\n后序遍历：");PostOrder(pRoot);
	//printf("\n");
	//printf("二叉树的高度是=%d\n", HeightBinTree(pRoot));
	printf("二叉树是不是平衡树=%d\n", isBalanceTree(pRoot));
	printf("二叉树是不是平衡树=%d\n", isBalanceTree_p(pRoot));
	//printf("二叉树的结点数=%d\n", GetNodeCount(pRoot));
	//printf("二叉树的叶子结点数=%d\n", GetLeafNodeCount(pRoot));
	//printf("二叉树K层的叶子结点数=%d\n", GetKLevelNodeCount(pRoot, 2));
	//printf("二叉树K层的叶子结点数=%d\n", GetKLevelNodeCount(pRoot, 3));
	//printf("二叉树K层的叶子结点数=%d\n", GetKLevelNodeCount(pRoot, 4));
	//printf("%p\n", GetNode(pRoot, 'C'));
	//printf("%p\n", GetNodeParent(pRoot, GetNode(pRoot, 'E')));
	Mirror(pRoot);

	DestroyBinTree(pRoot);
	system("pause");
	return 0;
}