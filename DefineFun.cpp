#include "Function.h"



//读取仓库的物品数据，并记录仓库的物品种类总数(头结点不带数据)
int ReadFileOfBase(BaseOfGoods &Base)
{
	FILE* fp;
	if ((fp = fopen("DataOfBase.txt", "r+")) == NULL)
	{
		printf("未能打开数据库文件！\n");
		return 0;
	}
	int i=1;
	Base.next =(BaseOfGoods*) malloc(sizeof(BaseOfGoods));
	BaseOfGoods* Base_1 = Base.next,*Base_2;
	//读取物品编码，名称，数量，价格。
	fscanf(fp, "%s%s%d%f", Base_1->goods.code, Base_1->goods.name, &Base_1->goods.sum, &Base_1->goods.price);
	//读取物品的生产日期(年月日)，保质期(保的月份)
	fscanf(fp, "%d%d%d%d", &Base_1->goods.ED.pd.y, &Base_1->goods.ED.pd.m, &Base_1->goods.ED.pd.d, &Base_1->goods.ED.Ex_Mon);
	//入库日期(年月日)
	fscanf(fp, "%d%d%d\n", &Base_1->goods.InTime.year, &Base_1->goods.InTime.month, &Base_1->goods.InTime.day);
	/*printf("%s %s %d %.2f", Base_1->goods.code, Base_1->goods.name, Base_1->goods.sum, Base_1->goods.price);
	printf(" %d %d %d %d", Base_1->goods.ED.pd.y, Base_1->goods.ED.pd.m, Base_1->goods.ED.pd.d, Base_1->goods.ED.Ex_Mon);
	printf(" %d %d %d\n", Base_1->goods.InTime.year, Base_1->goods.InTime.month, Base_1->goods.InTime.day);*/
	while (!feof(fp))
	{
		Base_2 = (BaseOfGoods*)malloc(sizeof(BaseOfGoods));
		if (fscanf(fp, "%s%s%d%f", Base_2->goods.code, Base_2->goods.name, &Base_2->goods.sum, &Base_2->goods.price) != 4)
			break;
		fscanf(fp, "%d%d%d%d", &Base_2->goods.ED.pd.y, &Base_2->goods.ED.pd.m, &Base_2->goods.ED.pd.d, &Base_2->goods.ED.Ex_Mon);
		fscanf(fp, "%d%d%d", &Base_2->goods.InTime.year, &Base_2->goods.InTime.month, &Base_2->goods.InTime.day);
		Base_1->next = Base_2;
		Base_1 = Base_1->next;
		i++;
	}
	Base_1->next= NULL;
	Base.sumOfGoods = i;
	if (fclose(fp))
	{
		printf("文件未关闭成功。\n");
		return 0;
	}
	return 1;
}

//保存数据文件
int ConserveFileOfBase(BaseOfGoods Base)
{
	FILE* fp;
	if ((fp = fopen("DataOfBase.txt", "r+")) == NULL)
	{
		printf("未能打开数据库文件！\n");
		return 0;
	}
	BaseOfGoods *Base_1 = &Base;
	while (Base_1->next!= NULL)
	{
		Base_1 = Base_1->next;
		fprintf(fp, "%s %s %d %.2f", Base_1->goods.code, Base_1->goods.name, Base_1->goods.sum, Base_1->goods.price);
		fprintf(fp, " %d %d %d %d", Base_1->goods.ED.pd.y, Base_1->goods.ED.pd.m, Base_1->goods.ED.pd.d, Base_1->goods.ED.Ex_Mon);
		fprintf(fp, " %d %d %d\n", Base_1->goods.InTime.year, Base_1->goods.InTime.month, Base_1->goods.InTime.day);
	}
	if (fclose(fp))
	{
		printf("文件未关闭成功。\n");
		return 0;
	}
	return 1;
}

//（未完成)主菜单
void MainMenu()
{
	system("cls");
	printf("*************************************仓库数据管理系统*****************************************\n");
	printf("请输入要进行的操作：\n");
	printf("1.查询货物菜单                        2.货物入库登记\n");
	printf("3.货物出库登记                        4.货物临期统计\n");
	printf("5.修改货物信息(增删查改)系统          6.退出系统\n");
	printf("**********************************************************************************************\n");
	int opt;
	while(1)
	{ 
		scanf("%d", &opt);
		if (opt > 6 || opt <= 0)
		{
			printf("输入有误，请重新输入:\n");
			continue;
		}
		else if (opt == 6)
			break;		
		switch (opt)
		{
		case 1:
			SearchMenu();
			break;
		case 2:
			
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		default:
			break;
		}
	}
	
}


//(未完成)查询系统
void SearchMenu()
{
	int opt;
	while (1)
	{
		system("cls");
		printf("*************************************仓库数据管理系统*****************************************\n");
		printf("        *****************************  查询系统菜单  *****************************    \n");
		printf("请输入要进行的操作：\n");
		printf("1.按货物码查询                        2.按货物名称查询\n");
		printf("3.货物入库时间查询                    4.货物入库时间查询\n");
		printf("5.范围查询货物信息                    6.显示所有货物信息，以页输出\n");
		printf("7.退出该系统，返回上一界面\n");
		printf("**********************************************************************************************\n");
		scanf("%d", &opt);
		if (opt > 7 || opt <= 0)
		{
			printf("输入有误，请重新输入:\n");
			continue;
		}
		else if (opt == 7)
			break;
		switch (opt)
		{
		case 1:
			BaseOfGoods * b;
			b=SearchByCode();
			PrintSheet();
			PrintGoods(b);
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			PrintAllGoods();
			break;
		default:
			break;
		}
	}



}

//按码查找物品
BaseOfGoods* SearchByCode()
{
	BaseOfGoods *Base_1 = Base.next;
	printf("请输入要查找物品的超市码：\n");
	char tem_a[LEN];
	scanf("%s", tem_a);
	while (!Is_MarkCode(tem_a))
	{
		printf("输入的超市码不符合规则(CSXXX)，请重新输入：\n");
		scanf("%s", tem_a);
	}
	printf("输入成功。\n");
	while (Base_1!=NULL)
	{
		if (strcmp(Base_1->goods.code, tem_a)==0)
		{ 
			printf("已匹配到对应物品：\n");
			return Base_1;
		}
		Base_1 = Base_1->next;
	}
	printf("要查找的%s不在超市码中。\n", tem_a);
	return NULL;
}

//超市物品码格式判断：
int Is_MarkCode(char* code)
{
	if (code[0] == 'C' && code[1] == 'S')
	{
		if (code[2] <= '9' && code[2] >= '0')
			if (code[3] <= '9' && code[3] >= '0')
				if (code[4] <= '9' && code[4] >= '0')
					return 1;
	}
	else return 0;
}

//物品信息表单属性
void PrintSheet()
{
	printf("\t物品码\t名称\t数量\t价格\t生产日期\t\t保质期\t入库时间\n");
}

//显示指定物品信息
void PrintGoods(BaseOfGoods* b)
{
	printf("\t%s\t%s\t%d\t%.2f",b->goods.code,b->goods.name,b->goods.sum,b->goods.price);
	printf("\t%d\t%d\t%d\t%d", b->goods.ED.pd.y, b->goods.ED.pd.m, b->goods.ED.pd.d, b->goods.ED.Ex_Mon);
	printf("\t%d\t%d\t%d\n", b->goods.InTime.year, b->goods.InTime.month, b->goods.InTime.day);
}

//显示所有物品信息（分页形式）;
void PrintAllGoods()
{
	BaseOfGoods* Base_1 = Base.next;
	int count = 0, page = 1, All_page = Base.sumOfGoods / 10+1;
	//count 控制一页输出十个物品信息，page记录当前页数
	PrintByPage(page);
	while(true)
	{
		char opt;	
		while (1)
		{
			printf("请输入要进行的操作：\n");			
		    getchar();
			scanf("%c", &opt);
			if (opt == '0')
				return;
			else if (opt != 'a' && opt != 'd' && opt != 'w' && opt != 's')
			{
				printf("输入不在范围,请重新输入：\n");
				continue;
			}			
			else break;
		}
		int opt_num = (int)opt;
		switch(opt_num)
		{
		case 'a':
			if (page == 1)
			printf("此页已经是首页！\n");
			else
			{
				page = 1;
				PrintByPage(page);
				system("pause");
			}			
			break;
		case's':
			if(page==All_page)
				printf("此页已经是尾页！\n");
			else
			{
				PrintByPage(++page);
				system("pause");
			}
			break;
		case 'w':
			if (page == 1)
			printf("此页已经是首页！\n");
			else
		{
			PrintByPage(--page);
			system("pause");
		}
			break;
		case 'd':
			if (page ==All_page )
				printf("此页已经是尾页！\n");
			else
			{
				page = All_page;
				PrintByPage(page);
				system("pause");
			}
			break;
		default:
			break;
		}

	}

}


//按页打印物品信息：
void PrintByPage(int page)
{
	BaseOfGoods *Base_1 = Base.next;
	int count=0;
	while (count / 10 + 1 < page&&Base_1->next!=NULL)
	{
		Base_1 = Base_1->next;
		count++;
	}
	system("cls");
	printf("********************************************   物品信息表   *********************************************\n");
	PrintSheet();
	while (count < page * 10 && Base_1 != NULL)
	{
	    PrintGoods(Base_1);
		Base_1 = Base_1->next;
		count++;
	}
	printf("**********************************************************************************************************\n");
	printf("-------------------------------当前为第%d页,共%d页--------------------------------\n", page, Base.sumOfGoods/10+1);
	printf("输入:w.上一页***a.转至页首***d.转至页尾***s.下一页***0.返回查询系统\n");
}