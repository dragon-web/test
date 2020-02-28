#pragma once
#include"common.h"
typedef struct Cycle
{
	char CycleHoster[20];//���г�������
	int Sex;
	int Age;
	char IDcard[18];//���֤��
	int hour;      //���ʱ��
	struct Cycle* next;
	int number;//���г���λ��
}CycleNode;

typedef struct CycleList
{
	CycleNode *first;
	CycleNode *last;
	size_t  space;
}CycleList;

void menu();
void LoginCycle(CycleList *plist);//�Ǽ����г�����
bool SearchCycle();//���ճ�λ�Ų�ѯ���г�
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
	printf("   ************************��ӭʹ�����г���Ź���ϵͳ*******************************   \n");
	printf("|                          ���г�ͣ���շѱ�׼2ԪһСʱ                     |\n");
	printf("|\t1.--�Ǽ����г�ͣ��λ��Ϣ                                                |\n");
	printf("|\t2.--��ѯ���г�ͣ��λ��Ϣ                                                |\n");
	printf("|\t3.--�޸����г���Ϣ                                                        |\n");
	printf("|\t4.--�û�ȡ������                                                        |\n");
	printf("|\t5.--��ʾ��ǰ�������г�λ��Ϣ                                                    |\n");
	printf("|\t0.--�˳����г�����ϵͳ                                                    |\n");
	printf("|                                                                               |\n");
	printf("|*******************************************************************************|\n");
	printf("|********************>>>>���솴-�ƿƣ�02����-20190101134<<<<********************|\n");
	printf("|*******************************************************************************|\n\n");

}

void LoginCycle(CycleList *plist)
{
	if (!CycleListIsFull(plist))
	{
		printf("���������г�������");
		char name[20];
		int age;
		int sex;
		char IDcard[18];
		int hour;
		int Number;
		scanf("%s",plist->last->CycleHoster);
		printf("�������Ա�(0�����У�1����Ů)");
		scanf("%d", &sex);
		printf("�����복������");
		scanf("%d", &age);
		printf("���������֤��");
		scanf("%s", IDcard[18]);
		printf("������Ҫͣ��ʱ��(ע�ⲻ��һСʱдһСʱ)");
		scanf("%d", &hour);
		printf("������Ҫͣ��λ��");
		scanf("%d ", &Number);
		_Buynode(name, sex, age, IDcard, hour,Number);
		printf("�Ǽǳɹ�");
	}
	printf("���г�λ���������ܼ���ͣ��");
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
	printf("                                  ��ѯ�ͷ���Ϣ\n");
	printf("������Ҫ��ѯ���г�λ��:\n");
	scanf("%d", &num);
	CycleNode* p = ;


	if (k <= 0 || k > 100)
	{
		printf("�Բ���û����Ӧ�ķ��䡣\n");
		SearchRoom();
	}
	if (Room[k - 1].Sign == 1)
	{
		printf("����:%s\n", Room[k - 1].Clientlist.Name);
		if (Room[k - 1].Clientlist.Sex == 1)
		{
			printf("�Ա�:��\n");
		}
		else
		{
			printf("�Ա�Ů\n");
		}
		printf("����:%d\n", Room[k - 1].Clientlist.Age);
		printf("���֤��:%s\n", Room[k - 1].Clientlist.IDcard);
		printf("��ϵ�绰:%s\n", Room[k - 1].Tel);
		printf("��סʱ��:%s\n", Room[k - 1].Clientlist.date);
		printf("��סʱ��:%d\n", Room[k - 1].Clientlist.hour);
		printf("����:%ld\n", Room[k - 1].Price);
	}
	else
	{
		system("cls");
		printf("�ܱ�Ǹ,û���ҵ��÷���Ǽǵ������Ϣ!!\n\n");
	}
}