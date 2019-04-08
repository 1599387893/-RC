#include<iostream>
using namespace std;

template<class T>
class vector
{
public:
	vector(size_t capacity = 10)
		:_pData(new T[10]),
		_capacity(capacity);
		_size(0)
	{}
	~vector()
	{

	}
	vector(const vector& v)
	{

	}
	vector& operator=(const vector& v)
	{

	}
	void PushBack(const T& data){};
	void PopBack(){};
	size_t GetSize(){}const;
	size_t GetCapacity(){}const;
	T& operator[](size_t pos){}const;
	bool Empty(){}const;
private:
	T* _pData;
	size_t _capacity;
	size_t _size;
};