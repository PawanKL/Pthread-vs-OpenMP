#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h> 
#define MAX 1000
int partition (int arr[], int low, int high)
{
    int i,j,pivot = arr[high],temp;    // pivot
    i = low - 1;  // Index of smaller element
 
    for(j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            //swap(&arr[i], &arr[j]);
	    temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
        }
    }
    //swap(&arr[i + 1], &arr[high]);
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
	#pragma omp parallel sections num_threads(2)
	{
		#pragma omp section 
        	quickSort(arr, low, pi - 1);
		#pragma omp section
        	quickSort(arr, pi + 1, high);
	}
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[MAX],i;
    srand(time(NULL));
    for(i=0;i<MAX;i++){
     arr[i] = rand() % MAX;
    }
    clock_t t1,t2;
    t1 = clock();
    quickSort(arr, 0, MAX-1);
    t2 = clock();
    double t_time = (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Sorted array: n");
    printArray(arr, MAX);
    printf("\t\tTime Elapsed: %.5f\n",t_time);
    return 0;
}
