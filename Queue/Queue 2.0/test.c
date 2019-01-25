#include"Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("Emtpy = %d\n", QueueEmpty(&q));
	printf("size = %d\n", QueueSize(&q));
	printf("Front->data = %d\n", QueueFront(&q));
	printf("Back->data = %d\n", QueueBack(&q));
	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	QueueDestory(&q);
	system("pause");
	return 0;
}