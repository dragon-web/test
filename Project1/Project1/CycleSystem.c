#include"system.h"

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			LoginCycle();
			break;
		case 0:
			printf("���г�����ϵͳ�Ѿ��˳�\n");
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
			printf("��������������ѡ��\n");
			break;
		}
	} while (input);


		system("pause");
		return 0;
	}
