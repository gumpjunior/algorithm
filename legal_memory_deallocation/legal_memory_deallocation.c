/*
 ============================================================================
 Name        : memory_deallocation_error.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    printf("Program starts!\n");

    int* ptr = NULL;
    free(ptr);

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}
