/*****************************************************
程序功能：十进制与二进制，八进制，十六进制间单一的转换
******************************************************/
#include "stdio.h"
#include "string.h"
//#include "math.h"
#include "process.h"

int giConvertNumber=0;

typedef struct menuitem 
{
	char cMenuname[20];
	void (* fpMenuFun)();
}MenuItem;

#define HEX (16)
#define OCT (8)
#define BIN (2)

void Convert2Hex();
void Convert2Oct();
void Convert2Bin();
void ClearScreen();
int ExitProgrom();
int GetMenuItemCount(MenuItem *pmMenu);
void ConvertFunction(char cType,int iConvertNum);
void InputConvertNum();

//菜单选项
MenuItem gmMenuInfo[]={
	{"转换为十六进制",            Convert2Hex},
	{"转换为八进制",              Convert2Oct},
	{"转换为二进制",              Convert2Bin},
	{"重新输入转换数据",          InputConvertNum},
	{"清屏",                      ClearScreen},
	{"退出",                      ExitProgrom},
	{"0",0}
};

/****************************************
函数名：InputConvertNum
功能：输入要转换的数据
输入参数：无
输出参数：无
日期：
*****************************************/
void InputConvertNum()
{
	printf("请输入一个十进制数据:");
	scanf("%d",&giConvertNumber);
}

/****************************************
函数名：PrintMenuInfo
功能：显示出菜单选项
输入参数：结构体数组名
输出参数：无
日期：
*****************************************/
void PrintMenuInfo(MenuItem *pmMenuItem)
{
	int index;
	int iItemCounts;
	iItemCounts=GetMenuItemCount(pmMenuItem);

	printf("待转换十进制数据为:%d\n",giConvertNumber);
	for (index=0;index<iItemCounts;index++)
	{
		printf("%d\t %s\n",index+1,pmMenuItem[index].cMenuname);
	}
	printf("请输入选项：(1~%d)",index);	
}

/****************************************
函数名：InputKey
功能：输入要转换的类型选项
输入参数：无
输出参数：无
日期：
*****************************************/
int InputKey()
{
	int iKeyNum;
	scanf("%d",&iKeyNum);
	return iKeyNum;
}

/****************************************
函数名：SelectMenu
功能：选择菜单
输入参数：输入要转换的类型选项
输出参数：无
日期：
*****************************************/
void SelectMenu(int iKeyNum,MenuItem *pmMenu)
{
	if (iKeyNum<1||iKeyNum>GetMenuItemCount(gmMenuInfo))
	{
		printf("输入的数字错误!\n");
	}
	else
		(*pmMenu[iKeyNum-1].fpMenuFun)();
}

//主函数
void main()
{
	int iKeyCode;
	InputConvertNum();
	while(1)
	{
		PrintMenuInfo(gmMenuInfo);
		iKeyCode=InputKey();
		SelectMenu(iKeyCode,gmMenuInfo);
	}
}

/****************************************
函数名：GetMenuItemCount
功能：计算结构体数组的大小
输入参数：结构体数组名
输出参数：结构体大小的数值
日期：
*****************************************/
int GetMenuItemCount(MenuItem *pmMenu)
{
	int iCount=0;
	while (strcmp(pmMenu->cMenuname,"0")!=0)
	{
		iCount++;
		pmMenu++;
	}
	return iCount;
}

/****************************************
函数名：Convert2Hex
功能：转换成二进制
输入参数：无
输出参数：无
日期：
*****************************************/
void Convert2Hex()
{
	ConvertFunction(HEX,giConvertNumber);
}

/****************************************
函数名：Convert2Oct
功能：转换成八进制
输入参数：无
输出参数：无
日期：
*****************************************/
void Convert2Oct()
{
	ConvertFunction(OCT,giConvertNumber);
}

/****************************************
函数名：Convert2Bin
功能：转换成二进制
输入参数：无
输出参数：无
日期：
*****************************************/
void Convert2Bin()
{
	ConvertFunction(BIN,giConvertNumber);
}

/****************************************
函数名：ClearScreen
功能：清屏
输入参数：无
输出参数：无
日期：
*****************************************/
void ClearScreen()
{
	system("CLS");
}

/****************************************
函数名：ExitProgrom
功能：退出程序运行
输入参数：无
输出参数：无
日期：
*****************************************/
int ExitProgrom()
{
	printf("Exit\n");
	exit(1);
}

/****************************************
函数名：ConvertFunction
功能：转换功能函数
输入参数：要转换的类型
输出参数：要转换的数据
日期：
*****************************************/
void ConvertFunction(char cType,int iConvertNum)
{
	int iNum;
	int iCount=0;
	char cBuffer[200];
	char cTemp;

	iNum=iConvertNum;
	//转换
	while (iNum!=0)
	{
		cBuffer[iCount]=iNum%cType;
		iNum=iNum/cType;
		iCount++;
	}
	//反转
	for (iNum=0;iNum<iCount/2;iNum++)
	{
		cTemp=cBuffer[iNum];
		cBuffer[iNum]=cBuffer[iCount-iNum-1];
		cBuffer[iCount-iNum-1]=cTemp;
	}
	printf("转换结果:");
	switch(cType)
	{
		case HEX:
			printf("0x");
			break;
		case OCT:
			printf("0");
			break;
		case BIN:
			printf("0b");
			break;
	}
	for (iNum=0;iNum<iCount;iNum++)
	{
		if (cBuffer[iNum]>=10&&cType==HEX)
		{
			printf("%c",cBuffer[iNum]-10+'A');		
		}
		else
			printf("%c",cBuffer[iNum]+48);		//ASCII码中十进制和字符间隔了48
	}
	putchar('\n');
}