/**********************************************************************
*
* 
*
* 文 件 名:  msgQueue.c
*
* 内容描述:  消息队列操作(先进先出队列)
*
* 文件历史:
*
* 版本号           日期               作者           说明
*
* 
*
*/
#define DEBUG_PRINT  /* 每个C源文件中最顶行可使用该行作为调试信息开关 */
			
/* includes */

#include <stdio.h>
#include <stdlib.h>
#include "ipos.h"
#include "intfDebug.h"
#include "intfQueue.h"

/* includes end */

/* functions */

/**********************************************************************
*
*函数名:msgQueueInit
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
INT1 msgQueueInit
(
	MsgQueue *_pQueue	/* 队列指针 */
)	
{
	MsgNode *pt = NULL;

	/* 申请内存 */
	IPOS_CALLOC(pt, 1, MsgNode)
	
	_pQueue->pFront = pt;
    _pQueue->pRear = pt;
	pt->pNext = NULL;
	
	return TRUE;

}

/***********************************************************************
*
*函数名:msgQueueSend
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
INT1 msgQueueSend
(
	MsgQueue *_pQueue,	/* 队列指针 */
	ThreadMsg _msg		/* 线程消息结构 */
)
{
	MsgNode *pt = NULL;

	/* 申请内存 */
	IPOS_CALLOC(pt, 1, MsgNode)
	
	_pQueue->pRear->pNext = pt;
	_pQueue->pRear = pt;
	pt->msg = _msg;
	pt->pNext = NULL;

	return TRUE;	
}

/*********************************************************************
*
*函数名:msgQueueSend
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
INT1 msgQueueRecv
(
	MsgQueue *_pQueue,			/* 队列指针 */
	ThreadMsg *_pMsg			/* 线程消息结构指针，返回值 */
)
{
	
	MsgNode *pt = NULL;

	/* 判断队列是否为空 */
	if(_pQueue->pFront == _pQueue->pRear)
	{
		DEBUG_ERR("fifo is empty!\n");
		return FALSE;
	}
	
	/* 非空时才可出队 */	
	else
	{
		pt = _pQueue->pFront->pNext;
		*_pMsg  = pt->msg;
		_pQueue->pFront->pNext = pt->pNext;
		
		if(pt->pNext == NULL)
		{
			_pQueue->pRear = _pQueue->pFront;
		}
		
		IPOS_FREE(pt)
	}

	return TRUE;
}

/**********************************************************************
*
*函数名:msgQueueDel
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
INT1 msgQueueDel
(
	MsgQueue *_pQueue	/* 队列指针 */
)	
{
	MsgNode *pt = NULL;

	/* 判断队列是否为空 */
	while(_pQueue->pFront != _pQueue->pRear)
	{
		pt = _pQueue->pFront->pNext;
		_pQueue->pFront->pNext = pt->pNext;
		
		if(pt->pNext == NULL)
		{
			_pQueue->pRear = _pQueue->pFront;
		}
		IPOS_FREE(pt)

	}

	/* 删除头节点 */
   IPOS_FREE(_pQueue->pFront)

	return TRUE;
}

/* functions end */

/* end of  msgQueue.c*/
