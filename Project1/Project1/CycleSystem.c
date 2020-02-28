#include"system.h"

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			LoginCycle();
			break;
		case 0:
			printf("自行车管理系统已经退出\n");
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:

			break;

		default:
			printf("输入有误请重新选择\n");
			break;
		}
	} while (input);


		system("pause");
		return 0;
	}
