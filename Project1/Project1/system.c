#include"system.h"


void menu()
{
	system("color 4");
	printf("     ***********************************************************************     \n");
	printf("  ************************��ӭʹ�����г���Ź���ϵͳ*******************************   \n");
	printf("|                          ���г�ͣ���շѱ�׼2ԪһСʱ                          |\n");
	printf("|\t1.--�Ǽ����г�ͣ��λ��Ϣ                                                |\n");
	printf("|\t2.--��ѯ���г�ͣ��λ��Ϣ                                                |\n");
	printf("|\t3.--�޸����г���Ϣ                                                      |\n");
	printf("|\t4.--�û�ȡ������                                                        |\n");
	printf("|\t5.--��ʾ��ǰ�������г�λ��Ϣ                                            |\n");
	printf("|\t0.--�˳����г�����ϵͳ                                                  |\n");
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
		int year;
		int month;
		int day;
		scanf("%s",name);
		_flushall();
		printf("�������Ա�(0�����У�1����Ů)");
		scanf("%d", &sex);
		printf("�����복������");
		scanf("%d", &age);
		printf("���������֤��");
		scanf("%s", IDcard);
		_flushall();
		printf("������ͣ��ʱ��(�꣬�£��գ�ʱ)");
		scanf("%d,%d,%d,%d",&year,&month,&day,&hour);
		printf("������Ҫͣ��λ��(λ��Ϊ1��2000)");
		scanf("%d", &Number);
		plist->space += 1;
		plist->last->next = _Buynode(name, sex, age, IDcard, Number,year,month,day,hour);
		plist->last = _Buynode(name, sex, age, IDcard, Number, year, month, day, hour);
		printf("�Ǽǳɹ�\n");
		printf("\n");
	}
	else
	{
		printf("���г�λ���������ܼ���ͣ��");
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
	char qname[20] = "������ʼ��";
	char qnumber[18] = "���֤��ʼ��";
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
	printf("      ��ѯ�ͷ���Ϣ\n");
	printf("������Ҫ��ѯ���г�λ��:\n");
	scanf("%d", &num);
	CycleNode* p = myBycycleList->first->next;
	while ((p) != NULL)
	{
		if (p->number == num)
		{
			printf("����������%s\n", p->CycleHoster);
			(p)->Sex == 0 ? printf("��") : printf("Ů");
			printf("�������� %d\n", p->Age);
			printf("���������֤��Ϊ%s \n", p->IDcard);
			printf("ͣ��ʱ���� %d �� %d  ��  %d ��  %dʱ\n", p->partingTime.year,p->partingTime.month,p->partingTime.day,p->partingTime.hour);
			printf("ͣ��λ��Ϊ%d \n", p->number);
			printf("��ѯ�ɹ�\n");
			printf("\n");
			return true;
		}
		p = p->next;
	}
	system("cls");
	printf("��ѯʧ��,�˳�λ��δ��ͣ��\n");
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
	int SEX;
	int AGE;
	printf("��������Ҫ���ĵ���Ϣ�����г�λ��\n");
	scanf("%d", &num);
	CycleNode *p = myBycycleList->first;
	while (p != NULL)
	{
		if (p->number == num)
		{
			printf("������ѯ����Ϣ����\n");
			SearchCycle(myBycycleList);
			printf("��������Ҫ���ĵ���Ϣ\n");
			printf("1:��������\n");
			printf("2:�����Ա�\n");			
			printf("3:��������\n");
			printf("4:�������֤��\n");
			scanf("%d", &temp);
			_flushall();
			switch (temp)
			{
			case  1:
				printf("�������µ�����\n");
				scanf("%s", Name);
				sz1 = strlen(Name)+1;
				memcpy(p->CycleHoster, Name, sz1);
				break;
			case 2:
				printf("�������Ա𣺣�0�����У�\n");
					scanf("%d", &SEX);
					p->Sex = num;
					break;
			case 3:
				printf("����������\n");
				scanf("%d", &AGE);
				p->Age = AGE;
				break;
			case 4:
				printf("���������֤��\n");
				scanf("%s", Number);
				_flushall();
				sz2 = strlen(Number)+1;
				memcpy(p->IDcard, Number, sz2);
				break;
			default:
				printf("��������,�������˵�\n");
				break;
			}
		}
		p = p->next;
	}
	if(p == NULL)
	{
	printf("�������󣬷������˵�");
	printf("\n");
	}
}

void PickUpCycle(CycleList* myBycycleList)//ȡ��
{
	int Year;
	int Month;
	int Day;
	int Hour;
	int FEE;
	CycleNode*p = SearchCycle1(myBycycleList);
	assert(p != NULL);
	printf("������ȡ�����꣬�£��գ�ʱ��");
	scanf("%d,%d,%d,%d", &Year, &Month, &Day, &Hour);
	printf("���泵��ʱ���� %d�� %d�� %d�� %dʱ", (*p).partingTime.year, (*p).partingTime.month, (*p).partingTime.day, (*p).partingTime.hour);
	FEE = (((Year - (*p).partingTime.year) * 365 * 24 + (Month - (*p).partingTime.month) * 30 + (Day - (*p).partingTime.day) * 24 + (Hour - (*p).partingTime.hour)))*2;
	printf("����Ҫ���ɵķ���Ϊ%d", FEE);
}
CycleNode* SearchCycle1(CycleList* myBycycleList)
{
	int num;
	printf("������Ҫ��ѯ���г�λ��:\n");
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
	printf("=============��ѯʣ�೵λ===================");






}