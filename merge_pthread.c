#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 1000
void *mergesort_pthread(void *);
void merge(int,int);
int arr[MAX];

struct ArrayIndex
{
 int low;
 int high;
 
};
int main()
{

 struct ArrayIndex ai;
 ai.low = 0;
 ai.high =  MAX - 1;
 pthread_t t;

 // Generating Random Values...
 
 printf("Unsorted Data\n");
 srand(time(NULL));
 int i;
 for(i=0;i<MAX;i++)
 {
   arr[i] = rand() % MAX; 
   printf("%d ",arr[i]); 

 }

 int retval;
 clock_t t1,t2;
 t1 = clock();
 
  retval = pthread_create(&t,NULL,mergesort_pthread,&ai);
  if(retval) 
  {  
          printf("Thread Creation Failed...!! Return value is %d\n",retval);
	  return 0;

  }
  pthread_join(t,NULL);
 t2 = clock();
 double t3 = (double)(t2 - t1)/CLOCKS_PER_SEC;
 printf("\nSorted Data\n");
 
 for(i=0;i<MAX;i++)
 {
   printf("%d ",arr[i]);
 }

 printf("\nTime Elapsed: %.5f\n",t3);

 return 0;

}
void* mergesort_pthread(void* ptr)
{
   struct ArrayIndex *p = (struct ArrayIndex *)ptr;
   struct ArrayIndex a1,a2;

   int mid = (p->low + p->high)/2;

   pthread_t t1,t2;
   int retval;

   a1.low = p->low;
   a1.high = mid;

   a2.low = mid + 1;
   a2.high = p->high;  

  if(p->low >= p->high)
  {
    return 0;
  } 
   
   retval = pthread_create(&t1,NULL,mergesort_pthread,&a1);
   if(retval) 
   {  
          printf("Thread Creation Failed...!! Return value is %d\n",retval);
	  return 0;

   }

   retval = pthread_create(&t2,NULL,mergesort_pthread,&a2);
   if(retval) 
   {  
          printf("Thread Creation Failed...!! Return value is %d\n",retval);
	  return 0;

   }	

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  
  merge(p->low,p->high);
  return 0;
}
