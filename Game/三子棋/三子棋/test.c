#include"ThirdGame.h"


void Menu()
{
	printf("--------------------------------------------\n");
	printf("--------------	 ������    -----------------\n");
	printf("-------------- 1. PLAY     ----------------\n");
	printf("-------------- 0. EXIT     -----------------\n");
	printf("--------------------------------------------\n");
}
//������Ϸ
void Play()
{
	char arr[ROW][COL];
	Init(arr, ROW, COL);

}
int main()
{
	int input = 0;
	Menu();
	do
	{
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
			case 1: 
				Play();
				break;
			case 0:
				printf("��Ϸ������\n");
				return 0;
			default:
				printf("ѡ�����\n");
				break;
		}
	} while (input);
	
	return 0;
}
