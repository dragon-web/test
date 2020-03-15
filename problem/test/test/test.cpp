#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<math.h>
using namespace std;

/*
int main()
{
	int n[][3] = { 10,20,30,40,50,60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2] << endl;
	system("pause");
	return 0;//10 20 30
}
void fun(const int &num1, const int &num2)
{
	cout << num1 << endl;
	cout << num2 << endl;
}
int  main()
{
	int i = 0;
	fun(++i, i++);
	system("pause");
	return 0;
}


void fun(int i, int j)
{

	printf("%d ", i);
	printf("%d", j);
}

int main()
{
	int i = 0;
	fun(++i, i++);
	system("pause");
	return 0;
}

void fun(const int *num1, const int *num2)
{
	cout << num1 << endl;
	cout << num2 << endl;
}
int  main()
{
	int i = 0;
	fun(&(++i), &(i++));
	system("pause");
	return 0;
}
//判断两个素数
void Swap(int *a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
bool Depen(int a)
{
	int q = 0;
	for (q = 1; q < a; ++q)
	{
		for (int p = 1; p < a; ++p)
		{
			if (q * p == a)
				return false;
		}
	}
	return true;
}
int* Judge(int num)
{
	int* answer = (int *)malloc(sizeof(int)*2);
	int i = 0, j = 0;
	int k, p;
	int temp = 2147483647;
	int temp1;
	for (i = 1; i <= num; ++i)
	{
		for (j = 1; j <= num; j++)
		{
			if ((Depen(i)) && (Depen(j)) && (i + j) == num)
			{
				temp1 = abs(i - j);
				if (temp1 < temp)
				{
					Swap(&temp1, &temp);
					k = i;
					p = j;
				}
			}
		}
	}
	answer[0] = k;
	answer[1] = p;
	return answer;
}

int main()
{
	int num;
	printf("请输入一个大于2的偶数");
	scanf("%d", &num);
	int *p = Judge(num);
	for (int i = 0; i < 2; ++i)
	{
		printf("%d\n", p[i]);
	}
	system("pause");
	return 0;
}*/


int main()
{
	/*int i, a[10];
	for (i = 9; i >= 0; i--)
		a[i] = 10 - i;
	printf("%d%d%d", a[2], a[5], a[8]);*/

	int i = 0, a = 1, b = 2, c = 3;
	 i = ++a || ++b || ++c;
	printf("%d %d %d %d", i, a, b, c);
	system("pause");
	return 0;
}
