/******************************************************************************
*
*  
*
* 文 件 名：ipos.h
*
* 内容描述：开发工程的全局头文件。包括一些全局的宏定义，结构定义等内容
*
* 文件历史：
*
* 版本号    日期                作者          	说明
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


#define LCD_PRINTF				DEBUG_MSG	/* 在屏幕上打印信息 */
//#define LCD_PRINTF						/*  */

#define MAX_TASK_MSG_LEN		(20)		/* 最大进程消息长度 */
#define TASK_MSG_HEAD			(2)			/* 进程消息头长度 */
#define MAX_TASK_MSG_DATA_LEN	(MAX_TASK_MSG_LEN-TASK_MSG_HEAD)/* 最大进程消息数据长度 */

#define MAX_THREAD_MSG_LEN		(128)		/* 最大线程消息长度 */
#define THREAD_MSG_HEAD			(4)			/* 线程消息头长度 */
#define MAX_THREAD_MSG_DATA_LEN	(MAX_THREAD_MSG_LEN-THREAD_MSG_HEAD)/* 最大线程消息数据长度 */

#define IPOS_SUCCESS			(0)			/* 成功，一般作为函数返回值使用 */
#define IPOS_FAIL				(-1)		/* 失败，一般作为函数返回值使用 */

#define CHINESE					(0)			/* 中文字符串显示 */
#define ENGLISH					(1)			/* 英文字符串显示 */

#define PRESS_KEY_SOUND_TIME	(50)		/* 按键音时间(ms) */			
#define PRESS_KEY_SOUND_FREQ	(800)		/* 按键音频率(hz) */			

#ifndef TRUE
#define TRUE  					(1)
#endif

#ifndef FALSE
#define FALSE 					(0)
#endif

#ifndef NULL
#define NULL (0x0)
#endif /* NULL */

/* 统一内存管理宏定义 */

/* 内存分配宏 */
#define IPOS_CALLOC(pt, count, type){ \
	pt = (type *)calloc(count, sizeof(type)); \
	assert(pt != NULL); \
}

/* 内存释放宏 */
#define IPOS_FREE(pt) { \
	if (pt != NULL) \
	{ \
		free (pt); \
		pt = NULL; \
	} \
}

/* 大端小端相互转换宏 */
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

/* 进程间通讯消息 */
typedef struct tagTaskMSG
{
	UINT1  ucMsgCode;						    /* 消息代码 */
	UINT1  ucMsgLen;						    /* 消息长度 */
	UCHAR  aMsgData[MAX_TASK_MSG_DATA_LEN];	/* 消息体 */
} TaskMsg;

/* 线程间通讯消息 */
typedef struct tagThreadMSG
{
	UINT2  usMsgCode;							/* 消息代码 */
	UINT2  usMsgLen;							/* 消息长度 */
	UCHAR  aMsgData[MAX_THREAD_MSG_DATA_LEN];	/* 消息体 */
} ThreadMsg;

/* structures end */

extern const CHAR	*g_pSWVersion;

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _IPOS_H */

/* ipos.h end */

