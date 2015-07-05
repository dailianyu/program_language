/**********************************************************************
*
* 
*
* �� �� ��:  msgQueue.c
*
* ��������:  ��Ϣ���в���(�Ƚ��ȳ�����)
*
* �ļ���ʷ:
*
* �汾��           ����               ����           ˵��
*
* 
*
*/
#define DEBUG_PRINT  /* ÿ��CԴ�ļ�����п�ʹ�ø�����Ϊ������Ϣ���� */
			
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
*������:msgQueueInit
*
* ��  ��: ��ʽ���г�ʼ��
*
* ��  ��: _pQueue
*
* ��  ��: ��
*
* ��  ��:  FALSE----��ʼ��ʧ��
*          TRUE-----��ʼ���ɹ�
*
*/
INT1 msgQueueInit
(
	MsgQueue *_pQueue	/* ����ָ�� */
)	
{
	MsgNode *pt = NULL;

	/* �����ڴ� */
	IPOS_CALLOC(pt, 1, MsgNode)
	
	_pQueue->pFront = pt;
    _pQueue->pRear = pt;
	pt->pNext = NULL;
	
	return TRUE;

}

/***********************************************************************
*
*������:msgQueueSend
*
* ��  ��: ����ʽ�����м���ڵ�
*
* ��  ��: _pQueue
*         _msg
*
* ��  ��: ��
*
* ��  ��:  FALSE----ʧ��
*          TRUE-----�ɹ�
*
*/
INT1 msgQueueSend
(
	MsgQueue *_pQueue,	/* ����ָ�� */
	ThreadMsg _msg		/* �߳���Ϣ�ṹ */
)
{
	MsgNode *pt = NULL;

	/* �����ڴ� */
	IPOS_CALLOC(pt, 1, MsgNode)
	
	_pQueue->pRear->pNext = pt;
	_pQueue->pRear = pt;
	pt->msg = _msg;
	pt->pNext = NULL;

	return TRUE;	
}

/*********************************************************************
*
*������:msgQueueSend
*
* ��  ��: ����ʽ������ȡ���ڵ�
*
* ��  ��: _pQueue
*         _pMsg
*
* ��  ��: _pMsg
*
* ��  ��:  FALSE----ʧ��
*          TRUE-----�ɹ�
*
*/
INT1 msgQueueRecv
(
	MsgQueue *_pQueue,			/* ����ָ�� */
	ThreadMsg *_pMsg			/* �߳���Ϣ�ṹָ�룬����ֵ */
)
{
	
	MsgNode *pt = NULL;

	/* �ж϶����Ƿ�Ϊ�� */
	if(_pQueue->pFront == _pQueue->pRear)
	{
		DEBUG_ERR("fifo is empty!\n");
		return FALSE;
	}
	
	/* �ǿ�ʱ�ſɳ��� */	
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
*������:msgQueueDel
*
* ��  ��: ɾ����ʽ���У��ͷ������ڴ�
*
* ��  ��: _pQueue
*        
* ��  ��: ��
*
* ��  ��:  TRUE-----�ɹ�
*          
*/
INT1 msgQueueDel
(
	MsgQueue *_pQueue	/* ����ָ�� */
)	
{
	MsgNode *pt = NULL;

	/* �ж϶����Ƿ�Ϊ�� */
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

	/* ɾ��ͷ�ڵ� */
   IPOS_FREE(_pQueue->pFront)

	return TRUE;
}

/* functions end */

/* end of  msgQueue.c*/
