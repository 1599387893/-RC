#include <iostream>
using namespace std;

class regionTreeNode
{
public:
	int left; //��˵�ֵ
	int right; //�Ҷ˵�ֵ
	int cover; //�����ǵĴ���
	regionTreeNode* leftChild;  //ָ�����ӵ�ָ��
	regionTreeNode* rightChild; //ָ���Һ��ӵ�ָ��

	regionTreeNode() : left(0), right(0), cover(0), leftChild(nullptr), rightChild(nullptr){} //���캯��
};



