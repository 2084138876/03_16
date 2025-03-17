#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//菜单
void menu()
{
	printf("----------------------------------------------------------------\n");
	printf("---------------- 1.增加               2.删除	----------------\n");
	printf("---------------- 3.查找               4.修改	----------------\n");
	printf("---------------- 5.显示               6.排序	----------------\n");
	printf("---------------- 0.退出\n");
	printf("----------------------------------------------------------------\n");
}


// 通讯录初始化
void Contact_Init(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//增加信息
void Add_Contact(Contact* pc)
{
	assert(pc);
	if (pc->count ==MAX_COUNT)
	{
		printf("通讯录已满，无法添加！");
		return;
	}
	printf("请输入名字 >");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄 >");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别 >");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话 >");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址 >");
	scanf("%s", pc->data[pc->count].addr);

	(pc->count)++;
	printf("添加成功\n");
}


// 查找信息
int Serch_Contact(const Contact* pc,char name[MAX_NAME])
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，无法查找\n");
		return -1;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			printf("%s\t%d\t%s\t%s\t%s\n", pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
			return i;
		}
	}
	printf("未查询到信息\n");
	return -1;
}



// 显示通讯录
void Show_Contact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		printf("%s\t%d\t%s\t%s\t%s\n", pc->data[i].name,
										pc->data[i].age, 
										pc->data[i].sex,
										pc->data[i].tele,
										pc->data[i].addr);
	}
}



// 删除
void Del_Contact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("姓名 >");
	scanf("%s", name);
	int ret = Serch_Contact(pc, name);
	if ( ret== -1)
	{
		printf("要删除的人不存在");
		return;
	}
	int i = 0;//  要删除的人存在
	for (i = ret; i < pc->count-1; i++)
	{
		pc->data[i] = pc->data[i + 1];

	}
	printf("删除成功！\n");
	(pc->count)--;
}

void Mod_Contact(Contact* pc)
{
	assert(pc);
	// 1.查找
	char name[MAX_NAME] = { 0 };
	printf("输入要修改的名字 >");
	scanf("%s", name);
	int ret=Serch_Contact(pc, name);
	if (ret == -1)
	{
		printf("要修改的内容不存在\n");
		return;
	}
	// 2.修改
	// ret里面存放着要修改的名字对应的下标
	printf("开始修改\n");
	printf("名字 >");
	scanf("%s", pc->data[ret].name);
	printf("年龄 >");
	scanf("%d", &(pc->data[ret].age));
	printf("性别 >");
	scanf("%s", pc->data[ret].sex);
	printf("电话 >");
	scanf("%s", pc->data[ret].tele);
	printf("地址 >");
	scanf("%s", pc->data[ret].addr);

	printf("修改成功！\n");
}



int Sort_By_Name(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

// 排序
void Sort_COntact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo),Sort_By_Name);

	printf("排序成功！\n");

}
