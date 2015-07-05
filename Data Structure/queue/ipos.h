/******************************************************************************
*
*  
*
* �� �� ����ipos.h
*
* �����������������̵�ȫ��ͷ�ļ�������һЩȫ�ֵĺ궨�壬�ṹ���������
*
* �ļ���ʷ��
*
* �汾��    ����                ����          	˵��
*
*/

#ifndef _IPOS_H
#define _IPOS_H

#ifdef __cplusplus
extern "C" {
#endif   /*__cplusplus */

/* includes */
#include <stdlib.h>
#include "assert.h"
#include "intfDebug.h"

/* includes end */

/* defines */


#define LCD_PRINTF				DEBUG_MSG	/* ����Ļ�ϴ�ӡ��Ϣ */
//#define LCD_PRINTF						/*  */

#define MAX_TASK_MSG_LEN		(20)		/* ��������Ϣ���� */
#define TASK_MSG_HEAD			(2)			/* ������Ϣͷ���� */
#define MAX_TASK_MSG_DATA_LEN	(MAX_TASK_MSG_LEN-TASK_MSG_HEAD)/* ��������Ϣ���ݳ��� */

#define MAX_THREAD_MSG_LEN		(128)		/* ����߳���Ϣ���� */
#define THREAD_MSG_HEAD			(4)			/* �߳���Ϣͷ���� */
#define MAX_THREAD_MSG_DATA_LEN	(MAX_THREAD_MSG_LEN-THREAD_MSG_HEAD)/* ����߳���Ϣ���ݳ��� */

#define IPOS_SUCCESS			(0)			/* �ɹ���һ����Ϊ��������ֵʹ�� */
#define IPOS_FAIL				(-1)		/* ʧ�ܣ�һ����Ϊ��������ֵʹ�� */

#define CHINESE					(0)			/* �����ַ�����ʾ */
#define ENGLISH					(1)			/* Ӣ���ַ�����ʾ */

#define PRESS_KEY_SOUND_TIME	(50)		/* ������ʱ��(ms) */			
#define PRESS_KEY_SOUND_FREQ	(800)		/* ������Ƶ��(hz) */			

#ifndef TRUE
#define TRUE  					(1)
#endif

#ifndef FALSE
#define FALSE 					(0)
#endif

#ifndef NULL
#define NULL (0x0)
#endif /* NULL */

/* ͳһ�ڴ����궨�� */

/* �ڴ����� */
#define IPOS_CALLOC(pt, count, type){ \
	pt = (type *)calloc(count, sizeof(type)); \
	assert(pt != NULL); \
}

/* �ڴ��ͷź� */
#define IPOS_FREE(pt) { \
	if (pt != NULL) \
	{ \
		free (pt); \
		pt = NULL; \
	} \
}

/* ���С���໥ת���� */
#define LITTLE_BIG_CONVERT(_pIn, _pOut, _uiSize) {\
	char *pIn = (char *)_pIn;\
	char *pOut = (char *)_pOut;\
	int i;\
	assert(_pIn != 0x0);\
	assert(_pOut != 0x0);\
	for (i = 0; i < _uiSize; i++)\
	{\
		pOut[i] = pIn[_uiSize - i - 1];\
	}\
}
/* defines end */


/* typedefs */
typedef unsigned 	char   		UINT1;
typedef unsigned 	short  		UINT2;
typedef unsigned 	int			UINT4;
typedef unsigned 	long long  	UINT8;
typedef unsigned 	char   		UCHAR;
typedef signed 		char   		INT1;
typedef signed 		short  		INT2;
typedef signed 		int			INT4;
typedef signed 		long long  	INT8;
typedef 			char   		CHAR;
typedef 			void   		VOID;
/* typedefs end */

/* structures */

/* ���̼�ͨѶ��Ϣ */
typedef struct tagTaskMSG
{
	UINT1  ucMsgCode;						    /* ��Ϣ���� */
	UINT1  ucMsgLen;						    /* ��Ϣ���� */
	UCHAR  aMsgData[MAX_TASK_MSG_DATA_LEN];	/* ��Ϣ�� */
} TaskMsg;

/* �̼߳�ͨѶ��Ϣ */
typedef struct tagThreadMSG
{
	UINT2  usMsgCode;							/* ��Ϣ���� */
	UINT2  usMsgLen;							/* ��Ϣ���� */
	UCHAR  aMsgData[MAX_THREAD_MSG_DATA_LEN];	/* ��Ϣ�� */
} ThreadMsg;

/* structures end */

extern const CHAR	*g_pSWVersion;

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _IPOS_H */

/* ipos.h end */

