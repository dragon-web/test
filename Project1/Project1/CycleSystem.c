#include"system.h"

int main()
{
	CycleList myCycleList;
	CycleListInit(&myCycleList);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			LoginCycle(&myCycleList);
			break;
		case 0:
			system("cls");
			printf("���г�����ϵͳ�Ѿ��˳�\n");
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
			printf("��������������ѡ��\n");
			break;
		}
	} while (input);


		system("pause");
		return 0;
	}
