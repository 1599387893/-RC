#include"Queue(stack).h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueRear(&q));
	printf("%d\n\n\n", QueueSize(&q));

	QueuePop(&q);
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueRear(&q));
	printf("%d\n\n\n", QueueSize(&q));
	QueueDestroy(&q);
	system("pause");
	return 0;
}