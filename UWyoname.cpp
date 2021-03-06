// UWyoname.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include "UWyoname.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <time.h>
#include <Timer.h>
using namespace std;

//Bubble sort 
void swapBubble(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swapBubble(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}
//end of bubble sort

//start of insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
//end of insertion sort

//start of selection sort
void swapSelection(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swapSelection(&arr[min_idx], &arr[i]);
	}
}
//end of selection sort

//start of merge sort
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
//end of merge sort

//start of quick sort

void swapQuick(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element 
			swapQuick(&arr[i], &arr[j]);
		}
	}
	swapQuick(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
//end of quick sort

int main()
{
	vector<int> bubbleVector;
	srand((unsigned)time(NULL));
	int a = 20000;
	for (int i = 0; i < a; i++) {
		int b = rand() % 500 + 1;
		bubbleVector.push_back(b);
		cout << bubbleVector[i] << endl;
	}
	start();
	int n = sizeof(bubbleVector) / sizeof(bubbleVector[0]);
	bubbleSort(bubbleVector, n);
	stop();

	
	vector<int> insertionVector;
	srand((unsigned)time(NULL));
	int a = 20000;
	for (int i = 0; i < a; i++) {
		int b = rand() % 500 + 1;
		insertionVector.push_back(b);
		cout << insertionVector[i] << endl;
	}
	start();
	int n = sizeof(insertionVector) / sizeof(insertionVector[0]);
	insertionSort(insertionVector, n);
	stop();


	vector<int> selectionVector;
	srand((unsigned)time(NULL));
	int a = 20000;
	for (int i = 0; i < a; i++) {
		int b = rand() % 500 + 1;
		selectionVector.push_back(b);
		cout << selectionVector[i] << endl;
	}
	start();
	int n = sizeof(selectionVector) / sizeof(selectionVector[0]);
	selectionSort(selectionVector, n);
	stop();


	vector<int> mergeVector;
	srand((unsigned)time(NULL));
	int a = 20000;
	for (int i = 0; i < a; i++) {
		int b = rand() % 500 + 1;
		mergeVector.push_back(b);
		cout << mergeVector[i] << endl;
	}
	start();
	int arr_size = sizeof(mergeVector) / sizeof(mergeVector[0]);
	mergeSort(mergeVector, 0, arr_size - 1);
	stop();
	


	vector<int> quickVector;
	srand((unsigned)time(NULL));
	int a = 20000;
	for (int i = 0; i < a; i++) {
		int b = rand() % 500 + 1;
		quickVector.push_back(b);
		cout << quickVector[i] << endl;
	}
	start();
	int n = sizeof(quickVector) / sizeof(quickVector[0]);
	quickSort(quickVector, 0, n - 1);
	stop();

	vector<int> stlVector;
	srand((unsigned)time(NULL));
	int a = 20000;
	for (int i = 0; i < a; i++) {
		int b = rand() % 500 + 1;
		stlVector.push_back(b);
		cout << stlVector[i] << endl;
	}
	start();
	int n = sizeof(stlVector) / sizeof(stlVector[0]);
	sort(stlVector, stlVector + n);
	stop();
	
	
	return 0;
}

