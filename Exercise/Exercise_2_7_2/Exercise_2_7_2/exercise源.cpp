#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>

//int main()
//{
//	int n = 0;
//	int line = 0;
//	int i = 0;
//	int space = 0;
//	printf("������Ҫ��ӡ���������������");
//	scanf("%d", &n);
//
//	//�ϰ벿��
//	//�ȴ�ӡ�ո񣬺��ӡ*
//	for (line = 1; line <= n; line++)
//	{
//		//�ո�
//		for (space = n - line; space > 0; space--)
//		{
//			printf(" ");
//			Sleep(50);
//		}
//		//*
//		for (i = 2 * line - 1; i > 0; i--)
//		{
//			printf("*");
//			Sleep(50);
//		}	
//		printf("\n");
//	}
//	//�°벿��
//	for (line = 1; line <= n-1; line++)
//	{
//		//�ո�
//		for (space = line ; space > 0; space--)
//		{
//			printf(" ");
//			Sleep(50);
//		}
//		//*
//		for (i = 2 * (n - line) - 1; i > 0; i--)
//		{
//			printf("*");
//			Sleep(50);
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//}

//void SwopArray(int arr[], int size)
//{
//	assert(arr);
//	int start = 0;
//	int last = size;
//	int temp = 0;
//	while (start<last)
//	{
//		while (arr[start] % 2)
//			start++;
//		while (1 != arr[last] % 2)
//			last--;
//		if (start < last)
//		{
//			temp = arr[start];
//			arr[start] = arr[last];
//			arr[last] = temp;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 6, 2, 4, 5, 9, 8, 3, 1, 7, 10 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	SwopArray(arr, sizeof(arr) / sizeof(arr + 0));
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[5] = { 1, 2, 3, 2, 1 };
//	int size = 5;
//	int num = 0;
//	while (size-- > 0)
//	{
//		num ^= arr[size];
//	}
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	printf("Please input a number:");
//	scanf("%d", &num);
//	while (num)
//	{
//		printf("%d\n", num%10);
//		num /= 10;
//	}
//	system("pause");
//	return 0;
//}


//int main(){
//
//	int digit, number, power, t;
//	printf("enter an integer:");
//	scanf("%d", &number);
//	number = number<0 ? -number : number;
//	//��ȡ�Ӽ����������������λ 3456 ��1000
//	power = 1;//���λ
//	t = number;
//	while (t >= 10){
//		power *= 10;
//		t /= 10;
//	};
//	//��������Ӽ����ϻ�ȡ������ �����ϵ�λ��
//	printf("the digits are:");
//	while (power >= 1){
//		digit = number / power;
//		printf("%d\n", digit);
//		number %= power;
//		power /= 10;
//	}
//	system("pause");
//	return 0;
//}