#include"Main.h"

  
void main()   
{   
    system("color 18");  
	
    M_authority();               //版权说明函数   
    char *m = SL_read();         //密码输入函数   
	
		
    char choice='1' ;   
    while(choice!='0')					 //显示主菜单   
    {   
				

        system("color 18");   
        system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE |FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN);
        printf("                   ****※ %s欢迎使用超市管理系统 ※****\n",m); 
				printf(" =============================================================================\n");
				for (int i = 0; i<21 ;i++)
				{
						printf("*                                                                             *\n");
				}
				printf(" =============================================================================");
				goto_xy(7,6);
				printf("               1.进货管理系统           2.销售管理系统\n\n");   
				printf("*\t              3.库存管理系统           4.员工管理系统\n\n");  
				printf("*\t              5.供货商管理系统         6.用户管理系统\n\n");   
        printf("*\t              9.帮助                   0.退出程序\n\n\n"); 
				goto_xy(10,16);
        printf("请输入你的选择\n>");  
				goto_xy(25,16);
        choice=getchar();   
        fflush(stdin);   
           
        switch(choice)   
        {   
            case '1' :   
                 PM_menu();   
								break ;   
            case '2' :   
								 SLM_menu();
								 break ;   
            case '3' :   
								STM_Menu();
								 break ;   
            case '4' :   
								SFM_menu();
            break ;  
						case '5':
								SPM_Check()	;
								break;
						case '6':
								system("cls");   
								SYM_user();  
								break;
						case '9': 
								system("cls");   
								M_help();
								break;
            case '0' : 
								{ 
										system("cls");
								
										printf("                       ****※ %s再见 ※****\n",m); 
								
										printf(" =============================================================================\n");
										for (int m = 0; m<21 ;m++)
										{
												printf("*                                                                             *\n");
										}
										printf(" =============================================================================");
										goto_xy(30,8);
										printf("   谢谢你的使用!"); 
										goto_xy(30,10);
										system("pause");
										goto_xy(300,1000);
										exit(0);
								}  
            default : 
								{
										system("cls");
										
										printf("                   ****※ %s欢迎使用超市管理系统 ※****\n",m); 
										
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

void M_help()
{
		system("color F7");
	char content;
	
	FILE *fphelp ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |
            FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		printf("          帮助文档            \n");
		
		  
	fphelp = fopen("Help.txt","r");
	while((content = getc(fphelp) )!= EOF)
	{
			printf("%c",content);

	}

	system("pause");

	
}

void M_authority()   
{   
		int k=0,m=3,n=1,t=0,ll=0;   
		
	for (ll=0;ll<=60;ll++)
	{		
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE |FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN);
		printf("\n\n\n\n");
		printf("     *******    *******   *******           *******     *******   *******    \n");
		printf("     ********   *******  *********         *********   *********  ********   \n");
		printf("     **     **    ***    ***               ***         **     **  **    ***  \n");
		printf("     **     **    ***    ***               ***         **     **  **     **  \n");
		printf("     ********     ***    ***         ****  ***         **     **  **     **  \n");
		printf("     ********     ***    ***   ****  ****  ***   ****  **     **  **     **  \n");
		printf("     **     **    ***    ***   ****        ***   ****  **     **  **     **  \n");
		printf("     **     **    ***    ***    **         ***    **   **     **  **    ***  \n");
		printf("     ********   *******  *********         *********   *********  ********   \n");
		printf("     *******    *******   *******           *******     *******   *******    \n");
		system("cls");
	}

		 system("cls"); 
		 goto_xy(20,10);
    printf("              超");   
    for(ll=0;ll<=80000000;ll++);   
    printf("市");   
    for( ll=0;ll<=80000000;ll++);   
    printf("管"); 
		for( ll=0;ll<=80000000;ll++);   
    printf("理"); 
		for( ll=0;ll<=80000000;ll++);   
    printf("系"); 
    for( ll=0;ll<=80000000;ll++);   
    printf("统\n\n");   
    //for( ll=0;ll<=80000000;ll++);   

		goto_xy(30,20);
    printf("按下任意键进入系统");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE |FOREGROUND_BLUE);
	
		system("pause");
		
    system("cls");   
   
}

   


  


 

//====================================================================///================================================================///


void goto_xy(int x,int y){				//定位光标位置指定坐标
		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos={x,y};
		SetConsoleCursorPosition(hOut,pos);
} 
