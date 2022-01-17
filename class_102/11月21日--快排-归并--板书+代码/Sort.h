#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// ����ʵ�ֵĽӿ�
void PrintArray(int* a, int n);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void HeapSort(int* a, int n);

// MaoPaoSort
// MaoPaoPaixXu
void BubbleSort(int* a, int n);

void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);

void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);

void CountSort(int* a, int n);