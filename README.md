# Pthread-vs-OpenMP
##### Contributors:
Pawan Kumar K16-3965 Inseya Batool K15-2265
## Introduction
Parallel programming is about dividing a program into multiple sub programs and each program will be run on separate processor or core. Each core have multiple threads the problem is to divide the task into multiple tasks so that they can run concurrently on different threads. We used parallel programming model and apply it on sorting algorithms which Merge sort, Quick sort.

A sorting algorithm is a method for reorgaizing a large number of items into a specific order, such as alphabetical, highest-to-lowest value or shortest-to-longest distance. Sorting Algorithms like merge sort and quick sort and radix sort can be run parallel
by using data parallelism and Task parallelism. We have used Data parallelsim by dividing a huge array into sub arrrays and perform sort in individual array concurrently.

There are many API'S available out there we have pthread which POSIX library and OpenMp which was a project of Intel.
Pthread is low level implementation and OpenMp is higher level implementation. For example we assembly language and C language.
OpenMp do all the stuff by just writing #pragma omp parallel and that will be run parallel with given number of threads.
In Pthread there are two functions create and join threads.

## Getting Started

Installation Procedure:

1. Open your terminal by pressing <code>Ctrl + Alt + T</code>
2. Type <code>sudo apt-get install git</code> to install git on your linux system. Skip this step if you have installed git on your system.
3. After the installation done, type <code>git clone https://github.com/PawanKL/Pthread-vs-OpenMP</code>
4. After step(3) type cd Pthread-vs-OpenMP
5. Type ls to list all source files
6. Compile source code by typing <code>gcc -o any_name merge_pthread.c -lpthread</code>. For *omp.c* files replace *-lpthread* with *-fopenmp*
and *pthread.c* with *omp.c*
7. Execute the compiled program by typing <code>./any_name</code>

## Explanation

In OpenMp version we used Section clause which defines how many sections will be run in parallel. In both merge and quick sort we have define two sections running parallel. One for the half part of the array and other for remaining part of array which they will be further divided in sub parts.

In Pthread version we create one main thread for execution of two local threads running parallel. In both merge and quick sort we create one main thread and two local threads and two local threads wil be created simultaneously for each recursive call. One for the half part of the array and other for remaining part of array which they will be further divided in sub parts.

Additional Libraries Used: <pthread.h> and <omp.h>

## Glossary

### Threads

A thread of execution is the smallest sequence of programmed instructions that can be managed independently by a scheduler, which is typically a part of the operating system. The implementation of threads and processes differs between operating systems, but in most cases a thread is a component of a process. Multiple threads can exist within one process, executing concurrently and sharing resources such as memory, while different processes do not share these resources. In particular, the threads of a process share its executable code and the values of its variables at any given time.

#### Pthread
<pre>
<code>pthread_t: is the data-type for the threads being used that is included in the library pthread.

pthread_create(): is a function used to create threads. It requires four parameters: 
pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

pthread_join(): is also a function that shall suspend execution of the calling thread until the target thread terminates, unless the target thread has already terminated. This function requires two parameters:
pthread_join(pthread_t thread, void **value_ptr);</code>
</pre>

#### OpenMP

<pre>
<code>#pragma omp parallel starts parallel region of code

#pragma omp parallel num_thread num starts parallel region of code with number of threads given

#pragma omp parallel sections(num) start parallel region of code with number of sections

#pragma omp parallel section(num) single thread will execute this section all other tasks will wait until both sections executed completley</code>
</pre>
