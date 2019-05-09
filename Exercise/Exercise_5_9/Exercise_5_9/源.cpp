////����ģʽ
////����ģʽ
//#include<iostream>
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* Getinstance()
//	{
//		return &m_instance;
//	}
//private:
//	Singleton(){};
//	Singleton(const Singleton& s) = delete;
//	Singleton& operator=(const Singleton& s) = delete;
//
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance;
//
//
//#include<mutex>
//#include<thread>
////����ģʽ
//class Singleton1
//{
//public:
//	static Singleton1* Getinstance()
//	{
//		if (nullptr == m_instance)
//		{
//			m_mtx.lock();
//			if (nullptr == m_instance)
//			{
//				m_instance = new Singleton1;
//			}
//			m_mtx.unlock();
//		}
//		return m_instance;
//	}
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (Singleton1::m_instance)
//				delete Singleton1::m_instance;
//		}
//	};
//	static CGarbo Garbo;
//private:
//	Singleton1(){};
//	Singleton1(const Singleton1& s) = delete;
//	Singleton1& operator=(const Singleton& s) = delete;
//
//	static Singleton1* m_instance;
//	static mutex m_mtx;
//};
//Singleton1* Singleton1::m_instance = nullptr;
//mutex Singleton1::m_mtx;
//Singleton1::CGarbo Garbo;


#include<iostream>
using namespace std;

struct ServerInfo
{
	char _ip[32];
	int _port;
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
		ofs.writs((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	oid WriteText(const ServerInfo& info)
	{
		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��Ȱ�����itoa��д
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
			// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
			// C ���Ե��ȶ��ַ�������atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile;
};
int main()
{
	ConfigManager cfgmgr;

	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// �����ƶ�д
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// �ı���д
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;

	return 0;
}