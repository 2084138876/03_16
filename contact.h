#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 50
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 50
#define MAX_COUNT 100
//菜单
void menu();


// 个人信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


// 通讯录
typedef struct Contact
{
	PeoInfo data[MAX_COUNT];
	int count;//记录当前通讯录中的实际人数
}Contact;


//通讯录初始化
void Contact_Init(Contact* pc);

//增加信息
void Add_Contact(Contact* pc);

// 查询
// 查到了返回下标，查不到返回-1
int Serch_Contact(const Contact* pc);

// 显示通讯信息
void Show_Contact(const Contact* pc);

// 删除
void Del_Contact(Contact* pc);

// 修改
void Mod_Contact(Contact* pc);

// 排序
void Sort_COntact(Contact* pc);
