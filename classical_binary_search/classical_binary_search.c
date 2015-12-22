/*
 ============================================================================
 Name        : binary.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int classical_binary_search_for_first_match(int* arr, int size, int target);
int test_classical_binary_search_for_first_match(int* arr, int size, int target);
int test_classical_binary_search_for_last_match(int* arr, int size, int target);

int main(void) {

    printf("Program starts!\n");

    //int arr[] = {1, 2, 3, 3, 5, 9, 12, 2, 3, 10, 11};
    int arr[] = {1, 2, 2, 3, 3, 3, 5, 9, 10, 11, 12};
    int size  = sizeof(arr)/sizeof(int);

    test_classical_binary_search_for_first_match(arr, size, 3);
    test_classical_binary_search_for_last_match(arr, size, 3);

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}


int classical_binary_search_for_first_match(int* arr, int size, int target) {

    if (arr == NULL || size == 0) {
        printf("\nArray does not exist!\n");
        return EXIT_FAILURE;
    }

    int start, end, mid;
    start = 0;
    end   = size-1;

    while ((start+1) < end) {
        mid = start + (end-start)/2;
        if (arr[mid] < target) {
            start = mid;
        }
        else if (arr[mid] == target) {
            end = mid;
        }
        else {
            end = mid;
        }
    }

    if (arr[start] == target) {     //Check start first.
        return start;
    }
    if (arr[end] == target) {
        return end;
    }
    printf("\nTarget does not exist in this array!\n");
    return EXIT_FAILURE;
}

int classical_binary_search_for_last_match(int* arr, int size, int target) {

    if (arr == NULL || size == 0) {
        printf("\nArray does not exist!\n");
        return EXIT_FAILURE;
    }

    int start, end, mid;
    start = 0;
    end   = size-1;

    while ((start+1) < end) {
        mid = start + (end-start)/2;
        if (arr[mid] < target) {
            start = mid;
        }
        else if (arr[mid] == target) {
            start = mid;
        }
        else {
            end = mid;
        }
    }

    if (arr[end] == target) {       //Check end first.
        return end;
    }
    if (arr[start] == target) {
        return start;
    }
    printf("\nTarget does not exist in this array!\n");
    return EXIT_FAILURE;
}

int test_classical_binary_search_for_first_match(int* arr, int size, int target) {

    int targetIndex = -1;
    targetIndex = classical_binary_search_for_first_match(arr, size, target);
    printf("\nTarget index is: %d\n", targetIndex);
    return EXIT_SUCCESS;

}

int test_classical_binary_search_for_last_match(int* arr, int size, int target) {

    int targetIndex = -1;
    targetIndex = classical_binary_search_for_last_match(arr, size, target);
    printf("\nTarget index is: %d\n", targetIndex);
    return EXIT_SUCCESS;

}
