#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>

typedef struct People
{
	char name[10];	//	姓名
	char sex[5];	//	性别
	int age;	//	年龄
	char nation[10];	//	民族
	char political_status[10];	//	政治面貌
	char address[30];	//	家庭住址
	char phone[15];		//	电话号码
	char ID_number[20];		//	身份证号
}People;  //  定义结构体
People p[100];
int index;

void menu()
{
	printf("***********************************************************\n");
	printf("*                      医保信息管理系统                   *\n");
	printf("***********************************************************\n");
	printf("***********************************************************\n");
	printf("*                       1.录入信息                        *\n");
	printf("*                       2.信息更改                        *\n");
	printf("*                       3.信息查询                        *\n");
	printf("*                       4.数据统计                        *\n");
	printf("*                       5.数据排序                        *\n");
	printf("*                       6.生成报表                        *\n");
	printf("*                       7.退出系统                        *\n");
	printf("***********************************************************\n");
}
void menu2()
{
	printf("*                       1.信息改正                        *\n");
	printf("*                       2.信息添加                        *\n");
	printf("*                       3.信息删除                        *\n");
	printf("*                       4.信息保存                        *\n");
	printf("*                       5.打开文件                        *\n");
}

void enter()
{
	system("CLS");
	int n, i, j;
	printf("请输入你想要录入的人数\n");
	scanf_s("%d", &n);
	for (i = 0, j = index + i; i < n; i++, j++)
	{
		system("CLS");
		printf("请输入第%d个人的姓名\n", i + 1);
		scanf_s("%s", p[j].name, 10);
		printf("请输入第%d个人的性别\n", i + 1);
		scanf_s("%s", p[j].sex, 5);
		printf("请输入第%d个人的民族\n", i + 1);
		scanf_s("%s", p[j].nation, 10);
		printf("请输入第%d个人的年龄\n", i + 1);
		scanf_s("%d", &p[j].age, 4);
		printf("请输入第%d个人的政治面貌\n", i + 1);
		scanf_s("%s", p[j].political_status, 10);
		printf("请输入第%d个人的家庭住址\n", i + 1);
		scanf_s("%s", p[j].address, 30);
		printf("请输入第%d个人的联系电话\n", i + 1);
		scanf_s("%s", p[j].phone, 15);
		printf("请输入第%d个人的身份证号\n", i + 1);
		scanf_s("%s", p[j].ID_number, 20);
		index++;
	}
	system("CLS");
	printf("录入成功!\n");
	system("pause");
}

void gaizheng()
{
	system("CLS");
	char id[20];
	int i;
	int flag = 0;
	printf("请输入您想要修改的人的身份证号码\n");
	scanf_s("%s", id, 20);
	system("CLS");
	for (i = 0; i < index; i++)
	{
		if (!strcmp(id, p[i].ID_number))
		{
			flag = 1;
			printf("已经找到此人！\n");
			printf("请修改这个人的政治面貌\n");
			scanf_s("%s", p[i].political_status,10);
			printf("请修改这个人的家庭住址\n");
			scanf_s("%s", p[i].address, 30);			
		}
	}
	if (flag == 0)
	{
		printf("此人不存在!\n");
	}
}
void add()
{
	int i = index;
	system("CLS");
	printf("请输入想要添加人的姓名\n");
	scanf_s("%s", p[i].name, 10);
	printf("请输入想要添加人的性别\n");
	scanf_s("%s", p[i].sex, 5);
	printf("请输入想要添加人的民族\n");
	scanf_s("%s", p[i].nation, 10);
	printf("请输入想要添加人的年龄\n");
	scanf_s("%d", &p[i].age, 4);
	printf("请输入想要添加人的政治面貌\n");
	scanf_s("%s", p[i].political_status, 10);
	printf("请输入想要添加人的的家庭住址\n");
	scanf_s("%s", p[i].address, 30);
	printf("请输入想要添加人的联系电话\n");
	scanf_s("%s", p[i].phone, 15);
	printf("请输入想要添加人的身份证号\n");
	scanf_s("%s", p[i].ID_number, 20);
	index++;
	system("CLS");
	printf("添加完成!");
}
void delet()
{
	system("CLS");
	char id[20];
	int i;
	int j;
	int flag = 0;
	printf("请输入您想要删除的人的身份证号码\n");
	scanf_s("%s", id, 20);
	for (i = 0; i < index; i++)
	{
		if (!strcmp(id, p[i].ID_number))
		{
			flag = 1;
			if (index == 1)
			{
				index = 0;
			}
			for (j = i; j < index-1; j++)
			{
				p[j] = p[j + 1];
			}
		}
	}
	index--;
	if (flag == 0)
	{
		printf("无此人信息！\n");
	}
	else
	{
		printf("删除成功!\n");
	}
	system("pause");
}
void baocun()
{
	FILE *fp;
	int err;
	//文件打开函数
	if ((err = fopen_s(&fp, "1.txt", "w+")) != 0)
	{
		printf("文件打开失败");
	}
	int i;
	fprintf(fp,"人员信息名单如下%c",'\n');
	fprintf(fp,"姓名  性别 年龄 民族 政治面貌 身份证号	家庭住址	联系电话%c",'\n');
	for (i = 0; i < index; i++)
	{
		fprintf(fp, "%s ", p[i].name);
		fprintf(fp, "%s  ", p[i].sex);
		fprintf(fp, "%d ", p[i].age);
		fprintf(fp, "%s  ", p[i].nation);
		fprintf(fp, "%s   ", p[i].political_status);
		fprintf(fp, "%s ", p[i].ID_number);
		fprintf(fp, "%s ", p[i].address);
		fprintf(fp, "%s ", p[i].phone);
		fprintf(fp, "%c", '\n');
	}
	if (fp)
	{
		if (fclose(fp))
			printf("文件关闭失败");
	}

	printf("保存成功!\n");
	system("pause");
}
void wenjiandakai()
{
	system("CLS");
	FILE *fp = NULL;
	int err;
	char s[50];
	int i = 0;
	//文件打开函数
	if ((err = fopen_s(&fp, "2.txt", "r+")) != 0)
	{
		printf("文件打开失败");
	}
	char name[10];	//	姓名
	char sex[5];	//	性别
	char age[5];	//	年龄
	char nation[10];	//	民族
	char political_status[10];	//	政治面貌
	char address[30];	//	家庭住址
	char phone[15];		//	电话号码
	char ID_number[20];		//	身份证号
	fscanf_s(fp, "%s", s, 50);
	fscanf_s(fp, "%s", name, 10);
	fscanf_s(fp, "%s", sex, 5);
	fscanf_s(fp, "%s", age, 5);
	fscanf_s(fp, "%s", nation, 10);
	fscanf_s(fp, "%s", political_status, 10);
	fscanf_s(fp, "%s", ID_number, 10);
	fscanf_s(fp, "%s", address, 10);
	fscanf_s(fp, "%s", phone, 10);
	while (!feof(fp))
	{
		fscanf_s(fp, "%s", p[i].name, 10);
		fscanf_s(fp, "%s", p[i].sex, 5);
		fscanf_s(fp, "%d", &p[i].age);
		fscanf_s(fp, "%s", p[i].nation, 10);
		fscanf_s(fp, "%s", p[i].political_status, 10);
		fscanf_s(fp, "%s", p[i].ID_number, 20);
		fscanf_s(fp, "%s", p[i].address, 30);
		fscanf_s(fp, "%s", p[i].phone, 15);
		i++;
	}
	index = i-1;
	//文件关闭函数；
	if (fp)
	{
		if (fclose(fp))
			printf("文件关闭失败");
	}
	printf("%s\n", s);
	printf("%s %s %s %s %s %s %s %s\n", name, sex, age, nation, political_status, ID_number, address, phone);
	for (i = 0; i < index; i++)
	{
		printf("%s ", p[i].name);
		printf("%s  ", p[i].sex);
		printf("%d ", p[i].age);
		printf("%s  ", p[i].nation);
		printf("%s   ", p[i].political_status);
		printf("%s ", p[i].ID_number);
		printf("%s ", p[i].address);
		printf("%s ", p[i].phone);
		printf("\n");
	}
	system("pause");
}

void xiugai()
{
	system("CLS");
	int a;
	char ch;
	while(1)
	{
		system("CLS");
		menu2();
		printf("请输入您需要进行的操作号:\n");
		scanf_s("%d", &a, 10);
		switch (a)
		{
		case 1:gaizheng(); break;
		case 2:add(); break;
		case 3:delet(); break;
		case 4:baocun();break;
		case 5:wenjiandakai(); break;
		}
		system("CLS");
		printf("您是否要继续操作？如果不需要请按 N 或 n\n");
		getchar();
		scanf_s("%c", &ch, 1);
		if (ch == 'N' || ch == 'n')
		{
			break;
		}
	}
}

void chaxun2()
{
	system("CLS");
	printf("请输入您要查询的人的姓名\n");
	char name[20];
	int flag = 0;
	scanf_s("%s", name, 20);
	system("CLS");
	int i;
	for (i = 0; i < index; i++)
	{
		if (!strcmp(name, p[i].name))
		{
			flag = 1;
			printf("查找成功，这个人的信息如下:\n");
			printf("姓名  性别 年龄 民族 政治面貌 身份证号	家庭住址	联系电话\n");;
			printf("%s ", p[i].name);
			printf("%s ", p[i].sex);
			printf("%d ", p[i].age);
			printf("%s ", p[i].nation);
			printf("%s ", p[i].political_status);
			printf("%s ", p[i].ID_number);
			printf("%s ", p[i].address);
			printf("%s ", p[i].phone);
			printf("\n");
		}
	}
	if (flag == 0)
	{
		printf("无此人信息！\n");
	}
	system("pause");
}
void chaxun3()
{
	system("CLS");
	printf("请输入您要查询的人的身份证号\n");
	char id[20];
	int flag = 0;
	scanf_s("%s", id, 20);
	system("CLS");
	int i;
	for (i = 0; i < index; i++)
	{
		if (!strcmp(id, p[i].ID_number))
		{
			flag = 1;
			printf("查找成功，这个人的信息如下:\n");
			printf("姓名  性别 年龄 民族 政治面貌 身份证号	家庭住址	联系电话\n");
			printf("%s ", p[i].name);
			printf("%s ", p[i].sex);
			printf("%d ", p[i].age);
			printf("%s ", p[i].nation);
			printf("%s ", p[i].political_status);
			printf("%s ", p[i].ID_number);
			printf("%s ", p[i].address);
			printf("%s ", p[i].phone);
			printf("\n");
		}
	}
	if (flag == 0)
	{
		printf("无此人信息!\n");
	}
	system("pause");
}
void chaxun4()
{
	system("CLS");
	printf("请输入您要查询的人的姓名\n");
	char name[20];
	scanf_s("%s", name, 20);
	printf("请输入您要查询的人的身份证号\n");
	char id[20];
	scanf_s("%s", id, 20);
	int i;
	system("CLS");
	int flag = 0;
	for (i = 0; i < index; i++)
	{
		if (!strcmp(name, p[i].name)&& !strcmp(id, p[i].ID_number))
		{
			flag = 1;
			printf("查找成功，这个人的信息如下:\n");
			printf("姓名  性别 年龄 民族 政治面貌 身份证号	家庭住址	联系电话\n");
			printf("%s ", p[i].name);
			printf("%s ", p[i].sex);
			printf("%d ", p[i].age);
			printf("%s ", p[i].nation);
			printf("%s ", p[i].political_status);
			printf("%s ", p[i].ID_number);
			printf("%s ", p[i].address);
			printf("%s ", p[i].phone);
			printf("\n");
		}
	}
	if (flag == 0)
	{
		printf("无此人信息!\n");
	}
	system("pause");
}
void chaxun()
{
	system("CLS");
	printf("请选择您的查询方式\n");
	printf("1、姓名查询\n");
	printf("2、身份证号查询\n");
	printf("3、姓名和身份证号组合查询\n");
	int a;
	scanf_s("%d", &a, 10);
	switch (a)
	{
	case 1:chaxun2(); break;
	case 2:chaxun3(); break;
	case 3:chaxun4(); break;
	default:
		break;
	}
}

void tongji()
{
	system("CLS");
	printf("该系统共录入%d人\n", index);
	system("pause");
}

void paixu()
{
	system("CLS");
	int i, j;
	for (i = 0; i < index - 1;i++)
	{
		for (j = 0; j < index - 1 - i; j++)
		{
			if (p[j].age < p[j + 1].age)
			{
				People tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
	printf("人员信息按照年龄排序如下:");
	printf("姓名  性别 年龄 民族 政治面貌 身份证号	家庭住址	联系电话\n");
	for (i = 0; i < index; i++)
	{
		printf("%s ", p[i].name);
		printf("%s ", p[i].sex);
		printf("%d ", p[i].age);
		printf("%s ", p[i].nation);
		printf("%s ", p[i].political_status);
		printf("%s ", p[i].ID_number);
		printf("%s ", p[i].address);
		printf("%s ", p[i].phone);
		printf("\n");
	}
	system("pause");
}

void print()
{
	system("CLS");
	int i;
	if (index == 0)
	{
		printf("无人员信息\n");
		system("pause");
		return;
	}
	printf("人员信息名单如下\n");
	printf("姓名  性别 年龄 民族 政治面貌 身份证号	家庭住址	联系电话\n");
	for (i = 0; i < index; i++)
	{
		printf("%s ", p[i].name);
		printf("%s  ", p[i].sex);
		printf("%d ", p[i].age);
		printf("%s  ", p[i].nation);
		printf("%s   ", p[i].political_status);
		printf("%s ", p[i].ID_number);
		printf("%s ", p[i].address);
		printf("%s ", p[i].phone);
		printf("\n");
	}
	system("pause");
}

int main()
{
	int a;
	while (1)
	{
		system("CLS");	//	清屏
		menu();
		printf("请输入您需要进行的操作号:\n");
		scanf_s("%d", &a,4);
		switch (a)
		{
		case 1:  enter(); break;
		case 2:	 xiugai(); break;
		case 3:	 chaxun(); break;
		case 4:  tongji(); break;
		case 5:  paixu(); break;
		case 6:  print(); break;
		case 7: exit(0); break;
		}
	}
	system("pause");
	return 0;
}


