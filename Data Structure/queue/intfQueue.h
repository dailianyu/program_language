/*********************************************************************************
*
*
*
* 文 件 名:  intfQueue.h
*
* 内容描述:  消息队列操作接口头文件
*
* 文件历史:
*
* 版本号           日期               作者           说明
*

*
*/
#ifndef __INTFQUEUE_H
#define __INTFQUEUE_H

#ifdef __cplusplus
extern "C" {
#endif   /*__cplusplus */

/* includes */

#include "ipos.h"

/* includes end */


/* structs */

/* 消息结点的结构  */
typedef struct tagMsgNode
{
	ThreadMsg  msg;			/* 线程消息结构 */
	struct tagMsgNode *pNext;	/* 下一个节点指针 */

}MsgNode;

/* 队列数据结构 */
typedef struct 
{
  MsgNode *pFront;			/* 队列头指针 */
  MsgNode *pRear;			/* 队列尾指针 */

}MsgQueue;

/* strcuts end */


/* function declarations */

/**********************************************************************
*
*
函数名:
msgQueueInit
*
* 功  能: 链式队列初始化
*
* 输  入: _pQueue
*
* 输  出: 无
*
* 返  回:  FALSE----初始化失败
*          TRUE-----初始化成功
*
*/
extern INT1 msgQueueInit
(
	MsgQueue *_pQueue	/* 队列指针 */
);

/***********************************************************************
*
*
函数名:
msgQueueSend
*
* 功  能: 向链式队列中加入节点
*
* 输  入: _pQueue
*         _msg
*
* 输  出: 无
*
* 返  回:  FALSE----失败
*          TRUE-----成功
*
*/
extern INT1 msgQueueSend
(
	MsgQueue *_pQueue,	/* 队列指针 */
	ThreadMsg _msg		/* 线程消息结构 */
);

/*********************************************************************
*
*
函数名:
msgQueueSend
*
* 功  能: 从链式队列中取出节点
*
* 输  入: _pQueue
*         _pMsg
*
* 输  出: _pMsg
*
* 返  回:  FALSE----失败
*          TRUE-----成功
*
*/
extern INT1 msgQueueRecv
(
	MsgQueue *_pQueue,			/* 队列指针 */
	ThreadMsg *_pMsg			/* 线程消息结构指针，返回值 */
);

/**********************************************************************
*
*
函数名:
msgQueueDel
*
* 功  能: 删除链式队列，释放链表内存
*
* 输  入: _pQueue
*        
* 输  出: 无
*
* 返  回:  TRUE-----成功
*          
*/
extern INT1 msgQueueDel
(
	MsgQueue *_pQueue	/* 队列指针 */
);

/* function declarations end */


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /*__INTFQUEUE_H */


/*  end of intfQueue.h */

