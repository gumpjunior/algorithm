/*
 ============================================================================
 Name        : longest_common_subsequence_main.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int longest_common_subsequence(char* str, int strSize, \
        char* str2, int str2Size, int** result);
void test_longest_common_subsequence();

int main(void) {

    printf("Program starts!\n");

    test_longest_common_subsequence();

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}

//============================================================
//============================================================

int longest_common_subsequence(char* str, int strSize, \
        char* str2, int str2Size, int** result) {

    int i = 0;
    int j = 0;
    int max = 0;

    //
    //Illegal case
    //
    if (str == NULL || str2 == NULL || str[0] == '\0' || str2[0] == '\0') {
        return -1;
    }

    //
    //Initialize
    //
    for (i=0; i<strSize; ++i) {
        result[i][0] = 0;
    }
    for (i=0; i<str2Size; ++i) {
        result[0][j] = 0;
    }

    //
    //Get length for longest common subsequence.
    //
    for (i=1; i<strSize; ++i) {
        for (j=1; j<str2Size; ++j) {
            if (str[i] == str2[j]) {
                max = (result[i][j-1] > result[i-1][j]) ? result[i][j-1] : result[i-1][j];
                result[i][j] = (max > (result[i-1][j-1] + 1)) ? max : (result[i-1][j-1] + 1);
            }
            else {
                result[i][j] = (result[i][j-1] > result[i-1][j]) ? result[i][j-1] : result[i-1][j];
            }
        }
    }

    return result[strSize-1][str2Size-1];
}

//============================================================
//============================================================

void test_longest_common_subsequence() {
    
    int i;
    //
    //Test case 1
    //
    int lcs = -1;
    //Memory allocation
    //Refer <Understanding and using C pointers>
    //Chapter4, allocating potentially noncontiguous memory.
    //Allocate a 2D memory space, size is row x column.
    char str[] = "abcd";
    int row = sizeof(str)/sizeof(str[0]) - 1;       //'\0' will be count as one item.
    //char str2[] = "abcd";
    char str2[] = "eacb";
    int column = sizeof(str2)/sizeof(str2[0]) - 1;
    //Add 1 to both row and column, coz 2D array result need to initialize 
    //extra lines for both row and column, result[0][x] and result[x][0].
    row++;
    column++;

    int** result = (int**)malloc(row * sizeof(char*));
    for (i=0; i<row; ++i) {
        *(result+i) = (int*)malloc(column * sizeof(char*));
    }

    //
    //Call DUT
    //
    lcs = longest_common_subsequence(str, row, str2, column, result);
    printf("\nThe lsc should be 4\n");
    printf("lsc = %d\n", lcs);

    //
    //Print out result
    //
    //...

    //Memory de-allocation.
    for (i=0; i<row; ++i) {
        free(result[i]);
        result[i] = NULL;
    }
    free(result);
    result = NULL;

    //
    //Test case 2
    //
    lcs = -1;
    //Memory allocation
    char str3[] = "abcd";
    row = sizeof(str3)/sizeof(str3[0]) - 1;
    char str4[] = "a0xasbdc3ud";
    column = sizeof(str4)/sizeof(str4[0]) - 1;
    row++;
    column++;

    result = (int**)malloc(row * sizeof(char*));
    for (i=0; i<row; ++i) {
        *(result+i) = (int*)malloc(column * sizeof(char*));
    }

    //
    //Call DUT
    //
    lcs = longest_common_subsequence(str3, row, str4, column, result);
    printf("\nThe lsc should be 4 as well\n");
    printf("lsc = %d\n", lcs);

    //Memory de-allocation.
    for (i=0; i<row; ++i) {
        free(result[i]);
        result[i] = NULL;
    }
    free(result);
    result = NULL;

    return;

}
