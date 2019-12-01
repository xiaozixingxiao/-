void Bubbling(int* arr, int len)	//冒泡排序
{
	int temp;				//冒泡太简单了就不注释了
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

void Choice(int* arr, int len)	//选择排序
{
	int temp, k;
	for (int i = 0; i < len - 1; i++)
	{
		k = i;		//标记一个下标
		for (int j = i + 1; j < len; j++)	//j为第二个元素
		{
			if (arr[k] > arr[j])	//判断第这个元素是否大于下一个元素
			{
				k = j;		//是的话保存它的下标
			}
		}
		temp = arr[i];		//然后和i交换
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

void insert(int* arr, int len)	//插入排序
{
	int temp, j;
	for (int i = 1; i < len; i++)	//从第二个元素开始
	{
		temp = arr[i];		//标记第二个元素
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)	//i前面一个元素和i相比较
		{
			arr[j + 1] = arr[j];		//如果大于i对应的元素，那么元素往后移
		}
		arr[j + 1] = temp;		//然后插入
	}
}

void fast(int* arr, int len, int regith)	//快速排序
{
	if (len >= regith)	//判断是否只有一个元素或者没有
	{
		return;
	}
	int temp, min;
	min = arr[len];	//标记min为左边的元素
	int i = len;	//从左边开始
	int j = regith;	//从右边开始

	while (i < j)	//判断两边相遇
	{
		while (i<j && arr[j]>min)	//从右往左找比标记数大的
		{
			j--;		//找到了就往左移
		}
		while (i < j && arr[i] <= min)	//从左往右找比标记数小或相等
		{	
			i++;		//找到了往右移
		}
		if (i < j)		//不相遇的话交换i和j的元素
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i];		//相遇后交换相遇的元素和第一个元素
	arr[i] = arr[len];
	arr[len] = temp;

	fast(arr, len, i - 1);//从右往左排
	fast(arr, i + 1, regith);//从左往右排
}