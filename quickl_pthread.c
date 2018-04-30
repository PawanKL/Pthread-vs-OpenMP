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
