#include"system.h"


void menu()
{
	system("color 4");
	printf("     ***********************************************************************     \n");
	printf("  ************************欢迎使用自行车存放管理系统*******************************   \n");
	printf("|                          自行车停车收费标准2元一小时                          |\n");
	printf("|\t1.--登记自行车停放位信息                                                |\n");
	printf("|\t2.--查询自行车停车位信息                                                |\n");
	printf("|\t3.--修改自行车信息                                                      |\n");
	printf("|\t4.--用户取车管理                                                        |\n");
	printf("|\t5.--显示当前空余自行车位信息                                            |\n");
	printf("|\t0.--退出自行车管理系统                                                  |\n");
	printf("|                                                                               |\n");
	printf("|*******************************************************************************|\n");
	printf("|********************>>>>杨天喆-计科（02）班-20190101134<<<<********************|\n");
	printf("|*******************************************************************************|\n\n");

}

void LoginCycle(CycleList *plist)
{
	
	if (!CycleListIsFull(plist))
	{
		char name[20];
		int age;
		int sex;
		char IDcard[18];
		int hour;
		int Number;
		int year;
		int month;
		int day;
		printf("请输入自行车主姓名\n");
		scanf("%s",name);
		_flushall();
		printf("请输入性别(0代表男，1代表女)");
		scanf("%d", &sex);
		printf("请输入车主年龄");
		scanf("%d", &age);
		printf("请输入身份证号");
		scanf("%s", IDcard);
		_flushall();
		printf("请输入停车时间(年，月，日，时)");
		scanf("%d,%d,%d,%d",&year,&month,&day,&hour);
		printf("请输入要停的位号(位号为1到2000)");
		scanf("%d", &Number);
		plist->space++;
		plist->last->next = _Buynode(name, sex, age, IDcard, Number,year,month,day,hour);
		plist->last = _Buynode(name, sex, age, IDcard, Number, year, month, day, hour);
		FILE *fp = fopen("Test.txt", "a");
		fprintf(fp, "%s %d %d %s %d %d %d %d %d %d\n", name,age,sex,IDcard,hour,Number,year,month,day,hour);
		fclose(fp);

		printf("登记成功\n");
		printf("\n");
	}
	else
	{
		printf("自行车位已满，不能继续停车");
	}
}

CycleNode* _Buynode(char* p, int sex, int age, char* number, int Pnumber, int year, int month, int day, int hour)
{
	CycleNode *s = (CycleNode*)malloc(sizeof(CycleNode));
	size_t sz = strlen(p)+1;
	size_t sz1 = strlen(number)+1;
	if (s == NULL)
		return NULL;
	else
	{
		memcpy(s->CycleHoster,p,sz);
		s->Age = age;
		s->Sex = sex;
		s->partingTime.year = year;
		s->partingTime.month = month;
		s->partingTime.hour = hour;
		s->partingTime.day = day;
		memcpy(s->IDcard,number,sz1);
		s->number = Pnumber;
		s->next = NULL;
		return s;
	}
}
void CycleListInit(CycleList *plist)
{
	char qname[20] = "姓名初始化";
	char qnumber[18] = "身份证初始化";
	CycleNode* p = _Buynode(qname, 0, 0, qnumber, 0, 0,0,0,0);
	plist->first = plist->last = p;
	plist->space = 0;
}
bool CycleListIsFull(CycleList *plist)
{
	if (plist->space > Space)
		return true;
	return false;
}
bool SearchCycle(CycleList* myBycycleList)
{
	int num;
	printf("      查询客房信息\n");
	printf("请输入要查询自行车位号:\n");
	scanf("%d", &num);
	CycleNode* p = myBycycleList->first->next;
	while ((p) != NULL)
	{
		if (p->number == num)
		{
			printf("车主姓名：%s\n", p->CycleHoster);
			(p)->Sex == 0 ? printf("男") : printf("女");
			printf("车主年龄 %d\n", p->Age);
			printf("车主的身份证号为%s \n", p->IDcard);
			printf("停车时间是 %d 年 %d  月  %d 日  %d时\n", p->partingTime.year,p->partingTime.month,p->partingTime.day,p->partingTime.hour);
			printf("停车位号为%d \n", p->number);
			printf("查询成功\n");
			printf("\n");
			return true;
		}
		p = p->next;
	}
	system("cls");
	printf("查询失败,此车位还未被停车\n");
	return false;
}

void ChangeCycle(CycleList* myBycycleList)
{
	int num;
	int temp;
	char Name[20];
	char Number[18];
	size_t sz1;
	size_t sz2;
	FILE *fp = fopen("Test.txt", "wt");
	int SEX;
	int AGE;
	printf("请输入你要更改的信息的自行车位号\n");
	scanf("%d", &num);
	CycleNode *p = myBycycleList->first;
	while (p != NULL)
	{
		if (p->number == num)
		{
			printf("您所查询的信息如下\n");
			SearchCycle(myBycycleList);
			printf("请输入你要更改的信息\n");
			printf("1:更改姓名\n");
			printf("2:更改性别\n");		
			printf("3:更改年龄\n");
			printf("4:更改身份证号\n");
			scanf("%d", &temp);
			switch (temp)
			{
			case  1:
				_flushall();
				printf("请输入新的姓名\n");
				scanf("%s", Name);
				_flushall();
				sz1 = strlen(Name)+1;
				memcpy(p->CycleHoster, Name, sz1);
				printf("更改成功，返回主菜单");
				printf("\n");
				return;
			case 2:
				printf("请输入性别：（0代表男）\n");
					scanf("%d", &SEX);
					p->Sex = num;
					printf("更改成功，返回主菜单");
					printf("\n");
					return;
			case 3:
				printf("请输入年龄\n");
				scanf("%d", &AGE);
				p->Age = AGE;
				printf("更改成功，返回主菜单");
				printf("\n");
				return;
			case 4:
				printf("请输入身份证号\n");
				scanf("%s", Number);
				_flushall();
				sz2 = strlen(Number)+1;
				memcpy(p->IDcard, Number, sz2);
				printf("更改成功，返回主菜单");
				printf("\n");
				return;
			default:
				printf("输入有误,返回主菜单\n");
				return;
			}
		}
		p = p->next;
	}
	if(p == NULL)
	{
	printf("输入有误，返回主菜单");
	printf("\n");
	}
	fclose(fp);
}

void PickUpCycle(CycleList* myBycycleList)//取车
{
	int Year;
	int Month;
	int Day;
	int Hour;
	int FEE;
	CycleNode*p = SearchCycle1(myBycycleList);
	CycleNode* q = p->next;
	assert(p != NULL);
	printf("请输入取车（年，月，日，时）");
	scanf("%d,%d,%d,%d", &Year, &Month, &Day, &Hour);
	printf("您存车的时间是 %d年 %d月 %d日 %d时", (*p).partingTime.year, (*p).partingTime.month, (*p).partingTime.day, (*p).partingTime.hour);
	FEE = (((Year - (*p).partingTime.year) * 365 * 24 + (Month - (*p).partingTime.month) * 30 + (Day - (*p).partingTime.day) * 24 + (Hour - (*p).partingTime.hour)))*2;
	printf("您需要缴纳的费用为%d\n\n", FEE);
	DeleteCyNode(myBycycleList, p->number);
	printf("取车成功,返回主菜单\n");
	printf("\n");
}
CycleNode* SearchCycle1(CycleList* myBycycleList)
{
	int num;
	printf("请输入要查询自行车位号:\n");
	scanf("%d", &num);
	CycleNode* p = myBycycleList->first;
	while (p != NULL)
	{
		if (p->number == num)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void PrintResSpace(CycleList* myBycycleList)
{
	printf("=============查询剩余车位===================\n");
	CycleNode* p = myBycycleList->first->next;
	assert(p != NULL);
	while (p != NULL)
	{
		printf("当前使用中的车位号是 %d\n", p->number);
		p = p->next;
	}

	printf("剩余车位数为: %zu \n",Space - myBycycleList->space);
	printf("=============================================\n");
}
void FileWrite(CycleList* myBycycleList)
{
	FILE *fp = fopen("Test.txt", "w");
	CycleNode *p = myBycycleList->first;
	assert(p != NULL);
	while (p != NULL)
	{
		fprintf("%s %d %d %s %d %d %d %d %d ",p->CycleHoster, p->Age,p->Sex,p->IDcard,p->number,p->partingTime.year,p->partingTime.month,p->partingTime.day, p->partingTime.hour);
		p = p->next;
	}
	fclose(fp);
}
void DeleteCyNode(CycleList* myBycycleList, int key)
{
	CycleNode *s;//q
	CycleNode *t = myBycycleList->first;//p
	while (t->next != NULL && t->next->number != key)
		t = t->next;
	if (t->next == NULL)
		return;

	s = t->next;
	if (t->next == myBycycleList->last)
		myBycycleList->last = t;
	t->next = s->next;
	free(t);
	myBycycleList->space--;
	return;
}