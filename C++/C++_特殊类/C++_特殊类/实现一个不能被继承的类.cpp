//���ܱ��̳е���
#include<iostream>
using namespace std;

//C++98������
//C++98�й��캯��˽�л����������е���������Ĺ��캯�����������޷��̳�
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit(){};
};

//C++11������
//C++11ʹ���µĹؼ���final��ֹ�̳�
class NonInherit
{};