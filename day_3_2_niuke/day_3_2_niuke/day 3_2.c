#include"common.h"
CountFabi(int x);
//��Դ�ַ�������ɾ��Ŀ���ַ���
/*
char* DeletePubChar(char* str1,char* str2)// Դ�ַ���  Ŀ���ַ���
{
	char* p = str1;
	char* q = str2;
	while (*q != '\0')
	{
		while (*p != '\0')
		{
			if (*q == *p)
			{
				char* temp = p;
				while (*temp != '\0')
				{
					*temp = *(temp + 1);
					temp++;
				}
			}
			else
			{
				p++;
			}
		}
		q++;
	}
	return str1;
}
int main()
{
	char arr[] = "They are students";
	char arr1[] = "ae";
	char* p = DeletePubChar(arr, arr1);
	printf("%s",arr);
	system("pause");
	return 0;
}
/*

int main()
{
	int a = 1, b = 2, c = 3;
	if (a == 1 && b++ == 2)
		if (b != 2 || c-- != 3)//��·����
			printf("%d %d %d\n", a, b, c);
		else
			printf("%d %d %d\n", a, b, c);
	else
		printf("%d %d %d\n", a, b, c);
		
	int a = 1, b = 0, c = -1, d = 0;
	d = ++a || ++b&&++c;//��·����
	printf("%d", d);
	int a;
	int c;
	scanf("%d", &a);
	c = CountFabi(a);
	printf("%d", c);


	system("pause");
	return 0;
}
//ǰ��������������n
CountFabi(int x)
{
	int sum1 = 0;
	int sum2 = 0;
	int a = 0;
	int b = 1;
	int temp = a;
	int temp1 = x;
	while (a + b < x)//�ҵ��ٽ�С��x��쳲�������
	{
		a = b;
		b = temp + b;
		temp = a;
	}
	while (a + b != x)
	{
		++x;
		sum1++;
	}
	while (b != temp1)
	{
		--temp1;
		sum2++;
	}
	return sum1 > sum2 ? sum2 : sum1;
}
*/

int main()
{


	system("pause");
	return 0;
}