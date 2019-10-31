#include"QtoS.hpp"
#include"StoQ.hpp"

int main()
{
	Queue<int> q;
	q.Push(1);

	q.Push(2);

	q.Push(3);

	q.Push(4);
	cout << q.Pop() << endl;
	cout << q.Pop() << endl;
	cout << q.Pop() << endl;
	cout << q.Pop() << endl;
	

	system("pause");
	return 0;
}