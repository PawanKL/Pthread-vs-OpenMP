#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#define MAX 10000
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
   pthread_t thread;
   struct ArrayIndex ai;
   ai.low = 0;
   ai.high = MAX - 1;
   clock_t t1,t2;

   
   //Generating Random values..

   srand(time(NULL));
   printf("Unsorted Data\n");z
   for(i=0;i<MAX;i++)
   {
	arr[i]=rand() % MAX;
	printf("%d ",arr[i]);
   }
   printf("\n");
   t1 = clock();
   retval = pthread_create(&thread,NULL,QuickSort_pthread,&ai);
   if(retval) 
   {  
          printf("Thread Creation Failed...!! Return value is %d\n",retval);
	  return 0;

   }
   pthread_join(thread,NULL);
   t2 = clock();
   double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
   printf("Sorted Data\n");
   for(i=0;i<MAX;i++)
   {
     printf("%d ",arr[i]);
   }
  printf("\nTime Elapsed: %.5f\n",t); 

  return 0;
}

