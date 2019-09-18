#include<iostream>
#include<vector>
using namespace std;

//异常的抛出和捕获
#if 0
double Division(int a,int b)
{
	if (b == 0)
		throw "Division by zero condition";
	else
		return ((double)a / (double)b);
}
void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main()
{
	try{
		Func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	catch (...){
		cout << "unkown execption" << endl;
	}
	system("pause");
	return 0;
}

//异常的重新抛出
double Division(int a, int b)
{
	if (b == 0)
		throw "Division by zero condition";
	if (b == -1)
		throw 1;
	else
		return ((double)a / (double)b);
}
void Func()
{
	int* array = new int[10];
	try{
		int len, time;	
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...){
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	cout << "delete[]" << array << endl;
	delete[] array;
}

int main()
{
	try{
		Func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	catch (const int a){
		cout << a << endl;
	}
	
	system("pause");
	return 0;
}
#endif


#if 0
//服务器开发中常用的异常继承体系
class Execption
{
protected:
	string _errmsg;
	int _id;

};
class SqlExecption:public Execption
{};

class CacheExecption:public Execption
{};

class HttpExecption :public Execption
{};

int main()
{
	try{

	}
	catch(const Execption& e){
	}
	catch (...){
		cout << "unkown Execption" << endl;
	}
	return 0;
}
#endif

int main()
{
	try{
		vector<int> v(10, 5);
		v.reserve(1000000000000);
		v.at(10) = 100;
	}
	catch(const exception& e){
		cout << e.what() << endl;
	}
	catch (...){
		cout << "unkown exception" << endl;
	}
	system("pause");
	return 0;
}