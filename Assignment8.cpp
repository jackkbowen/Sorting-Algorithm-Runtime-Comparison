#include <iostream>
#include <iomanip>
#include <ctime>
#include "Sorters.h"

using namespace std;

int toSort1[10000];
int toSort2[20000];
int toSort3[30000];
int toSort4[40000];
int toSort5[50000];

int main()
{
	//Start execution time clock.
	clock_t start, finish;
	start = clock();

	cout << "All measurements are in seconds." << endl;
	cout << setw(5) << "Data Size" << setw(13) << "Insertion" << setw(10) << "Bubble" << setw(13) << "Selection" << setw(10) << "Heap" << setw(10) << "Quick" << setw(10) << "Merge" << endl;
	
	//Puts random ints into each array
	for (int i = 0; i < 10000; i++)
	{
		toSort1[i] = rand() % 1000;
	}

	for (int i = 0; i < 20000; i++)
	{
		toSort2[i] = rand() % 1000;
	}

	for (int i = 0; i < 30000; i++)
	{
		toSort3[i] = rand() % 1000;
	}

	for (int i = 0; i < 40000; i++)
	{
		toSort4[i] = rand() % 1000;
	}

	for (int i = 0; i < 50000; i++)
	{
		toSort5[i] = rand() % 1000;
	}

	//Output each sorts runtime

	cout << setw(5) << "10000" << setw(14) << InsertionSort(toSort1, 10000);
	cout << setw(12) << BubbleSort(toSort1, 10000);
	cout << setw(12) << SelectionSort(toSort1, 10000);
	cout << setw(13) << HeapSort(toSort1, 10000);
	cout << setw(9) << QuickSort(toSort1, 10000);
	cout << setw(10) << MergeSort(toSort1, 10000) << endl;

	cout << setw(5) << "20000" << setw(14) << InsertionSort(toSort2, 20000);
	cout << setw(12) << BubbleSort(toSort2, 20000);
	cout << setw(12) << SelectionSort(toSort2, 20000);
	cout << setw(13) << HeapSort(toSort2, 20000);
	cout << setw(9) << QuickSort(toSort2, 20000);
	cout << setw(10) << MergeSort(toSort2, 20000) << endl;

	cout << setw(5) << "30000" << setw(14) << InsertionSort(toSort3, 30000);
	cout << setw(12) << BubbleSort(toSort3, 30000);
	cout << setw(12) << SelectionSort(toSort3, 30000);
	cout << setw(13) << HeapSort(toSort3, 30000);
	cout << setw(9) << QuickSort(toSort3, 30000);
	cout << setw(10) << MergeSort(toSort3, 30000) << endl;

	cout << setw(5) << "40000" << setw(14) << InsertionSort(toSort4, 40000);
	cout << setw(12) << BubbleSort(toSort4, 40000);
	cout << setw(12) << SelectionSort(toSort4, 40000);
	cout << setw(13) << HeapSort(toSort4, 40000);
	cout << setw(9) << QuickSort(toSort4, 40000);
	cout << setw(10) << MergeSort(toSort4, 40000) << endl;

	cout << setw(5) << "50000" << setw(14) << InsertionSort(toSort5, 50000);
	cout << setw(12) << BubbleSort(toSort5, 50000);
	cout << setw(12) << SelectionSort(toSort5, 50000);
	cout << setw(13) << HeapSort(toSort5, 50000);
	cout << setw(9) << QuickSort(toSort5, 50000);
	cout << setw(10) << MergeSort(toSort5, 50000) << endl;


	finish = clock();
	double duration = ((double)(finish - start)/CLOCKS_PER_SEC);
	cout << "Execution time : " << duration << " s " << endl;
	

}


