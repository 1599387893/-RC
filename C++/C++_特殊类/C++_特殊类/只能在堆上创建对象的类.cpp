//ֻ���ڶ��ϴ����������
class HeapOnly
{
public:
	static HeapOnly* createObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}

	//C++98����
	//1.ֻ��������ʵ�֣�
	//2.����Ϊ˽��
	HeapOnly(const HeapOnly&);

	//C++11����
	HeapOnly(const HeapOnly&) = delete;
};