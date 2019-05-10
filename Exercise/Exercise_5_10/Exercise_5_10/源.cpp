#include<iostream>
using namespace std;

void Test()
{
	int* a = new int(5);
	delete[] a;
	int* arr = new int[10];
	delete arr;
}

int main()
{
	Test();

	return 0;
}