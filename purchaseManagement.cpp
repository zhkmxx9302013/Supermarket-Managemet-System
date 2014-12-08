#include "Main.h"

/*
*提供给主菜单的子菜单接口函数
*/

	
void PM_menu()
{
  int c = 0;
	int i = 1;
	while (i)
	{

				system("color 20");   
				system("cls"); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN |FOREGROUND_INTENSITY |
				FOREGROUND_RED | FOREGROUND_GREEN);
				printf("                      ****※ 进货管理系统 ※****\n"); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
				printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(7,6);
				printf("               1.新建货单的记录          2.预订单处理\n\n");   
			printf("*\t              3.进货记录查询       \t0.返回主菜单\n\n");  

			goto_xy(10,16);
			printf("请输入你的选择\n>");  
			goto_xy(25,16);
			char choice=getchar();   
			fflush(stdin);   
			
			switch(choice)   
			{   
			case '1' :   
					system("cls");  
					PM_EnteringPurchaseList();
					break ;   
			case '2' :   
					system("cls");
					PM_submenu1();
					break ;   
			case '3' :   
					
					system("cls"); 
					PM_submenu2();
					break ;   
					
			case '0' : 
					{ 
							return;
					}  
			default : 
					{
							system("cls");
							
							printf("                   ****※ 进货管理系统 ※****\n"); 
							
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

void PM_submenu1()
{
		int c = 0;
		int i = 1;
		while (i)
		{
				
				system("color 20");   
				system("cls"); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN |FOREGROUND_INTENSITY |
						FOREGROUND_RED | FOREGROUND_GREEN);
				printf("                      ****※ 预订单处理 ※****\n"); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(7,6);
				printf("         1.添加商品至预订单          2.输出预订单全部商品信息\n\n");
				goto_xy(8,8);
				printf("        0.返回上层菜单       \n\n"); 
		
				
				goto_xy(10,16);
				printf("请输入你的选择\n>");  
				goto_xy(25,16);
				char choice=getchar();   
				fflush(stdin);   
				
				switch(choice)   
				{   
				case '1' :   
						system("cls"); 
						PM_AddProductToOrderPlan();
						break ;   
				case '2' :   
						system("cls");
						PM_PrintOrderPlan();

						break ;     				
				case '0' : 
						{ 
								return;
						}  
				default : 
						{
								system("cls");
								
								printf("                   ****※ 预订单处理 ※****\n"); 
								
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
void PM_submenu2()
{
		int c = 0;
		int i = 1;
		while (i)
		{
				
				system("color 20");   
				system("cls"); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN |FOREGROUND_INTENSITY |
						FOREGROUND_RED | FOREGROUND_GREEN);
				printf("                      ****※ 进货记录查询※****\n"); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(5,6);
				printf("               1.按照日期时间查询详单          2.查询商品单品进货记录\n\n"); 
				goto_xy(5,8);
				printf("               0.返回上层菜单       \n\n"); 
				
				
				goto_xy(7,12);
				printf("请输入你的选择\n>");  
				goto_xy(25,16);
				char choice=getchar();   
				fflush(stdin);   
				
				switch(choice)   
				{   
				case '1' :   
						system("cls");  
						PM_PrintPurchasedListByTime();
      
						break ;   
				case '2' :   
						system("cls");
						PM_PrintPurchasedListByProduct();
						break ;     				
				case '0' : 
						{ 
								return;
						}  
				default : 
						{
								system("cls");
								
								printf("                   ****※ 预订单处理 ※****\n"); 
								
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

/*
** 面向菜单的接口函数 实现录入入库单的功能
** 
*/
void PM_EnteringPurchaseList() //纯调用模块内部函数 自身无意义
{
	pPFP  psRoot = NULL;
	float fMoneyInAll = 0.0f;

	psRoot = CreatePurchaseList();
	fMoneyInAll = EnteringPurchaseList(psRoot);
	SavingPurchasedListToFile(psRoot, fMoneyInAll);
	//AlterStock(psRoot);
	//RewriteOrderPlan(psRoot);
	FreePFP(psRoot);
	puts("ok!");
	getchar();
}


/*
** 要有界面实现 判断是否有预订单，有则向里输入 无则新建并向里输入
**
*/
void PM_AddProductToOrderPlan() 
{
	AddProductToOrderPlan();
}


/*
** 输出预订单
**
*/
void PM_PrintOrderPlan()
{
	PFO soTemp;
	FILE* pfOrderPlan = NULL;
	float fMoneyInAll = 0.0f;
	char acProductName[40] = "";
	FILE* pfListPrinting = NULL;
	char acPath[255] = "";              //保存用户桌面路径
	int iPathLength = 0;				//保存用户桌面路径长度
	
	//获得用户桌面绝对路径
	SHGetSpecialFolderPath(0, acPath, CSIDL_DESKTOPDIRECTORY, 0);				//获取用户桌面路径
	iPathLength = strlen(acPath);                                           //求路径长
	strcat(acPath, "\\预订单.txt");										//得出将要保存的文件
	pfListPrinting = fopen(acPath, "w");
	fprintf(pfListPrinting, "商品编号\t商品名称\t需求数量\t进货价\t总金额\n");
	
	if (NULL != (pfOrderPlan = fopen("OrderPlan.txt", "r")))
	{
		//下面按照格式读取文件，修正格式、输出。
		fscanf(pfOrderPlan, "%f", &fMoneyInAll);
		fgetc(pfOrderPlan);
		while (1)
		{
			if (EOF == fscanf(pfOrderPlan, "%s", soTemp.acProductNumber))
			{
				break;
			}
			fscanf(pfOrderPlan, "%d", &soTemp.iOrderAmount);
			fscanf(pfOrderPlan, "%f", &soTemp.fStockPrice);
			fscanf(pfOrderPlan, "%f", &soTemp.fMoneyAmount);
			strcpy(acProductName, STM_SearchProductProductName(soTemp.acProductNumber));
			fprintf(pfListPrinting, "%s\t\t", soTemp.acProductNumber);
			fprintf(pfListPrinting, "%s\t\t", acProductName);
			fprintf(pfListPrinting, "%d\t\t", soTemp.iOrderAmount);
			fprintf(pfListPrinting, "%.2f\t", soTemp.fStockPrice);
			fprintf(pfListPrinting, "%.2f\n", soTemp.fMoneyAmount);
			fgetc(pfOrderPlan);
		} 
	}
	
	fclose(pfOrderPlan);
	fprintf(pfListPrinting, "总金额：%.2f\n", fMoneyInAll);
	fclose(pfListPrinting);
	puts("预订单记录已存至桌面");
	getchar();
}

/*
** 输出一段时间内的进货记录
*/
void PM_PrintPurchasedListByTime()  //输出一段时间内的进货记录
{
	char acMinStockDate[11] = "";					//要查询的日期的起点
	char acMaxStockDate[11] = "";					//要查询的日期的终点
	FILE* pfPurchasedList = NULL;		//文件指针
	char cTypeSign = '\0';				//类型判断
	char acPurchaseListNumber[8] = "";;
	float fMoneyInAll = 0.0f;
	char acUser[20];
	char cTemp[300];
	char acPath[255] = "";              //保存用户桌面路径
	int iPathLength = 0;				//保存用户桌面路径长度
	PFP sTemp;
	char acProductName[40] = "";



	FILE* pfListPrinting = NULL;


	//获得用户桌面文件绝对路径
	SHGetSpecialFolderPath(0, acPath, CSIDL_DESKTOPDIRECTORY, 0);				//获取用户桌面路径
	iPathLength = strlen(acPath);                                           //求路径长
	strcat(acPath, "\\入库清单.txt");										//得出将要保存的文件

	pfListPrinting = fopen(acPath, "w");
	fprintf(pfListPrinting, "日期\t\t商品编号\t商品名称\t进货数量\t进货价\t总金额\n");
	//让用户输入起止日期
	puts("请输入起始时间  输入样例 2013.07.05");
	gets(acMinStockDate);
	puts("请输入截止时间");
	gets(acMaxStockDate);


	//打开进货记录文件
	if (NULL != (pfPurchasedList = fopen("PurchasedList.txt", "r")))
	{

		//下面按照格式读取文件内每个字符 分析后将开始将入库信息依次链入链表结尾
		fscanf(pfPurchasedList, "%c", &cTypeSign);

		while ('-' == cTypeSign)
		{
			fscanf(pfPurchasedList, "%s", sTemp.acPurchaseListNumber);
			fscanf(pfPurchasedList, "%f", &fMoneyInAll);
			fscanf(pfPurchasedList, "%s", sTemp.acStockDate);
			fscanf(pfPurchasedList, "%s", acUser);
			fgetc(pfPurchasedList);
			if ((0 > strcmp(sTemp.acStockDate, acMaxStockDate)) || (0 < strcmp(sTemp.acStockDate, acMinStockDate)))
			{
				fscanf(pfPurchasedList, "%c", &cTypeSign);
				do
				{
					fscanf(pfPurchasedList, "%s", sTemp.acProductNumber);
					fscanf(pfPurchasedList, "%s", acProductName);
					fscanf(pfPurchasedList, "%d", &sTemp.iPurchaseAmount);
					fscanf(pfPurchasedList, "%f", &sTemp.fStockPrice);
					fscanf(pfPurchasedList, "%f", &sTemp.fMoneyAmount);
					fprintf(pfListPrinting, "%s\t", sTemp.acStockDate);
					fprintf(pfListPrinting, "%s\t\t", sTemp.acProductNumber);
					fprintf(pfListPrinting, "%s\t", acProductName);
					fprintf(pfListPrinting, "%d\t\t", sTemp.iPurchaseAmount);
					fprintf(pfListPrinting, "%.2f\t", sTemp.fStockPrice);
					fprintf(pfListPrinting, "%.2f\n", sTemp.fMoneyAmount);
					fgetc(pfPurchasedList);
					if (EOF == fscanf(pfPurchasedList, "%c", &cTypeSign))
					{
						break;
					}
				} while ('.' == cTypeSign);
			}
		}
		fclose(pfPurchasedList);
	}
	fclose(pfListPrinting);
	puts("入库清单已保存至桌面");
}

/*
** 输出某商品的进货记录
*/
void PM_PrintPurchasedListByProduct()  //输出一段时间内的进货记录
{
	char acProductNumber[6]; 
	char acProductName[40];
	char acTempProductName[40];

	FILE* pfPurchasedList = NULL;		//文件指针
	char cTypeSign = '\0';				//类型判断
	char acPurchaseListNumber[8] = "";;
	float fMoneyInAll = 0.0f;
	char acUser[20];
	char cTemp[300];
	char acPath[255] = "";              //保存用户桌面路径
	int iPathLength = 0;				//保存用户桌面路径长度
	PFP sTemp;
	int iPurchasedInAll = 0;			//总进货数计数器
	float fPurchasedInAll = 0.0f;		//总进货金额计数器
	FILE* pfListPrinting = NULL;
	//让用户输入商品编号或商品名称
	puts("请输入商品编号或商品名称");
	gets(acTempProductName);

	//获得用户桌面文件绝对路径
	SHGetSpecialFolderPath(0, acPath, CSIDL_DESKTOPDIRECTORY, 0);			//获取用户桌面路径
	iPathLength = strlen(acPath);                                           //求路径长
	sprintf(acPath + iPathLength, "\\入库清单_%s.txt", acTempProductName);	//得出将要保存的文件
	pfListPrinting = fopen(acPath, "w");
	fprintf(pfListPrinting, "进货时间\t进货数量\t进货价\t总金额\t\n");

	//打开进货记录文件
	if (NULL != (pfPurchasedList = fopen("PurchasedList.txt", "r")))
	{

		//下面按照格式读取文件内每个字符 然后判断修正格式输出
		fscanf(pfPurchasedList, "%c", &cTypeSign);

		while ('-' == cTypeSign)
		{
			fscanf(pfPurchasedList, "%s", sTemp.acPurchaseListNumber);
			fscanf(pfPurchasedList, "%f", &fMoneyInAll);
			fscanf(pfPurchasedList, "%s", sTemp.acStockDate);
			fscanf(pfPurchasedList, "%s", acUser);
			fgetc(pfPurchasedList);
			fscanf(pfPurchasedList, "%c", &cTypeSign);
			do
			{
				fscanf(pfPurchasedList, "%s", sTemp.acProductNumber);
				fscanf(pfPurchasedList, "%s", acProductName);
				fscanf(pfPurchasedList, "%d", &sTemp.iPurchaseAmount);
				fscanf(pfPurchasedList, "%f", &sTemp.fStockPrice);
				fscanf(pfPurchasedList, "%f", &sTemp.fMoneyAmount);
				if ((0 == strcmp(acTempProductName, acProductName)) || (0 == strcmp(acTempProductName, sTemp.acProductNumber)))
				{
					fprintf(pfListPrinting, "%s\t", sTemp.acStockDate);
					fprintf(pfListPrinting, "%d\t\t", sTemp.iPurchaseAmount);
					iPurchasedInAll += sTemp.iPurchaseAmount;
					fprintf(pfListPrinting, "%.2f\t", sTemp.fStockPrice);
					fprintf(pfListPrinting, "%.2f\t\n", sTemp.fMoneyAmount);
					fPurchasedInAll += sTemp.fMoneyAmount;
					//fprintf(pfListPrinting, "%s\n", acUser);
				}
				fgetc(pfPurchasedList);
				if (EOF == fscanf(pfPurchasedList, "%c", &cTypeSign))
				{
					break;
				}
			} while ('.' == cTypeSign);
		}
		fclose(pfPurchasedList);
	}
	fprintf(pfListPrinting, "总入库数:%d\t", iPurchasedInAll);
	fprintf(pfListPrinting, "总金额%.2f\t", fPurchasedInAll);
	fclose(pfListPrinting);
	puts("入库清单已保存至桌面");
}



/*
** 创建进货单的链表
** 传出指针
*/
pPFP CreatePurchaseList()			
{
	//要有一个进货单链表的root节点传出
	pPFP Root = (pPFP)malloc(sizeof(PFP));
    return Root;
}


/*
** 读取用户提供的进货单转换成指针 
** 无返回
*/
float EnteringPurchaseList(pPFP psRoot)
{
	FILE* pfPurchaseList = NULL;	    //用户提供的入库单文件指针
	char acNamegivenByUser[20] = "";	//保存用户提供的入库单文件名
	pPFP psCurrent = NULL;				//新建的一个节点
	pPFP psLast = NULL;					//上一个节点
    //FILE* pfPurchaseList = NULL;		//进货单文件指针
    char acPath[255] = "";              //保存用户桌面路径
    int iPathLength = 0;				//保存用户桌面路径长度

	char acPurchaseListNumber[8] = "";	//进货单编号
	char acStockDate[11] = "";			//入库的时间

	char cTypeSign = '\0';				//类型标记
	
	float fMoneyInAll = 0.0f;			//进货单总金额

	char acBuff[20];
	char* pcBuff = acBuff;

	//链表准备
	psCurrent= (pPFP)malloc(sizeof(PFP));
	if (NULL == psCurrent)
	{
		puts("电脑内存不足，请释放内存后重新进行此操作");
		system("pause");
	}
	psRoot->psNext = psCurrent;
    psLast = psRoot;
	
	
	puts("--------------------------------------------------------");
	puts("请确认已录入的文件格式如下所示并已保存至桌面：\n");
	puts("- 进货单号 进货时间");
	puts("\\ 商品编号 数量 进货价");
	puts("\\ 商品编号 数量 进货价");
	puts("...");
	puts("...");
	puts("= 总价\n\n");
	puts("--------------------------------------------------------\n");
	//提示用户输入库单文件名
	puts("现在请键入入库单文件名：");
    gets(acNamegivenByUser);
	
	
    //获得用户入库单文件绝对路径
    SHGetSpecialFolderPath(0,acPath,CSIDL_DESKTOPDIRECTORY,0);				//获取用户桌面路径
    iPathLength = strlen(acPath);                                           //求路径长
    sprintf(acPath + iPathLength,"\\%s",acNamegivenByUser);                 //得出入库单名
	
    //打开用户提供的入库单文件
    pfPurchaseList = fopen(acPath,"r");
    if (NULL == pfPurchaseList)
    {
        puts("没有找到该文件，请重新确认");
		getchar();
	} 
	
    
	
    //下面按照格式读取文件内每个字符 分析后将开始将进货信息依次链入链表结尾
    for(;;)
    {
		

		fscanf(pfPurchaseList, "%c", &cTypeSign);
        
        switch(cTypeSign)
		{
			case '-':
			{
				fscanf(pfPurchaseList,"%s",acPurchaseListNumber);
				fscanf(pfPurchaseList,"%s",acStockDate);
				break;
			}
		
			case '\\':
				{
					fscanf(pfPurchaseList,"%s",psCurrent->acProductNumber);		//获得商品编号 
					fscanf(pfPurchaseList,"%d",&psCurrent->iPurchaseAmount);			//获得进货数量
					fscanf(pfPurchaseList,"%f",&psCurrent->fStockPrice);			//获得进货价
					
					psCurrent->fMoneyAmount = psCurrent->iPurchaseAmount * psCurrent->fStockPrice;	//计算总价
					strcpy(psCurrent->acPurchaseListNumber,acPurchaseListNumber);	//
					strcpy(psCurrent->acStockDate,acStockDate);

					//新建节点，向下移动部分			
					psLast = psCurrent;
					
					psCurrent = (pPFP)malloc(sizeof(PFP));
					if (NULL == psCurrent)
					{
						puts("电脑内存不足，请释放内存后重新进行此操作");
						system("pause");
					}
					psLast->psNext = psCurrent;

					break;
				}
			case '=':
				{
					fscanf(pfPurchaseList,"%f",&fMoneyInAll);
					break;
				}

		}
		if (EOF == fgetc(pfPurchaseList))
		{
			break;
		}
		
    }
	
	psCurrent->psNext = NULL;
	fclose(pfPurchaseList);
	return fMoneyInAll;
    //若不规范 输出提示语句，再system.pause
}

/*
** 这个函数实现将先头的进货单保存至进货记录文件
*/
void SavingPurchasedListToFile(pPFP psRoot,float fMoneyInAll)	
{
	pPFP psCurrent = NULL;					//要做遍历用的一个节点指针
	FILE* pfPurchasedList = NULL;			//获得入库历史文件指针
	char acUser[20]; 
	char acSP[20];
	char acProductName[40];
	char *name;
	//name = SL_read();
	//strcpy(acSP, SPM_Checkname( psCurrent -> acSupplierNumber));

	//需要调用SL_Read得到当前操作用户名
	//下面自PFP文件的ROOT节点开始依次读取每一个节点信息，存入存档文件



	//开文件
    pfPurchasedList = fopen("PurchasedList.txt","a");
	psCurrent = psRoot->psNext;


    /*
	**下面自PFP链表的ROOT节点开始依次读取每一个节点信息，存入存档文件
	**
	**需要调用SL_Read、STM_SearchProductProductName、SPM_Checkname
	*/
	fprintf(pfPurchasedList, "- %s", psCurrent->acPurchaseListNumber);
	fprintf(pfPurchasedList, " %f", fMoneyInAll);
	fprintf(pfPurchasedList, " %s", psCurrent->acStockDate);
	//strcpy(acUser, SL_NAME);
	fprintf(pfPurchasedList, " %s\n", SL_NAME);
	while (NULL != psCurrent->psNext)
	{
		fprintf(pfPurchasedList, ". %s", psCurrent->acProductNumber);
		strcpy(acProductName, STM_SearchProductProductName(psCurrent->acProductNumber));
		fprintf(pfPurchasedList, " %s",acProductName);
		fprintf(pfPurchasedList, " %d", psCurrent->iPurchaseAmount );
		fprintf(pfPurchasedList, " %f", psCurrent->fStockPrice);
	 	fprintf(pfPurchasedList, " %f\n", psCurrent->fMoneyAmount);
		//fprintf(pfPurchasedList, " %s\n", acSP);
		psCurrent = psCurrent->psNext;
	}
	
	fclose(pfPurchasedList);
}

/*
** 在入库单录入完成后更新库存 //未测试本函数 14.56
*/
void AlterStock(pPFP psRoot)
{

	pPFP psCurrent = NULL;			//要做遍历用的一个节点指针
		//FILE* pfOrderPlan = NULL;		//获得销售单文件的指针
	int a;
		
	psCurrent = psRoot;
		//下面自PFP文件的ROOT节点开始依次读取每一个节点信息；调用STM模块的STM_iChangeProductNumber从库存里删去相应数量
		
		while (NULL != psCurrent->psNext)
		{	
			psCurrent = psCurrent->psNext;
			if(-1 == (a = STM_ChangeProductNumber(psCurrent->acProductNumber,psCurrent->iPurchaseAmount)) ) 
			{
				printf("库存文件中没有商品编号为%s的商品记录",psCurrent->acProductNumber);
			}
			
		}
}

/*
** 在入库单录入完成后更新进货计划 计划本块改完可复用
*/
void RewriteOrderPlan(pPFP psRoot)
{
	pPFP psCurrent = NULL;			//要做遍历用的一个节点指针
	FILE* pfOrderPlan = NULL;		//获得预订单文件的指针
	pPFO psoCurrent = NULL;
	pPFO psoRoot = NULL;
	pPFO psoLast = NULL;
	float fMoneyInAll = 0.0f;


	//预订单链表预处理
	psoCurrent = (pPFO)malloc(sizeof(PFO));
	if (NULL == psoCurrent)
	{
		puts("内存不足");
	}
	psoRoot = (pPFO)malloc(sizeof(PFO));
	if (NULL == psoRoot)
	{
		puts("内存不足1");
	}
	psoRoot->psNext = psoCurrent;
	psoLast = psoRoot;
	psoCurrent->psNext = NULL;
	
	//入货单链表预处理
	psCurrent = psRoot->psNext;
	
	//下面打开预订单文件
	if (NULL != (pfOrderPlan = fopen("OrderPlan.txt", "r")))
	{
		
		//将预订单文件内容写入链表
		fscanf(pfOrderPlan, "%f", &fMoneyInAll);

		while (EOF != fscanf(pfOrderPlan, "%s", psoCurrent->acProductNumber))
		{
			fscanf(pfOrderPlan, "%d", &psoCurrent->iOrderAmount);
			fscanf(pfOrderPlan, "%f", &psoCurrent->fStockPrice);
			fscanf(pfOrderPlan, "%f", &psoCurrent->fMoneyAmount);
			psoCurrent->psNext = (pPFO)malloc(sizeof(PFO));
			psoLast = psoCurrent;
			psoCurrent = psoCurrent->psNext;
			if (NULL == psoCurrent)
			{
				puts("内存不足1");
			}
		}
		fclose(pfOrderPlan);
		psoLast->psNext = NULL;

		//将入货单链表的每个节点与预订单文件链表每个节点一一比对，判断是否相等，若相等则重写预订单链表节点数量
		while (NULL != psCurrent->psNext)
		{
			psCurrent = psCurrent->psNext;
			psoCurrent = psoRoot->psNext;
			while (NULL != psoCurrent->psNext)
			{
				psoLast = psoCurrent;
				psoCurrent = psoCurrent->psNext;
				if (0 == strcmp (psCurrent->acProductNumber,psoCurrent->acProductNumber) )
				{
					if (psCurrent->iPurchaseAmount < psoCurrent->iOrderAmount)
					{
						fMoneyInAll -= psCurrent->fMoneyAmount;
						psoCurrent->iOrderAmount -= psCurrent->iPurchaseAmount;
						psoCurrent->fMoneyAmount = psoCurrent->fStockPrice * psoCurrent->iOrderAmount;
					}
					else
					{
						fMoneyInAll -= psoCurrent->fMoneyAmount;
						psoLast->psNext = psoCurrent->psNext;
						free(psoCurrent);
						psoCurrent = psoLast;
					}
				}
			}
		}
	}

	//将预订单链表写回文件
	pfOrderPlan = fopen("OrderPlan.txt", "w");
	fprintf(pfOrderPlan, "%f\n", fMoneyInAll);
	psoCurrent = psoRoot;
	while (NULL != psoCurrent->psNext)
	{
		psoCurrent = psoCurrent->psNext;
		fprintf(pfOrderPlan, "%s ", psoCurrent->acProductNumber);
		fprintf(pfOrderPlan, "%d ", psoCurrent->iOrderAmount);
		fprintf(pfOrderPlan, "%f ", psoCurrent->fStockPrice);
		fprintf(pfOrderPlan, "%f\n",  psoCurrent->fMoneyAmount);
	}

	//将预订单链表的heep空间free掉
	psoLast = psoRoot;
	psoCurrent = psoRoot->psNext;
	
	while (NULL != psoCurrent->psNext)
	{
		free(psoLast);
		psoLast = psoCurrent;
		psoCurrent = psoCurrent->psNext;
	}
	free(psoLast);
	free(psoCurrent);
	psoRoot = NULL;
	psoLast = NULL;
	psoCurrent = NULL;

}

/*
** 释放入库单指针 //未测试本函数 14.56
*/
void FreePFP(pPFP psRoot)
{
	pPFP psCurrent = NULL;			//要做遍历用的一个节点指针
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



/*
** 这个函数将商品录入预订单 并保存到文件 如果曾经有商品记录 加上；如果没有商品记录，新建这个商品的那一行
** 尚待实现
*/
void AddProductToOrderPlan()		
{
	pPFO psoRoot;
	pPFO psoCurrent; 
	pPFO psoLast;
	FILE* pfOrderPlan = NULL;			//获得预订单文件指针
	char acProductNumber[6] = "";		//商品编号
	int iOrderAmount = 0;				//订货数量
	float fStockPrice = 0.0f;			//进货价
	float fMoneyAmount = 0.0f;			//进货总金额
	int iMark = 0;							//迭代器
	float fMoneyInAll = 0.0f;

	//提示用户输入商品编号
	puts("请输入商品编号");
	gets(acProductNumber);
	//提示用户输入数量
	puts("请输入加入订单计划的商品数量");
	scanf("%d", &iOrderAmount);

	// 得到商品进货价
	fStockPrice = STM_SearchProductStockPrice(acProductNumber);

	//预订单链表预处理
	psoCurrent = (pPFO)malloc(sizeof(PFO));
	if (NULL == psoCurrent)
	{
		puts("内存不足");
	}
	psoRoot = (pPFO)malloc(sizeof(PFO));
	if (NULL == psoRoot)
	{
		puts("内存不足1");
	}
	psoRoot->psNext = psoCurrent;
	psoLast = psoRoot;
	psoCurrent->psNext = NULL;

	//下面打开预订单文件
	if (NULL != (pfOrderPlan = fopen("OrderPlan.txt", "r")))
	{

		//将预订单文件内容写入链表
		fscanf(pfOrderPlan, "%f", &fMoneyInAll);

		while (EOF != fscanf(pfOrderPlan, "%s", psoCurrent->acProductNumber))
		{
			fscanf(pfOrderPlan, "%d", &psoCurrent->iOrderAmount);
			fscanf(pfOrderPlan, "%f", &psoCurrent->fStockPrice);
			fscanf(pfOrderPlan, "%f", &psoCurrent->fMoneyAmount);
			psoCurrent->psNext = (pPFO)malloc(sizeof(PFO));
			psoLast = psoCurrent;
			psoCurrent = psoCurrent->psNext;
			if (NULL == psoCurrent)
			{
				puts("内存不足1");
			}
		}
		fclose(pfOrderPlan);
		psoLast->psNext = NULL;
	}
	


		//将用户要增加的商品编号与预订单文件链表每个节点一一比对，判断是否相等，若有相等则重写预订单链表节点，若无则新增节点

		psoCurrent = psoRoot;
		
		while (NULL != psoCurrent->psNext)
		{
			psoLast = psoCurrent;
			psoCurrent = psoCurrent->psNext;
			if (0 == strcmp(acProductNumber, psoCurrent->acProductNumber))
			{
				fMoneyInAll += fStockPrice;
				psoCurrent->iOrderAmount += iOrderAmount;
				iMark++;
				break;
			}
		}
		if (0 == iMark)
		{
			psoCurrent->psNext = (pPFO)malloc(sizeof(PFO));
			psoCurrent = psoCurrent->psNext;
			strcpy(psoCurrent->acProductNumber, acProductNumber);
			psoCurrent->iOrderAmount = iOrderAmount;
			psoCurrent->fStockPrice = fStockPrice;
			psoCurrent->fMoneyAmount = fStockPrice * iOrderAmount;
			psoCurrent->psNext = NULL;
			fMoneyInAll += fStockPrice;
		}

	

	//将预订单链表写回文件

	pfOrderPlan = fopen("OrderPlan.txt", "w");
	fprintf(pfOrderPlan, "%f\n", fMoneyInAll);
	psoCurrent = psoRoot;
	while (NULL != psoCurrent->psNext)
	{
		psoCurrent = psoCurrent->psNext;
		fprintf(pfOrderPlan, "%s ", psoCurrent->acProductNumber);
		fprintf(pfOrderPlan, "%d ", psoCurrent->iOrderAmount);
		fprintf(pfOrderPlan, "%f ", psoCurrent->fStockPrice);
		fprintf(pfOrderPlan, "%f\n", psoCurrent->fMoneyAmount);
	}
	fclose(pfOrderPlan);
	//将预订单链表的heep空间free掉
	psoLast = psoRoot;
	psoCurrent = psoRoot->psNext;

	while (NULL != psoCurrent->psNext)
	{
		free(psoLast);
		psoLast = psoCurrent;
		psoCurrent = psoCurrent->psNext;
	}
	free(psoLast);
	free(psoCurrent);
	psoRoot = NULL;
	psoLast = NULL;
	psoCurrent = NULL;
	printf("\n\n\t\t添加成功！");
	getchar();
	return;
}





