#include"system.h"

int main()
{
	CycleList myCycleList;
	CycleListInit(&myCycleList);
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			LoginCycle(&myCycleList);
			break;
		case 0:
			system("cls");
			printf("自行车管理系统已经退出\n");
			break;
		case 2:
			system("cls");
			SearchCycle(&myCycleList);
			break;
		case 3:
			system("cls");
			ChangeCycle(&myCycleList);
			break;
		case 4:
			system("cls");
			PickUpCycle(&myCycleList);
			FileWrite(&myCycleList);
			break;
		case 5:
			system("cls");
			PrintResSpace(&myCycleList);
			break;

		default:
			system("cls");
			printf("输入有误请重新选择\n");
			break;
		}
	} while (input);


		system("pause");
		return 0;
	}
