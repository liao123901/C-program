#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>


struct Person
{
	char name[20];
	char birthday[20];
	char remarks[20];
	char phoneNumber[20];
	struct Person* pNext;
};


void menue();
void addContacts();
void changeContacts(struct Person* pTemp);
void deleteContacts(struct Person* pTemp);
struct Person* findContacts();
void glanceContacts();
void openFile_way1();
void openFile_way2();
void saveContactsToFileFromList();
void saveContactsToListFromFile();
struct Person* creatList_way1();
struct Person* creatList_way2();
void cleanList_1();
void cleanList_2();


FILE* fp;


struct Person* pHead_1 = NULL;
struct Person* pEnd_1 = NULL;

struct Person* pHead_2 = NULL;
struct Person* pEnd_2= NULL;

int main()
{
	int choose;
	saveContactsToListFromFile();
	while (1)
	{
		menue();
		scanf("%d", &choose);
		if (choose != 6)
		{
			switch (choose)
			{
			case 1:
				system("cls");
				addContacts();
				printf("����س��������˵�............\n");
				getchar();
				break;
			case 2:
				system("cls");
				printf("���Ȳ�������Ҫ���ĵ���ϵ��.......\n");
				changeContacts(findContacts());
				printf("����س��������˵�............\n");
				getchar();
				break;
			case 3:
				system("cls");
				printf("���Ȳ�������Ҫɾ������ϵ��.......\n");

				deleteContacts(findContacts());
				printf("����س��������˵�............\n");
				getchar();
				break;
			case 4:
				system("cls");
				struct Person* pTemp;
				pTemp=findContacts();
				if(pTemp != NULL)
				{
					printf("����ϵ��ȫ����Ϣ���£�\n");
					printf("������%s\t���գ�%s\t��ע��%s\t��ϵ�绰��%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
				}
				printf("����س��������˵�............\n");
				getchar();
				break;
			case 5:
				system("cls");
				glanceContacts();
				printf("����س��������˵�............\n");
				getchar();
				break;
			default:
				system("cls");
				printf("�����������س��������˵�����ѡ��");
				getchar();
				break;
			}
			Sleep(2000);
			getchar();
			system("cls");
			printf("��ѡ��������Ĳ���.....\n");  
		}
		else
			if (choose == 6)
			{
				printf("�����˳�..............\n");
				cleanList_1();
				Sleep(2000);
				printf("Goodbye!");
				break;
			}
	}
	return 0;
}


void menue()
{
	printf("-----------------------------------------------------------------------\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>���˵�<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("                                                                       \n");
	printf("                                  ��ӭ!                                \n");
	printf("                                                                       \n");
	printf("                          ������ͨѶ¼����ϵͳ��                       \n");
	printf("                                                                       \n");
	printf("                      1.�����ϵ��       2.������ϵ��                  \n");
	printf("                                                                       \n");
	printf("                      3.ɾ����ϵ��       4.������ϵ��                  \n");
	printf("                                                                       \n");
	printf("                      5.���             6.�˳�ϵͳ                    \n");
	printf("                                                                       \n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("-----------------------------------------------------------------------\n");
	printf("                             *��ѡ����:");
}


void addContacts()
{
	struct Person*pTemp;
	pTemp = creatList_way1();
	printf("��ʼ���.........\n");
	printf("������������\n");
	scanf("%s", pTemp->name);
	printf("���������գ�\n");
	scanf("%s", pTemp->birthday);
	printf("�����뱸ע��\n");
	scanf("%s", pTemp->remarks);
	printf("������绰���룺\n");
	scanf("%s", pTemp->phoneNumber);
	openFile_way1();
	fprintf(fp, "%s\t%s\t%s\t%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
	fclose(fp);
	printf("�����ϵ�˳ɹ���\n ");
	printf("����ϵ��ȫ����Ϣ���£�\n");
	printf("������%s\t���գ�%s\t��ע��%s\t��ϵ�绰��%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
}


void changeContacts(struct Person* pTemp)
{
	int select;
	char name[20];
	char birthday[20];
	char remarks[20];
	char phoneNumber[20];
	if (pTemp == NULL)
	{
		printf("�����²���!\n");
	}
	else
	{
		printf("����ϵ��ȫ����Ϣ���£�\n");
		printf("������%s\t���գ�%s\t��ע��%s\t��ϵ�绰��%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
		strcpy(name, pTemp->name);
		strcpy(birthday, pTemp->birthday);
		strcpy(remarks, pTemp->remarks);
		strcpy(phoneNumber, pTemp->phoneNumber);
		printf("........�˵�........\n");
		printf("1.����\n");
		printf("2.����\n");
		printf("3.��ע\n");
		printf("4.��ϵ�绰\n");
		printf("��ѡ����Ҫ���ĵ����ݣ�\n");
		printf("....................\n");
		scanf("%d", &select);
		printf("��ʼ����.........\n");
		switch (select)
		{
		case 1:
			printf("�������µ�������");
			scanf("%s", pTemp->name);
			if (strcmp(name, pTemp->name) != 0)
				printf("���ĳɹ���\n");
			else
				printf("����ʧ�ܣ������ԣ�\n");
			break;
		case 2:
			printf("�������µ����գ�");
			scanf("%s", pTemp->birthday);
			if (strcmp(birthday, pTemp->birthday) != 0)
				printf("���ĳɹ���\n");
			else
				printf("����ʧ�ܣ������ԣ�\n");
			break;
		case 3:
			printf("�������µı�ע��");
			scanf("%s", pTemp->remarks);
			if (strcmp(remarks, pTemp->remarks) != 0)
				printf("���ĳɹ���\n");
			else
				printf("����ʧ�ܣ������ԣ�\n");
			break;
		case 4:
			printf("�������µ���ϵ�绰��");
			scanf("%s", pTemp->phoneNumber);
			if (strcmp(phoneNumber, pTemp->phoneNumber) != 0)
				printf("���ĳɹ���\n");
			else
				printf("����ʧ�ܣ������ԣ�\n");
			break;
		default:
			printf("������������ԣ�\n");
		}
		printf("����ϵ�˸��ĺ��ȫ����Ϣ���£�\n");
		printf("������%s\t���գ�%s\t��ע��%s\t��ϵ�绰��%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
		saveContactsToFileFromList();
	}
}


void deleteContacts(struct Person* pTemp)
{
	int select;
	if (pTemp == NULL)
	{
		printf("�����²��ң�\n");
	}
	else
	{
		printf("����ϵ��ȫ����Ϣ���£�\n");
		printf("������%s\t���գ�%s\t��ע��%s\t��ϵ�绰��%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
		printf("�Ƿ�ȷ��ɾ������ϵ�ˣ���ȷ������'1',ȡ������'0'��:\n");
		scanf("%d", &select);
		if (select == 1)
		{
			printf("��ʼɾ��...........\n");
			if (pTemp == pHead_1)
			{
				pHead_1 = pTemp->pNext;
				free(pTemp);
			}
			else
				if (pTemp == pEnd_1)
				{
					struct Person* p1 = pHead_1;
					while (p1->pNext != pEnd_1)
					{
						p1 = p1->pNext;
					}
					free(pEnd_1);
					pEnd_1 = p1;
					pEnd_1->pNext = NULL;
				}
				else
				{
					struct Person* p1 = pHead_1;
					while (p1 != pTemp)
					{
						p1 = p1->pNext;
					}
					p1->pNext = pTemp->pNext;
					free(pTemp);
				}
			saveContactsToFileFromList();
			Sleep(2000); 
			printf("ɾ���ɹ���\n");
		}
		else
		{
			printf("��ȡ����\n");
		}
	}
}


struct Person* findContacts()
{
	int select;
	char name[20];
	char birthday[20];
	char remarks[20];
	char phoneNumber[20];
	struct Person* pTemp = pHead_1;
	printf("...........�˵�...........\n");
	printf("1.����\n");
	printf("2.����\n");
	printf("3.��ע\n");
	printf("4.��ϵ�绰\n");
	printf("��ѡ����ҷ�ʽ��\n");
	printf("..........................\n");
	scanf("%d", &select);
	printf("��ʼ����.........\n");
	switch (select)
	{
	case 1:
		printf("������������");
		scanf("%s", name);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->name, name) == 0)
			{
				printf("�ҵ�����ϵ�ˣ�\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("�޴���ϵ�ˣ�\n");
		return(NULL);
		break;
	case 2:
		printf("���������գ�");
		scanf("%s", birthday);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->birthday, birthday) == 0)
			{
				printf("�ҵ�����ϵ�ˣ�\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("�޴���ϵ�ˣ�\n");
		return(NULL);
		break;
	case 3:
		printf("�����뱸ע��");
		scanf("%s", remarks);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->remarks, remarks) == 0)
			{
				printf("�ҵ�����ϵ�ˣ�\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("�޴���ϵ�ˣ�\n");
		return(NULL);
		break;
	case 4:
		printf("��������ϵ�绰��");
		scanf("%s", phoneNumber);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->phoneNumber, phoneNumber) == 0)
			{
				printf("�ҵ�����ϵ�ˣ�\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("�޴���ϵ�ˣ�\n");
		return(NULL);
		break;
	}
}


void glanceContacts()
{
	int select;
	struct Person* pTemp;
	printf("..........�˵�..........\n");
	printf("1.�����˳���ǰ����\n");
	printf("2.�����˳��Ӻ���ǰ\n");
	printf("��ѡ����ʾ��ʽ��\n");
	printf("........................\n");
	scanf("%d", &select);
	printf("ͨ��¼����Ϣ����..............\n");
	printf("����\t\t\t����\t\t\t��ע\t\t\t��ϵ�绰\n");
	printf("----------------------------------------------------------------------------------\n");
	switch (select)
	{
	case 1:
		pTemp = pHead_1;
		while (pTemp != NULL)
		{
			printf("%s\t\t\t%s\t\t%s\t\t\t%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
			pTemp = pTemp->pNext;
		}
		break;
	case 2:
		pTemp = pHead_1;
		while (pTemp != NULL)
		{
			struct Person* p1 = creatList_way2();
			strcpy(p1->name, pTemp->name);
			strcpy(p1->birthday,pTemp->birthday);
			strcpy(p1->remarks,pTemp->remarks);
			strcpy(p1->phoneNumber,pTemp->phoneNumber);
			pTemp = pTemp->pNext;
		}
		pTemp = pHead_2;
		while (pTemp != NULL)
		{
			printf("%s\t\t\t%s\t\t%s\t\t\t%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
			pTemp = pTemp->pNext;
		}
		cleanList_2();
		break;
	}
	printf("----------------------------------------------------------------------------------\n");
}  


void openFile_way1()
{
	if ((fp = fopen("D:\\visualStudio2017\\ͨ��¼.txt", "a+")) == NULL)
	{
		printf("��ͨ��¼ʧ�ܣ�\n");
		exit(0);
	}
}


void openFile_way2()
{
	if ((fp = fopen("D:\\visualStudio2017\\ͨ��¼.txt", "w")) == NULL)
	{
		printf("��ͨ��¼ʧ�ܣ�\n");
		exit(0);
	}
}


void saveContactsToListFromFile()
{
	char name[20];
	char birthday[20];
	char remarks[20];
	char phoneNumber[20];
	openFile_way1();
	while(fscanf(fp,"%s%s%s%s",name,birthday,remarks,phoneNumber) != EOF)
	{
		struct Person* pTemp = creatList_way1();
		strcpy(pTemp->name, name);
		strcpy(pTemp->birthday,birthday);
		strcpy(pTemp->remarks, remarks);
		strcpy(pTemp->phoneNumber, phoneNumber);
	}
	fclose(fp);
}


void saveContactsToFileFromList()
{
	struct Person* pTemp = pHead_1;
	openFile_way2();
	while (pTemp != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
		pTemp = pTemp->pNext;
	}
	fclose(fp);
}

struct Person* creatList_way1()
{
	struct Person* pTemp = (struct Person*)malloc(sizeof(struct Person));
	pTemp->pNext = NULL;
	if (pHead_1 == NULL)
	{
		pHead_1 = pTemp;
		pEnd_1 = pTemp;
	}
	else
	{
		pEnd_1->pNext = pTemp;
		pEnd_1 = pTemp;
	}
	return(pTemp);
}

struct Person* creatList_way2()
{
	struct Person* pTemp = (struct Person*)malloc(sizeof(struct Person));
	pTemp->pNext = NULL;
	if (pHead_2 == NULL)
	{
		pHead_2 = pTemp;
		pEnd_2 = pTemp;
	}
	else
	{
		pTemp->pNext = pHead_2;
		pHead_2 = pTemp;
	}
	return(pTemp);
}


void cleanList_1()
{
	struct Person* pTemp = pHead_1;
	while (pTemp != NULL)
	{
		struct Person* pt = pTemp;
		pTemp = pTemp->pNext;
		free(pt);
		pt = NULL;
	}
	pHead_1 = NULL;
	pEnd_1 = NULL;
}

void cleanList_2()
{
	struct Person* pTemp = pHead_2;
	while (pTemp != NULL)
	{
		struct Person* pt = pTemp;
		pTemp = pTemp->pNext;
		free(pt);
		pt = NULL;
	}
	pHead_2 = NULL;
	pEnd_2 = NULL;
}