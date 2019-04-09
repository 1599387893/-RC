#include"SeqList.h"

template <class T>
SeqList<T>::~SeqList()
{
	if (_pData)
		delete[] _pData;
	_capacity = 0;
	_size = 0;
}
template <class T>
void SeqList<T>::CheckCapacity()
{
	if (_capacity == _size)
	{
		int newcapacity = 2 * _capacity;
		T* newData = new T[newcapacity];
		memcpy(newData, _pData, sizeof(T)*newcapacity);
		delete[] _pData;
		_pData = newData;
		_capacity = newcapacity;
	}
}
 

template <class T>
void SeqList<T>::PushBack(const T& data)
{
	CheckCapacity();
	_pData[_size++] = data;
}

template <class T>
void SeqList<T>::PopBack()
{
	if (_size)
		--_size;
}
template <class T>
size_t SeqList<T>::GetSize()
{
	return _size;
}
template <class T>
size_t SeqList<T>::GetCapacity()
{
	return _capacity;
}
template <class T>
bool SeqList<T>::Empty()
{
	if (_size)
		return false;
	return true;
}
template <class T>
T& SeqList<T>::operator[](int pos)
{
	if (pos < _size && pos > 0)
		return _pData[pos];
}

int main()
{
	SeqList<int> arr;
	cout << arr.Empty() << endl;
	cout << arr.GetCapacity() << endl;
	cout << arr.GetSize() << endl;
	cout << &arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	arr.PushBack(0);
	arr.PushBack(1);
	arr.PushBack(2);
	arr.PushBack(3);
	arr.PushBack(4);
	cout << arr.Empty() << endl;
	cout << arr.GetCapacity() << endl;
	cout << arr.GetSize() << endl;
	cout << &arr[0] << endl;
	cout << arr[0] << endl;
	arr.PopBack();
	cout << arr.GetSize() << endl;

	return 0;
}

