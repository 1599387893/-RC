#include"BinTree.h"

int main()
{
	int level = 3;
	BTNode* bt = NULL;
	BTNode* bt2 = NULL;
	DateTypedef array[] = "ABD###CE##F";
	bt = CreateBinTree(array,strlen(array));
	bt2 = CopyBinTree(bt);
	printf("ǰ�������");
	PreOrder(bt);
	printf("	\n");
	PreOrder(bt2);
	printf("\n");
	
	printf("���������");
	InOrder(bt);
	printf("	\n");
	InOrder(bt2);
	printf("\n");

	
	printf("���������");
	PostOrder(bt);
	printf("	\n");
	PostOrder(bt2);
	printf("\n");

	printf("���ĸ߶�=%d\n", BinTreeHeight(bt));
	printf("�����ǲ���ƽ����(1.0)=%d\n", isBalanced1(bt));
	printf("�����ǲ���ƽ����(2.0)=%d\n", isBalanced2(bt,&level));
	printf("�����е�Ҷ�ӽ�����=%d\n", GetLeafNodeCount(bt));
	printf("�����еĽڵ����=%d\n", GetNodeCount(bt));
	printf("����������Ľ��=%d\n", GetKLevelNodeCount1(bt, 3));
	printf("����������Ľ��=%d\n", GetKLevelNodeCount2(bt, 3));

	printf("���Ϊ'D'��˫��Ϊ��%c\n", GetNodeParent(bt, FindNode(bt, 'D'))->_data);
	printf("���Ϊ'F'��˫��Ϊ��%c\n", GetNodeParent(bt, FindNode(bt, 'F'))->_data);
	//printf("���Ϊ'G'��˫��Ϊ��%c\n", GetNodeParent(bt, FindNode(bt, 'G'))->_data);



	DestroyBinTree(&bt);
	system("pause");
	return 0;
}