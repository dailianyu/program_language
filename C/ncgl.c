// �ṹ���ж�̬�ڴ������˳���ȸ��ṹ����������ڴ棬�ٸ��ṹ���Ա�����ڴ�
// �ṹ���ж�̬�ڴ���ͷ�˳�����ͷŽṹ���Ա���ڴ棬���ͷŽṹ��������ڴ�

#include <stdio.h>

struct stu1
{
	int a;
	short b;
	char c[5];
}__attribute__((packed)); // 11

struct stu2
{
	char c[5];
	int a;
	short b;
	char *p;
}; // 20

int main()
{
	struct stu2 *q;

	q = (struct stu2 *)malloc(sizeof(struct stu2));
	if (q==NULL)
	{
		
	}

	q->p = (char *)malloc(100);
	if (q->p==NULL)
	{
		
	}

	free(q->p);
	free(q);
    
	printf("sizeof(struct stu1)=%d\n", sizeof(struct stu1));
	printf("sizeof(struct stu2)=%d\n", sizeof(struct stu2));
}

