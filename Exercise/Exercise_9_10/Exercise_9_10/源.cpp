//文件流
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct ServerInfo
{
	char _ip[32];	//ip
	int _port;		//端口
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "RCServer.config")
		:_configfile(configfile)
	{}

	void writeBit(const ServerInfo& info)
	{
		ofstream ofs(_configfile,ifstream::in|ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
		ifs.read((char*)&info,sizeof(ServerInfo));
		ifs.close();
	}

	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}

	void ReadText(ServerInfo& info)
	{
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
	ConfigManager cfgMgr;

	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip,"127.0.0.1");
	wtinfo._port = 80;

	//二进制读写
	cfgMgr.writeBit(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;

	//文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;

	system("pause");
	return 0;
}