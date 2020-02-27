#include"common.h"
#include"game.h"

int main()
{	
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d",&input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入有误请重新选择\n");
			break;
		}
	} while (input);

	/*首先是这个大体的框架，这个框架使用了do while ，在最后的时候使用了while (input)语句直接检测
	input,只用一个变量却解决了很多事情，框架结构一定要学会*/

	system("pause");
	return 0;
}