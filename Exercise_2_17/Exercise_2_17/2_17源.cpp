#include<iostream>
using namespace std;

class Integer
{
private:
	int val;
public:
	Integer(){ val = 0; }								
	Integer(int v = 0){ val = v; }					
	void Show(){ cout << val << endl; }				
};

int main()
{
	Integer a(2), b(0);										
	a.Show();													
	b.Show();											
	system("pause");
	return 0;           					
}