#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 50
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 50
#define MAX_COUNT 100
//�˵�
void menu();


// ������Ϣ
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


// ͨѶ¼
typedef struct Contact
{
	PeoInfo data[MAX_COUNT];
	int count;//��¼��ǰͨѶ¼�е�ʵ������
}Contact;


//ͨѶ¼��ʼ��
void Contact_Init(Contact* pc);

//������Ϣ
void Add_Contact(Contact* pc);

// ��ѯ
// �鵽�˷����±꣬�鲻������-1
int Serch_Contact(const Contact* pc);

// ��ʾͨѶ��Ϣ
void Show_Contact(const Contact* pc);

// ɾ��
void Del_Contact(Contact* pc);

// �޸�
void Mod_Contact(Contact* pc);

// ����
void Sort_COntact(Contact* pc);
