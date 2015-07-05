#include <stdio.h>
#include <stdlib.h>
#include "ipos.h"
#include "intfDebug.h"
#include "intfQueue.h"

int main()
{
	ThreadMsg msg,msg2;

	MsgQueue *q = (MsgQueue*)malloc(sizeof(MsgQueue));

	msgQueueInit(q);

	memset(&msg,0,sizeof(msg));
	msg.usMsgCode = 100;
	strcpy(msg.aMsgData, "hello100");
	msg.usMsgLen = strlen(msg.aMsgData)  + 4;

    msgQueueSend(q, msg);

	memset(&msg,0,sizeof(msg));
	msg.usMsgCode = 101;
	strcpy(msg.aMsgData, "hello101");
	msg.usMsgLen = strlen(msg.aMsgData)  + 4;

    msgQueueSend(q, msg);

	memset(&msg,0,sizeof(msg));
	msg.usMsgCode = 102;
	strcpy(msg.aMsgData, "hello102");
	msg.usMsgLen = strlen(msg.aMsgData)  + 4;

    msgQueueSend(q, msg);


	memset(&msg2,0,sizeof(msg2));
	msgQueueRecv(q, &msg2);
	printf("code:%d,len:%d,data:%s\n",msg2.usMsgCode,msg2.usMsgLen,msg2.aMsgData);

	memset(&msg2,0,sizeof(msg2));
	msgQueueRecv(q, &msg2);
	printf("code:%d,len:%d,data:%s\n",msg2.usMsgCode,msg2.usMsgLen,msg2.aMsgData);


	msgQueueDel(q);

	
	
	free(q);
}

