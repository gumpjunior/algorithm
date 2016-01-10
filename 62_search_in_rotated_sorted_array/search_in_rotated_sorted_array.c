/*
 ============================================================================
 Name        : search.c
 Author      : gumpjunior
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int search_in_rotated_sorted_array(int* arr, int size, int target);
int test_search_in_rotated_sorted_array(int* arr, int size, int target);

int main(void) {
    
    printf("Program starts!\n");
    
    int arr[]  = {4, 6, 7, 8, 99, 0, 2, 3};
    int size   = sizeof(arr)/sizeof(int);
    int target, i;
    //target = arr[4];

    //test_search_in_rotated_sorted_array(arr, size, target);
    for (i=0; i<size; ++i) {
        target = arr[i];
        test_search_in_rotated_sorted_array(arr, size, target);
    }

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}

int search_in_rotated_sorted_array(int* arr, int size, int target) {
    
    int start = 0;
    int end   = size - 1;
    int mid   = -1;

    while (start+1 < end) {
        mid = start + (end-start)/2;
        if (arr[mid] > arr[start]) {        //arr[mid] != arr[start] never.
            if (target > arr[mid] || target < arr[start]) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        else {
            if (target >= arr[mid] && target <= arr[end]) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
    }

    if (arr[start] == target) {
        return start;
    }
    if (arr[end] == target) {
        return end;
    }
    return -1;

}

int test_search_in_rotated_sorted_array(int* arr, int size, int target) {
    int returnVal = -1;
    returnVal = search_in_rotated_sorted_array(arr, size, target);
    printf("\nTarget is arr[%d] = %d\n", returnVal, arr[returnVal]);
    return returnVal;
}
