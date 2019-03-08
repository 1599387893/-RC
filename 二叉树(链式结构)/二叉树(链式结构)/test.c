#include"BinTree.h"

int main()
{
	int level = 3;
	BTNode* bt = NULL;
	BTNode* bt2 = NULL;
	DateTypedef array[] = "ABD###CE##F";
	bt = CreateBinTree(array,strlen(array));
	bt2 = CopyBinTree(bt);
	printf("前序遍历：");
	PreOrder(bt);
	printf("	\n");
	PreOrder(bt2);
	printf("\n");
	
	printf("中序遍历：");
	InOrder(bt);
	printf("	\n");
	InOrder(bt2);
	printf("\n");

	
	printf("后序遍历：");
	PostOrder(bt);
	printf("	\n");
	PostOrder(bt2);
	printf("\n");

	printf("树的高度=%d\n", BinTreeHeight(bt));
	printf("该树是不是平衡树(1.0)=%d\n", isBalanced1(bt));
	printf("该树是不是平衡树(2.0)=%d\n", isBalanced2(bt,&level));
	printf("该树中的叶子结点个数=%d\n", GetLeafNodeCount(bt));
	printf("该树中的节点个数=%d\n", GetNodeCount(bt));
	printf("该树第三层的结点=%d\n", GetKLevelNodeCount1(bt, 3));
	printf("该树第三层的结点=%d\n", GetKLevelNodeCount2(bt, 3));

	printf("结点为'D'的双亲为：%c\n", GetNodeParent(bt, FindNode(bt, 'D'))->_data);
	printf("结点为'F'的双亲为：%c\n", GetNodeParent(bt, FindNode(bt, 'F'))->_data);
	//printf("结点为'G'的双亲为：%c\n", GetNodeParent(bt, FindNode(bt, 'G'))->_data);



	DestroyBinTree(&bt);
	system("pause");
	return 0;
}