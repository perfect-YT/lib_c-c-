#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void  ArrayPrint( int* arr, int n)
{
	int i= 0;
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void  Swap(int* a, int* b)
{
	int tmp=0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

InsertSort(int* arr, int n)
{
	int end = 0;
	int tmp = 0;
	for(end= 0; end< n-1; end++)
	{
		tmp= arr[end+1];
		while(end>= 0)
		{
			if(tmp< arr[end])
			{
				arr[end+1] = arr[end];
				end--;

			}
			else
				break;
		}
		arr[end+1] = tmp;
	}
}

void ShellSort(int* arr, int n)
{
	int gap =n;
	int i = 0;
	while(gap > 0)
	{
		gap = gap / 3 + 1;
		i = 0;
		for(i = 0; i < n-gap; ++i)
		{
			int end = i;
			int tmp = 0;
			tmp = arr[end + gap];
			while(end >= 0)
			{
				if(tmp < arr[end])
				{
					arr[end+gap] = arr[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			arr[end+ gap] = tmp;

		}
		if(gap == 1)
			break;

	}
}

void SelectSort(int * arr, int n)

{
	int max = n-1;
	int min = 0;
	int i = 0;
	while(max > min)
	{
		for(i= min; i<= max; i++)
		{
			if(arr[i] > arr[max])
			{
				Swap(&arr[i] , &arr[max]);
			}
			if(arr[i] < arr[min])
			{
				Swap(&arr[i] , &arr[min]);
			}
		}
		min++;
		max--;
	}
}

void AdjustDown(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;
	int cur = parent;

	while(child <= n-1)
	{
		if(arr[child+1] > arr[child] && child+1 <n)
		{
			child =child + 1;
		}
		if(arr[cur] < arr[child])
		{
			Swap(&arr[cur],&arr[child]);
			cur = child;
			child= cur * 2 +1;
		}
		else
		{
			break;
		}

	}
}

void HeapSort(int* arr, int n)
{
	//建大堆
	int root = ((n-1)-1)/2;
	int end = n-1;
	while(root>=0)
	{
		AdjustDown(arr, n, root);
		root--;
	}
	while(end>=0)
	{
		Swap(&arr[end], &arr[0]);
		AdjustDown(arr, end, 0);
		end--;
	}

}


//三数取中
int GetMid(int * arr , int begin, int end )
{
	int mid = begin + ((end - begin) >> 1);
	if(arr[mid] > arr[begin])
	{
		if(arr[mid] < arr[end])
			return mid;
		else if(arr[begin] > arr[end])
			return begin;
		else
			return end;
	}
	else
	{
		if(arr[mid] > arr[end])
			return mid;
		else if(arr[begin] < arr[end])
			return begin;
		else
			return end;
	}
}


//PartSort()函数负责将数组中大于key的放到key的右边，小于key的放到key的左边，
//key通过三数取中法GetMid得到，

int PartSort1(int * arr, int begin, int end)
{
	int mid = GetMid(arr, begin, end);
	int ret =0; 
	int key =0; 
	Swap(&arr[mid], &arr[begin]);
	ret = begin;
	key = arr[begin];
		while(begin < end)
		{
			while(begin < end && arr[end] >= key)
				end--;
			while(begin < end && arr[begin] <= key)
				begin++;
			if(begin < end)
				Swap(&arr[begin], &arr[end]);

		}
		arr[ret] = arr[begin];
		arr[begin] = key;
		return begin;
}

//2、挖坑法
int PartSort2(int* arr, int begin, int end)
{
	int mid = GetMid(arr, begin, end);
	int key= 0;
	Swap(&arr[begin], &arr[mid]);
	key = arr[begin];
	while(begin < end)
	{
		//从右开始找  比key小的
		while(begin < end && arr[end] >= key)
		{
			end--;
		}
		arr[begin] = arr[end];
		//从左开始找  比key大的
		while(begin < end && arr[begin] <= key)
		{
			begin++;
		}
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}

//3、前后指针法
int PartSort3(int* arr, int begin, int end)
{
	int mid = GetMid(arr, begin, end);
	int key = 0, prev = 0, cur = 0;
	Swap(&arr[begin], &arr[mid]);
	key = arr[begin];
	prev = begin;
	cur = prev + 1;
	while(cur <= end)
	{
		if(arr[cur] < key && ++prev)
		{
			if(cur != prev)
			{
				Swap(&arr[cur], &arr[prev]);
			}
		}
		cur++;
	}

	Swap(&arr[begin], &arr[prev]);
	return prev;
}



void QuickSort(int* arr, int begin, int end)
{
	int mid;
	if (begin >= end)
		return;
	if(begin<end)
	{
		//mid = PartSort1(arr, begin, end);
		mid = PartSort2(arr, begin, end);
		//mid = PartSort3(arr, begin, end);
		QuickSort(arr, begin, mid - 1);
		QuickSort(arr, mid+1, end);
	}
	
}


void _MergrSort(int* arr, int left, int right, int* tmp)
{
	int mid = left + ((right - left)>>1);
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int ret = left;
	if(left >= right)
		return;
//	int mid = GetMid(left, right);
	_MergrSort(arr, left, mid, tmp);
	_MergrSort(arr, mid+1, right, tmp);



	while(begin1 <= end1 && begin2 <= end2)
	{
		if(arr[begin1] <= arr[begin2])
		{
			tmp[left] = arr[begin1];
			begin1++;
		}
		else
		{
			tmp[left] = arr[begin2];
			begin2++;
		}
		left++;
	}
	//当其中一个区间遍历完后、把另一个区间剩下的元素拷贝到tmp数组中
	while(begin1 <= end1)
	{
		tmp[left] = arr[begin1];
		begin1++;
		left++;
	}
	while(begin2 <= end2)
	{
		tmp[left] = arr[begin2];
		begin2++;
		left++;
	}
	while(ret <= right)
	{
		arr[ret] = tmp[ret];
		ret++;
	}

}

void MergrSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergrSort(arr, 0, n-1, tmp);
	free(tmp);
}



void CountSort(int* arr, int n)
{
	int max = arr[0];
	int min = arr[0];
	int i = 0;
	int size = 0;
	int* tmp = NULL;
	int begin = 0;
	for(i = 0; i < n; i++)
	{
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}
	size = max - min + 1;
	tmp = (int*)malloc(sizeof(int) * size);
	memset(tmp, 0, sizeof(int) * size);
	
	while(begin < n)
	{
		tmp[arr[begin] - min]++;
		begin++;
	}
	begin = 0;
	i = 0;
	while(begin < size)
	{
		while(tmp[begin] > 0)
		{
			arr[i] = begin + 1;
			i++;
			tmp[begin]--;

		}
		begin++;
	}
}



void SortTest()
{
	int arr1[]={9, 5, 6, 7, 1, 2, 3, 5, 8, 4};
	int arr2[]={9, 5, 6, 7, 1, 2, 3, 5, 8, 4};
	int arr3[]={9, 5, 6, 7, 1, 2, 3, 5, 8, 4};
	int arr4[]={9, 5, 6, 7, 1, 2, 3, 5, 8, 4};


	int size= sizeof(arr1)/sizeof(arr1[0]);
	/*InsertSort(arr1, size);
	ShellSort(arr2, size);
	SelectSort(arr3, size);
	HeapSort(arr4, size);

	ArrayPrint(arr1, size);
	ArrayPrint(arr2, size);
	ArrayPrint(arr3, size);
	ArrayPrint(arr4, size);*/

	QuickSort(arr1, 0, size-1);
	MergrSort(arr2, size);
	CountSort(arr3, size);
	ArrayPrint(arr1, size);
	ArrayPrint(arr2, size);
	ArrayPrint(arr3, size);




}

