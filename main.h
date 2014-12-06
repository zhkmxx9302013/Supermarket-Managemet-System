#include <stdio.h>   
#include <string.h>   
#include <stdlib.h>   
#include <conio.h> 
#include <shlobj.h>  
#include <windows.h>
//用户管理模块
struct users    
{   
    char user_name[20];   
    char user_password[7];   
    char user_kind ;   
    struct users*next ;   
};  

static char* SL_NAME;
void addpassword(char answer[]);  //密码加密控制  

void M_authority();               //版权说明函数   
void SYM_user();									//用户管理界面菜单（判断权限）
char * SL_read();									//用户名及密码读取判断
void SYM_createUser();						//创建用户
void SYM_deleteUser();						//删除用户
void SYM_modify();								//更改用户信息
void M_help();										//帮助
void goto_xy(int x,int y);				//指针坐标调节函数


//库存模块
void STM_Menu();
struct Product * CreateDataList();
void SaveData(struct Product * head);
void STM_ListAllProduct();
void STM_SearchProduct();
void STM_ListProductShortage();
void STM_ChangeProduct();
void STM_AddProduct();
void STM_DeletProduct();
int STM_ChangeProductNumber(char * pName,int pStockNumber);
float STM_SearchProductStockPrice(char pNumber[6]);	
char * STM_SearchProductProductName(char pNumber[6]);

void newStaff();						//录入新员工信息
void changeMessage(char[]);			//更改员工信息
void findStaff(char[]);				//查询员工信息
void changePosition(char[]);			//调整员工职务
void deleteMessage(char[]);			//删除员工信息
void SFM_menu();						//main函数接口



//员工管理模块
struct staffMessage
{
		char cName[30];				//员工姓名
		char cStaffId[10];					//员工号
		char cSex[3];					//员工性别
		int iAge;						//员工年龄
		char iId[20];							//员工身份证号
		char cAddress[120];				//员工住址
		char lPhoneNumber[20];					//员工手机号
		char cTelephoneNumber[14];			//员工固话
		int iLaborage;			//员工工资
		char cPosition[20];				//员工职务
		char cEmployTime[11];				//员工入编时间 例：2014.07.28
		char cHistoricalWork[120];	//员工历史工作职务记录
};

typedef struct staffMessage staff;		



//供货商管理模块
//====================================================================================

	struct supplier
	{
		char Sup_CName[60];		    //名称
		char Sup_CNum[10];			//编号（4位）
		char Sup_CAdd[120];			//地址
		char Sup_CFName[10];		//负责人姓名
		char Sup_CTelf[30];			//联系方式（负责人）
		char Sup_CTelg[14];			//联系方式（固定电话）:区号（4位）-固话（8位）
		struct supplier *next;
	};
	
		//=====================================================================================
		
			int SPM_Check(  );								//判断文件中是否有供货商信息
			int SupplierData(  );							//供货商信息记录
			int DataChange(  );		//供货商信息更改
			int EntirelyCheck(  );					//供货商信息整体查询
			int PartlyCheck( );	//供货商信息局部查询
			int DataDelete(	);					//供货商信息删除
			char* SPM_Checkname(char[] );	
			int SPM_searchname();			//通过编号查询供货商名称
			struct supplier * SPM_CreateDataList( );			//从文件当中读取数据创建数据链
			void SaveData(struct supplier * head);				//更新库文件


//进货管理模块
struct ProductForPurchase    //这个是进货单用的结构体
{
		char acPurchaseListNumber[8];		//进货单编号 其实前几位就可以保存进货日期
		char acProductNumber[6];			//商品编号
		char acSupplierNumber[10];			//供货商编号
		float fStockPrice;				//进货价
		char acStockDate[11];			//进货日期
		int iPurchaseAmount;			//进货数量
		float fMoneyAmount;				//总金额
		char acComments[300];			//备注
		
		struct ProductForPurchase* psNext;
};
			
			
struct ProductForOrder		//这个是预订单里用的结构体
{
		char acProductNumber[6];		//商品编号
		char acSupplierNumber[5];		//供货商编号
		float fStockPrice;				//进货价
		int iOrderAmount;				//进货数量
		float fMoneyAmount;				//总金额
		
		struct ProductForOrder* psNext;
};
			
			
			
			
//typedef
typedef struct ProductForPurchase PFP;
typedef struct ProductForOrder PFO;


typedef PFP* pPFP;
typedef PFO* pPFO;
			
			

//内部函数
pPFP CreatePurchaseList();
float EnteringPurchaseList(pPFP psRoot);
void SavingPurchasedListToFile(pPFP psRoot,float fMoneyInAll);
void AlterStock(pPFP psRoot);
void RewriteOrderPlan(pPFP psRoot);
void FreePFP(pPFP psRoot);
void AddProductToOrderPlan();
void PM_submenu1();
void PM_submenu2();
void PM_AddProductToOrderPlan();
void PM_PrintOrderPlan();
void PM_PrintPurchasedListByTime();
   void PM_PrintPurchasedListByProduct();


//外部接口
void PM_EnteringPurchaseList();
void PM_AddProductToOrderPlan();
void PM_menu(); 
			
	/*		//引用的外部接口
			char* SL_Read();
			char* STM_SearchProductProductName(char* acProductNumber);
			char* SPM_Checkname(char* acSupplierNumber)	;
			int STM_ChangeProductNumber(char* acProductNumber,int iPurchaseAmount);
float STM_SearchProductStockPrice(char* acProductNumber ); 

*/


//销售管理模块

struct ProductForSale
{
		char acProductNumber[6];		//商品编号
		float fSalePrice;			//销售价
		char acSaleDate[11];			//销售日期
		int iSaleAmount;			//销售数量额
		float fMoneyAmount;           //总金额
		char acSaleListNumber[10];			//销售单号
		
		
		struct ProductForSale* psNext;
};




//typedef
typedef struct ProductForSale* pPFS;
typedef struct ProductForSale PFS;

void  SLM_menu();
void SLM_CreateSaleList();
void SLM_AddProductToSoldList();
void SLM_AlterProductAmountToSoldList();
void SLM_PrintSoldListByTime();
void SLM_PrintSoldListByProduct();
void SLM_CheckSoldList();
void SLM_submenu1();
void SLM_submenu2();
/*
//调用其他模块函数的声明
int STM_ChangeProductNumber(char*,int) ;         //更改商品数量
float STM_SearchProductStockPrice(char* cProductNumber[6]);                       //返回商品进价
char STM_SearchProductProductName(char* cProductNumber[6]);                       //返回商品名称

char* SL_Read();     */                                                              //返回当前操作员工

//还有个传入供货商编号 传出供货商名的借口没传
