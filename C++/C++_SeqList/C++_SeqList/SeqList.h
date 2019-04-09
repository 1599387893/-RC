#include<iostream>
using namespace std;

template <class T>
class SeqList
{
public:
	SeqList(int capacity = 10)
		:_pData(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}
	~SeqList();
	void CheckCapacity();
	void PushBack(const T& data);

	void PopBack();
	T& operator[](int pos);
	size_t GetSize();
	size_t GetCapacity();
	bool Empty();
private:
	T* _pData;
	size_t _capacity;
	size_t _size;
};
