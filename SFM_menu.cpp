#include "Main.h"



void SFM_menu() 
{
  int c = 0;
	int i = 1;
	while (i)
	{
			system("color 20");   
	system("cls"); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN |FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN);
	printf("                      ****※ 员工管理系统 ※****\n"); 
	printf(" =============================================================================\n");
	for (int i = 0; i<21 ;i++)
	{
						printf("*                                                                             *\n");
	}
	printf(" =============================================================================");
	goto_xy(7,6);
	printf("               1.新员工注册          2.员工信息修改\n\n");   
	printf("*\t              3.查询员工信息        4.员工职务调整\n\n");  
	printf("*\t              5.删除员工信息        0.返回主菜单\n\n");   

	goto_xy(10,16);
	printf("请输入你的选择\n>");  
	goto_xy(25,16);
	char choice=getchar();   
        fflush(stdin);   
	switch(choice)
	{
	case '1': 
		newStaff();	
		i=0;
		break;
	case '2':
		char Sid[10];
				system("cls"); 
				printf("                   ****※ 员工管理系统 ※****\n"); 
				printf(" =============================================================================\n");
				for ( c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				  goto_xy(6,7);
		printf("请输入员工号：");
		scanf("%s",Sid);
		changeMessage(Sid);	
		i=0;
		break;

	case '3':
		char Sida[10];
				system("cls"); 
				printf("                   ****※ 员工管理系统 ※****\n"); 
				printf(" =============================================================================\n");
				for ( c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				  goto_xy(6,7);
		printf("请输入员工号：");
		scanf("%s",Sida);
		findStaff(Sida);
		i=0;
		break;
	case '4':
		char Sidb[10];
				system("cls"); 
				printf("                   ****※ 员工管理系统 ※****\n"); 
				printf(" =============================================================================\n");
				for ( c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				  goto_xy(6,7);
		printf("请输入员工号：");
		scanf("%s",Sidb);
		changePosition(Sidb);	
		i=0;
		break;
	case '5':
		char Sidc[10];
				system("cls"); 
				printf("                   ****※ 员工管理系统 ※****\n"); 
				printf(" =============================================================================\n");
				for ( c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				  goto_xy(6,7);
		printf("请输入员工号：");
		scanf("%s",Sidc);
		deleteMessage(Sidc);
		i=0;
		break;
		case  '0':
				return;
				break;

	default:
			system("cls"); 
			printf("                   ****※ 员工管理系统 ※****\n"); 
			printf(" =============================================================================\n");
			for ( c = 0; c<21 ;c++)
			{
					printf("*                                                                             *\n");
			}
			printf(" =============================================================================");
				  goto_xy(6,7);
		printf("输入错误请重新输入");
		getchar();
		break;
	}
	}
	
}

//*********************************新员工信息录入


void newStaff()
{
	long ch = 0;
	char *cName;				//员工姓名
	char *cStaffId;					//员工号
	char *cSex;					//员工性别
	char *cAddress;				//员工住址
	char *cTelephoneNumber;			//员工固话
	char *cPosition;				//员工职务
	char *cEmployTime;				//员工入编时间 例：2014.07.28
	char *cHistoricalWork;	//员工历史工作职务记录
	char *iId;
	char *lPhoneNumber;
	char s[255];
	FILE *fp = NULL;
	staff *p = (staff *)malloc(sizeof(struct staffMessage));
	if(NULL==p)
	{
		printf("内存不足");
	}
	else
	{
			system("cls"); 
			printf("                   ****※ 新建员工信息 ※****\n"); 
			printf(" =============================================================================\n");
			for (int i = 0; i<21 ;i++)
			{
					printf("*                                                                             *\n");
			}
			printf(" =============================================================================");
	goto_xy(6,7);
		printf("*\t请输入员工姓名");
		scanf("%s",p->cName);
		printf("*\t请输入员工号");
		scanf("%s",p->cStaffId);
		printf("*\t请输入员工性别");
		scanf("%s",p->cSex);
		printf("*\t请输入员工年龄");
		scanf("%i",&p->iAge);
		printf("*\t请输入员工身份证号");
		scanf("%s",p->iId);
		printf("*\t请输入员工地址");
		getchar();
		gets(p->cAddress);
		printf("*\t请输入员工手机号");
		scanf("%s",p->lPhoneNumber);
		printf("*\t请输入员工固定电话号码");
		scanf("%s",p->cTelephoneNumber);
		printf("*\t请输入员工工资");
		scanf("%i",&p->iLaborage);
		printf("*\t请输入员工职务");
		scanf("%s",p->cPosition);
		printf("*\t请输入员工入编时间");
		scanf("%s",p->cEmployTime);
		printf("*\t请输入员工工作记录");
		scanf("%s",p->cHistoricalWork);
	//将文件名设置为员工号
		sprintf(s, "%s.txt", p->cStaffId);
	//创建文件	
		fp=fopen(s,"a");
	//将员工数据存入文件
		cName = p->cName;
		fprintf(fp,"%s\n",cName);
		cStaffId = p->cStaffId;
		fprintf(fp,"%s\n",cStaffId);
		cSex = p->cSex;
		fprintf(fp,"%s\n",cSex);
		ch = p->iAge;
		fprintf(fp,"%d\n",ch);
		iId = p->iId;
		fprintf(fp,"%s\n",iId);
		cAddress = p->cAddress;
		fprintf(fp,"%s\n",cAddress);
		lPhoneNumber = p->lPhoneNumber;
		fprintf(fp,"%s\n",lPhoneNumber);
		cTelephoneNumber = p->cTelephoneNumber;
		fprintf(fp,"%s\n",cTelephoneNumber);
		ch = p->iLaborage;
		fprintf(fp,"%d\n",ch);
		cPosition = p->cPosition;
		fprintf(fp,"%s\n",cPosition);
		cEmployTime = p->cEmployTime;
		fprintf(fp,"%s\n",cEmployTime);
		cHistoricalWork = p->cHistoricalWork;
		fprintf(fp,"%s\n",cHistoricalWork);
		
	//关闭文件
		int a = fclose(fp);
		if (a != 0)
		{
				system("cls"); 
				printf("                   ****※ 新建员工信息 ※****\n"); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(10,15);
				printf("文件关闭异常\n");
				getchar();
				return;
		}
				system("cls"); 
				printf("                   ****※ 新建员工信息 ※****\n"); 
				printf(" =============================================================================\n");
				for (int c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(10,15);
		printf("员工注册成功");
		getchar();
	//释放内存
		free(p);
		p = NULL;
	}
	getchar();
	return;
}

//*************************************员工信息更改

void changeMessage(char x[])
{
	char cName[30];				//员工姓名
	char cStaffId[10];					//员工号
	char cSex[3];					//员工性别
	int iAge;						//员工年龄
	char iId;							//员工身份证号
	char cAddress[120];				//员工住址
	char lPhoneNumber;					//员工手机号
	char cTelephoneNumber[14];			//员工固话
	int iLaborage;			//员工工资
	char cPosition[20];				//员工职务
	char cEmployTime[11];				//员工入编时间 例：2014.07.28
	char cHistoricalWork[120];
	
	int c = 0;
	char m = '\0';
	char ch = '0';
	char s[255];
	sprintf(s, "%s.txt", x);
	FILE *fp;
	staff *f = (staff *)malloc(sizeof(staff));
	if(NULL==f)
	{
																																																									system("cls"); 
																																																									printf("                   ****※ 员工信息更改 ※****\n"); 
																																																									printf(" =============================================================================\n");
																																																									for ( c = 0; c<21 ;c++)
																																																									{
																																																											printf("*                                                                             *\n");
																																																									}
																																																									printf(" =============================================================================");
																																																										goto_xy(6,7);
		printf("内存不足");
		getchar();
	}
	else
	{
		fp = fopen(s,"r");
		if (fp==NULL) 
		{
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for (c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("未找到员工信息\n");
			getchar();
			getchar();
			return;
		}
		else
		{
		fscanf(fp,"%s",f->cName);
		fscanf(fp,"%s",f->cStaffId);
		fscanf(fp,"%s",f->cSex);
		fscanf(fp,"%d",&f->iAge);
		fscanf(fp,"%s",f->iId);
		fscanf(fp,"%s",f->cAddress);
		fscanf(fp,"%s",f->lPhoneNumber);
		fscanf(fp,"%s",f->cTelephoneNumber);
		fscanf(fp,"%d",&f->iLaborage);
		fscanf(fp,"%s",f->cPosition);
		fscanf(fp,"%s",f->cEmployTime);
		fscanf(fp,"%s",f->cHistoricalWork);
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for ( c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

		printf("请输入需要更改的信息\n");
		printf("*\t1:员工姓名\n*\t2:员工性别\n*\t3:员工年龄\n*\t4:员工身份证号\n*\t5:员工住址\n*\t6:员工手机号\n");
		printf("*\t7:员工固定电话号\n*\t8:员工工资\n*\t9:员工入编时间\n*\t10:员工历史工作记录\n");
		printf("*\t选择为：");
		getchar();
		//scanf("%c",&m);
		m = getchar();
		switch (m)
		{
		case '1':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for ( c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新姓名：");
			scanf("%s",f->cName);
			getchar();
			break;
		case '2':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for ( c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新性别：");
			scanf("%s",f->cSex);
			getchar();
			break;
		case '3':
																																																										system("cls"); 
																																																										printf("                   ****※ 员工信息更改 ※****\n"); 
																																																										printf(" =============================================================================\n");
																																																										for (c = 0; c<21 ;c++)
																																																										{
																																																												printf("*                                                                             *\n");
																																																										}
																																																										printf(" =============================================================================");
																																																										goto_xy(6,7);

			printf("请输入新年龄：");
			scanf("%d",&f->iAge);
			getchar();
			break;
		case '4':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for ( c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新身份证号：");
			scanf("%s",f->iId);
			getchar();
			break;
		case '5':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for ( c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新住址：");
			scanf("%s",f->cAddress);
			getchar();
			break;
		case '6':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for (c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新手机号码：");
			scanf("%s",f->lPhoneNumber);
			getchar();
			break;
		case '7':
																																																										system("cls"); 
																																																										printf("                   ****※ 员工信息更改 ※****\n"); 
																																																										printf(" =============================================================================\n");
																																																										for ( c = 0; c<21 ;c++)
																																																										{
																																																												printf("*                                                                             *\n");
																																																										}
																																																										printf(" =============================================================================");
																																																										goto_xy(6,7);

			printf("请输入新固定电话：");
			scanf("%s",f->cTelephoneNumber);
			getchar();
			break;
		case '8':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for (c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新工资：");
			scanf("%d",&f->iLaborage);
			getchar();
			break;
		case '9':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for (c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新入编时间：");
			scanf("%s",f->cName);
			getchar();
			break;
		case '10':
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for (c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("请输入新工作记录：");
			scanf("%s",f->cHistoricalWork);
			getchar();
			break;
		default:{
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for (c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("hh输入错误请重新输入\n");
						getchar();
			
			break;}
		}
		int a = fclose(fp);
		if (a != 0)
		{
																																																										system("cls"); 
																																																										printf("                   ****※ 员工信息更改 ※****\n"); 
																																																										printf(" =============================================================================\n");
																																																										for (c = 0; c<21 ;c++)
																																																										{
																																																												printf("*                                                                             *\n");
																																																										}
																																																										printf(" =============================================================================");
																																																										goto_xy(6,7);

			printf("文件关闭异常\n");
			getchar();
			return;
		}
		FILE *p = fopen(s,"w");
		fprintf(p,"%s\n",f->cName);
		fprintf(p,"%s\n",f->cStaffId);
		fprintf(p,"%s\n",f->cSex);
		fprintf(p,"%d\n",f->iAge);
		fprintf(p,"%s\n",f->iId);
		fprintf(p,"%s\n",f->cAddress);
		fprintf(p,"%s\n",f->lPhoneNumber);
		fprintf(p,"%s\n",f->cTelephoneNumber);
		fprintf(p,"%d\n",f->iLaborage);
		fprintf(p,"%s\n",f->cPosition);
		fprintf(p,"%s\n",f->cEmployTime);
		fprintf(p,"%s\n",f->cHistoricalWork);
		int b = fclose(p);
		if (b != 0)
		{
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息更改 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for ( c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);

			printf("文件关闭异常\n");
						getchar();
			return;
		}
		}	
		
		
	}
}


//*************************查询员工信息

void findStaff(char x[])
{
	int c = 0;
	char ch = '0';
	char s[255];
	FILE *fp;

	sprintf(s, "%s.txt", x);
	fp = fopen(s,"r");
	getchar();

	if (NULL == fp) 
	{
																																																									system("cls"); 
																																																									printf("                   ****※ 员工信息查询 ※****\n"); 
																																																									printf(" =============================================================================\n");
																																																									for ( c = 0; c<21 ;c++)
																																																									{
																																																											printf("*                                                                             *\n");
																																																									}
																																																									printf(" =============================================================================");
																																																									goto_xy(12,7);
		printf("未找到员工信息！\n");
		getchar();
			return;
	}
	else
	{
		staff *message = (staff *)malloc(sizeof(staff));
		
		fscanf(fp,"%s",message->cName);
		fscanf(fp,"%s",message->cStaffId);
		fscanf(fp,"%s",message->cSex);
		fscanf(fp,"%d",&message->iAge);
		fscanf(fp,"%s",message->iId);
		fscanf(fp,"%s",message->cAddress);
		fscanf(fp,"%s",message->lPhoneNumber);
		fscanf(fp,"%s",message->cTelephoneNumber);
		fscanf(fp,"%d",&message->iLaborage);
		fscanf(fp,"%s",message->cPosition);
		fscanf(fp,"%s",message->cEmployTime);
		fscanf(fp,"%s",message->cHistoricalWork);
																																																								system("cls"); 
																																																								printf("                   ****※ 员工信息查询 ※****\n"); 
																																																								printf(" =============================================================================\n");
																																																								for ( c = 0; c<21 ;c++)
																																																								{
																																																										printf("*                                                                             *\n");
																																																								}
																																																								printf(" =============================================================================");
																																																								goto_xy(6,7);
		printf("*\t姓名：%s\n",message->cName);
		printf("*\t员工号：%s\n",message->cStaffId);
		printf("*\t性别：%s\n",message->cSex);
		printf("*\t年龄：%d\n",message->iAge);
		printf("*\t身份证号：%s\n",message->iId);
		printf("*\t住址：%s\n",message->cAddress);
		printf("*\t手机号：%s\n",message->lPhoneNumber);
		printf("*\t固定电话：%s\n",message->cTelephoneNumber);
		printf("*\t工资：%d\n",message->iLaborage);
		printf("*\t职务：%s\n",message->cPosition);
		printf("*\t入编时间：%s\n",message->cEmployTime);
		printf("*\t工作记录：%s\n",message->cHistoricalWork);
			getchar();
			getchar();
			return;
				
		
		int a = fclose(fp);
		if (a != 0)
		{
			system("cls"); 
			printf("                   ****※ 员工信息查询 ※****\n"); 
			printf(" =============================================================================\n");
			for ( c = 0; c<21 ;c++)
			{
						printf("*                                                                             *\n");
			}
			printf(" =============================================================================");
			goto_xy(6,7);
			printf("文件关闭异常\n");
			getchar();
			return;
		}

	}
	
}
//***********************调换员工职务*********************************//

void changePosition(char x[])
{
	char cName[30];				//员工姓名
	char cStaffId[10];					//员工号
	char cSex[3];					//员工性别
	int iAge;						//员工年龄
	char iId;							//员工身份证号
	char cAddress[120];				//员工住址
	char lPhoneNumber;					//员工手机号
	char cTelephoneNumber[14];			//员工固话
	int iLaborage;			//员工工资
	char cPosition[20];				//员工职务
	char cEmployTime[11];				//员工入编时间 例：2014.07.28
	char cHistoricalWork[120];

	int m = 0, c = 0;
	char ch = '0';
	char s[255];
	sprintf(s, "%s.txt", x);
	FILE *fp;
	staff *f = (staff *)malloc(sizeof(staff));
	if(NULL==f)
	{
			system("cls"); 
			printf("                   ****※ 员工职务变更 ※****\n"); 
			printf(" =============================================================================\n");
			for ( c = 0; c<21 ;c++)
			{
					printf("*                                                                             *\n");
			}
			printf(" =============================================================================");
				goto_xy(6,7);
		printf("内存不足");
	}
	else
	{
		fp = fopen(s,"r");
		if (fp==NULL) 
		{
				system("cls"); 
				printf("                   ****※ 员工职务变更 ※****\n"); 
				printf(" =============================================================================\n");
				for ( c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(6,7);
			printf("未找到员工信息\n");
		}
		else
		{
		fscanf(fp,"%s",f->cName);
		fscanf(fp,"%s",f->cStaffId);
		fscanf(fp,"%s",f->cSex);
		fscanf(fp,"%d",&f->iAge);
		fscanf(fp,"%s",f->iId);
		fscanf(fp,"%s",f->cAddress);
		fscanf(fp,"%s",f->lPhoneNumber);
		fscanf(fp,"%s",f->cTelephoneNumber);
		fscanf(fp,"%d",&f->iLaborage);
		fscanf(fp,"%s",f->cPosition);
		fscanf(fp,"%s",f->cEmployTime);
		fscanf(fp,"%s",f->cHistoricalWork);
		system("cls"); 
		printf("                   ****※ 员工职务变更 ※****\n"); 
		printf(" =============================================================================\n");
		for ( c = 0; c<21 ;c++)
		{
				printf("*                                                                             *\n");
		}
		printf(" =============================================================================");
				goto_xy(6,7);
		printf("请输入更改后的职务：");
		scanf("%s",f->cPosition);	
		system("cls"); 
		printf("                   ****※ 员工职务变更 ※****\n"); 
		printf(" =============================================================================\n");
		for ( c = 0; c<21 ;c++)
		{
				printf("*                                                                             *\n");
		}
		printf(" =============================================================================");
				goto_xy(6,7);
		printf("职务修改成功！\n");
		getchar();
		getchar();
	
		int a = fclose(fp);
		if (a != 0)
		{
				system("cls"); 
				printf("                   ****※ 员工职务变更 ※****\n"); 
				printf(" =============================================================================\n");
				for ( c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(6,7);
			printf("文件关闭异常\n");
			getchar();
				return;
		}
		FILE *p = fopen(s,"w");
		fprintf(p,"%s\n",f->cName);
		fprintf(p,"%s\n",f->cStaffId);
		fprintf(p,"%s\n",f->cSex);
		fprintf(p,"%d\n",f->iAge);
		fprintf(p,"%s\n",f->iId);
		fprintf(p,"%s\n",f->cAddress);
		fprintf(p,"%s\n",f->lPhoneNumber);
		fprintf(p,"%s\n",f->cTelephoneNumber);
		fprintf(p,"%d\n",f->iLaborage);
		fprintf(p,"%s\n",f->cPosition);
		fprintf(p,"%s\n",f->cEmployTime);
		fprintf(p,"%s\n",f->cHistoricalWork);
		int b = fclose(p);
		if (b != 0)
		{
				system("cls"); 
				printf("                   ****※ 员工职务变更 ※****\n"); 
				printf(" =============================================================================\n");
				for ( c = 0; c<21 ;c++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(6,7);
			printf("文件关闭异常\n");
			getchar();
				return;
		}
		return;
		}	
		
		
	}	
		
}

//***********************删除员工信息*************************************//

void deleteMessage(char x[])
{
	char s[255];
	int c = 0;
	sprintf(s, "%s.txt", x);
//	getchar();
	int a = remove(s);
	if(a==0)
	{
			system("cls"); 
			printf("                   ****※ 员工信息查询 ※****\n"); 
			printf(" =============================================================================\n");
			for ( c = 0; c<21 ;c++)
			{
					printf("*                                                                             *\n");
			}
			printf(" =============================================================================");
				goto_xy(6,7);
		printf("员工删除成功\n");
				getchar();
					getchar();
		return;
	}
	else 
	{
			system("cls"); 
			printf("                   ****※ 员工信息查询 ※****\n"); 
			printf(" =============================================================================\n");
			for ( c = 0; c<21 ;c++)
			{
					printf("*                                                                             *\n");
			}
			printf(" =============================================================================");
				goto_xy(6,7);
		printf("员工删除成功\n");
		getchar();
		getchar();
		return;
	}
}
