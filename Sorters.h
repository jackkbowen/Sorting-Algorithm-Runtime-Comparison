#pragma once
#include <iostream>
#include <ctime>

using namespace std;


double InsertionSort(int arr[], int n);
double BubbleSort(int arr[], int n);
double SelectionSort(int arr[], int n);
double HeapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
double QuickSort(int arr[], int n);
void recQuickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
double MergeSort(int arr[], int n);
void MergeAlgo(int arr[], const int i, const int j, const int k);
void merge(int arr[], const int i, const int j, const int k);
