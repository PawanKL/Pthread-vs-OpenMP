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
   srand(time(NULL));
   printf("Unsorted Data\n");
   for(i=0;i<MAX;i++)
   {
	arr[i]=rand() % MAX;
	printf("%d ",arr[i]);
   }
   printf("\n");
   pthread_t thread;
   struct ArrayIndex ai;
   ai.low = 0;
   ai.high = MAX - 1;
   clock_t t1,t2;
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
void *QuickSort_pthread(void *ptr)
{
	struct ArrayIndex *p = (struct ArrayIndex*)ptr;
	int start=p->low;
	int end=p->high;
	if(start<end)
        {
	   int i,p = Partition(start,end);
	   pthread_t t1,t2;
	   struct ArrayIndex a1,a2;
	   a1.low=start;
	   a1.high=p-1;
	   a2.low=p+1;
	   a2.high=end;
	   int retval;

	   retval = pthread_create(&t1,NULL,QuickSort_pthread,&a1);
	   if(retval) 
	   {  
             printf("Thread Creation Failed...!! Return value is %d\n",retval);		  	       return 0;
           }

           retval = pthread_create(&t2,NULL,QuickSort_pthread,&a2);
           if(retval) 
           {  
              printf("Thread Creation Failed...!! Return value is %d\n",retval);
	      return 0;

           }	
           pthread_join(t1,NULL);
           pthread_join(t2,NULL);
           return 0;
        }
        else
        {
           return 0;
        }
}
int Partition(int low, int high)
{
  int j,i,pivot=arr[low],temp;
  j=high+1;
  for(i=high;i>0;i--)
  {
    if(arr[i]>pivot)
    {
      j--;
      temp=arr[j];
      arr[j]=arr[i];
      arr[i]=temp;
   }
 }
temp=arr[j-1];
arr[j-1]=arr[low];
arr[low]=temp;
return (j-1);
}
