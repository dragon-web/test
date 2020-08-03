#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>

typedef struct People
{
	char name[10];	//	����
	char sex[5];	//	�Ա�
	int age;	//	����
	char nation[10];	//	����
	char political_status[10];	//	������ò
	char address[30];	//	��ͥסַ
	char phone[15];		//	�绰����
	char ID_number[20];		//	���֤��
}People;  //  ����ṹ��
People p[100];
int index;

void menu()
{
	printf("***********************************************************\n");
	printf("*                      ҽ����Ϣ����ϵͳ                   *\n");
	printf("***********************************************************\n");
	printf("***********************************************************\n");
	printf("*                       1.¼����Ϣ                        *\n");
	printf("*                       2.��Ϣ����                        *\n");
	printf("*                       3.��Ϣ��ѯ                        *\n");
	printf("*                       4.����ͳ��                        *\n");
	printf("*                       5.��������                        *\n");
	printf("*                       6.���ɱ���                        *\n");
	printf("*                       7.�˳�ϵͳ                        *\n");
	printf("***********************************************************\n");
}
void menu2()
{
	printf("*                       1.��Ϣ����                        *\n");
	printf("*                       2.��Ϣ���                        *\n");
	printf("*                       3.��Ϣɾ��                        *\n");
	printf("*                       4.��Ϣ����                        *\n");
	printf("*                       5.���ļ�                        *\n");
}

void enter()
{
	system("CLS");
	int n, i, j;
	printf("����������Ҫ¼�������\n");
	scanf_s("%d", &n);
	for (i = 0, j = index + i; i < n; i++, j++)
	{
		system("CLS");
		printf("�������%d���˵�����\n", i + 1);
		scanf_s("%s", p[j].name, 10);
		printf("�������%d���˵��Ա�\n", i + 1);
		scanf_s("%s", p[j].sex, 5);
		printf("�������%d���˵�����\n", i + 1);
		scanf_s("%s", p[j].nation, 10);
		printf("�������%d���˵�����\n", i + 1);
		scanf_s("%d", &p[j].age, 4);
		printf("�������%d���˵�������ò\n", i + 1);
		scanf_s("%s", p[j].political_status, 10);
		printf("�������%d���˵ļ�ͥסַ\n", i + 1);
		scanf_s("%s", p[j].address, 30);
		printf("�������%d���˵���ϵ�绰\n", i + 1);
		scanf_s("%s", p[j].phone, 15);
		printf("�������%d���˵����֤��\n", i + 1);
		scanf_s("%s", p[j].ID_number, 20);
		index++;
	}
	system("CLS");
	printf("¼��ɹ�!\n");
	system("pause");
}

void gaizheng()
{
	system("CLS");
	char id[20];
	int i;
	int flag = 0;
	printf("����������Ҫ�޸ĵ��˵����֤����\n");
	scanf_s("%s", id, 20);
	system("CLS");
	for (i = 0; i < index; i++)
	{
		if (!strcmp(id, p[i].ID_number))
		{
			flag = 1;
			printf("�Ѿ��ҵ����ˣ�\n");
			printf("���޸�����˵�������ò\n");
			scanf_s("%s", p[i].political_status,10);
			printf("���޸�����˵ļ�ͥסַ\n");
			scanf_s("%s", p[i].address, 30);			
		}
	}
	if (flag == 0)
	{
		printf("���˲�����!\n");
	}
}
void add()
{
	int i = index;
	system("CLS");
	printf("��������Ҫ����˵�����\n");
	scanf_s("%s", p[i].name, 10);
	printf("��������Ҫ����˵��Ա�\n");
	scanf_s("%s", p[i].sex, 5);
	printf("��������Ҫ����˵�����\n");
	scanf_s("%s", p[i].nation, 10);
	printf("��������Ҫ����˵�����\n");
	scanf_s("%d", &p[i].age, 4);
	printf("��������Ҫ����˵�������ò\n");
	scanf_s("%s", p[i].political_status, 10);
	printf("��������Ҫ����˵ĵļ�ͥסַ\n");
	scanf_s("%s", p[i].address, 30);
	printf("��������Ҫ����˵���ϵ�绰\n");
	scanf_s("%s", p[i].phone, 15);
	printf("��������Ҫ����˵����֤��\n");
	scanf_s("%s", p[i].ID_number, 20);
	index++;
	system("CLS");
	printf("������!");
}
void delet()
{
	system("CLS");
	char id[20];
	int i;
	int j;
	int flag = 0;
	printf("����������Ҫɾ�����˵����֤����\n");
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
		printf("�޴�����Ϣ��\n");
	}
	else
	{
		printf("ɾ���ɹ�!\n");
	}
	system("pause");
}
void baocun()
{
	FILE *fp;
	int err;
	//�ļ��򿪺���
	if ((err = fopen_s(&fp, "1.txt", "w+")) != 0)
	{
		printf("�ļ���ʧ��");
	}
	int i;
	fprintf(fp,"��Ա��Ϣ��������%c",'\n');
	fprintf(fp,"����  �Ա� ���� ���� ������ò ���֤��	��ͥסַ	��ϵ�绰%c",'\n');
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
			printf("�ļ��ر�ʧ��");
	}

	printf("����ɹ�!\n");
	system("pause");
}
void wenjiandakai()
{
	system("CLS");
	FILE *fp = NULL;
	int err;
	char s[50];
	int i = 0;
	//�ļ��򿪺���
	if ((err = fopen_s(&fp, "2.txt", "r+")) != 0)
	{
		printf("�ļ���ʧ��");
	}
	char name[10];	//	����
	char sex[5];	//	�Ա�
	char age[5];	//	����
	char nation[10];	//	����
	char political_status[10];	//	������ò
	char address[30];	//	��ͥסַ
	char phone[15];		//	�绰����
	char ID_number[20];		//	���֤��
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
	//�ļ��رպ�����
	if (fp)
	{
		if (fclose(fp))
			printf("�ļ��ر�ʧ��");
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
		printf("����������Ҫ���еĲ�����:\n");
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
		printf("���Ƿ�Ҫ�����������������Ҫ�밴 N �� n\n");
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
	printf("��������Ҫ��ѯ���˵�����\n");
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
			printf("���ҳɹ�������˵���Ϣ����:\n");
			printf("����  �Ա� ���� ���� ������ò ���֤��	��ͥסַ	��ϵ�绰\n");;
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
		printf("�޴�����Ϣ��\n");
	}
	system("pause");
}
void chaxun3()
{
	system("CLS");
	printf("��������Ҫ��ѯ���˵����֤��\n");
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
			printf("���ҳɹ�������˵���Ϣ����:\n");
			printf("����  �Ա� ���� ���� ������ò ���֤��	��ͥסַ	��ϵ�绰\n");
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
		printf("�޴�����Ϣ!\n");
	}
	system("pause");
}
void chaxun4()
{
	system("CLS");
	printf("��������Ҫ��ѯ���˵�����\n");
	char name[20];
	scanf_s("%s", name, 20);
	printf("��������Ҫ��ѯ���˵����֤��\n");
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
			printf("���ҳɹ�������˵���Ϣ����:\n");
			printf("����  �Ա� ���� ���� ������ò ���֤��	��ͥסַ	��ϵ�绰\n");
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
		printf("�޴�����Ϣ!\n");
	}
	system("pause");
}
void chaxun()
{
	system("CLS");
	printf("��ѡ�����Ĳ�ѯ��ʽ\n");
	printf("1��������ѯ\n");
	printf("2�����֤�Ų�ѯ\n");
	printf("3�����������֤����ϲ�ѯ\n");
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
	printf("��ϵͳ��¼��%d��\n", index);
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
	printf("��Ա��Ϣ����������������:");
	printf("����  �Ա� ���� ���� ������ò ���֤��	��ͥסַ	��ϵ�绰\n");
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
		printf("����Ա��Ϣ\n");
		system("pause");
		return;
	}
	printf("��Ա��Ϣ��������\n");
	printf("����  �Ա� ���� ���� ������ò ���֤��	��ͥסַ	��ϵ�绰\n");
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
		system("CLS");	//	����
		menu();
		printf("����������Ҫ���еĲ�����:\n");
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


