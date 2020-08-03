#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define N sizeof(struct PLAYER)
struct PLAYER        //��Ա��Ϣ 
{
	char number[10];   //��Ա�� 
	char tname[10];     //���� 
	char player[10];    //��Ա 
	char type[10];      //���� 
	char city[10];  //����
	char time[8];        //���� 
	float price;       //���  
	int x;        //���ر�ţ�����ɾ�����޸ĵ� 
	struct PLAYER *next;   //ָ���� 
};
typedef struct PLAYER PlayeR;
typedef PlayeR *player;

void HideCursor();    //���ع��
void toxy(int x, int y);    //������ƶ���X,Y���괦
void over();             //�˳� 
void menu();           //�˵� 
void input_player();     //��Ա��� 
void save_player(player p);//����Ա��Ϣ�����ļ� 
void find_player();      //��ѯ 
void print_player();    //��Ա���� 
void del_player();     //ɾ����Ա 
void amend_player();    //�޸���Ϣ 
player ss();
void find_tname_player();  //��������ѯ 
void find_player_player(); //����Ա��ѯ 
void find_number_player();  //�������ѯ
void find_city_player();  //�����в�ѯ  
void shengxupaixu();
void jiangxupaixu();
void HideCursor()     //���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void toxy(int x, int y)      //������ƶ���X,Y���괦
{
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

void menu()    //�˵� 
{
	do
	{
		system("cls");  //���� 
		HideCursor();  //���ع��  
		char t;
		toxy(52, 5);//������ƶ�����50��5�����괦
		printf(" ��ѯ����ϵͳ");
		toxy(48, 8);
		printf("|     1.��Ա���      |");
		toxy(48, 10);
		printf("|     2.�޸���Ϣ      |");
		toxy(48, 12);
		printf("|     3.ɾ����Ϣ      |");
		toxy(48, 14);
		printf("|     4.��Ա��ѯ      |");
		toxy(48, 16);
		printf("|     5.��Ա����      |");
		toxy(48, 18);
		printf("|     6.��Ա��������  |");
		toxy(48, 20);
		printf("|     7.��Ա��������  |");
		toxy(48, 22);
		printf("|     8.�˳����      |");
		t = getch();    //�����Ժ��� 
		switch (t)
		{
		case '1':input_player(); break;
		case '2':amend_player(); break;
		case '3':del_player(); break;
		case '4':find_player(); break;
		case '5':print_player(); break;
		case '6':jiangxupaixu(); break;
		case '7':shengxupaixu(); break;
		case '8':over(); break;;
		default:break;
		}
	} while (1);
}

player ss()      //���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ 
{
	FILE *fp;      //�ļ�ָ�� 
	int n = 0;
	player head = NULL;
	player p2, p, pr = NULL;
	fp = fopen("myplayer", "ab+");     //��ֻ���ķ�ʽ���ļ� 
	if (fp == NULL)
	{
		printf("cannot open file\n");
	}
	while (!feof(fp))        //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ 
	{
		n++;
		p = (player)malloc(N); //���ڴ�����һ�οռ� 
		fread(p, N, 1, fp);     //��fp��ָ����ļ��е����ݸ���p 
		if (n == 1)
		{
			head = p;
			p2 = p;
		}
		else             //�������� 
		{
			pr = p2;
			p2->next = p;
			p2 = p;
		}
	}
	if (pr != NULL)  //βָ�븽NULL 
		pr->next = NULL;
	else
		head = NULL;
	fclose(fp);    //�ر��ļ� 
	return head;   //����ͷָ�� 
}

void input_player()    //ͼ��¼�� 
{
	do
	{
		system("cls");
		char t;
		player p;
		p = (player)malloc(N);     //����ռ� 
		//������Ա��Ϣ
		toxy(48, 8);
		printf("��������Ա��(С��10λ��)��");
		scanf("%s", p->number); getchar();  //gttchar�Ե��س���ֹ���ź������ 
		toxy(48, 10);
		printf("���������(С��10λ��)��");
		scanf("%s", p->tname); getchar();
		toxy(48, 12);
		printf("��������Ա��(С��10λ��)��");
		scanf("%s", p->player); getchar();
		toxy(48, 14);
		printf("��������Աλ��(С��10λ��)��");
		scanf("%s", p->type); getchar();
		toxy(48, 16);
		printf("��������Ա����(С��10λ��)��");
		scanf("%s", p->city); getchar();
		toxy(48, 18);
		printf("��������Ա����(С��8λ��)��");
		scanf("%s", p->time); getchar();
		toxy(48, 20);
		printf("��������Ա��ۣ�");
		scanf("%f", &p->price); getchar();
		toxy(48, 22);
		save_player(p);
		toxy(48, 24);
		printf("���ڱ���....");
		Sleep(500);   //��ͣ0.5�� 
		system("cls");
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|                       |");
		toxy(46, 10);
		printf("| ����ɹ����Ƿ������  |");
		toxy(46, 12);
		printf("| 1.��             2.�� |");
		toxy(46, 13);
		printf("|                       |");
		toxy(46, 14);
		printf("-------------------------");
		while (1)    //������ѭ����ֹ������������ 
		{
			t = getch();
			if (t == '1')
			{
				break;
			}
			else if (t == '2')
			{
				menu(); break;
			}
		}
	} while (1);

}
void  shengxupaixu()
{
	system("cls");
	player head;
	head = ss();
	int i;
	toxy(10, 5);
	printf("****************************************��Ա(��۽���)����****************************************");
	toxy(10, 8);
	printf("--------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ��� ");
	toxy(10, 10);
	printf("--------------------------------------------------------------------------------------------------");
	if (head == NULL)
	{
		toxy(45, 11);
		printf("��Ա����ʱ��ԱŶ~�Ͽ�ȥ��Ӱ�^_^(�����������)");
		getch();
		menu();
	}
	PlayeR *p = NULL;
	PlayeR *q = NULL;
	PlayeR t;
	for (p = head; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->price > q->price)
			{
				t = *p;
				*p = *q;
				*q = t;
				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
			}
		}
	}
	p = head;
	while (p->next != NULL)
	{
		printf("\n%14s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
		p = p->next;
	}

	printf("�����������");
	getch();//�����Ժ��� 
}
void jiangxupaixu()
{
	system("cls");
	player head;
	head = ss();
	int i;
	toxy(10, 5);
	printf("****************************************��Ա(��۽���)����****************************************");
	toxy(10, 8);
	printf("--------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ��� ");
	toxy(10, 10);
	printf("--------------------------------------------------------------------------------------------------");
	if (head == NULL)
	{
		toxy(45, 11);
		printf("��Ա����ʱ��ԱŶ~�Ͽ�ȥ��Ӱ�^_^(�����������)");
		getch();
		menu();
	}
	PlayeR *p = NULL;
	PlayeR *q = NULL;
	PlayeR t;
	for (p = head; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->price < q->price)
			{
				t = *p;
				*p = *q;
				*q = t;
				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
			}
		}
	}
	p = head;
	while (p->next != NULL)
	{
		printf("\n%14s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
		p = p->next;
	}

	printf("�����������");
	getch();//�����Ժ��� 
}
void amend_player()    //�޸���Ա��Ϣ 
{
	do
	{
		system("cls");
		player head, p;
		int i = 11, j = 0, x;
		char ch, t;
		FILE *fp;    //�ļ�ָ�� 
		char _name[10];
		char number[10];   //��� 
		char tname[10];     //���� 
		char player[10];    //���� 
		char type[10];      //���� 
		char city[10];  //���� 
		char time[8];        //���� 
		float price;       //���
		head = ss();
		p = head;
		toxy(48, 10);
		printf("��������Ҫ�޸ĵĶ�����");
		gets(_name);
		while (p != NULL)    //��ʼ��p->xΪ0 
		{
			p->x = 0;
			p = p->next;
		}
		p = head;    //��p����ָ���ͷ 
		toxy(10, 5);
		printf("***********************************************��Ա��Ϣ***********************************************");
		toxy(10, 8);
		printf("------------------------------------------------------------------------------------------------------");
		toxy(10, 9);
		printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ���     ");
		toxy(10, 10);
		printf("------------------------------------------------------------------------------------------------------");
		while (p != NULL)
		{
			if (p != NULL && strcmp(p->tname, _name) == 0)   //�ж������ַ��Ƿ���� 
			{
				toxy(8, i);
				j++;  //������� 
				printf("No.%d:%s%14s%14s%14s   %14s   %18s         %.2f\n", j, p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
				p->x = j;    //�����ϲ�ѯ��׼�Ľ���� 
				i++;   //������ 
			}
			p = p->next;
		}
		if (j == 0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{
			toxy(50, i);
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while (1)               //��ѭ����ֹ��0��1�������������� 
			{
				ch = getch();
				if (ch == '0')
				{
					menu(); break;
				}
				else if (ch == '1')
				{
					break;
				}
			}
			if (ch == '1')     //��������ch����1�����������ѭ�� 
				continue;
		}
		while (1)
		{
			toxy(45, i);
			printf("��������Ҫ�޸ĵ���Ա�ı�ţ�");
			scanf("%d", &x); getchar();
			if (x > j || x == 0)
			{
				toxy(45, ++i);
				printf("�����������������!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p = head;     //��p����ָ���ͷ 
		while (p != NULL && p->x != x)   //���������ѯ���������Ľ�� 
		{
			p = p->next;
		}
		if (p)    //���p��Ϊ�� 
		{
			system("cls");
			//����Ҫ�޸ĵ���Ϣ 
			toxy(48, 8);
			printf("��������Ա�ĺ���(С��10λ��)��");
			scanf("%s", number); getchar(); strcpy(p->number, number);   //�Ե�scanfǰ��Ļس��Է������±ߵ���� 
			toxy(48, 10);
			printf("���������(С��10λ��)��");
			scanf("%s", tname); getchar(); strcpy(p->tname, tname);
			toxy(48, 12);
			printf("��������Ա��(С��10λ��)��");
			scanf("%s", player); getchar(); strcpy(p->player, player);
			toxy(48, 14);
			printf("��������Աλ��(С��10λ��)��");
			scanf("%s", type); getchar(); strcpy(p->type, type);
			toxy(48, 16);
			printf("��������Ա����(С��10λ��)��");
			scanf("%s", city); getchar(); strcpy(p->city, city);
			toxy(48, 18);
			printf("��������Ա����(С��8λ��)��");
			scanf("%s", time); getchar(); strcpy(p->time, time);
			toxy(48, 20);
			printf("��������ۣ�");
			scanf("%f", &price); getchar(); p->price = price;
			toxy(48, 22);
		}
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|                       |");
		toxy(46, 10);
		printf("|     �Ƿ�ȷ���޸ģ�    |");
		toxy(46, 12);
		printf("| 1.��             2.�� |");
		toxy(46, 13);
		printf("|                       |");
		toxy(46, 14);
		printf("-------------------------");
		while (1)   //������ѭ����ֹ������������ 
		{
			t = getch();
			if (t == '1')   //querenxiugai
			{
				break;
			}
			else if (t == '2')   //ȡ���޸� 
			{
				menu(); break;  //�������˵� 
			}
		}
		system("cls");
		toxy(46, 10);
		printf("�����޸ģ����Ժ�....");
		fp = fopen("myplayer", "wb");   //��ֻд�ķ�ʽ����Ϊmyplayer�Ķ������ļ����򿪵�ͬʱ����ļ��е����� 
		if (fp == NULL)
		{
			printf("cannot open file");
		}
		if (fwrite(head, N, 1, fp) != 1)   //��headд��fp��ָ����ļ��� 
		{
			printf("write error!");
		}
		fclose(fp);   //�ر��ļ� 
		if (head != NULL)   //���head��Ϊ�� 
		{
			p = head->next;     //��pָ��ڶ������ 
			fp = fopen("mybook", "ab");   //Ϊֻд�򿪶������ļ���׷�� 
			if (fp == NULL)
			{
				printf("cannot open file");
			}
			while (p != NULL)
			{
				if (fwrite(p, N, 1, fp) != 1)//��pд��fp��ָ����ļ���
				{
					printf("write error!");
				}
				p = p->next;
			}
			fclose(fp);  //�ر��ļ� 
		}
		Sleep(500);   //��ͣ0.5�� 
		system("cls");
		toxy(46, 10);
		printf("�޸ĳɹ��������Զ��������˵�....");
		Sleep(500);
		break;
	} while (1);
}

void del_player()   //ɾ����Ϣ 
{
	do
	{
		system("cls");
		FILE *fp;
		player head, p, pre = NULL;
		int j = 0, x, i = 11;
		char name[10];
		char t, c, ch;
		head = ss();    //���ú��������ر�ͷ��ַ 
		toxy(48, 10);
		printf("��������Ҫɾ������Ա������");
		scanf("%s", name);
		p = head;
		while (p != NULL)
		{
			p->x = 0;     //��ʼ����� 
			p = p->next;
		}
		p = head;
		toxy(10, 5);
		printf("***********************************************��Ա��Ϣ***********************************************");
		toxy(10, 8);
		printf("------------------------------------------------------------------------------------------------------");
		toxy(10, 9);
		printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ���     ");
		toxy(10, 10);
		printf("------------------------------------------------------------------------------------------------------");
		while (p != NULL)
		{
			if (p != NULL && strcmp(p->tname, name) == 0)
			{
				toxy(8, i);
				j++;
				printf("No.%d:%s%14s%14s%14s   %14s   %18s         %.2f\n", j, p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
				p->x = j;
				i++;
			}
			p = p->next;
		}
		if (j == 0)                   //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ 
		{
			toxy(50, i);
			printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");
			while (1)               //��ѭ����Ϊ�˷�ֹ��0��1�������������� 
			{
				ch = getch();
				if (ch == '0')
				{
					menu(); break;
				}
				else if (ch == '1')
				{
					break;
				}
			}
			if (ch == '1')     //��������ch����1�����������ѭ�� 
				continue;
		}
		while (1)
		{
			toxy(45, i);
			printf("��������Ҫɾ������Ա��ţ�");
			scanf("%d", &x); getchar();
			if (x > j || x == 0)
			{
				toxy(45, ++i);
				printf("�����������������!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|                       |");
		toxy(46, 10);
		printf("|     �Ƿ�ȷ��ɾ����    |");
		toxy(46, 12);
		printf("| 1.��             2.�� |");
		toxy(46, 13);
		printf("|                       |");
		toxy(46, 14);
		printf("-------------------------");
		while (1)
		{
			t = getch();
			if (t == '1')
			{
				break;
			}
			else if (t == '2')
			{
				menu();
			}
		}
		p = head;
		while (p != NULL && p->x != x)
		{
			pre = p;
			p = p->next;
		}
		if (p != NULL)
		{
			if (pre == NULL)
			{
				head = head->next;
			}
			else
			{
				pre->next = p->next;
			}
		}
		free(p);
		fp = fopen("myplayer", "wb");
		if (fp == NULL)
		{
			printf("cannot open file");
		}
		if (fwrite(head, N, 1, fp) != 1)
		{
			printf("write error!");
		}
		fclose(fp);
		if (head != NULL)
		{
			p = head->next;
			fp = fopen("myplayer", "ab");
			if (fp == NULL)
			{
				printf("cannot open file");
			}
			while (p != NULL)
			{
				if (fwrite(p, N, 1, fp) != 1)
				{
					printf("write error!");
				}
				p = p->next;
			}
			fclose(fp);
		}
		system("cls");
		toxy(46, 10);
		printf("����ɾ�������Ժ�....");
		Sleep(500);
		system("cls");
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|                       |");
		toxy(46, 10);
		printf("|  ɾ���ɹ����Ƿ������ |");
		toxy(46, 12);
		printf("| 1.��             2.�� |");
		toxy(46, 13);
		printf("|                       |");
		toxy(46, 14);
		printf("-------------------------");
		while (1)
		{
			c = getch();
			if (c == '1')
			{
				break;
			}
			else if (c == '2')
			{
				menu();
			}
		}
	} while (1);
}

void print_player()   //��Ա���� 
{
	system("cls");
	player head, p;
	int i = 11;
	int sum = 0;
	head = ss();
	toxy(10, 5);
	printf("***********************************************��Ա����*******************************************");
	toxy(10, 8);
	printf("--------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ��� ");
	toxy(10, 10);
	printf("--------------------------------------------------------------------------------------------------");
	if (head == NULL)
	{
		toxy(45, 11);
		printf("��Ա����ʱû����ԱŶ~�Ͽ�ȥ��Ӱ�^_^(�����������)");
		getch();
		menu();
	}
	p = head;
	while (p != NULL)
	{
		toxy(8, i);
		printf("%s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
		i++;
		//������Ա���� 
		p = p->next;
		sum++;
	}
	toxy(48, 7);
	printf("��Ա����Ϊ��%d", sum);
	toxy(45, i);
	printf("�����������");
	getch();//�����Ժ��� 
}

void find_player()  //��ѯ��Ա 
{
	do
	{
		system("cls");  //���� 
		char t;
		toxy(50, 5);
		printf(" ��Ա��ѯ");
		toxy(48, 8);
		printf("|     1.����  ��ѯ      |");
		toxy(48, 10);
		printf("|     2.��Ա����ѯ      |");
		toxy(48, 12);
		printf("|     3.��Ա�Ų�ѯ      |");
		toxy(48, 14);
		printf("|     4.��Ա���в�ѯ      |");
		toxy(50, 18);
		printf("��0�������˵�");
		t = getch();
		switch (t)
		{
		case '0':menu(); break;
		case '1':find_tname_player(); break;
		case '2':find_player_player(); break;
		case '3':find_number_player(); break;
		case '4':find_city_player(); break;
		default:break;
		}
	} while (1);
}

void find_tname_player()  //��������ѯ 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char name[10];
	toxy(48, 8);
	printf("��������Ҫ��ѯ��Ա�Ķ�����");
	gets(name);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	p = head;
	toxy(10, 5);
	printf("***********************************************��Ա����**************************************************");
	toxy(10, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ���        ");
	toxy(10, 10);
	printf("---------------------------------------------------------------------------------------------------------");
	while (p != NULL)
	{
		if (p != NULL && strcmp(p->tname, name) == 0)
		{
			toxy(8, i);
			printf("%s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
			i++;
		}
		p = p->next;
	}
	toxy(45, i);
	printf("����������أ�");
	getch();
	find_player();
}

void find_player_player()   //��������ѯ 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char author[10];
	toxy(48, 8);
	printf("��������Ҫ��ѯ��Ա��������");
	gets(author);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	p = head;
	toxy(20, 5);
	printf("***********************************************��Ա����**************************************************");
	toxy(20, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(20, 9);
	printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ���        ");
	toxy(20, 10);
	printf("---------------------------------------------------------------------------------------------------------");
	while (p != NULL)
	{
		if (p != NULL && strcmp(p->player, author) == 0)
		{
			toxy(8, i);
			printf("%s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
			i++;
		}
		p = p->next;
	}
	toxy(45, i);
	printf("����������أ�");
	getch();
	find_player();
}

void find_number_player()   //����Ų�ѯ 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char number[10];
	toxy(48, 8);
	printf("��������Ҫ��ѯ��Ա����Ա�ţ�");
	gets(number);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	p = head;
	toxy(10, 5);
	printf("***********************************************��Ա����**************************************************");
	toxy(10, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ���        ");
	toxy(10, 10);
	printf("---------------------------------------------------------------------------------------------------------");
	while (p != NULL)
	{
		if (p != NULL && strcmp(p->number, number) == 0)
		{
			toxy(18, i);
			printf("%s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
			i++;
		}
		p = p->next;
	}
	toxy(45, i);
	printf("����������أ�");
	getch();
	find_player();
}

void find_city_player()   //�����в�ѯ 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char city[10];
	toxy(48, 8);
	printf("��������Ҫ��ѯ��Ա�ĳ��У�");
	gets(city);
	toxy(48, 10);
	printf("���ڲ�ѯ....");
	Sleep(500);
	p = head;
	toxy(6, 5);
	printf("***********************************************��Ա����**************************************************");
	toxy(6, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(6, 9);
	printf("��Ա��        ����        ��Ա��         ��Աλ��         ��Ա����         ��Ա����          ���        ");
	toxy(6, 10);
	printf("---------------------------------------------------------------------------------------------------------");
	while (p != NULL)
	{
		if (p != NULL && strcmp(p->city, city) == 0)
		{
			toxy(8, i);
			printf("%s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
			i++;
		}
		p = p->next;
	}
	toxy(45, i);
	printf("����������أ�");
	getch();
	find_player();
}

void save_player(player p)   //��p������д���ļ� 
{
	FILE *fp;    //�ļ�ָ�� 
	fp = fopen("myplayer", "ab");   //��׷�ӵķ�ʽ������Ϊmyplayer�Ķ������ļ� 
	if (fp == NULL)
	{
		printf("cannot open file");
	}
	if (fwrite(p, N, 1, fp) != 1)   //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ��� 
	{
		printf("write error");
	}
	fclose(fp);    //�ر��ļ�  
}

void over()       //�˳���� 
{
	char t;
	toxy(48, 11);
	printf("-----------------------");
	toxy(48, 12);
	printf("|   ��ȷ��Ҫ�˳���  |");
	toxy(48, 14);
	printf("| 1.ȷ��     2.ȡ��   |");
	toxy(48, 15);
	printf("-----------------------");
	while (1)
	{
		t = getch();         //����t
		switch (t)
		{
		case '1':
			system("cls");
			toxy(48, 10);
			printf("���ڰ�ȫ�˳�....");
			Sleep(1000);     //��ͣ1�� 
			system("cls");
			toxy(48, 10);
			printf("�Ѱ�ȫ�˳����");
			toxy(48, 12);
			printf("ллʹ�ã�");
			toxy(48, 14);
			printf("by-by^_^");
			exit(0);  break; //��ֹ���� 
		case '2':
			menu(); break;   //���ú���������˵� 
		}
	}
}

main()   //������˵������� 
{
	int x;
	HideCursor();
	printf("\n\n\n");
	printf("\t\t\t\t\t|******�ڿ�ʼǰ��ѡ������Ҫ�ı���!******|\n");
	printf("\t\t\t\t\t|**************1.��׻���***************|\n");
	printf("\t\t\t\t\t|**************2.��׺���***************|\n");
	printf("\t\t\t\t\t|**************3.�������***************|\n");
	printf("\t\t\t\t\t|**************4.�׵׺���***************|\n");
	printf("\t\t\t\t\t|**************5.�׵�����***************|\n");
	printf("\t\t\t\t\t|**************6.���׻���***************|\n");
	printf("\t\t\t\t\t|**************7.���׺���***************|\n");
	printf("\t\t\t\t\t|**************8.�ϵ׺���***************|\n");
	printf("\t\t\t\t\t|**************9.�ϵ׻���***************|\n");
	printf("\t\t\t\t\t|**************0.�ڵװ���***************|\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t|************�������ѡ��***************|\n");
	scanf("%d", &x);
	switch (x)
	{
	case 1: system("color 46");   break;           //ǰ��ʾ���������ʾ������ɫ 
	case 2: system("color 40");   break;
	case 3: system("color 41");   break;
	case 4: system("color 74");   break;
	case 5: system("color 71");   break;
	case 6: system("color 16");   break;
	case 7: system("color 14");   break;
	case 8: system("color 54");   break;
	case 9: system("color 56");   break;
	case 0: system("color 07");   break;
	default:printf("����������������룡"); getch(); main();
	}
	menu();//�˵� 
}
