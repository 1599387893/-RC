//只能在堆上创建对象的类
class HeapOnly
{
public:
	static HeapOnly* createObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}

	//C++98方法
	//1.只声明，不实现；
	//2.声明为私有
	HeapOnly(const HeapOnly&);

	//C++11方法
	HeapOnly(const HeapOnly&) = delete;
};