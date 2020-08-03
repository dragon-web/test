#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define N sizeof(struct PLAYER)
struct PLAYER        //球员信息 
{
	char number[10];   //球员号 
	char tname[10];     //队名 
	char player[10];    //队员 
	char type[10];      //类型 
	char city[10];  //城市
	char time[8];        //球龄 
	float price;       //身价  
	int x;        //隐藏编号，用于删除，修改等 
	struct PLAYER *next;   //指针域 
};
typedef struct PLAYER PlayeR;
typedef PlayeR *player;

void HideCursor();    //隐藏光标
void toxy(int x, int y);    //将光标移动到X,Y坐标处
void over();             //退出 
void menu();           //菜单 
void input_player();     //球员入库 
void save_player(player p);//将球员信息存入文件 
void find_player();      //查询 
void print_player();    //球员总览 
void del_player();     //删除球员 
void amend_player();    //修改信息 
player ss();
void find_tname_player();  //按队名查询 
void find_player_player(); //按球员查询 
void find_number_player();  //按号码查询
void find_city_player();  //按城市查询  
void shengxupaixu();
void jiangxupaixu();
void HideCursor()     //隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void toxy(int x, int y)      //将光标移动到X,Y坐标处
{
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

void menu()    //菜单 
{
	do
	{
		system("cls");  //清屏 
		HideCursor();  //隐藏光标  
		char t;
		toxy(52, 5);//将光标移动到（50，5）坐标处
		printf(" 查询管理系统");
		toxy(48, 8);
		printf("|     1.球员入库      |");
		toxy(48, 10);
		printf("|     2.修改信息      |");
		toxy(48, 12);
		printf("|     3.删除信息      |");
		toxy(48, 14);
		printf("|     4.球员查询      |");
		toxy(48, 16);
		printf("|     5.球员总览      |");
		toxy(48, 18);
		printf("|     6.球员升序排序  |");
		toxy(48, 20);
		printf("|     7.球员降序排序  |");
		toxy(48, 22);
		printf("|     8.退出软件      |");
		t = getch();    //不回显函数 
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

player ss()      //将文件中的内容读出到链表中，返回值为表头地址 
{
	FILE *fp;      //文件指针 
	int n = 0;
	player head = NULL;
	player p2, p, pr = NULL;
	fp = fopen("myplayer", "ab+");     //以只读的方式打开文件 
	if (fp == NULL)
	{
		printf("cannot open file\n");
	}
	while (!feof(fp))        //判断文件位置标志是否移动到文件末尾 
	{
		n++;
		p = (player)malloc(N); //向内存申请一段空间 
		fread(p, N, 1, fp);     //将fp所指向的文件中的内容赋给p 
		if (n == 1)
		{
			head = p;
			p2 = p;
		}
		else             //创建链表 
		{
			pr = p2;
			p2->next = p;
			p2 = p;
		}
	}
	if (pr != NULL)  //尾指针附NULL 
		pr->next = NULL;
	else
		head = NULL;
	fclose(fp);    //关闭文件 
	return head;   //返回头指针 
}

void input_player()    //图书录入 
{
	do
	{
		system("cls");
		char t;
		player p;
		p = (player)malloc(N);     //申请空间 
		//输入球员信息
		toxy(48, 8);
		printf("请输入球员号(小于10位数)：");
		scanf("%s", p->number); getchar();  //gttchar吃掉回车防止干扰后边输入 
		toxy(48, 10);
		printf("请输入队名(小于10位数)：");
		scanf("%s", p->tname); getchar();
		toxy(48, 12);
		printf("请输入球员名(小于10位数)：");
		scanf("%s", p->player); getchar();
		toxy(48, 14);
		printf("请输入球员位置(小于10位数)：");
		scanf("%s", p->type); getchar();
		toxy(48, 16);
		printf("请输入球员城市(小于10位数)：");
		scanf("%s", p->city); getchar();
		toxy(48, 18);
		printf("请输入球员球龄(小于8位数)：");
		scanf("%s", p->time); getchar();
		toxy(48, 20);
		printf("请输入球员身价：");
		scanf("%f", &p->price); getchar();
		toxy(48, 22);
		save_player(p);
		toxy(48, 24);
		printf("正在保存....");
		Sleep(500);   //暂停0.5秒 
		system("cls");
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|                       |");
		toxy(46, 10);
		printf("| 保存成功！是否继续？  |");
		toxy(46, 12);
		printf("| 1.是             2.否 |");
		toxy(46, 13);
		printf("|                       |");
		toxy(46, 14);
		printf("-------------------------");
		while (1)    //利用死循环防止其他按键干扰 
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
	printf("****************************************球员(身价降序)排序****************************************");
	toxy(10, 8);
	printf("--------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价 ");
	toxy(10, 10);
	printf("--------------------------------------------------------------------------------------------------");
	if (head == NULL)
	{
		toxy(45, 11);
		printf("球员库暂时球员哦~赶快去添加吧^_^(按任意键返回)");
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

	printf("按任意键返回");
	getch();//不回显函数 
}
void jiangxupaixu()
{
	system("cls");
	player head;
	head = ss();
	int i;
	toxy(10, 5);
	printf("****************************************球员(身价降序)排序****************************************");
	toxy(10, 8);
	printf("--------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价 ");
	toxy(10, 10);
	printf("--------------------------------------------------------------------------------------------------");
	if (head == NULL)
	{
		toxy(45, 11);
		printf("球员库暂时球员哦~赶快去添加吧^_^(按任意键返回)");
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

	printf("按任意键返回");
	getch();//不回显函数 
}
void amend_player()    //修改球员信息 
{
	do
	{
		system("cls");
		player head, p;
		int i = 11, j = 0, x;
		char ch, t;
		FILE *fp;    //文件指针 
		char _name[10];
		char number[10];   //编号 
		char tname[10];     //姓名 
		char player[10];    //队名 
		char type[10];      //类型 
		char city[10];  //城市 
		char time[8];        //球龄 
		float price;       //身价
		head = ss();
		p = head;
		toxy(48, 10);
		printf("请输入你要修改的队名：");
		gets(_name);
		while (p != NULL)    //初始化p->x为0 
		{
			p->x = 0;
			p = p->next;
		}
		p = head;    //让p重新指向表头 
		toxy(10, 5);
		printf("***********************************************球员信息***********************************************");
		toxy(10, 8);
		printf("------------------------------------------------------------------------------------------------------");
		toxy(10, 9);
		printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价     ");
		toxy(10, 10);
		printf("------------------------------------------------------------------------------------------------------");
		while (p != NULL)
		{
			if (p != NULL && strcmp(p->tname, _name) == 0)   //判断两个字符是否相等 
			{
				toxy(8, i);
				j++;  //编号自增 
				printf("No.%d:%s%14s%14s%14s   %14s   %18s         %.2f\n", j, p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
				p->x = j;    //给符合查询标准的结点标号 
				i++;   //列自增 
			}
			p = p->next;
		}
		if (j == 0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{
			toxy(50, i);
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while (1)               //死循环防止除0和1的其他按键干扰 
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
			if (ch == '1')     //如果输入的ch等于1，则结束本次循环 
				continue;
		}
		while (1)
		{
			toxy(45, i);
			printf("请输入您要修改的球员的编号：");
			scanf("%d", &x); getchar();
			if (x > j || x == 0)
			{
				toxy(45, ++i);
				printf("输入错误，请重新输入!");
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		p = head;     //让p重新指向表头 
		while (p != NULL && p->x != x)   //遍历链表查询符合条件的结点 
		{
			p = p->next;
		}
		if (p)    //如果p不为空 
		{
			system("cls");
			//输入要修改的信息 
			toxy(48, 8);
			printf("请输入球员的号码(小于10位数)：");
			scanf("%s", number); getchar(); strcpy(p->number, number);   //吃掉scanf前面的回车以防干扰下边的输出 
			toxy(48, 10);
			printf("请输入队名(小于10位数)：");
			scanf("%s", tname); getchar(); strcpy(p->tname, tname);
			toxy(48, 12);
			printf("请输入球员名(小于10位数)：");
			scanf("%s", player); getchar(); strcpy(p->player, player);
			toxy(48, 14);
			printf("请输入球员位置(小于10位数)：");
			scanf("%s", type); getchar(); strcpy(p->type, type);
			toxy(48, 16);
			printf("请输入球员城市(小于10位数)：");
			scanf("%s", city); getchar(); strcpy(p->city, city);
			toxy(48, 18);
			printf("请输入球员球龄(小于8位数)：");
			scanf("%s", time); getchar(); strcpy(p->time, time);
			toxy(48, 20);
			printf("请输入身价：");
			scanf("%f", &price); getchar(); p->price = price;
			toxy(48, 22);
		}
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|                       |");
		toxy(46, 10);
		printf("|     是否确认修改？    |");
		toxy(46, 12);
		printf("| 1.是             2.否 |");
		toxy(46, 13);
		printf("|                       |");
		toxy(46, 14);
		printf("-------------------------");
		while (1)   //利用死循环防止其他按键干扰 
		{
			t = getch();
			if (t == '1')   //querenxiugai
			{
				break;
			}
			else if (t == '2')   //取消修改 
			{
				menu(); break;  //返回主菜单 
			}
		}
		system("cls");
		toxy(46, 10);
		printf("正在修改，请稍后....");
		fp = fopen("myplayer", "wb");   //以只写的方式打开名为myplayer的二进制文件，打开的同时清空文件中的内容 
		if (fp == NULL)
		{
			printf("cannot open file");
		}
		if (fwrite(head, N, 1, fp) != 1)   //将head写入fp所指向的文件中 
		{
			printf("write error!");
		}
		fclose(fp);   //关闭文件 
		if (head != NULL)   //如果head不为空 
		{
			p = head->next;     //让p指向第二个结点 
			fp = fopen("mybook", "ab");   //为只写打开二进制文件并追加 
			if (fp == NULL)
			{
				printf("cannot open file");
			}
			while (p != NULL)
			{
				if (fwrite(p, N, 1, fp) != 1)//将p写入fp所指向的文件中
				{
					printf("write error!");
				}
				p = p->next;
			}
			fclose(fp);  //关闭文件 
		}
		Sleep(500);   //暂停0.5秒 
		system("cls");
		toxy(46, 10);
		printf("修改成功！即将自动返回主菜单....");
		Sleep(500);
		break;
	} while (1);
}

void del_player()   //删除信息 
{
	do
	{
		system("cls");
		FILE *fp;
		player head, p, pre = NULL;
		int j = 0, x, i = 11;
		char name[10];
		char t, c, ch;
		head = ss();    //调用函数，返回表头地址 
		toxy(48, 10);
		printf("请输入你要删除的球员队名：");
		scanf("%s", name);
		p = head;
		while (p != NULL)
		{
			p->x = 0;     //初始化编号 
			p = p->next;
		}
		p = head;
		toxy(10, 5);
		printf("***********************************************球员信息***********************************************");
		toxy(10, 8);
		printf("------------------------------------------------------------------------------------------------------");
		toxy(10, 9);
		printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价     ");
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
		if (j == 0)                   //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息 
		{
			toxy(50, i);
			printf("没有找到相应的信息！(按0返回，按1重新搜索)");
			while (1)               //死循环是为了防止除0和1的其他按键干扰 
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
			if (ch == '1')     //如果输入的ch等于1，则结束本次循环 
				continue;
		}
		while (1)
		{
			toxy(45, i);
			printf("请输入您要删除的球员编号：");
			scanf("%d", &x); getchar();
			if (x > j || x == 0)
			{
				toxy(45, ++i);
				printf("输入错误，请重新输入!");
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
		printf("|     是否确认删除？    |");
		toxy(46, 12);
		printf("| 1.是             2.否 |");
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
		printf("正在删除，请稍后....");
		Sleep(500);
		system("cls");
		toxy(46, 8);
		printf("-------------------------");
		toxy(46, 9);
		printf("|                       |");
		toxy(46, 10);
		printf("|  删除成功，是否继续？ |");
		toxy(46, 12);
		printf("| 1.是             2.否 |");
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

void print_player()   //球员总览 
{
	system("cls");
	player head, p;
	int i = 11;
	int sum = 0;
	head = ss();
	toxy(10, 5);
	printf("***********************************************球员总览*******************************************");
	toxy(10, 8);
	printf("--------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价 ");
	toxy(10, 10);
	printf("--------------------------------------------------------------------------------------------------");
	if (head == NULL)
	{
		toxy(45, 11);
		printf("球员库暂时没有球员哦~赶快去添加吧^_^(按任意键返回)");
		getch();
		menu();
	}
	p = head;
	while (p != NULL)
	{
		toxy(8, i);
		printf("%s%14s%14s%14s   %14s   %18s         %.2f\n", p->number, p->tname, p->player, p->type, p->city, p->time, p->price);
		i++;
		//计算球员总量 
		p = p->next;
		sum++;
	}
	toxy(48, 7);
	printf("球员总量为：%d", sum);
	toxy(45, i);
	printf("按任意键返回");
	getch();//不回显函数 
}

void find_player()  //查询球员 
{
	do
	{
		system("cls");  //清屏 
		char t;
		toxy(50, 5);
		printf(" 球员查询");
		toxy(48, 8);
		printf("|     1.队名  查询      |");
		toxy(48, 10);
		printf("|     2.球员名查询      |");
		toxy(48, 12);
		printf("|     3.球员号查询      |");
		toxy(48, 14);
		printf("|     4.球员城市查询      |");
		toxy(50, 18);
		printf("按0返回主菜单");
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

void find_tname_player()  //按队名查询 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char name[10];
	toxy(48, 8);
	printf("请输入您要查询球员的队名：");
	gets(name);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	p = head;
	toxy(10, 5);
	printf("***********************************************球员总览**************************************************");
	toxy(10, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价        ");
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
	printf("按任意键返回！");
	getch();
	find_player();
}

void find_player_player()   //按姓名查询 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char author[10];
	toxy(48, 8);
	printf("请输入您要查询球员的姓名：");
	gets(author);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	p = head;
	toxy(20, 5);
	printf("***********************************************球员总览**************************************************");
	toxy(20, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(20, 9);
	printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价        ");
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
	printf("按任意键返回！");
	getch();
	find_player();
}

void find_number_player()   //按编号查询 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char number[10];
	toxy(48, 8);
	printf("请输入您要查询球员的球员号：");
	gets(number);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	p = head;
	toxy(10, 5);
	printf("***********************************************球员总览**************************************************");
	toxy(10, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(10, 9);
	printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价        ");
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
	printf("按任意键返回！");
	getch();
	find_player();
}

void find_city_player()   //按城市查询 
{
	system("cls");
	player head, p;
	int i = 11;
	head = ss();
	char city[10];
	toxy(48, 8);
	printf("请输入您要查询球员的城市：");
	gets(city);
	toxy(48, 10);
	printf("正在查询....");
	Sleep(500);
	p = head;
	toxy(6, 5);
	printf("***********************************************球员总览**************************************************");
	toxy(6, 8);
	printf("---------------------------------------------------------------------------------------------------------");
	toxy(6, 9);
	printf("球员号        队名        球员名         球员位置         球员城市         球员球龄          身价        ");
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
	printf("按任意键返回！");
	getch();
	find_player();
}

void save_player(player p)   //将p中内容写入文件 
{
	FILE *fp;    //文件指针 
	fp = fopen("myplayer", "ab");   //以追加的方式打开名字为myplayer的二进制文件 
	if (fp == NULL)
	{
		printf("cannot open file");
	}
	if (fwrite(p, N, 1, fp) != 1)   //将p所指向的一段大小为N的内容存入fp所指向的文件中 
	{
		printf("write error");
	}
	fclose(fp);    //关闭文件  
}

void over()       //退出软件 
{
	char t;
	toxy(48, 11);
	printf("-----------------------");
	toxy(48, 12);
	printf("|   您确定要退出吗？  |");
	toxy(48, 14);
	printf("| 1.确定     2.取消   |");
	toxy(48, 15);
	printf("-----------------------");
	while (1)
	{
		t = getch();         //输入t
		switch (t)
		{
		case '1':
			system("cls");
			toxy(48, 10);
			printf("正在安全退出....");
			Sleep(1000);     //暂停1秒 
			system("cls");
			toxy(48, 10);
			printf("已安全退出软件");
			toxy(48, 12);
			printf("谢谢使用！");
			toxy(48, 14);
			printf("by-by^_^");
			exit(0);  break; //终止程序 
		case '2':
			menu(); break;   //调用函数，进入菜单 
		}
	}
}

main()   //简洁明了的主函数 
{
	int x;
	HideCursor();
	printf("\n\n\n");
	printf("\t\t\t\t\t|******在开始前请选择您需要的背景!******|\n");
	printf("\t\t\t\t\t|**************1.红底黄字***************|\n");
	printf("\t\t\t\t\t|**************2.红底黑字***************|\n");
	printf("\t\t\t\t\t|**************3.红底蓝字***************|\n");
	printf("\t\t\t\t\t|**************4.白底红字***************|\n");
	printf("\t\t\t\t\t|**************5.白底蓝字***************|\n");
	printf("\t\t\t\t\t|**************6.蓝底黄字***************|\n");
	printf("\t\t\t\t\t|**************7.蓝底红字***************|\n");
	printf("\t\t\t\t\t|**************8.紫底红字***************|\n");
	printf("\t\t\t\t\t|**************9.紫底黄字***************|\n");
	printf("\t\t\t\t\t|**************0.黑底白字***************|\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t|************输入你的选择***************|\n");
	scanf("%d", &x);
	switch (x)
	{
	case 1: system("color 46");   break;           //前表示背景，后表示字体颜色 
	case 2: system("color 40");   break;
	case 3: system("color 41");   break;
	case 4: system("color 74");   break;
	case 5: system("color 71");   break;
	case 6: system("color 16");   break;
	case 7: system("color 14");   break;
	case 8: system("color 54");   break;
	case 9: system("color 56");   break;
	case 0: system("color 07");   break;
	default:printf("输入出错，请重新输入！"); getch(); main();
	}
	menu();//菜单 
}
