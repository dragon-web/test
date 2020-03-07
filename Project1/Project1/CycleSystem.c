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
			_flushall();
			LoginCycle(&myCycleList);
			break;
		case 0:
			_flushall();
			system("cls");
			printf("自行车管理系统已经退出\n");
			break;
		case 2:
			_flushall();
			system("cls");
			SearchCycle(&myCycleList);
			break;
		case 3:
			_flushall();
			system("cls");
			ChangeCycle(&myCycleList);
			break;
		case 4:
			system("cls");
			_flushall();
			PickUpCycle(&myCycleList);
			//FileWrite(&myCycleList);
			_flushall();
			break;
		case 5:
			system("cls");
			_flushall();
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
