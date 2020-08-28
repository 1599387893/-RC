#include <iostream>
using namespace std;

class regionTreeNode
{
public:
	int left; //左端点值
	int right; //右端点值
	int cover; //被覆盖的次数
	regionTreeNode* leftChild;  //指向左孩子的指针
	regionTreeNode* rightChild; //指向右孩子的指针

	regionTreeNode() : left(0), right(0), cover(0), leftChild(nullptr), rightChild(nullptr){} //构造函数
};



