#include"common.h"

/*int func()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0,j = -1;j = 0;i++,j++)
	{
		k++;
	}
	return k;
}


int main()
{

	printf("%d ", func());
	system("pause");
	return 0;
}

//在一行内输出连续最长的数字串

char* FindLongestNum(int sz,char* arr)
{
	int sum = 0;
	char* q = (char*)malloc(sz);
	char* temp = arr;
	char* p = arr + 1;
	int i = 0;
	memset(q, 0, sz);
	while (*temp != '\0')//计算数字串个数
	{
		if ((*temp <'0' || (*temp) > '9') && (*p >= '0'&&*p <= '9'))
		{
			sum++;
		}
	}
	int* C = (int*)malloc(sum);//比较数字串 
	while (*temp != '\0')
	{
		if (*temp >= '0' && (*temp) <= '9'&&)  
		{
			C[i]++;
		}
	}
	return q;
}

int main()
{
	char p[] = "abcd12345ed125ss123456789"; 
	int sz = sizeof(p) / sizeof(p[0]);//传进来长度包含\0;
	FindLongestNum(sz,p);
	system("pause");
	return 0;
}

int main()
{
	int arr[] = { 1,3,5,7,9 };
	int *p = (int*)(&arr + 1);
	printf("%d %d", *(arr + 1), *(p - 1));
	system("pause");
	return 0;
}
*/

void DevideApple(int a,int b,int c,int d)
{
	double temp1 = (a + c) / 2.0;//A
	double temp2 = (b + d) / 2.0;//B
	if (temp1 + temp2 == (double)c)
	{
		printf("A = %d,B = %d,C= %d",(int)temp1,(int)temp2,(int)(temp1 + temp2));
	}
	else
	{
		printf("No");
	}
}
int main()
{
	int num[4];
	for (int i = 0; i < 4; ++i)
	{
		scanf("%d",&num[i]);
	}
	DevideApple(num[0], num[1], num[2], num[3]);


	system("pause");
	return 0;
}