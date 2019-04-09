#include"Vector.h"


int main()
{
	
	Svector<int> arr;
	cout << arr.Empty() << endl;
	cout << arr.GetCapacity() << endl;
	cout << arr.GetSize() << endl;
	arr.PushBack(1);
	cout << arr[0] << endl;
	arr.PushBack(2);
	arr.PushBack(3);
	cout << arr[0] << endl;
	arr.PushBack(4);
	arr.PushBack(5);
	arr.PushBack(6);
	cout << arr.Empty() << endl;
	cout << arr.GetCapacity() << endl;
	cout << arr.GetSize() << endl;
	arr.PopBack();
	cout << arr[0] << endl;

	return 0;
}