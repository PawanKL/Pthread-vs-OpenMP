#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h> 
#define MAX 1000
int partition (int arr[], int low, int high)
{
    int i,j,pivot = arr[low],temp; 
    i = high + 1; 
 
    for (j = high; j > 0; j--)
    {
        if (arr[j] > pivot)
        {
            i--;    
	    temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[i-1];
    arr[i-1] = temp;
    return (i-1);
}
