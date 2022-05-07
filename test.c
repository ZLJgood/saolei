#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("**********  1. play   **********\n");
	printf("**********  0. exit   **********\n");
	printf("********************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查好的雷的信息
	//初始化数组的内容为指定内容
	//mine 数组在没有布置雷之前全为‘0’
	InitBoard(mine, ROWS, COLS,'0');
	//show 数组在没有排查雷之前全为‘*’
	InitBoard(show, ROWS, COLS,'*');
	
	//DisplayBoard(mine, ROW, COL);	
	//设置雷
	SetMine(mine, ROW, COL);

	DisplayBoard(show, ROW, COL);

	//排查雷
	FineMine(mine,show, ROW, COL);
	
	
}
int main()
{
	//设置随机数的生成
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}