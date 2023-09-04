#include "algorithms.h"

void BubbleSort(int arr[], int size) {
  for(int i = 0; i < size - 1; ++i) {
    for(int j = 0; j < size - i - 1; ++j) {
      if(arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
};

void Merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int* L = new int[n1];
  int* R = new int[n2];

  for(int i = 0; i < n1; i++)
    L[i] = arr[left + i];

  for(int i = 0; i < n2; i++) 
    R[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = left;
  while(i < n1 && j < n2) {
    if(L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while(i < n1) {
    arr[k++] = L[i++];
  }

  while(j < n2) {
    arr[k++] = R[j++];
  }

  delete[] L;
  delete[] R;
};
void MergeSort(int arr[], int left, int right) {
  if(left < right) {
    int mid = left + (right - left) / 2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    Merge(arr, left, mid, right);
  }
};

void Heapify(int arr[], int size, int root) {
  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if(left < size && arr[left] > arr[largest])
    largest = left;

  if(right < size && arr[right] > arr[largest])
    largest = right;

  if(largest != root) {
    std::swap(arr[root], arr[largest]);
    Heapify(arr, size, largest);
  }
};
void HeapSort(int arr[], int size) {
  for(int i = size / 2 - 1; i >= 0; i--)
    Heapify(arr, size, i);

  for(int i = size - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);
    Heapify(arr, i, 0);
  }
};

void Swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
};

int Partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++) {
    if(arr[j] <= pivot) {
      i++;
      Swap(&arr[i], &arr[j]);
    }
  }
  Swap(&arr[i + 1], &arr[high]);
  return (i + 1);
};

void QuickSort(int arr[], int low, int high) {
  if(low < high) {
    int pi = Partition(arr, low, high);
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
};

void InsertionSort(int arr[], int size) {
  for(int i = 1; i < size; ++i) {
    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
};
