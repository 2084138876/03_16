#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


int main()
{
	menu();

	Contact con;//����ͨѶ¼����
	Contact_Init(&con);//��ʼ��ͨѶ¼

	int input=0;
	char name[MAX_NAME] = { 0 };
	do {
		printf("��ѡ�� >");
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
			printf("����Ҫ���ҵ����� >");
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
			printf("�˳���\n");
			break;
		default:
			printf("�������\n");
			break;
		};


	} while (input);
	
	return 0;
}