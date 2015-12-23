/*
 ============================================================================
 Name        : linked.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description : 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
//#include "linked_list.h"
//#define DEBUG_LOCAL 1

int test_list_init(sList* list);
void test_list_ins_next(sList* list);
void test_list_destroy(sList* list);

int main(void) {

    printf("Program starts!\n");

    sList myList;
    sList* pMyList = &myList;
    list_init(pMyList, element_destroy);

    //test list init function.
    test_list_init(pMyList);

    //test list insertion and remove.
    test_list_ins_next(pMyList);

    //test function list_destroy.
    test_list_destroy(pMyList);

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}

int test_list_init(sList* list) {

    printf("\n//==============================================\n");
    printf("//test_list_init starts");
    printf("\n//==============================================\n");

    if (list->size != 0 || list->head != NULL 
            || list->tail != NULL || list->destroy ==NULL ) {
        printf("Error: list initilization wrong!\n");
        //exit(-1);
        return EXIT_FAILURE;
    }

    printf("\nDEBUG: list_init testing done.\n");

    printf("\n//==============================================\n");
    printf("//test_list_init done");
    printf("\n//==============================================\n");

    return EXIT_SUCCESS;

}

//Testing is never more than expectation.
//I make mistakes in macro definition.
//int test_macro() {
//    
//    return EXIT_SUCCESS;
//}

void test_list_ins_next(sList* list) {

    printf("\n//==============================================\n");
    printf("//test_list_ins_next starts");
    printf("\n//==============================================\n");

    //Allocate memory space for test vars. Direct declaration for vars 
    //by "int" cannot be de-allocated by "free".
    int* pVar  = (int*)malloc(sizeof(int));
    int* pVar2 = (int*)malloc(sizeof(int));
    int* pVar3 = (int*)malloc(sizeof(int));
    int* pVar4 = (int*)malloc(sizeof(int));
    *pVar = 9;
    *pVar2 = 8;
    *pVar3 = 5;
    *pVar4 = 3;
    int** tempDataStore = (int**)malloc(sizeof(int));
    if (tempDataStore == NULL) {
        printf("\nMemory allocation failed.\n");
        exit(-1);
    }

    //When list is empty, element = NULL, so insert new node at head.
    //List is 9.
    list_ins_next(list, NULL, (void*)pVar);             //Insert when empty.
    display_for_int_list(list);
    check_list(list);

    //List is 8, 5, 9, 3.
    list_ins_next(list, NULL, (void*)pVar2);            //Insert at head.
    list_ins_next(list, list->head, (void*)pVar3);      //Insert at any position.
    printf("\nshould be 9, and tail element = %d\n", *(int*)(list->tail->data));
    printf("\nshould be 8, and head element = %d\n", *(int*)(list->head->data));
    list_ins_next(list, list->tail, (void*)pVar4);      //Insert at tail.

    display_for_int_list(list);
    check_list(list);

    //List is 5, 9, 3.
    list_rem_next(list, NULL, (void**)tempDataStore);           //Remove head.
    printf("\nshould be 3, and tail element = %d\n", *(int*)(list->tail->data));
    printf("\nshould be 5, and tail element = %d\n", *(int*)(list->head->data));
    display_for_int_list(list);

    //Nothing to remove
    list_rem_next(list, list->tail, (void**)tempDataStore);     //Remove the one after tail.
    display_for_int_list(list);

    //5, 9
    list_rem_next(list, list->head->next, (void**)tempDataStore);     //Remove any node.
    display_for_int_list(list);

    //5
    list_rem_next(list, list->head, (void**)tempDataStore);     //Remove 2nd node.
    display_for_int_list(list);

    //empty
    list_rem_next(list, NULL, (void**)tempDataStore);           //Remove head.
    display_for_int_list(list);
    check_list(list);

    //De-allocate memory space.
    free(pVar);
    free(pVar2);
    free(pVar3);
    free(pVar4);
    free(tempDataStore);

    //Upon returning of this test function, list is still empty as it passed in.

    printf("\n//==============================================\n");
    printf("//test_list_ins_next done");
    printf("\n//==============================================\n");

    return;

}

void test_list_destroy(sList* list) {

    printf("\n//==============================================\n");
    printf("//test_list_destroy starts");
    printf("\n//==============================================\n");

    //Allocate memory space for test vars. Direct declaration for vars 
    //by "int" cannot be de-allocated by "free".
    int* pVar  = (int*)malloc(sizeof(int));
    int* pVar2 = (int*)malloc(sizeof(int));
    int* pVar3 = (int*)malloc(sizeof(int));
    int* pVar4 = (int*)malloc(sizeof(int));
    *pVar = 9;
    *pVar2 = 8;
    *pVar3 = 5;
    *pVar4 = 3;

    //When list is empty, element = NULL, so insert new node at head.
    //List is 8, 5, 9, 3.
    list_ins_next(list, NULL, (void*)pVar);             //Insert when empty.
    list_ins_next(list, NULL, (void*)pVar2);            //Insert at head.
    list_ins_next(list, list->head, (void*)pVar3);      //Insert at any position.
    printf("\nshould be 9, and tail element = %d\n", *(int*)(list->tail->data));
    printf("\nshould be 8, and head element = %d\n", *(int*)(list->head->data));
    list_ins_next(list, list->tail, (void*)pVar4);      //Insert at tail.

    display_for_int_list(list);
    check_list(list);

    list_destroy(list);

    check_list(list);

    printf("\n//==============================================\n");
    printf("//test_list_destroy done");
    printf("\n//==============================================\n");

    return;

}
