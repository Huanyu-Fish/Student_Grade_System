#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define LEN 24
#define MAXSIZE 100

typedef struct time_IO  //进入仓库的时间
{
	int year;
	int month;
	int day;
}IO_Time;

typedef struct produce_date
{
	int y;
	int m;
	int d;
}ProDate;

typedef struct expiration_date  //保质期
{
	ProDate pd;
	int Ex_Mon;
}Exp_Date;

typedef struct goods  //物品代码，物品名称，物品总量，商品价格、保质期时间、入库时间
{
	char code[LEN];
	char name[LEN];
	int sum;
	float price;
	Exp_Date ED;
	IO_Time InTime;
}Goods;

//仓库结构，采用链表
typedef struct baseofGoods
{
	Goods goods;
	int sumOfGoods;
	baseofGoods* next;
}BaseOfGoods;

extern BaseOfGoods Base;   //使用全局变量形式创建仓库

int ReadFileOfBase(BaseOfGoods &Base); //读取文件数据
int ConserveFileOfBase(BaseOfGoods Base);//保存文件数据
void MainMenu();//主菜单
void SearchMenu();//查询菜单
BaseOfGoods* SearchByCode();//按码查找物品
int Is_MarkCode(char* code);//超市物品码格式判断：
void PrintSheet();//物品信息表单属性显示
void PrintGoods(BaseOfGoods* b);//显示指定物品信息
void PrintAllGoods();//显示所有物品信息（分页形式）;
void PrintByPage(int page);//打印指定页的物品信息
void SearchMenu();//物品数据管理系统
void InsertGoods();//插入物品信息
void DeleteGoods();//删除物品信息
void ModityGoods();//修改物品信息
void GoodsIOMenu();//物品出入库菜单
void GetNowTime(int &a,int &b,int &c);//获取当前时间