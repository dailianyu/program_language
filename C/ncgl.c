// 结构体中动态内存的申请顺序：先跟结构体变量申请内存，再跟结构体成员申请内存
// 结构体中动态内存的释放顺序：先释放结构体成员的内存，再释放结构体变量的内存

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

