//不能被继承的类
#include<iostream>
using namespace std;

//C++98方法：
//C++98中构造函数私有化，派生类中调不到基类的构造函数，这样就无法继承
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

//C++11方法：
//C++11使用新的关键字final禁止继承
class NonInherit
{};