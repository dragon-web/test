#include"common.h"
//要求返回无重复字母数组
char* DeletePubChar(char* p)
{
	int sz = (int)strlen(p);//3
	char* q = (char*)malloc(sizeof(char)*(sz+1));//多申请一个内存空间存放‘\0’
	int* arr = (int*)malloc(sizeof(int)*sz);
	memset(arr,0,sizeof(int)*sz);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < sz; ++i)
	{
		for (j = 0; j < sz; ++j)
		{
			if (p[i] == p[j])
				arr[i] += 1;
		}
		if (arr[i] <= 1)
		{
			q[k] = p[i];
			k++;
		}
	}
	q[k + 1] = '\0';
	return q;
}
int main()
{
	char arr[] = "abbascxxxx";
	char*pp = DeletePubChar(arr);
	printf("%s", pp);
	system("pause");
	return 0;
}