//加密txt程序，直接将文件拖入后就可以加密
#include <stdio.h>

int main(int a, char* name[])
{

	FILE* p;
	FILE* q;
	p = fopen(name[1], "r");
	q = fopen("解密.txt", "w");

	if (p == NULL || q == NULL)
	{
		printf("文件打开失败\n");
		getchar();
		return 0;
	}

	char ch;
	while (1)
	{
		ch = fgetc(p);
		if (feof(p))		//文件是否读到末尾
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