#include "Main.h"

/*
*提供给主菜单的子菜单接口函数
*/

	
void SLM_menu()
{
  int c = 0;
	int i = 1;
	while (i)
	{

				system("color 20");   
				system("cls"); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN |FOREGROUND_INTENSITY |
				FOREGROUND_RED | FOREGROUND_GREEN);
				printf("                      ****※ 销售管理系统 ※****\n"); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
				printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(7,6);
				printf("               1.新建销售单         2.销售单维护\n\n");   
			printf("*\t              3.销售记录查询       0.返回主菜单\n\n");  

			goto_xy(10,16);
			printf("请输入你的选择\n>");  
			goto_xy(25,16);
			char choice=getchar();   
			fflush(stdin);   
			
			switch(choice)   
			{   
			case '1' :   
					system("cls");  
					SLM_CreateSaleList();
					break ;   
			case '2' :   
					system("cls");
					SLM_submenu1();
					break ;   
			case '3' :   
					
					system("cls"); 
					SLM_submenu2();
					break ;   
					
			case '0' : 
					{ 
							return;
					}  
			default : 
					{
							system("cls");
							
							printf("                   ****※ 销售管理系统 ※****\n"); 
							
							printf(" =============================================================================\n");
							for (int i = 0; i<21 ;i++)
							{
									printf("*                                                                             *\n");
							}
							printf(" =============================================================================");
							goto_xy(30,8);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE |
									FOREGROUND_RED | FOREGROUND_GREEN);
							printf("输入有误，请按照序号选择！\n\n\n\n");   
							printf("*  \t\t\t\t按下任意键返回重新输入");
							getch();   
					}
					
        }   
	}

}

void SLM_submenu1()
{
		int c = 0;
		int i = 1;
		while (i)
		{
				
				system("color 20");   
				system("cls"); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN |FOREGROUND_INTENSITY |
						FOREGROUND_RED | FOREGROUND_GREEN);
				printf("                       ****※ 销售单维护 ※****\n"); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(7,10);
				printf(" 1.添加遗漏商品至历史销售单      2.修改商品销售数量至历史销售单\n\n"); 
				goto_xy(7,12);
				printf(" 0.返回上层菜单       \n\n"); 
		
				
				goto_xy(10,16);
				printf("请输入你的选择\n>");  
				goto_xy(25,16);
				char choice=getchar();   
				fflush(stdin);   
				
				switch(choice)   
				{   
				case '1' :   
						system("cls"); 
						SLM_AddProductToSoldList();
						break ;   
				case '2' :   
						system("cls");
						SLM_AlterProductAmountToSoldList();

						break ;     				
				case '0' : 
						{ 
								return;
						}  
				default : 
						{
								system("cls");
								
								printf("                   ****※ 销售单维护 ※****\n"); 
								
								printf(" =============================================================================\n");
								for (int i = 0; i<21 ;i++)
								{
										printf("*                                                                             *\n");
								}
								printf(" =============================================================================");
								goto_xy(30,8);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE |
										FOREGROUND_RED | FOREGROUND_GREEN);
								printf("输入有误，请按照序号选择！\n\n\n\n");   
								printf("*  \t\t\t\t按下任意键返回重新输入");
								getch();   
						}
						
        }   
	}

}
void SLM_submenu2()
{
		int c = 0;
		int i = 1;
		while (i)
		{
				
				system("color 20");   
				system("cls"); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN |FOREGROUND_INTENSITY |
						FOREGROUND_RED | FOREGROUND_GREEN);
				printf("                      ****※ 销售记录查询 ※****\n"); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(7,8);
				printf("          1.按照日期时间查询详单         2.查询商品单品进货记录\n\n");
				goto_xy(7,12);
				printf("          3.销售盘点                     0.返回上层菜单       \n\n"); 
				
				
				goto_xy(10,16);
				printf("请输入你的选择\n>");  
				goto_xy(25,16);
				char choice=getchar();   
				fflush(stdin);   
				
				switch(choice)   
				{   
				case '1' :   
						system("cls");  
						SLM_PrintSoldListByTime();
      
						break ;   
				case '2' :   
						system("cls");
						SLM_PrintSoldListByProduct();
						break ;   
				case '3' :   
						system("cls");
						SLM_CheckSoldList();
						break ;  
				case '0' : 
						{ 
								return;
						}  
				default : 
						{
								system("cls");
								
								printf("                   ****※ 销售记录查询 ※****\n"); 
								
								printf(" =============================================================================\n");
								for (int i = 0; i<21 ;i++)
								{
										printf("*                                                                             *\n");
								}
								printf(" =============================================================================");
								goto_xy(30,8);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE |
										FOREGROUND_RED | FOREGROUND_GREEN);
								printf("输入有误，请按照序号选择！\n\n\n\n");   
								printf("*  \t\t\t\t按下任意键返回重新输入");
								getch();   
						}
						
        }   
	}
}



//内部函数

/*
** 调用这个进入新销售单扫入过程 
**
*/
pPFS CreateSaleList()    
{
    //要有个链表的root节点传出
    pPFS Root = (pPFS)malloc(sizeof(PFS));
    return Root;
}

float EnteringSaleList(pPFS psRoot)		//提示用户输入要输入的销售单 并提示输入规范
{
    FILE* pfListgivenByUser = NULL;		//用户提供的销售单的指针
    FILE* pfPurchaseList = NULL;		//销售单文件指针
    pPFS psCurrent = NULL;				//新建的一个节点
    pPFS psLast = NULL;					//上一个节点
    char acListgivenByUser[20] = "";	//保存用户提供的销售单文件名
    char acPath[255] = "";              //保存用户桌面路径
    int iPathLength = 0;				//保存用户桌面路径长度
    char acSaleListNumber[10] = "";			//销售单号
	float fSaleListWipe = 0.0f;			//销售单抹零数额
	char acSaleListTime[11] = "";		//销售的时间
	
	psCurrent= (pPFS)malloc(sizeof(PFS));
	if (NULL == psCurrent)
	{
		puts("电脑内存不足，请释放内存后重新进行此操作");
		system("pause");
	}
	psRoot->psNext = psCurrent;
    psLast = psRoot;
	
    
    //提示用户销售单文件输入范例
	printf("---------------------------------------------------------------------\n");
	puts("\t请确认已录入的文件格式如下所示并已保存至桌面：\n");
	puts("\t- 销售单号 销售时间");
	puts("\t商品编号 数量 销售价");
	puts("\t商品编号 数量 销售价");
	puts("\t...");
	puts("\t...");
	puts("\t= 抹零\n");
	printf("---------------------------------------------------------------------\n");

	//提示用户输入销售单文件文件名并处理为字符串常量
    puts("\n\n\t现在请键入销售单文件名：");
    gets(acListgivenByUser);

    //获得用户销售单文件绝对路径
    SHGetSpecialFolderPath(0,acPath,CSIDL_DESKTOPDIRECTORY,0);				//获取用户桌面路径
    iPathLength = strlen(acPath);                                           //求路径长
    sprintf(acPath + iPathLength,"\\%s",acListgivenByUser);                 //插入文件单名


    //打开用户提供的销售单文件
    pfListgivenByUser = fopen(acPath,"r");

    if (NULL == pfListgivenByUser)
    {
        puts("没有找到该文件，请重新确认");
    } 

    

    //下面按照格式读取文件内每个字符 分析后将开始将进货信息依次链入链表结尾
    for(;;)
    {
        if (EOF == fscanf(pfListgivenByUser,"%s",psCurrent->acProductNumber))
		{
			break;
		} 
        
        
        if('-' == psCurrent->acProductNumber[0] )
        {
            fscanf(pfListgivenByUser,"%s",acSaleListNumber);
			fscanf(pfListgivenByUser,"%s",acSaleListTime);
        }
		else if ('=' == psCurrent->acProductNumber[0])   //这块很乱 得整理
		{
			
			fscanf(pfListgivenByUser,"%f",&fSaleListWipe);
		} 
		else
		{
			fscanf(pfListgivenByUser,"%d",&psCurrent->iSaleAmount);		//获得卖出数量 
			fscanf(pfListgivenByUser,"%f",&psCurrent->fSalePrice);		//获得售价
			strcpy(psCurrent->acSaleListNumber,acSaleListNumber);		//将商品售出所在销售单存入节点
			strcpy(psCurrent->acSaleDate,acSaleListTime);				//将商品售出时间存入节点
			psCurrent->fMoneyAmount = psCurrent->fSalePrice * psCurrent->iSaleAmount;	//计算总价
			
			//新建节点，向下移动部分				
			psLast = psCurrent;
			
			psCurrent = (pPFS)malloc(sizeof(PFS));
			if (NULL == psCurrent)
			{
				puts("电脑内存不足，请释放内存后重新进行此操作");
				system("pause");
			}
			psLast->psNext = psCurrent;

		}
		

    }
	psCurrent->psNext = NULL;
	fclose(pfListgivenByUser);
	return fSaleListWipe;
}

void AlterStock(pPFS psRoot) 
{
    pPFS psCurrent = NULL;			//要做遍历用的一个节点指针
    //FILE* pfOrderPlan = NULL;		//获得销售单文件的指针


	psCurrent = psRoot->psNext;
    //下面自PFP文件的ROOT节点开始依次读取每一个节点信息；调用STM模块的STM_iChangeProductNumber从库存里删去相应数量
	
	while (NULL != psCurrent->psNext)
	{	
		if(-1 == STM_ChangeProductNumber(psCurrent->acProductNumber,-(psCurrent->iSaleAmount)) ) 
		{
			printf("库存文件中没有商品编号为%s的商品记录\n",psCurrent->acProductNumber);
		}
		psCurrent = psCurrent->psNext;
	}
    //可以做一个商品编号与商品名称的比对,先搁置
    
}

void SaveSoldListToFile(pPFS psRoot,float fSaleListWipe)
{
    pPFS psCurrent = NULL;				//要做遍历用的一个节点指针
    FILE* pfSoldList = NULL;			//获得销售历史文件指针
	float  fMoneyInAll = 0.0f;
    pfSoldList = fopen("SoldList.txt","a");
	psCurrent = psRoot->psNext;
    //下面自PFS链表的ROOT节点开始依次读取每一个节点信息，存入存档文件
	fprintf(pfSoldList,"- %s %s\n",psCurrent->acSaleListNumber,psCurrent->acSaleDate);
	while (NULL != psCurrent->psNext)
	{
		fMoneyInAll += psCurrent->fMoneyAmount;
		fprintf(pfSoldList,"\\ %s %s %d %f\n",psCurrent->acProductNumber,STM_SearchProductProductName(psCurrent->acProductNumber), psCurrent->iSaleAmount,psCurrent->fMoneyAmount);
		psCurrent = psCurrent->psNext;
	}
	fprintf(pfSoldList,"= %f %f %s -\n",fMoneyInAll,fSaleListWipe,SL_NAME); //这块要改
    fclose(pfSoldList);
}

/*
** 释放销售单指针 //未测试本函数 14.56
*/
void FreePFS(pPFS psRoot)
{
	pPFS psCurrent = NULL;			//要做遍历用的一个节点指针
	psCurrent = psRoot->psNext;
	while (NULL != psCurrent->psNext)
	{
		free(psRoot);
		psRoot = psCurrent;
		psCurrent = psCurrent->psNext;
	}
	free(psRoot);
	free(psCurrent);
	psRoot = NULL;
	psCurrent = NULL;
}



//外部接口（4个）






/*
** 开始新销售单录入 
**
*/
void SLM_CreateSaleList()    
{
	float fSaleListWipe = 0.0f;
	//调用内部模块的CreateSaleList函数
    pPFS Root = CreateSaleList();
    //调用内部模块的EnteringSaleList函数
    fSaleListWipe = EnteringSaleList(Root);
	//调用内部模块的AlterStock函数
	AlterStock(Root);
	//调用内部模块的SaveSoldListToFile函数
	SaveSoldListToFile(Root,fSaleListWipe);
	FreePFS(Root);
	
	puts("录入已完成,谢谢使用");
	getchar();


}






/*
** 输出商品的相应销售详单 
**
*/
void SLM_PrintSoldListByProduct()
{
	char acProductNumber[6];
	char acProductName[40];
	char acTempProductName[40];
	
	FILE* pfSoldList = NULL;		//文件指针
	char cTypeSign = '\0';				//类型判断
	char acSaleListNumber[10] = "";;
	float fMoneyInAll = 0.0f;
	float fSaleListWipe = 0.0f;
	char acUser[20];
	char acUserC[20];
	char cTemp[300];
	char acPath[255] = "";              //保存用户桌面路径
	int iPathLength = 0;				//保存用户桌面路径长度
	PFS sTemp;
	int iSoldInAll = 0;					//总进货数计数器
	float fSoldInAll = 0.0f;			//总进货金额计数器
	FILE* pfListPrinting = NULL;
	int iMark = 0;
	//让用户输入商品编号或商品名称
	puts("请输入商品编号或商品名称");
	gets(acTempProductName);
	
	//获得用户桌面文件绝对路径
	SHGetSpecialFolderPath(0, acPath, CSIDL_DESKTOPDIRECTORY, 0);			//获取用户桌面路径
	iPathLength = strlen(acPath);                                           //求路径长
	sprintf(acPath + iPathLength, "\\销售清单_%s.txt", acTempProductName);	//得出将要保存的文件
	pfListPrinting = fopen(acPath, "w");
	fprintf(pfListPrinting, "销售时间\t销售数量\t售价\t总金额\t操作用户\t修改用户\n");
	
	//打开进货记录文件
	if (NULL != (pfSoldList = fopen("SoldList.txt", "r")))
	{
		
		//下面按照格式读取文件内每个字符 然后判断修正格式输出
		fscanf(pfSoldList, "%c", &cTypeSign);
		for (;;)
		{ 
			switch (cTypeSign)
			{
			case '-':
				{	iMark = 0;
				fscanf(pfSoldList, "%s", sTemp.acSaleListNumber);
				fscanf(pfSoldList, "%s", sTemp.acSaleDate);
				fgetc(pfSoldList);
				break;
				}
			case '\\':
				{
					fscanf(pfSoldList, "%s", sTemp.acProductNumber);
					fscanf(pfSoldList, "%s", acProductName);
					fscanf(pfSoldList, "%d", &sTemp.iSaleAmount);
					fscanf(pfSoldList, "%f", &sTemp.fSalePrice);
					fgetc(pfSoldList);
					if ((0 == strcmp(acTempProductName, acProductName)) || (0 == strcmp(acTempProductName, sTemp.acProductNumber)))
					{
						fprintf(pfListPrinting, "%s\t", sTemp.acSaleDate);
						fprintf(pfListPrinting, "%d\t\t", sTemp.iSaleAmount);
						iSoldInAll += sTemp.iSaleAmount;
						fprintf(pfListPrinting, "%.2f\t", sTemp.fSalePrice);
						sTemp.fMoneyAmount = sTemp.fSalePrice * sTemp.iSaleAmount;
						fprintf(pfListPrinting, "%.2f\t", sTemp.fMoneyAmount);
						fSoldInAll += sTemp.fMoneyAmount;
						iMark++;
					}	
					break;
				}
			case '=':
				{
					fscanf(pfSoldList, "%f", &fMoneyInAll);
					fscanf(pfSoldList, "%f", &fSaleListWipe);
					fscanf(pfSoldList, "%s\t", acUser);
					fscanf(pfSoldList, "%s", acUserC);
					if (iMark)
					{
						fprintf(pfListPrinting, "%s\t\t", acUser);
						fprintf(pfListPrinting, "%s\n", acUserC);
					}
					fgetc(pfSoldList);
					break;
				}
			default:
				break;
			}
			if (EOF == fscanf(pfSoldList, "%c", &cTypeSign))
			{
				break;
			}
		}
		fprintf(pfSoldList, "共销售：%d", iSoldInAll);
		fprintf(pfSoldList, "\t共收入：%.2f\n", fSoldInAll);
		fclose(pfSoldList);
	}
	fclose(pfListPrinting);
	puts("销售清单已保存至桌面");
	getchar();
	return;
}

/*
** 输出时间段内销售详单
*/
void SLM_PrintSoldListByTime()  		
{
	char acMinSaleDate[11] = "";					//要查询的日期的起点
	char acMaxSaleDate[11] = "";					//要查询的日期的终点
	FILE* pfSoldList = NULL;		//文件指针
	char cTypeSign = '\0';				//类型判断
	char acSaleListNumber[10] = "";
	float fMoneyInAll = 0.0f;
	char acUser[20];
	char acUserC[20];
	char cTemp[300];//////////////////////////////////////////////////////
	char acPath[255] = "";              //保存用户桌面路径
	int iPathLength = 0;				//保存用户桌面路径长度
	PFS sTemp;
	char acProductName[40] = "";
	FILE* pfListPrinting = NULL;
	float fSaleListWipe = 0.0f;


	//获得用户桌面文件绝对路径
	SHGetSpecialFolderPath(0, acPath, CSIDL_DESKTOPDIRECTORY, 0);				//获取用户桌面路径
	iPathLength = strlen(acPath);                                           //求路径长
	strcat(acPath, "\\销售清单.txt");										//得出将要保存的文件

	pfListPrinting = fopen(acPath, "w");
	fprintf(pfListPrinting, "日期\t\t商品编号\t商品名称\t销售数量\t售价\t总金额\n");
	
	//让用户输入起止日期
	puts("请输入起始时间  输入样例 2013.07.05");
	gets(acMinSaleDate);
	puts("请输入截止时间");
	gets(acMaxSaleDate);


	//打开进货记录文件
	if (NULL != (pfSoldList = fopen("SoldList.txt", "r")))
	{

		//下面按照格式读取文件内每个字符 分析后将开始将入库信息依次链入链表结尾
		fscanf(pfSoldList, "%c", &cTypeSign);

		while ('-' == cTypeSign)
		{
			fscanf(pfSoldList, "%s", sTemp.acSaleListNumber);
			fscanf(pfSoldList, "%s", sTemp.acSaleDate);
			fgetc(pfSoldList);
				if ((0 > strcmp(sTemp.acSaleDate, acMaxSaleDate)) || (0 < strcmp(sTemp.acSaleDate, acMinSaleDate)))
				{
					fscanf(pfSoldList, "%c", &cTypeSign);
					do
					{
						fscanf(pfSoldList, "%s", sTemp.acProductNumber);
						fscanf(pfSoldList, "%s", acProductName);
						fscanf(pfSoldList, "%d", &sTemp.iSaleAmount);
						fscanf(pfSoldList, "%f", &sTemp.fSalePrice);
						sTemp.fMoneyAmount = sTemp.fSalePrice * sTemp.iSaleAmount;
						fMoneyInAll += sTemp.fMoneyAmount;
						fprintf(pfListPrinting, "%s\t", sTemp.acSaleDate);
						fprintf(pfListPrinting, "%s\t\t", sTemp.acProductNumber);
						fprintf(pfListPrinting, "%s\t\t", acProductName);
						fprintf(pfListPrinting, "%d\t\t", sTemp.iSaleAmount);
						fprintf(pfListPrinting, "%.2f\t", sTemp.fSalePrice);
						fprintf(pfListPrinting, "%.2f\n", sTemp.fMoneyAmount);
						fgetc(pfSoldList);
						if (EOF == fscanf(pfSoldList, "%c", &cTypeSign))
						{
							break;
						}
					} while ('\\' == cTypeSign);
				}
				fscanf(pfSoldList, "%f", &fSaleListWipe);
				fscanf(pfSoldList, "%f", &fSaleListWipe);
				fscanf(pfSoldList, "%s\t", acUser);
				fscanf(pfSoldList, "%s", acUserC);
				fgetc(pfSoldList);
				fscanf(pfSoldList, "%c", &cTypeSign);
		}
		fclose(pfSoldList);
	}
	fprintf(pfListPrinting, "总销售额：%.2f", fMoneyInAll);
	fclose(pfListPrinting);
	puts("销售清单已保存至桌面");
	getchar();
}

/*
** 销售信息盘点
*/
void SLM_CheckSoldList()				//销售信息盘点
{
	char acMinSaleDate[11] = "";					//要查询的日期的起点
	char acMaxSaleDate[11] = "";					//要查询的日期的终点
	FILE* pfSoldList = NULL;						//文件指针
	char cTypeSign = '\0';							//类型判断
	char acSaleListNumber[10] = "";
	float fMoneyInAll = 0.0f;
	char acUser[20];
	char acUserC[20];
	char acPath[255] = "";              //保存用户桌面路径
	int iPathLength = 0;				//保存用户桌面路径长度
	PFS sTemp;
	char acProductName[40] = "";
	FILE* pfListPrinting = NULL;
	FILE* pfFinalListPrinting = NULL;
	float fSaleListWipe = 0.0f;
	PFS asTemp[1000];
	int i = 0;
	int n = 0;
	int iMark = 0;
	//获得用户桌面文件绝对路径
	SHGetSpecialFolderPath(0, acPath, CSIDL_DESKTOPDIRECTORY, 0);				//获取用户桌面路径
	iPathLength = strlen(acPath);                                           //求路径长
	strcat(acPath, "\\销售盘点.txt");										//得出将要保存的文件

	pfListPrinting = fopen("SaleManagementTemp", "w+");
	//让用户输入起止日期
	puts("请输入起始时间  输入样例 2013.07.05");
	gets(acMinSaleDate);
	puts("请输入截止时间");
	gets(acMaxSaleDate);


	//打开进货记录文件
	if (NULL != (pfSoldList = fopen("SoldList.txt", "r")))
	{

		//下面按照格式读取文件内每个字符 分析后将开始将入库信息依次链入链表结尾
		fscanf(pfSoldList, "%c", &cTypeSign);

		while ('-' == cTypeSign)
		{
			fscanf(pfSoldList, "%s", sTemp.acSaleListNumber);
			fscanf(pfSoldList, "%s", sTemp.acSaleDate);
			fgetc(pfSoldList);
			if ((0 > strcmp(sTemp.acSaleDate, acMaxSaleDate)) || (0 < strcmp(sTemp.acSaleDate, acMinSaleDate)))
			{
				fscanf(pfSoldList, "%c", &cTypeSign);
				do
				{
					fscanf(pfSoldList, "%s", sTemp.acProductNumber);
					fscanf(pfSoldList, "%s", acProductName);
					fscanf(pfSoldList, "%d", &sTemp.iSaleAmount);
					fscanf(pfSoldList, "%f", &sTemp.fSalePrice);
					fprintf(pfListPrinting, "%s ", sTemp.acProductNumber);
					fprintf(pfListPrinting, "%d ", sTemp.iSaleAmount);
					fprintf(pfListPrinting, "%f\n", sTemp.fSalePrice);
					fgetc(pfSoldList);
					if (EOF == fscanf(pfSoldList, "%c", &cTypeSign))
					{
						break;
					}
				} while ('\\' == cTypeSign);
			}
			fscanf(pfSoldList, "%f", &fSaleListWipe);
			fscanf(pfSoldList, "%f", &fSaleListWipe);
			fscanf(pfSoldList, "%s\t", acUser);
			fscanf(pfSoldList, "%s", acUserC);
			fgetc(pfSoldList);
			fscanf(pfSoldList, "%c", &cTypeSign);
		}
		fclose(pfSoldList);
	}
	fclose(pfListPrinting);
	pfListPrinting = fopen("SaleManagementTemp", "r");



	fscanf(pfListPrinting, "%s", sTemp.acProductNumber);
	fscanf(pfListPrinting, "%d", &sTemp.iSaleAmount);
	fscanf(pfListPrinting, "%f", &sTemp.fSalePrice);
	//fscanf(pfListPrinting, "%f", &sTemp.fMoneyAmount);
	fgetc(pfListPrinting);
	strcpy(asTemp[0].acProductNumber, sTemp.acProductNumber);
	asTemp[0].iSaleAmount = sTemp.iSaleAmount;
	asTemp[0].fSalePrice = sTemp.fSalePrice;
	n = 1;
	while (EOF != (fscanf(pfListPrinting, "%s", sTemp.acProductNumber)))
	{
		fscanf(pfListPrinting, "%d", &sTemp.iSaleAmount);
		fscanf(pfListPrinting, "%f", &sTemp.fSalePrice);
		fgetc(pfListPrinting);

		for (i = 0; i < n; i++)
		{
			if (0 == strcmp(sTemp.acProductNumber, asTemp[i].acProductNumber))
			{
				asTemp[i].iSaleAmount += sTemp.iSaleAmount;
				iMark++;
				break;
			}
		}
		if (0 == iMark)
		{
			strcpy(asTemp[n].acProductNumber, sTemp.acProductNumber);
			asTemp[n].iSaleAmount = sTemp.iSaleAmount;
			asTemp[n].fSalePrice = sTemp.fSalePrice;
			n++;
		}
	}
	fclose(pfListPrinting);

	pfFinalListPrinting = fopen(acPath, "w");
	fprintf(pfFinalListPrinting, "商品编号\t商品名称\t销售数量\t售价\t\t总金额\n");
	for (i = 0; i < n; i++)
	{
		fprintf(pfFinalListPrinting, "%s\t\t ", asTemp[i].acProductNumber);
		strcpy(acProductName, STM_SearchProductProductName(asTemp[i].acProductNumber));
		fprintf(pfFinalListPrinting, "%s\t\t", acProductName);
		fprintf(pfFinalListPrinting, "%d\t\t", asTemp[i].iSaleAmount);
		fprintf(pfFinalListPrinting, "%.2f\t\t", asTemp[i].fSalePrice);
		asTemp[i].fMoneyAmount = asTemp[i].fSalePrice * asTemp[i].iSaleAmount ;
		fMoneyInAll += asTemp[i].fMoneyAmount;
		fprintf(pfFinalListPrinting, "%.2f\n", asTemp[i].fMoneyAmount);
	}
	fprintf(pfFinalListPrinting, "总销售额：%.2f\n", fMoneyInAll);
	fclose(pfFinalListPrinting);
	puts("销售盘点已保存至桌面");
	getchar();
}



/*
** 以下为其他模块的接口函数 集合测试时删掉或注释掉
*/
/*
char* SL_Read()
{
	char c[10] = "abc";
	char* ac = c;
	return ac;
}
char* STM_SearchProductProductName(char* acProductNumber)
{
	char c[10] = "abc";
	char* ac = c;
	return ac;
}
char* SPM_Checkname(char*
	)
{
	char c[10] = "abc";
	char* ac = c;
	return ac;
}
int STM_ChangeProductNumber(char* acProductNumber, int iPurchaseAmount)
{
	int i = 0;
	return i;
}
float STM_SearchProductStockPrice(char* acProductNumber)
{
	float f = 0.0f;
	return f;
}

*/
void SLM_AddProductToSoldList()
{
		printf("OOPS!系统正在升级.....\n");
		getchar();
		return;
}
void SLM_AlterProductAmountToSoldList()
{
		printf("OOPS!系统正在升级.....\n");
		getchar();
		return;
}
