/**
 * Program to implement buuble sort code and note down time to bubble sort using gettimeofday function.
 *
 * Compilation: gcc -o assign_2 assign_2.c
 * Execution:./assign_2
 *
 * @Aniket , (1910990836) , 26/07/2021
 * Assignment 1
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
/**
 * Function to generate array of random elements
 *
 * Parameters:
 * a[]:array of integers
 * n: size of array 
 * 
 */
void generate_input(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		a[i] = rand() % n + 1;
	}
}

/**
 * Function to do bubble sort
 *
 * Parameters:
 * a[]: array of integers
 * n: size of array
 * 
 */
void insertion_sort(int a[], int n)
{
    int i, j;
    int curr;
    for( i = 0 ; i < n; i++)
    {
        curr = a[i];
	j = i - 1 ;
	while ( j > 0 && a[j] > curr)
	{
	    a[j+1] = a[j];
	    j = j - 1;
	}
	a[j+1] = curr;
    }
}


/**
 * Function to compute time to sort array of random elements
 *
 * Parameters:
 * intial_input_size: size of array
 * increment_by: to increment size of array
 * prints time required to sort a random array of given size
 */
void result_3(int intial_input_size, int increment_by )
{
    struct timeval te;
    int i;
    int value = intial_input_size;
    for(i = 0; i < 8; i++)
        {
	    int n = intial_input_size + increment_by * i;
	    int a[n];
	    generate_input(a , n);
	    gettimeofday(&te, NULL);
	    long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
	    insertion_sort(a, n);
	    gettimeofday(&te, NULL);
            long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
	    printf("\t %lld", end - start);
            printf("\n");

	}
}


/**
 * Function to compute time to sort array of sorted data
 *
 * Parameters:
 * intial_input_size: size of array
 * increment_by: to increment size of array
 * prints time required to sort a sorted array of given size
 */
void result_2(int intial_input_size, int increment_by )
{
	struct timeval te;
	int i;
	int value = intial_input_size;
	for(i = 0; i < 8; i++)
	{
		int n = intial_input_size + increment_by * i;
		int a[n];
		generate_input(a , n);
		insertion_sort(a, n);
		
		gettimeofday(&te, NULL);
		long long start = te.tv_sec * 10000LL + te.tv_usec / 100;
		insertion_sort(a, n);
		gettimeofday(&te, NULL);
		long long end = te.tv_sec * 10000LL + te.tv_usec / 100;
		printf("\t %lld", end - start);
                printf("\n");
		

	}
}


/**
 * Function to compute time to sort array of reversely sorted data
 *
 * Parameters:
 * intial_input_size: size of array
 * increment_by: to increment size of array
 * prints time required to sort a reversely sorted  array of given size
 */
void result_1(int intial_input_size, int increment_by )
{
	struct timeval te;
	int i;
	int value = intial_input_size;
	for(i = 0; i < 8; i++)
	{
		int n = intial_input_size + increment_by * i;
		int a[n];
		generate_input(a , n);
	
		insertion_sort(a, n);
		
		reverse_array(a, 0 , n - 1);
		gettimeofday(&te, NULL);
		long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
		insertion_sort(a, n);
		gettimeofday(&te, NULL);
		long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
		printf("\t %lld", end - start);
                printf("\n");

	}
}


/**
 * Function to reverse an array
 *
 * Parameters:
 * *arr: array to reverse
 * start: starting index of array
 * end: ending index of array
 * 
 */
void reverse_array(int *arr, int start , int n)
{
    int j=n;
    while(start<j)
    {
        arr[j]=arr[start]+arr[j];
	arr[start]=arr[j]-arr[start];
	arr[j]=arr[j]-arr[start];
        start++;
	j--;
    }
}

int main()
{       
	// variable to take intial size of array
	int intial_input_size = 8000;
	// variable by which we increase intial size of array
	int increment_by = 4000;

	printf("For Random data -->\n");
	result_3(intial_input_size,increment_by);
	printf("\n");

	printf("For Sorted Data -->\n");
        result_2(intial_input_size,increment_by);
	printf("\n");

        printf("For Reversely Sorted Data-->\n");
        result_1(intial_input_size,increment_by);
	printf("\n");
}

