#include"sort.h"
#include"stack.h"
static void InsertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int x = array[end + 1];
		while (end >= 0)
		{
			if (array[end] > x)
			{
				array[end + 1] = array[end];
				--end;
			}
			else
			{
				break;
			}
		}
		array[end + 1] = x;
	}
}
static void ShellSort(int* array, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int x = array[end + gap];
			while (end >= 0)
			{
				if (array[end] > x)
				{
					array[end + gap] = array[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			array[end + gap] = x;
		}
	}
}
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
static void SeleteSort(int* array, int n)
{
	int begin = 0, end = n - 1;
	while (begin <= end)
	{
		int min =begin, max = end;
		for (int i = begin; i <= end; ++i)
		{
			if (array[min] > array[i])
			{
				min = i;
			}
			if (array[max] < array[i])
			{
				max = i;
			}
		}
		swap(array[begin], array[min]);
		if (max == begin)
		{
			max = min;
		}
		swap(array[max], array[end]);
		++begin;
		--end;
	}
}
static void AdjustDown(int* array, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && array[child] < array[child + 1])
		{
			child++;
		}
		if (array[parent] < array[child])
		{
			swap(array[parent], array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}static void AdjustUp(int* array, int child)
{
	int parent = (child + 1) / 2;
	while (child > 0)
	{
		if (array[child] > array[parent])
		{
			swap(array[child], array[parent]);
			child = parent;
			parent = (child + 1) / 2;
		}
		else
		{
			break;
		}
	}
}
static void HeapSort(int* array, int n)
{
	/*for (int i = 0; i < n; ++i)
	{
		AdjustDown(array, i, n);
	}*/
	for (int i = 0; i < n; i++)
	{
		AdjustUp(array, i);
	}
	for (int end = n - 1; end >= 0; --end)
	{
		swap(array[0], array[end]);
		AdjustDown(array, 0, end);
	}
}
static void BubbleSort(int* array, int n)
{
	int begin = 0, end = n - 1;
	bool flag = false;
	while (begin <= end)
	{
		for (int i = 1; i <= end; ++i)
		{
			if (array[i - 1] > array[i])
			{
				swap(array[i - 1], array[i]);
				flag = true;
			}
		}
		if (!flag)
			break;
		--end;
	}
}
int MidNum(int* array, int left, int rigth)
{
	int mid = left + ((rigth - left) >> 1);
	if (array[left] < array[rigth])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[rigth])
			return rigth;
		else
			return mid;
	}
	else  //array[left] >= array[rigth]
	{
		if (array[mid] > array[left])
			return left;
		else if (array[rigth] > array[mid])
			return  mid;
		else
			return rigth;
	}
}
int partion1(int* array, int left, int rigth) //hoare法
{
	int mid = MidNum(array, left, rigth);
	swap(array[left], array[mid]);
	int key = left;
	while (left < rigth)
	{
		while (left < rigth && array[rigth] >= array[key])
			rigth--;
		while (left < rigth && array[left] <= array[key])
			left++;
		swap(array[left], array[rigth]);
	}
	swap(array[left], array[key]);
	return left;
}
int partion2(int* array, int left, int rigth)
{
	int mid = MidNum(array, left, rigth);
	swap(array[left], array[mid]);
	int provit = left;
	int key = array[left];
	while (left < rigth)
	{
		while (left < rigth && array[rigth] >= key)
		{
			rigth--;
		}
		array[provit] = array[rigth];
		provit = rigth;
		while (left < rigth && array[left] <= key)
		{
			left++;
		}
		array[provit] = array[left];
		provit = left;
	}
	array[provit] = key;
	return provit;
}
static int partion3(int* array, int left, int rigth)
{
	int prev = left;
	int cur = left + 1;
	int key = left;
	while (cur <= rigth)
	{
		if (array[cur] < array[key] && ++prev != cur)
		{
			swap(array[prev], array[cur]);
		}
		cur++;
	}
	swap(array[prev], array[key]);
	return prev;
}
static void QuickSortR(int* array, int left, int rigth)
{
	if (left >= rigth)
		return;
	/*if (rigth - left + 1 < 10)
	{
		InsertSort(array+ left, rigth - left + 1);
	}*/
	else
	{
		//int key = partion1(array, left, rigth);
		//int key = partion2(array, left, rigth);
		int key = partion3(array, left, rigth);
		QuickSortR(array, left, key - 1);
		QuickSortR(array, key + 1, rigth);
	}
	
}
static void QucikSortNor(int* array, int left,int rigth)
{
	stack s;
	s.push(left);
	s.push(rigth);
	while (!s.empty())
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();
		int key = partion1(array, begin, end);
		if (key + 1 < end)
		{
			s.push(key + 1);
			s.push(end);
		}
		if (begin < key - 1)
		{
			s.push(begin);
			s.push(key - 1);
		}
	}
}
void _MergeSortR(int* array, int left, int rigth, int* tmp)
{
	if (left >= rigth)
		return;
	int mid = left + ((rigth - left) >> 1);
	_MergeSortR(array, left, mid, tmp);
	_MergeSortR(array, mid + 1, rigth, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = rigth;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] < array[begin2])
		{
			tmp[index++] = array[begin1++];
		}
		else
		{
			tmp[index++] = array[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = array[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = array[begin2++];
	}
	for (int i = left; i <= end2; ++i)
	{
		array[i] = tmp[i];
	}
}
static void MergeSortR(int* array, int n)
{
	int* tmp = new int[n];
	_MergeSortR(array, 0, n-1, tmp);
	delete[]tmp;
}
static void MergeSortNor(int* array, int n)
{
	int* tmp = new int[n];
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = begin1;
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (array[begin1] < array[begin2])
				{
					tmp[index++] = array[begin1++];
				}
				else
				{
					tmp[index++] = array[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = array[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = array[begin2++];
			}
			for (int j = i; j <= end2; j++)
			{
				array[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	delete[]tmp;
}
static void CountSotr(int* array, int n)
{
	int min = array[0], max = array[0];
	for (int i = 1; i < n; ++i)
	{
		if (min > array[i])
			min = array[i];
		if (max < array[i])
			max = array[i];
	}
	int range = max - min + 1;
	int* tmp = new int[range];
	memset(tmp ,0, sizeof(int) * range);
	for (int i = 0; i < n; ++i)
	{
		tmp[array[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (tmp[i]--)
		{
			array[j++] = i + min;
		}
	}
	delete[]tmp;
}
void PrintSort(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void test(void)
{
	int array[] = { 9,6,0,7,8,1,5,2,4,3 };
	//InsertSort(array, 10);
	//ShellSort(array, 10);
	//SeleteSort(array, 10);
	//HeapSort(array, 10);
	//BubbleSort(array, 10);
	//QuickSortR(array, 0, 9);
	//QucikSortNor(array, 0, 9);
	//MergeSortR(array, 10);
	//MergeSortNor(array, 10);
	CountSotr(array, 10);
	PrintSort(array, 10);
}
int main()
{
	stack st;
	/*st.push_back(1);
	st.push_back(2);
	st.push_back(3);
	st.push_back(4);
	st.push_back(5);
	st.push_back(6);
	st.push_back(7);
	st.push_back(8);
	st.push_back(9);
	st.push_back(10);
	st.Print();*/
	test();
}
