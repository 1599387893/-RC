#include<iostream>
using namespace std;

//STL�е�������ȡ

//������������
struct _true_type{  };
//�����Զ�������
struct _false_type{};

template<class T>
struct _type_traits
{
	typedef _false_type is_POD_type;
};

//�����е��������ͽ����ػ�
template<>
struct _type_traits < char >
{
	typedef _true_type is_POD_type;
};
template<>
struct _type_traits < short >
{
	typedef _true_type is_POD_type;
};
template<>
struct _type_traits < int>
{
	typedef _true_type is_POD_type;
};
template<>
struct _type_traits < double >
{
	typedef _true_type is_POD_type;
};

template<class T>
void _copy(T* dst, T* src, size_t n, _true_type)
{
	memcpy(dst, src, n*sizeof(T));
}
template<class T>
void _copy(T* dst, T* src, size_t n, _false_type)
{
	for (size_t i = 0; i < n; ++i)
		dst[i] = src[i];
}

template<class T>
void Copy(T* dst, T* src, size_t n)
{
	_copy(dst, src, n, _type_traits<T>::is_POD_type());
}

int main()
{
	
	return 0;
}