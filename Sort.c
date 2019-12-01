void Bubbling(int* arr, int len)	//ð������
{
	int temp;				//ð��̫���˾Ͳ�ע����
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
}

void Choice(int* arr, int len)	//ѡ������
{
	int temp, k;
	for (int i = 0; i < len - 1; i++)
	{
		k = i;		//���һ���±�
		for (int j = i + 1; j < len; j++)	//jΪ�ڶ���Ԫ��
		{
			if (arr[k] > arr[j])	//�жϵ����Ԫ���Ƿ������һ��Ԫ��
			{
				k = j;		//�ǵĻ����������±�
			}
		}
		temp = arr[i];		//Ȼ���i����
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

void insert(int* arr, int len)	//��������
{
	int temp, j;
	for (int i = 1; i < len; i++)	//�ӵڶ���Ԫ�ؿ�ʼ
	{
		temp = arr[i];		//��ǵڶ���Ԫ��
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)	//iǰ��һ��Ԫ�غ�i��Ƚ�
		{
			arr[j + 1] = arr[j];		//�������i��Ӧ��Ԫ�أ���ôԪ��������
		}
		arr[j + 1] = temp;		//Ȼ�����
	}
}

void fast(int* arr, int len, int regith)	//��������
{
	if (len >= regith)	//�ж��Ƿ�ֻ��һ��Ԫ�ػ���û��
	{
		return;
	}
	int temp, min;
	min = arr[len];	//���minΪ��ߵ�Ԫ��
	int i = len;	//����߿�ʼ
	int j = regith;	//���ұ߿�ʼ

	while (i < j)	//�ж���������
	{
		while (i<j && arr[j]>min)	//���������ұȱ�������
		{
			j--;		//�ҵ��˾�������
		}
		while (i < j && arr[i] <= min)	//���������ұȱ����С�����
		{	
			i++;		//�ҵ���������
		}
		if (i < j)		//�������Ļ�����i��j��Ԫ��
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i];		//�����󽻻�������Ԫ�غ͵�һ��Ԫ��
	arr[i] = arr[len];
	arr[len] = temp;

	fast(arr, len, i - 1);//����������
	fast(arr, i + 1, regith);//����������
}