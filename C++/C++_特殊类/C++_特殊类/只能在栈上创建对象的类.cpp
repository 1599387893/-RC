//只能在栈上创建对象的类
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly(){};

};
//只能在栈上创建对象，即不能在堆上创建，因此只要将new的功能屏蔽掉即可，即屏蔽掉operator new和定位new表达式，
class StackOnly
{
private:
	void* operator new(size_t size);
	void* operator new[](size_t size,size_t num);
	void operator delete(void* p);
	void operator delete[](void* p, size_t num);
};