#ifndef _ALGORITHMS_H
#define _ALGORITHMS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void InsertionSort(int arr[], int size);

void BubbleSort(int arr[], int size);

void Merge    (int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left,          int right);

void Heapify (int arr[], int size, int root);
void HeapSort(int arr[], int size);

void Swap     (int* a, int* b);
int  Partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);


#endif
