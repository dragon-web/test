#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string.h>

using namespace std;
class set
{
public:
	set(int *q = NULL, int length1 = 0);
	friend set operator+(set &e, set &f);
	friend set operator*(set &e, set &f);
	friend set operator-(set &e, set &f);
	void show();

private:
	int *p, length;
};

void set::show()
{
	for (int i = 0; i < length; i++)
		cout << p[i] << ' ';
	cout << "\n";
}

set::set(int *q, int length1)
{
	p = q;
	length = length1;
}

set operator+(set &e, set &f) //最多就是两个集合和的长度
{
	int i, j, flag;
	int *w = new int[e.length + f.length];             //开辟一段空间
	memset(w, 0, (e.length + f.length) * sizeof(int)); //w指针所有的空间里的值全部赋为0
	memcpy(w, e.p, e.length * sizeof(int));
	int num = 0;
	for (i = 0; i < f.length; i++) //f中的数要和e中的每个数比较一下是否相等 所以e是内循环
	{
		flag = 1;
		for (j = 0; j < e.length; j++)
		{
			if (f.p[i] == e.p[j]) //指针表示方法
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) //也就是此时f.p[i]与e中每个数都不一样
		{
			*(w + e.length + num) = f.p[i];
			num++;
		}
	}
	int *r = new int[e.length + num];
	memcpy(r, w, (e.length + num) * sizeof(int));
	delete w;
	set temp(r, e.length + num);
	return temp;
}

set operator*(set &e, set &f) //交集最多的长度就是数量少的集合长度
{
	int i, j;
	int num = 0;
	if (e.length > f.length)
	{
		int *w = new int[f.length];           //开辟一段空间
		memset(w, 0, f.length * sizeof(int)); //这一段空间赋为0
		for (i = 0; i < f.length; i++)        //数量少的集合去与数量多的集合比较 相等就把数量小的集合的值弄到w中
		{
			int flag = 0;
			for (j = 0; j < e.length; j++)
			{
				if (f.p[i] == e.p[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				*(w + num) = f.p[i];
				num++;
			}
		}
		int *r = new int[num]; //实际上只用了num这么大的内存
		memcpy(r, w, num * sizeof(int));
		delete w;         //之前的就没有用了
		set temp(r, num); //重新构造
		return temp;
	}
	else

	{
		int *w = new int[e.length];           //开辟一段空间
		memset(w, 0, e.length * sizeof(int)); //这一段空间赋为0
		for (i = 0; i < e.length; i++)        //数量少的集合去与数量多的集合比较 相等就把数量小的集合的值弄到w中
		{
			int flag = 0;
			for (j = 0; j < f.length; j++)
			{
				if (e.p[i] == f.p[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				*(w + num) = e.p[i];
				num++;
			}
		}
		int *r = new int[num]; //实际上只用了num这么大的内存
		memcpy(r, w, num * sizeof(int));
		delete w;         //之前的就没有用了
		set temp(r, num); //重新构造
		return temp;
	}
}

set operator-(set &e, set &f) //差集长度结果一定小于等于左操作数的长度
{
	int i, j;
	int *w = new int[e.length];           //开辟一个左操作数的长度
	memset(w, 0, e.length * sizeof(int)); //全部赋为0
	int num = 0;
	for (i = 0; i < e.length; i++)
	{
		int flag = 0;
		for (j = 0; j < f.length; j++)
		{
			if (e.p[i] == f.p[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			*(w + num) = e.p[i]; //f中没有与e相同的数 则这个数就是差集中的值
			num++;
		}
	}
	int *r = new int[num];
	memcpy(r, w, num * sizeof(int));
	delete w;
	set temp(r, num);
	return temp;
}

bool IsAMember(int test, int* numbers, int count)
{
	for (int i = 0; i < count; i++)//依次查找相同的元素
	{
		if (test == numbers[i])//若找到返回true
		{
			return true;
		}
	}

	return false;

}

void ui()
{
	cout << "1:并集的计算" << endl;
	cout << "2:差集的计算" << endl;
	cout << "3:交集的计算" << endl;
	cout << "4:结束程序" << endl;
	cout << "输入相应的进入相应的计算" << endl;
}

int main()
{
	int a[100], b[100], la, lb, i, j, n;
	cout << "欢迎进入集合操作系统" << endl;
	cout << "请输入第一个集合的个数及值" << endl;
	cin >> la;
	getchar();
	for (i = 0; i < la; i++)
	{
		cin >> a[i];
	}
	cout << "请输入第二个集合的个数及值" << endl;
	cin >> lb;
	getchar();
	for (j = 0; j < lb; j++)
	{
		cin >> b[j];
	}
	ui();
	set s1(a, la);
	set s2(b, lb);
	while (cin >> n)
	{
		if (n == 1)
		{
			set s3 = s1 + s2;
			cout << "并集的结果" << endl;
			s3.show();
			cout << "\n";
		}
		else if (n == 2)
		{
			set s4 = s1 - s2;
			cout << "差集的结果" << endl;
			s4.show();
			cout << "\n";
		}
		else if (n == 3)
		{
			set s5 = s1 * s2;
			cout << "交集的结果" << endl;
			s5.show();
			cout << "\n";
		}
		else if (n == 4)
			break;
		else
			cout << "输入错误 请重新输入" << endl;
	}
	system("pause");
	return 0;
}