#include<iostream>
using namespace std;

template<class T>
class Svector
{
public:
	Svector(size_t capacity = 10)
		:_pData(new T[10]),
		_capacity(capacity),
		_size(0){}
	~Svector();
	//Svector(const Svector& v)
	//{

	//}
	//Svector& operator=(const Svector& v)
	//{

	//}
	void CheckCapacity();
	void PushBack(const T& data);
	void PopBack();
	size_t GetSize();
	size_t GetCapacity();
	T& operator[](size_t pos);
	bool Empty();
private:
	T* _pData;
	size_t _capacity;
	size_t _size;
};