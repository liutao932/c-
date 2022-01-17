#include "Sort.h"

void PrintArray(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// ʱ�临�Ӷȣ�O(N^2)
// ��ã�O(N)   -- ˳��������߽ӽ�����
// ���O(N^2) -- ����
// �ռ临�Ӷȣ�O(1)
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; ++i)
	{
		// ��x����[0, end]��������
		int end = i;
		int x = a[end+1];
		while (end >= 0)
		{
			if (a[end] > x)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = x;
	}
}

// ϣ������
// O(N^1.3)
void ShellSort(int* a, int n)
{
	// ��gap�������ݽ���Ԥ����
	//int gap = 3;

	/*for (int j = 0; j < gap; ++j)
	{
		for (int i = j; i < n - gap; i += gap)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = x;
		}
	}*/

	// ���Ԥ����(gap > 1) +ֱ�Ӳ��� (gap == 1)
	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;
		
		// ����һ����
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = x;
		}
	}	
}

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

// ѡ������
// ʱ�临�Ӷȣ�O(N^2)
// ��ã�O(N^2)
// �����������������Ϊ����ʲô�������O(N^2)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[mini])
				mini = i;

			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		// begin == maxiʱ����󱻻����ˣ�����һ��maxi��λ��
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// ѡ�����Һ�����С����һ��
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		// ���С�ĺ���С�ڸ��ף��򽻻������������µ���
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// ������
void HeapSort(int* a, int n)
{
	// O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}