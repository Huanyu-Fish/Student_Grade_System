#include "Function.h"

BaseOfGoods Base;

int main()
{
	Base.next = NULL;
	if (ReadFileOfBase(Base))
		printf("读取仓库物品数据成功。\n");
	else printf("读取仓库物品数据失败。\n");
	/*if(Base.next->next->next!=NULL)
	printf("%s", Base.next->next->next);*/
	MainMenu();



	if(ConserveFileOfBase(Base))
		printf("保存仓库物品数据成功。\n");
	else printf("保存仓库物品数据失败。\n");
	system("pause");
	return 0;
}