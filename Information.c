/////////////////
//ѧ����Ϣ������--����ֻ���������ݣ��պ������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[20];
	int age;
	float number;
}STU;

typedef struct MyStruct
{
	STU* arr;

	int size;
	int str;
}ewa;


void init(ewa* p);	//��ʼ��
void insert(ewa* p, char* name1, int age1, float number1);	//����-����

void Myfree(ewa* p);	//�ڴ��ͷ�

int main()
{

	char name2[20];
	int age2;
	float number2;
	ewa brr;
	init(&brr);

	scanf("%s", name2);

	insert(&brr, name2, 20, 175.2);

	for (int i = 0; i < brr.size; i++)
	{
		printf("%s %d %.1f\n", brr.arr[i].name, brr.arr[i].age, brr.arr[i].number);
	}

	Myfree(&brr);
	return 0;
}


void init(ewa* p)
{
	p->arr = NULL;
	p->size = 0;
	p->str = 0;
}

void insert(ewa* p, char* name1, int age1, float number1)	//��������
{
	if (p->str >= p->size)
	{
		if (p->arr == NULL)
		{
			p->size += 1;
			p->arr = (STU*)malloc(sizeof(STU) * p->size);
		}
		else
		{
			p->size += p->size / 2 > 0 ? p->size / 2 : 1;
			p->arr = (STU*)realloc(p->arr, sizeof(STU) * p->size);
		}
	}
	strcpy(p->arr[p->str].name, name1);
	p->arr[p->str].age = age1;
	p->arr[p->str].number = number1;
}

void Myfree(ewa* p)		//�ͷ��ڴ�
{
	free(p->arr);
	p->size = 0;
	p->str = 0;
}