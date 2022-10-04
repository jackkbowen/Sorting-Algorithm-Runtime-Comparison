#include <iostream>
#include <ctime>
#include "Sorters.h"

using namespace std;

double InsertionSort(int arr[], int n)
{
	clock_t start, finish;
	start = clock(); // Time in milliseconds.

	int firstOutOfOrder, location, temp;

	//Finds the first out of order element then compares it to the rest of the list
	//finding where it is less than the compared element.
	for (firstOutOfOrder = 1; firstOutOfOrder < n; firstOutOfOrder++)
	{
		if (arr[firstOutOfOrder] < arr[firstOutOfOrder - 1])
		{
			temp = arr[firstOutOfOrder];
			location = firstOutOfOrder;

			do
			{
				arr[location] = arr[location - 1];
				location--;
			} while (location > 0 && arr[location - 1] > temp);

			arr[location] = temp;
		}
	}
	finish = clock();
	double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
	return duration;
}

double BubbleSort(int arr[], int n)
{
	clock_t start, finish;
	start = clock(); // Time in milliseconds.

	//Swaps element and element + 1 if it is less
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - (i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	finish = clock();
	double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
	return duration;
}

double SelectionSort(int arr[], int n)
{
	clock_t start, finish;
	start = clock(); // Time in milliseconds.

	//Finds the smallest element in the list and moves it to the top of the list
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}

			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}

	finish = clock();
	double duration = ((double)(finish - start)/CLOCKS_PER_SEC);
	return duration;
}

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;
	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;
	// If largest is not root
	if (largest != i) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

double HeapSort(int arr[], int n)
{
	clock_t start, finish;
	start = clock(); // Time in milliseconds.
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
	finish = clock();
	double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
	return duration;
}

double QuickSort(int arr[], int n)
{
	//Calls the sorting function and tracks runtime
	clock_t start, finish;
	start = clock(); // Time in milliseconds.

	recQuickSort(arr, 0, n - 1);

	finish = clock();
	double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
	return duration;
}

int partition(int arr[], int low, int high)
{
	int pivot, index, smallIndex;

	int temp = arr[low];
	arr[low] = arr[(high + low) / 2];
	arr[(high + low) / 2] = temp;

	//Compare each element with the pivot
	//Swap if 
	pivot = arr[low];
	smallIndex = low;

	for (index = low + 1; index <= high; index++)
	{
		if (arr[index] < pivot)
		{
			smallIndex++;
			int temp = arr[smallIndex];
			arr[smallIndex] = arr[index];
			arr[index] = temp;
		}
	}

	int temp1 = arr[low];
	arr[low] = arr[smallIndex];
	arr[smallIndex] = temp1;

	return smallIndex;

}

void recQuickSort(int arr[], int low, int high)
{
	//Creates pivot point and recursivly sorts on either side of it.
	int pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		recQuickSort(arr, low, pivot - 1);
		recQuickSort(arr, pivot + 1, high);
	}
}

void merge(int arr[], const int i, const int j, const int k)
{
	//Create a left and right array
	const int num1 = j - i + 1;
	const int num2 = k - j;

	int* arr1 = new int[num1];
	int* arr2 = new int[num2];

	for (int n = 0; n < num1; n++)
	{
		arr1[n] = arr[i + 1];
	}

	for (int n = 0; n < num2; n++)
	{
		arr2[n] = arr[j + 1 + n];
	}

	int index1 = 0;
	int index2 = 0;
	int index3 = i;
	
	//Merge the two arrays back together
	while (index1 < num1 && index2 < num2)
	{
		if (arr1[index1] <= arr2[index2])
		{
			arr[index3] = arr1[index1];
			index1++;
		}

		else
		{
			arr[index3] = arr2[index2];
			index2++;
		}
		index3++;
	}

	//Copy leftover nums into one array
	while (index1 < num1)
	{
		arr[index3] = arr1[index1];
		index1++;
		index3++;
	}

	while (index2 < num2)
	{
		arr[index3] = arr2[index2];
		index2++;
		index3++;
	}
}

void MergeAlgo(int arr[], const int i, const int j, const int k)
{
	//Recursively call the sort for left and right
	if (i >= j)
		return;

	int k = i + (j - i) / 2;
	MergeAlgo(arr, i, k);
	MergeAlgo(arr, k + 1, j);

	merge(arr, i, k, j);

}

double MergeSort(int arr[], int n)
{
	//Calls the sorting function and tracks runtime
	clock_t start, finish;
	start = clock(); // Time in milliseconds.

	MergeAlgo(arr, 0, n - 1);

	finish = clock();
	double duration = ((double)(finish - start) / CLOCKS_PER_SEC);
	return duration;
}