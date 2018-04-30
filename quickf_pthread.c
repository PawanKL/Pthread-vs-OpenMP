#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#define MAX 100
void *QuickSort_pthread(void *);
int Partition(int,int);
int arr[MAX];
struct ArrayIndex{
int low;
int high;
};
int main()
{
   int i,retval;
   printf("\n");
   clock_t t1,t2;
   pthread_t thread;
   struct ArrayIndex ai;
   ai.low = 0;
   ai.high = MAX - 1;

   // Generating Random values..   


   srand(time(NULL));
   printf("Unsorted Data\n");
   for(i=0;i<MAX;i++)
   {
	arr[i]=rand() % MAX;
	printf("%d ",arr[i]);
   }
}
