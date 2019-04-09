#include"Vector.h"

template <class T>
Svector<T>::~Svector()
{
	if (_pData)
		delete[] _pData;
	_capacity = 0;
	_size = 0;
}

template<class T>
void Svector<T>::CheckCapacity()
{
	if (_capacity == _size)
	{
		int newcapacity = 2 * _capacity;
		T* array = new T[newcapacity];
		memcpy(array, _pData, sizeof(T)*newcapacity);
		delete[] _pData;
		_pData = array;
		_capacity = newcapacity;
	}
}
template <class T>
void Svector<T>::PushBack(const T& data)
{
	CheckCapacity();
	_pData[_size] = data;
	_size++;
}

template <class T>
void Svector<T>::PopBack()
{
	if (_size != 0)
		_size--;
}

template <class T>
size_t Svector<T>::GetSize() 
{
	return _size;
}

template <class T>
size_t Svector<T>::GetCapacity() 
{
	return _capacity;
}

template <class T>
T& Svector<T>::operator[](size_t pos)
{
	if (pos < _size && pos > 0)
		return _pData[pos];
}

template <class T>
bool Svector<T>::Empty()
{
	if (_size > 0)
		return false;
	return true;
}