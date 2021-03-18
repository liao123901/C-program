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
				printf("输入回车返回主菜单............\n");
				getchar();
				break;
			case 2:
				system("cls");
				printf("请先查找你需要更改的联系人.......\n");
				changeContacts(findContacts());
				printf("输入回车返回主菜单............\n");
				getchar();
				break;
			case 3:
				system("cls");
				printf("请先查找你需要删除的联系人.......\n");

				deleteContacts(findContacts());
				printf("输入回车返回主菜单............\n");
				getchar();
				break;
			case 4:
				system("cls");
				struct Person* pTemp;
				pTemp=findContacts();
				if(pTemp != NULL)
				{
					printf("该联系人全部信息如下：\n");
					printf("姓名：%s\t生日：%s\t备注：%s\t联系电话：%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
				}
				printf("输入回车返回主菜单............\n");
				getchar();
				break;
			case 5:
				system("cls");
				glanceContacts();
				printf("输入回车返回主菜单............\n");
				getchar();
				break;
			default:
				system("cls");
				printf("输入错误，输入回车返回主菜单重新选择！");
				getchar();
				break;
			}
			Sleep(2000);
			getchar();
			system("cls");
			printf("请选择接下来的操作.....\n");  
		}
		else
			if (choose == 6)
			{
				printf("正在退出..............\n");
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
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>主菜单<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("                                                                       \n");
	printf("                                  欢迎!                                \n");
	printf("                                                                       \n");
	printf("                          【个人通讯录管理系统】                       \n");
	printf("                                                                       \n");
	printf("                      1.添加联系人       2.更改联系人                  \n");
	printf("                                                                       \n");
	printf("                      3.删除联系人       4.查找联系人                  \n");
	printf("                                                                       \n");
	printf("                      5.浏览             6.退出系统                    \n");
	printf("                                                                       \n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("-----------------------------------------------------------------------\n");
	printf("                             *请选择功能:");
}


void addContacts()
{
	struct Person*pTemp;
	pTemp = creatList_way1();
	printf("开始添加.........\n");
	printf("请输入姓名：\n");
	scanf("%s", pTemp->name);
	printf("请输入生日：\n");
	scanf("%s", pTemp->birthday);
	printf("请输入备注：\n");
	scanf("%s", pTemp->remarks);
	printf("请输入电话号码：\n");
	scanf("%s", pTemp->phoneNumber);
	openFile_way1();
	fprintf(fp, "%s\t%s\t%s\t%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
	fclose(fp);
	printf("添加联系人成功！\n ");
	printf("该联系人全部信息如下：\n");
	printf("姓名：%s\t生日：%s\t备注：%s\t联系电话：%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
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
		printf("请重新查找!\n");
	}
	else
	{
		printf("该联系人全部信息如下：\n");
		printf("姓名：%s\t生日：%s\t备注：%s\t联系电话：%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
		strcpy(name, pTemp->name);
		strcpy(birthday, pTemp->birthday);
		strcpy(remarks, pTemp->remarks);
		strcpy(phoneNumber, pTemp->phoneNumber);
		printf("........菜单........\n");
		printf("1.姓名\n");
		printf("2.生日\n");
		printf("3.备注\n");
		printf("4.联系电话\n");
		printf("请选择需要更改的内容：\n");
		printf("....................\n");
		scanf("%d", &select);
		printf("开始更改.........\n");
		switch (select)
		{
		case 1:
			printf("请输入新的姓名：");
			scanf("%s", pTemp->name);
			if (strcmp(name, pTemp->name) != 0)
				printf("更改成功！\n");
			else
				printf("更改失败，请重试！\n");
			break;
		case 2:
			printf("请输入新的生日：");
			scanf("%s", pTemp->birthday);
			if (strcmp(birthday, pTemp->birthday) != 0)
				printf("更改成功！\n");
			else
				printf("更改失败，请重试！\n");
			break;
		case 3:
			printf("请输入新的备注：");
			scanf("%s", pTemp->remarks);
			if (strcmp(remarks, pTemp->remarks) != 0)
				printf("更改成功！\n");
			else
				printf("更改失败，请重试！\n");
			break;
		case 4:
			printf("请输入新的联系电话：");
			scanf("%s", pTemp->phoneNumber);
			if (strcmp(phoneNumber, pTemp->phoneNumber) != 0)
				printf("更改成功！\n");
			else
				printf("更改失败，请重试！\n");
			break;
		default:
			printf("输入错误，请重试！\n");
		}
		printf("该联系人更改后的全部信息如下：\n");
		printf("姓名：%s\t生日：%s\t备注：%s\t联系电话：%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
		saveContactsToFileFromList();
	}
}


void deleteContacts(struct Person* pTemp)
{
	int select;
	if (pTemp == NULL)
	{
		printf("请重新查找！\n");
	}
	else
	{
		printf("该联系人全部信息如下：\n");
		printf("姓名：%s\t生日：%s\t备注：%s\t联系电话：%s\n", pTemp->name, pTemp->birthday, pTemp->remarks, pTemp->phoneNumber);
		printf("是否确定删除该联系人？（确定输入'1',取消输入'0'）:\n");
		scanf("%d", &select);
		if (select == 1)
		{
			printf("开始删除...........\n");
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
			printf("删除成功！\n");
		}
		else
		{
			printf("已取消！\n");
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
	printf("...........菜单...........\n");
	printf("1.姓名\n");
	printf("2.生日\n");
	printf("3.备注\n");
	printf("4.联系电话\n");
	printf("请选择查找方式：\n");
	printf("..........................\n");
	scanf("%d", &select);
	printf("开始查找.........\n");
	switch (select)
	{
	case 1:
		printf("请输入姓名：");
		scanf("%s", name);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->name, name) == 0)
			{
				printf("找到该联系人！\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("无此联系人！\n");
		return(NULL);
		break;
	case 2:
		printf("请输入生日：");
		scanf("%s", birthday);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->birthday, birthday) == 0)
			{
				printf("找到该联系人！\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("无此联系人！\n");
		return(NULL);
		break;
	case 3:
		printf("请输入备注：");
		scanf("%s", remarks);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->remarks, remarks) == 0)
			{
				printf("找到该联系人！\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("无此联系人！\n");
		return(NULL);
		break;
	case 4:
		printf("请输入联系电话：");
		scanf("%s", phoneNumber);
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->phoneNumber, phoneNumber) == 0)
			{
				printf("找到该联系人！\n");
				return(pTemp);
			}
			pTemp = pTemp->pNext;
		}
		printf("无此联系人！\n");
		return(NULL);
		break;
	}
}


void glanceContacts()
{
	int select;
	struct Person* pTemp;
	printf("..........菜单..........\n");
	printf("1.按添加顺序从前往后\n");
	printf("2.按添加顺序从后往前\n");
	printf("请选择显示方式：\n");
	printf("........................\n");
	scanf("%d", &select);
	printf("通信录的信息如下..............\n");
	printf("姓名\t\t\t生日\t\t\t备注\t\t\t联系电话\n");
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
	if ((fp = fopen("D:\\visualStudio2017\\通信录.txt", "a+")) == NULL)
	{
		printf("打开通信录失败！\n");
		exit(0);
	}
}


void openFile_way2()
{
	if ((fp = fopen("D:\\visualStudio2017\\通信录.txt", "w")) == NULL)
	{
		printf("打开通信录失败！\n");
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