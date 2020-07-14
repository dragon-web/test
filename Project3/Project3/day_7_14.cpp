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

set operator+(set &e, set &f) //�������������Ϻ͵ĳ���
{
	int i, j, flag;
	int *w = new int[e.length + f.length];             //����һ�οռ�
	memset(w, 0, (e.length + f.length) * sizeof(int)); //wָ�����еĿռ����ֵȫ����Ϊ0
	memcpy(w, e.p, e.length * sizeof(int));
	int num = 0;
	for (i = 0; i < f.length; i++) //f�е���Ҫ��e�е�ÿ�����Ƚ�һ���Ƿ���� ����e����ѭ��
	{
		flag = 1;
		for (j = 0; j < e.length; j++)
		{
			if (f.p[i] == e.p[j]) //ָ���ʾ����
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) //Ҳ���Ǵ�ʱf.p[i]��e��ÿ��������һ��
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

set operator*(set &e, set &f) //�������ĳ��Ⱦ��������ٵļ��ϳ���
{
	int i, j;
	int num = 0;
	if (e.length > f.length)
	{
		int *w = new int[f.length];           //����һ�οռ�
		memset(w, 0, f.length * sizeof(int)); //��һ�οռ丳Ϊ0
		for (i = 0; i < f.length; i++)        //�����ٵļ���ȥ��������ļ��ϱȽ� ��ȾͰ�����С�ļ��ϵ�ֵŪ��w��
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
		int *r = new int[num]; //ʵ����ֻ����num��ô����ڴ�
		memcpy(r, w, num * sizeof(int));
		delete w;         //֮ǰ�ľ�û������
		set temp(r, num); //���¹���
		return temp;
	}
	else

	{
		int *w = new int[e.length];           //����һ�οռ�
		memset(w, 0, e.length * sizeof(int)); //��һ�οռ丳Ϊ0
		for (i = 0; i < e.length; i++)        //�����ٵļ���ȥ��������ļ��ϱȽ� ��ȾͰ�����С�ļ��ϵ�ֵŪ��w��
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
		int *r = new int[num]; //ʵ����ֻ����num��ô����ڴ�
		memcpy(r, w, num * sizeof(int));
		delete w;         //֮ǰ�ľ�û������
		set temp(r, num); //���¹���
		return temp;
	}
}

set operator-(set &e, set &f) //����Ƚ��һ��С�ڵ�����������ĳ���
{
	int i, j;
	int *w = new int[e.length];           //����һ����������ĳ���
	memset(w, 0, e.length * sizeof(int)); //ȫ����Ϊ0
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
			*(w + num) = e.p[i]; //f��û����e��ͬ���� ����������ǲ�е�ֵ
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
	for (int i = 0; i < count; i++)//���β�����ͬ��Ԫ��
	{
		if (test == numbers[i])//���ҵ�����true
		{
			return true;
		}
	}

	return false;

}

void ui()
{
	cout << "1:�����ļ���" << endl;
	cout << "2:��ļ���" << endl;
	cout << "3:�����ļ���" << endl;
	cout << "4:��������" << endl;
	cout << "������Ӧ�Ľ�����Ӧ�ļ���" << endl;
}

int main()
{
	int a[100], b[100], la, lb, i, j, n;
	cout << "��ӭ���뼯�ϲ���ϵͳ" << endl;
	cout << "�������һ�����ϵĸ�����ֵ" << endl;
	cin >> la;
	getchar();
	for (i = 0; i < la; i++)
	{
		cin >> a[i];
	}
	cout << "������ڶ������ϵĸ�����ֵ" << endl;
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
			cout << "�����Ľ��" << endl;
			s3.show();
			cout << "\n";
		}
		else if (n == 2)
		{
			set s4 = s1 - s2;
			cout << "��Ľ��" << endl;
			s4.show();
			cout << "\n";
		}
		else if (n == 3)
		{
			set s5 = s1 * s2;
			cout << "�����Ľ��" << endl;
			s5.show();
			cout << "\n";
		}
		else if (n == 4)
			break;
		else
			cout << "������� ����������" << endl;
	}
	system("pause");
	return 0;
}