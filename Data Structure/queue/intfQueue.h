/*********************************************************************************
*
*
*
* �� �� ��:  intfQueue.h
*
* ��������:  ��Ϣ���в����ӿ�ͷ�ļ�
*
* �ļ���ʷ:
*
* �汾��           ����               ����           ˵��
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

/* ��Ϣ���Ľṹ  */
typedef struct tagMsgNode
{
	ThreadMsg  msg;			/* �߳���Ϣ�ṹ */
	struct tagMsgNode *pNext;	/* ��һ���ڵ�ָ�� */

}MsgNode;

/* �������ݽṹ */
typedef struct 
{
  MsgNode *pFront;			/* ����ͷָ�� */
  MsgNode *pRear;			/* ����βָ�� */

}MsgQueue;

/* strcuts end */


/* function declarations */

/**********************************************************************
*
*
������:
msgQueueInit
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
extern INT1 msgQueueInit
(
	MsgQueue *_pQueue	/* ����ָ�� */
);

/***********************************************************************
*
*
������:
msgQueueSend
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
extern INT1 msgQueueSend
(
	MsgQueue *_pQueue,	/* ����ָ�� */
	ThreadMsg _msg		/* �߳���Ϣ�ṹ */
);

/*********************************************************************
*
*
������:
msgQueueSend
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
extern INT1 msgQueueRecv
(
	MsgQueue *_pQueue,			/* ����ָ�� */
	ThreadMsg *_pMsg			/* �߳���Ϣ�ṹָ�룬����ֵ */
);

/**********************************************************************
*
*
������:
msgQueueDel
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
extern INT1 msgQueueDel
(
	MsgQueue *_pQueue	/* ����ָ�� */
);

/* function declarations end */


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /*__INTFQUEUE_H */


/*  end of intfQueue.h */

