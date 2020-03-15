#include"common.h"
CountFabi(int x);
//从源字符串里面删除目标字符串
/*
char* DeletePubChar(char* str1,char* str2)// 源字符串  目标字符串
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
		if (b != 2 || c-- != 3)//短路运算
			printf("%d %d %d\n", a, b, c);
		else
			printf("%d %d %d\n", a, b, c);
	else
		printf("%d %d %d\n", a, b, c);
		
	int a = 1, b = 0, c = -1, d = 0;
	d = ++a || ++b&&++c;//短路运算
	printf("%d", d);
	int a;
	int c;
	scanf("%d", &a);
	c = CountFabi(a);
	printf("%d", c);


	system("pause");
	return 0;
}
//前提是输入正整数n
CountFabi(int x)
{
	int sum1 = 0;
	int sum2 = 0;
	int a = 0;
	int b = 1;
	int temp = a;
	int temp1 = x;
	while (a + b < x)//找到临届小于x的斐波拉契数
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