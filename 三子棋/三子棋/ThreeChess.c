#include"common.h"
#include"game.h"

int main()
{	
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d",&input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("��������������ѡ��\n");
			break;
		}
	} while (input);

	/*�������������Ŀ�ܣ�������ʹ����do while ��������ʱ��ʹ����while (input)���ֱ�Ӽ��
	input,ֻ��һ������ȴ����˺ܶ����飬��ܽṹһ��Ҫѧ��*/

	system("pause");
	return 0;
}