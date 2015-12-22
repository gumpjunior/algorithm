/*
 ============================================================================
 Name        : find.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description : 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int test_find_peak_element(int* arr, int size);

int main(void) {

    printf("Program starts!\n");

    int arr[] = {1, 3, 2, 5, 9, 4, 2, 1, 9, 11, 18, 21};
    int size = sizeof(arr)/sizeof(int);

    test_find_peak_element(arr, size);

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}


int find_peak_element(int* arr, int size) {
    
    int start = 0;
    int end   = size-1;
    int mid   = 0;

    while (start+1 < end) {
        mid = start + (end-start)/2;
        if (arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {         //dan zeng
            start = mid;
        }
        else if (arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]) {    //dan jian
            end = mid;
        }
        else if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {    //Peak
            return mid;
        }
        else {                                                        //bo gu
            start = mid;        //Either start or end = mid is fine.
        }
    }

    return (arr[start]>arr[end]) ? start : end;

}

int test_find_peak_element(int* arr, int size) {

    int returnVal = -1;
    returnVal = find_peak_element(arr, size);
    printf("\nOne peak element is arr[%d] = %d\n", returnVal, arr[returnVal]);

    return returnVal;

}
