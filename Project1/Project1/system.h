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
	char CycleHoster[20];//自行车主名字
	int Sex;
	int Age;
	char IDcard[18];//身份证号
	Time partingTime;      //存放时间
	int number;//自行车车位号
	struct Cycle* next;
}CycleNode;

typedef struct CycleList
{
	CycleNode *first;
	CycleNode *last;
	size_t  space;
}CycleList;

void menu();
void LoginCycle(CycleList *plist);//登记自行车函数
bool SearchCycle(CycleList* myBycycleList);//按照车位号查询自行车
void ChangeCycle(CycleList* myBycycleList);
void PickUpCycle(CycleList* myBycycleList);
void PrintResSpace(CycleList* myBycycleList);
void CycleListInit(CycleList *plist);
CycleNode*_Buynode(char* p, int sex, int age, char* number, int Pnumber, int year, int month, int day, int hour);
bool CycleListIsFull(CycleList *plist);
CycleNode* SearchCycle1(CycleList* myBycycleList);
//void FileWrite(CycleList* myBycycleList);

	