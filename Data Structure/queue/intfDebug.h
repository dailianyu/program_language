/******************************************************************************
*
* 
*
* 文 件 名：intfDebug.h
*
* 内容描述：调试用头文件
*
* 文件历史：
*
* 版本号    日期                作者          	说明

*
*/

/* 每个C源文件都必须包含本头文件 */

#ifndef _INTFDEBUG_H
#define _INTFDEBUG_H

#ifdef __cplusplus
extern "C" {
#endif   /*__cplusplus */

#undef DEBUG_PRINT  /* 全局调试控制开关,启用该行代码时整个工程不会有调试信息*/

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

