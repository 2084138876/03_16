#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//�˵�
void menu()
{
	printf("----------------------------------------------------------------\n");
	printf("---------------- 1.����               2.ɾ��	----------------\n");
	printf("---------------- 3.����               4.�޸�	----------------\n");
	printf("---------------- 5.��ʾ               6.����	----------------\n");
	printf("---------------- 0.�˳�\n");
	printf("----------------------------------------------------------------\n");
}


// ͨѶ¼��ʼ��
void Contact_Init(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//������Ϣ
void Add_Contact(Contact* pc)
{
	assert(pc);
	if (pc->count ==MAX_COUNT)
	{
		printf("ͨѶ¼�������޷���ӣ�");
		return;
	}
	printf("���������� >");
	scanf("%s", pc->data[pc->count].name);
	printf("���������� >");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա� >");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰 >");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ >");
	scanf("%s", pc->data[pc->count].addr);

	(pc->count)++;
	printf("��ӳɹ�\n");
}


// ������Ϣ
int Serch_Contact(const Contact* pc,char name[MAX_NAME])
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
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
	printf("δ��ѯ����Ϣ\n");
	return -1;
}



// ��ʾͨѶ¼
void Show_Contact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
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



// ɾ��
void Del_Contact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("���� >");
	scanf("%s", name);
	int ret = Serch_Contact(pc, name);
	if ( ret== -1)
	{
		printf("Ҫɾ�����˲�����");
		return;
	}
	int i = 0;//  Ҫɾ�����˴���
	for (i = ret; i < pc->count-1; i++)
	{
		pc->data[i] = pc->data[i + 1];

	}
	printf("ɾ���ɹ���\n");
	(pc->count)--;
}

void Mod_Contact(Contact* pc)
{
	assert(pc);
	// 1.����
	char name[MAX_NAME] = { 0 };
	printf("����Ҫ�޸ĵ����� >");
	scanf("%s", name);
	int ret=Serch_Contact(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ����ݲ�����\n");
		return;
	}
	// 2.�޸�
	// ret��������Ҫ�޸ĵ����ֶ�Ӧ���±�
	printf("��ʼ�޸�\n");
	printf("���� >");
	scanf("%s", pc->data[ret].name);
	printf("���� >");
	scanf("%d", &(pc->data[ret].age));
	printf("�Ա� >");
	scanf("%s", pc->data[ret].sex);
	printf("�绰 >");
	scanf("%s", pc->data[ret].tele);
	printf("��ַ >");
	scanf("%s", pc->data[ret].addr);

	printf("�޸ĳɹ���\n");
}



int Sort_By_Name(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

// ����
void Sort_COntact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo),Sort_By_Name);

	printf("����ɹ���\n");

}
