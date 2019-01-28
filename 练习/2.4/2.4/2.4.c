//4.将三个数按从大到小输出。 
#include<stdio.h>   
#include<stdlib.h> 
int main()
{
	int i, j, temp, a[10] = {1,2,3};
	
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3 - j; i++)
		{
			if (a[i]>a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
	for (i = 1; i <= 3; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
	return 0;
}
