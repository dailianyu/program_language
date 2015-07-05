/******************************************************************************
*
* 
*
* �� �� ����intfDebug.h
*
* ����������������ͷ�ļ�
*
* �ļ���ʷ��
*
* �汾��    ����                ����          	˵��

*
*/

/* ÿ��CԴ�ļ������������ͷ�ļ� */

#ifndef _INTFDEBUG_H
#define _INTFDEBUG_H

#ifdef __cplusplus
extern "C" {
#endif   /*__cplusplus */

#undef DEBUG_PRINT  /* ȫ�ֵ��Կ��ƿ���,���ø��д���ʱ�������̲����е�����Ϣ*/

static __inline void DEBUG_NONE(const char *fmt, ...){}

/* defines */

#ifdef DEBUG_PRINT
#define DEBUG_MSG printf
#define DEBUG_ERR(_Fmt, ...) { \
	printf("Error Report: %s, line %u.\n", __FILE__, __LINE__); \
	printf(_Fmt, ##__VA_ARGS__); \
}
#else
//#define DEBUG_MSG debugPrntMsg
#define DEBUG_MSG DEBUG_NONE
#define DEBUG_ERR DEBUG_NONE
#endif

/* defines end */


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /*_INTFDEBUG_H*/

/* intfDebug.h end */

