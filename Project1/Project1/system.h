#pragma once
#include"common.h"
typedef struct Cycle
{
	char CycleHoster[20];//自行车主名字
	int Sex;
	int Age;
	char IDcard[18];//身份证号
	int hour;      //存放时间
	struct Cycle* next;
	int number;//自行车车位号
}CycleNode;

typedef struct CycleList
{
	CycleNode *first;
	CycleNode *last;
	size_t  space;
}CycleList;

void menu();
void LoginCycle(CycleList *plist);//登记自行车函数
bool SearchCycle();//按照车位号查询自行车
void ChangeCycle();
void PickUpCycle();
void PrintResSpace();
void CycleListInit(CycleList *plist);
CycleNode* _Buynode(char *p, int sex, int age, char* number, int time,int umber);
bool CycleListIsFull(CycleList *plist);
















void menu()
{
	system("color 4");
	printf("     ***********************************************************************     \n");
	printf("   ************************欢迎使用自行车存放管理系统*******************************   \n");
	printf("|                          自行车停车收费标准2元一小时                     |\n");
	printf("|\t1.--登记自行车停放位信息                                                |\n");
	printf("|\t2.--查询自行车停车位信息                                                |\n");
	printf("|\t3.--修改自行车信息                                                        |\n");
	printf("|\t4.--用户取车管理                                                        |\n");
	printf("|\t5.--显示当前空余自行车位信息                                                    |\n");
	printf("|\t0.--退出自行车管理系统                                                    |\n");
	printf("|                                                                               |\n");
	printf("|*******************************************************************************|\n");
	printf("|********************>>>>杨天喆-计科（02）班-20190101134<<<<********************|\n");
	printf("|*******************************************************************************|\n\n");

}

void LoginCycle(CycleList *plist)
{
	if (!CycleListIsFull(plist))
	{
		printf("请输入自行车主姓名");
		char name[20];
		int age;
		int sex;
		char IDcard[18];
		int hour;
		int Number;
		scanf("%s",plist->last->CycleHoster);
		printf("请输入性别(0代表男，1代表女)");
		scanf("%d", &sex);
		printf("请输入车主年龄");
		scanf("%d", &age);
		printf("请输入身份证号");
		scanf("%s", IDcard[18]);
		printf("请输入要停车时间(注意不足一小时写一小时)");
		scanf("%d", &hour);
		printf("请输入要停的位号");
		scanf("%d ", &Number);
		_Buynode(name, sex, age, IDcard, hour,Number);
		printf("登记成功");
	}
	printf("自行车位已满，不能继续停车");
}
CycleNode* _Buynode(char p[20], int sex, int age, char number[18], int time,int umber)
{
	CycleNode *s = (CycleNode*)malloc(sizeof(CycleNode));
	if (s == NULL)
		return NULL;
	else
	{
		s->CycleHoster = p;
		s->Sex = sex;
		s->Age = age;
		s->IDcard = number;
		s->next = NULL;
		s->number = number;
		return s;
	}
}
void CycleListInit(CycleList *plist)
{
	CycleNode* p = _Buynode(NULL, 0, 0, NULL, 0);
	plist->first = plist->last = p;
	plist->space = 0;
}
bool CycleListIsFull(CycleList *plist)
{
	if (plist->space > Space)
		return true;
		return false;
}
bool SearchCycle()
{
	int num;
	printf("                                  查询客房信息\n");
	printf("请输入要查询自行车位号:\n");
	scanf("%d", &num);
	CycleNode* p = ;


	if (k <= 0 || k > 100)
	{
		printf("对不起，没有相应的房间。\n");
		SearchRoom();
	}
	if (Room[k - 1].Sign == 1)
	{
		printf("姓名:%s\n", Room[k - 1].Clientlist.Name);
		if (Room[k - 1].Clientlist.Sex == 1)
		{
			printf("性别:男\n");
		}
		else
		{
			printf("性别：女\n");
		}
		printf("年龄:%d\n", Room[k - 1].Clientlist.Age);
		printf("身份证号:%s\n", Room[k - 1].Clientlist.IDcard);
		printf("联系电话:%s\n", Room[k - 1].Tel);
		printf("入住时间:%s\n", Room[k - 1].Clientlist.date);
		printf("入住时长:%d\n", Room[k - 1].Clientlist.hour);
		printf("费用:%ld\n", Room[k - 1].Price);
	}
	else
	{
		system("cls");
		printf("很抱歉,没有找到该房间登记的相关信息!!\n\n");
	}
}