#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 1000
void *mergesort_pthread(void *);
void merge(int,int);
int arr[MAX];
