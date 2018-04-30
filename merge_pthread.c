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
}

