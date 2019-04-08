#include"Vector.h"

template <class T>
void vector<T>::PushBack(const T& data)
{
	//CheckCapacity();
	_pData[_size] = data;
	_size++;
}

template <class T>
void vector<T>::PopBack()
{
	if (_size != 0)
		_size--;
}

template <class T>
size_t vector<T>::GetSize()const 
{
	return _size;
}

template <class T>
size_t vector<T>::GetCapacity()const 
{
	return _capacity;
}

template <class T>
T& vector<T>::operator[](size_t pos)const {};

template <class T>
bool vector<T>::Empty()const {};