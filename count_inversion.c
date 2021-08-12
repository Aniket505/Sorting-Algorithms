/**
 * Program to count number of inversions in an array
 *
 * Compilation: gcc -o count_inversion count_inversion.c 
 * Execution:./count_inversion
 *
 * @Aniket , (1910990836) , 12/08/2021
 * Assignment_7
 *
 * Resources:
 * https://geeksforgeeks.org/counting-inversions/
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Function to merge two sorted arrays and count the number of inversions
 * a[] : Input Array
 * b[] : Auxiliary Array
 * start : starting index of array
 * end : index of last element in array
 */
int merge(int a[], int b[], int start, int mid, int end)
{
    int inversion = 0;
    int i = start; // index for left subarray
    int j = mid;   // index for right subarray
    int k = start; // index for merged subarray
    while ((i <= mid - 1) && (j <= end))
    {
        if (a[i] <= a[j])
        {                                      // if element of left subarray is smaller than element of right subarray , put element of left subarray to resultant array
            b[k++] = a[i++];
        }
        else                                   // if element of left subarray is greater than element of right subarray , put element of right subarray to resultant array
        {
            b[k++] = a[j++];
            inversion = inversion + (mid - i);
        }
    }

    while (i <= mid - 1)    // to copy remaining elements of left subarray
        b[k++] = a[i++];

    while (j <= end)        // to copy remaining elements of right subarray 
        b[k++] = a[j++];

    for (i = start; i <= end; i++)  //copy merged elements to original array
        a[i] = b[i];

    return inversion;
}


/*
 * A function to sort the array and return the number of inversions
 *
 * a[] : Input Array
 * b[] : Auxiliary Array
 * start : starting index of array
 * end : index of last element in array
 *
 */
int mergeSort(int a[], int b[], int start, int end)
{
    int mid;
    int inversion = 0;
    if (end > start)
    {
        mid = (end + start) / 2;                       // to calculate mid element index in array
 
	inversion += mergeSort(a, b, start, mid);      // to sort and count inversions in left subarray
	inversion += mergeSort(a, b, mid + 1, end);    // to sort and count inversions in right subarray 

	inversion += merge(a, b, start, mid + 1, end); // to merge the two sorted arrays and count the inversions
    }
    return inversion;
}


int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int a[n];

    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
    }

    // taking auxiliary array to do merge sort
    int* b = (int*)malloc(sizeof(int) * n);

    printf("Number of inversions : %d  ", mergeSort(a, b, 0, n-1));
    return 0;
}

