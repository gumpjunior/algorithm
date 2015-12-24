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
#include <stdint.h>

#define K (1024)
//#define 2K 2*K        //Macro cannot starts with numbers
#define twoK  (2*K)
#define fourK (4*K)

int main(void) {

    printf("Program starts!\n");

    //============================================================
    // Allocate memory in unit of char/uint8_t.
    // This can lead to the right result.
    // Because malloc allocate memory in unit of byte.
    //============================================================
    //
    printf("\n//====================================================\n");
    printf("// Allocate memory in unit of char/uint8_t\n");
    printf("//====================================================\n");

    uint8_t* addr = (uint8_t*)malloc(sizeof(uint8_t));
    if (addr == NULL) {
        printf("\nError: memory allocation failed\n");
        return EXIT_FAILURE;
    }
    uint8_t* addrStart = NULL;

    //addrStart = addr + ( fourK - ((int)addr % fourK));
    addrStart = addr + ( fourK - ((long)addr % fourK));

    //If printing out a NULL pointer will show: (nil).
    //Print out addr
    if ((long)addr % fourK) {
        printf("\nAddress \"addr\" is NOT aligned yet.\n");
    }
    else {
        printf("\nAddress \"addr\" is already aligned.\n");
    }
    printf("addr = %p\n", addr);


    //Print out addStart
    long temp;
    if ((long)addrStart % fourK) {
        printf("\nAddress \"addrStart\" is NOT aligned, which is wrong.\n");
        temp = (long)addrStart % fourK;
        printf("addrStart = %ld\n", temp);
    }
    else {
        printf("\nAddress \"addrStart\" is aligned, which is right.\n");
    }
    printf("Aligned address addrStart = %p\n", addrStart);

    //============================================================
    // Allocate memory in unit of oher unit, like int.
    // This can lead to the wrong result.
    //============================================================

    printf("\n//====================================================\n");
    printf("// Allocate memory in unit of other data type, like int\n");
    printf("//====================================================\n");

    int* addr2 = (int*)malloc(sizeof(int));
    if (addr2 == NULL) {
        printf("\nError: memory allocation failed\n");
        return EXIT_FAILURE;
    }
    int* addrStart2 = NULL;

    addrStart2 = addr2 + ( fourK - ((long)addr2 % fourK));

    //Print out addr2
    if ((long)addr2 % fourK) {
        printf("\nAddress \"addr2\" is NOT aligned yet.\n");
    }
    else {
        printf("\nAddress \"addr2\" is already aligned.\n");
    }
    printf("addr2 = %p\n", addr2);


    //Print out addStart2
    long temp2;
    if ((long)addrStart2 % fourK) {
        printf("\nAddress \"addrStart2\" is NOT aligned, which is wrong.\n");
        temp2 = (long)addrStart2 % fourK;
        printf("addrStart2 = %ld\n", temp2);
    }
    else {
        printf("\nAddress \"addrStart2\" is aligned, which is right.\n");
    }
    printf("Aligned address addrStart2 = %p\n", addrStart2);

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}

