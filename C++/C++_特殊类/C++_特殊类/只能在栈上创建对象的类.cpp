//ֻ����ջ�ϴ����������
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
//ֻ����ջ�ϴ������󣬼������ڶ��ϴ��������ֻҪ��new�Ĺ������ε����ɣ������ε�operator new�Ͷ�λnew���ʽ��
class StackOnly
{
private:
	void* operator new(size_t size);
	void* operator new[](size_t size,size_t num);
	void operator delete(void* p);
	void operator delete[](void* p, size_t num);
};