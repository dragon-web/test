#pragma once
#include"common.h"
typedef struct Time
{
	int year;
	int month;
	int day;
	int hour;
}Time;
typedef struct Cycle
{
	char CycleHoster[20];//���г�������
	int Sex;
	int Age;
	char IDcard[18];//���֤��
	Time partingTime;      //���ʱ��
	int number;//���г���λ��
	struct Cycle* next;
}CycleNode;

typedef struct CycleList
{
	CycleNode *first;
	CycleNode *last;
	size_t  space;
}CycleList;

void menu();
void LoginCycle(CycleList *plist);//�Ǽ����г�����
bool SearchCycle(CycleList* myBycycleList);//���ճ�λ�Ų�ѯ���г�
void ChangeCycle(CycleList* myBycycleList);
void PickUpCycle(CycleList* myBycycleList);
void PrintResSpace(CycleList* myBycycleList);
void CycleListInit(CycleList *plist);
CycleNode*_Buynode(char* p, int sex, int age, char* number, int Pnumber, int year, int month, int day, int hour);
bool CycleListIsFull(CycleList *plist);
CycleNode* SearchCycle1(CycleList* myBycycleList);
//void FileWrite(CycleList* myBycycleList);

	