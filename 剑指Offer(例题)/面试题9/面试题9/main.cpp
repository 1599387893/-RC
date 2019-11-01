#include"QtoS.hpp"
#include"StoQ.hpp"

void TestQueue()
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
}

void TestStack()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();

}
int main()
{
	//TestQueue();
	TestStack();

	system("pause");
	return 0;
}