#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <omp.h>
 
#define MAX 1000
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
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
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        #pragma omp parallel sections num_threads(2) // Two threads are used here
	{
                #pragma omp section 
        	mergeSort(arr, l, m);
		#pragma omp section
        	mergeSort(arr, m+1, r);
 	}
        merge(arr, l, m, r);
    }
}
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
/* Driver program to test above functions */
int main()
{
 
    int arr[MAX],i;
    srand(time(NULL));
    for(i=0;i<MAX;i++){
     arr[i] = rand() % MAX;
    }
    clock_t t1,t2;
    t1 = clock();
    mergeSort(arr, 0, MAX - 1);
    t2 = clock();
    double t_time = (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, MAX);
    printf("\t\tTime Elapsed: %.5f\n",t_time);
    return 0;
 
}
