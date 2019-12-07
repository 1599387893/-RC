#include<iostream>
using namespace std;

int main()
{
	//static_case
	int a = 1;
	double b = static_cast<double>(a);
	void* pv = nullptr;
	int* aptr = &a;
	//void* c = dynamic_cast<void*>(aptr);
	int* aptr = &a;
	double* dptr = reinterpret_cast<double*>(aptr);
	double* d = reinterpret_cast<double*>(a);
	//dynamic_case
	//const_case
	//reinterpret_case

	const char c = 'a';
	char* c1 = const_cast<char*> (&c);

	return 0;
}