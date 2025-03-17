#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


int main()
{
	menu();

	Contact con;//创建通讯录对象
	Contact_Init(&con);//初始化通讯录

	int input=0;
	char name[MAX_NAME] = { 0 };
	do {
		printf("请选择 >");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add_Contact(&con);
			break;
		case 2:
			Del_Contact(&con);
			break;
		case 3:
			printf("输入要查找的名字 >");
			scanf("%s", name);
			Serch_Contact(&con,name);
			break;
		case 4:
			Mod_Contact(&con);
			break;
		case 5:
			Show_Contact(&con);
			break;
		case 6:
			Sort_COntact(&con);
			break;
		case 0:
			printf("退出！\n");
			break;
		default:
			printf("输入错误！\n");
			break;
		};


	} while (input);
	
	return 0;
}