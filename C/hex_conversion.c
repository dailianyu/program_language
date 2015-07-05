/*****************************************************
�����ܣ�ʮ����������ƣ��˽��ƣ�ʮ�����Ƽ䵥һ��ת��
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

//�˵�ѡ��
MenuItem gmMenuInfo[]={
	{"ת��Ϊʮ������",            Convert2Hex},
	{"ת��Ϊ�˽���",              Convert2Oct},
	{"ת��Ϊ������",              Convert2Bin},
	{"��������ת������",          InputConvertNum},
	{"����",                      ClearScreen},
	{"�˳�",                      ExitProgrom},
	{"0",0}
};

/****************************************
��������InputConvertNum
���ܣ�����Ҫת��������
�����������
�����������
���ڣ�
*****************************************/
void InputConvertNum()
{
	printf("������һ��ʮ��������:");
	scanf("%d",&giConvertNumber);
}

/****************************************
��������PrintMenuInfo
���ܣ���ʾ���˵�ѡ��
����������ṹ��������
�����������
���ڣ�
*****************************************/
void PrintMenuInfo(MenuItem *pmMenuItem)
{
	int index;
	int iItemCounts;
	iItemCounts=GetMenuItemCount(pmMenuItem);

	printf("��ת��ʮ��������Ϊ:%d\n",giConvertNumber);
	for (index=0;index<iItemCounts;index++)
	{
		printf("%d\t %s\n",index+1,pmMenuItem[index].cMenuname);
	}
	printf("������ѡ�(1~%d)",index);	
}

/****************************************
��������InputKey
���ܣ�����Ҫת��������ѡ��
�����������
�����������
���ڣ�
*****************************************/
int InputKey()
{
	int iKeyNum;
	scanf("%d",&iKeyNum);
	return iKeyNum;
}

/****************************************
��������SelectMenu
���ܣ�ѡ��˵�
�������������Ҫת��������ѡ��
�����������
���ڣ�
*****************************************/
void SelectMenu(int iKeyNum,MenuItem *pmMenu)
{
	if (iKeyNum<1||iKeyNum>GetMenuItemCount(gmMenuInfo))
	{
		printf("��������ִ���!\n");
	}
	else
		(*pmMenu[iKeyNum-1].fpMenuFun)();
}

//������
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
��������GetMenuItemCount
���ܣ�����ṹ������Ĵ�С
����������ṹ��������
����������ṹ���С����ֵ
���ڣ�
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
��������Convert2Hex
���ܣ�ת���ɶ�����
�����������
�����������
���ڣ�
*****************************************/
void Convert2Hex()
{
	ConvertFunction(HEX,giConvertNumber);
}

/****************************************
��������Convert2Oct
���ܣ�ת���ɰ˽���
�����������
�����������
���ڣ�
*****************************************/
void Convert2Oct()
{
	ConvertFunction(OCT,giConvertNumber);
}

/****************************************
��������Convert2Bin
���ܣ�ת���ɶ�����
�����������
�����������
���ڣ�
*****************************************/
void Convert2Bin()
{
	ConvertFunction(BIN,giConvertNumber);
}

/****************************************
��������ClearScreen
���ܣ�����
�����������
�����������
���ڣ�
*****************************************/
void ClearScreen()
{
	system("CLS");
}

/****************************************
��������ExitProgrom
���ܣ��˳���������
�����������
�����������
���ڣ�
*****************************************/
int ExitProgrom()
{
	printf("Exit\n");
	exit(1);
}

/****************************************
��������ConvertFunction
���ܣ�ת�����ܺ���
���������Ҫת��������
���������Ҫת��������
���ڣ�
*****************************************/
void ConvertFunction(char cType,int iConvertNum)
{
	int iNum;
	int iCount=0;
	char cBuffer[200];
	char cTemp;

	iNum=iConvertNum;
	//ת��
	while (iNum!=0)
	{
		cBuffer[iCount]=iNum%cType;
		iNum=iNum/cType;
		iCount++;
	}
	//��ת
	for (iNum=0;iNum<iCount/2;iNum++)
	{
		cTemp=cBuffer[iNum];
		cBuffer[iNum]=cBuffer[iCount-iNum-1];
		cBuffer[iCount-iNum-1]=cTemp;
	}
	printf("ת�����:");
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
			printf("%c",cBuffer[iNum]+48);		//ASCII����ʮ���ƺ��ַ������48
	}
	putchar('\n');
}