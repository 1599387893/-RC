//auto_ptr
template<class T>
class auto_ptr
{
public:
	auto_ptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	auto_ptr(const auto_ptr<T>& p)
		:_ptr(p._ptr)
	{
		p._ptr = nullptr;
	}
	auto_ptr<T>& operator=(const auto_ptr<T>& p)
	{
		if (this != &p)
		{
			if (_ptr)
				delete _ptr;
			_ptr = p._ptr;
			p._ptr = nullptr;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~auto_ptr()
	{
		if (_ptr)
			delete _ptr;
	}
private:
	T* _ptr;
};
//unique_ptr
template<class T>
class unique_ptr
{
public:
	unique_ptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~unique_prt()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator&()
	{
		return _ptr;
	}
private:
	unique_ptr(const unique_ptr<T>&) = delete;
	unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	T* _ptr;
};
//shared_ptr
template<class T>
class shared_ptr
{
public:
	shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pcount(nullptr)
	{
		if (_ptr)
			_pcount = new int(1);
	}
	shared_ptr(cosnt shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _pcount(sp._pcount)
	{
		++(*)_pcount;
	}
	shared_ptr<T>& operator=(const shared_ptr<T>& sp)
	{
		if (this != &sp)
		{
			if (--(*_pcount) == 0)
			{
				delete _ptr;
				delete _pcount;
			}
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			++(*_pcount);
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;;
	}
	T* operator->()
	{
		return _ptr;
	}
	~shared_ptr()
	{
		if (--(*_pcount) == 0)
		{
			delete _ptr;
			delete _pcount;
		}
	}
private:
	T* _ptr;
	int* _pcount;
};
//weak_ptr