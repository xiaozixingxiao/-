//����txt����ֱ�ӽ��ļ������Ϳ��Լ���
#include <stdio.h>

int main(int a, char* name[])
{

	FILE* p;
	FILE* q;
	p = fopen(name[1], "r");
	q = fopen("����.txt", "w");

	if (p == NULL || q == NULL)
	{
		printf("�ļ���ʧ��\n");
		getchar();
		return 0;
	}

	char ch;
	while (1)
	{
		ch = fgetc(p);
		if (feof(p))		//�ļ��Ƿ����ĩβ
		{
			break;
		}
		ch = ch ^ 90;
		fputc(ch, q);
	}

	fclose(p);
	fclose(q);
	return 0;
}