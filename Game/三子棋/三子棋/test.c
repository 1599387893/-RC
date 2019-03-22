#include"ThirdGame.h"


void Menu()
{
	printf("--------------------------------------------\n");
	printf("--------------	 三子棋    -----------------\n");
	printf("-------------- 1. PLAY     ----------------\n");
	printf("-------------- 0. EXIT     -----------------\n");
	printf("--------------------------------------------\n");
}
//进行游戏
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
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
			case 1: 
				Play();
				break;
			case 0:
				printf("游戏结束！\n");
				return 0;
			default:
				printf("选择错误！\n");
				break;
		}
	} while (input);
	
	return 0;
}
