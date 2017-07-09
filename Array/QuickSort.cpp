//http://www.geeksforgeeks.org/quick-sort/
#include <iostream>

using namespace std;
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
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
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before sort: ";
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}

/*******************************************************/

// My first Quick Sort
#include <iostream>
#include <array>
using namespace std;
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int arr[], int size){
    for(int i=0; i<size; i++) cout << arr[i] << " ";
    cout << endl;
}
int partition(int arr[], int l, int r){
    int t = arr[r];
    int i = l;
    for(int j=l; j<r; j++){
        if(arr[j] <= t) swap(&arr[i++], &arr[j]);
    }
    swap(&arr[i], &arr[r]);
    return i;
}
void quickSort(int arr[], int l, int r){
    if( l>=r ) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}
int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    quickSort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}

