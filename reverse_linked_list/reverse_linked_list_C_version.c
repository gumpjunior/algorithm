/*
 ============================================================================
 Name        : reverse_linked_list_C_version.c
 Author      : gumpjunior
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list/linked_list.h"

int reverse_list(sList* list);

int main(void) {

    puts("Program starts!\n");

    sList myList;
    sList* list = &myList;
    list_init(list, element_destroy);

    //Put data into the list.
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

    //List is 8, 5, 9, 3.
    list_ins_next(list, NULL, (void*)pVar);             //Insert when empty.
    list_ins_next(list, NULL, (void*)pVar2);            //Insert at head.
    list_ins_next(list, list->head, (void*)pVar3);      //Insert at any position.
    list_ins_next(list, list->tail, (void*)pVar4);      //Insert at tail.

    display_for_int_list(list);
    check_list(list);

    //Reverse a list.
    reverse_list(list);

    //List is still in use, so No deallocation.

    puts("\nProgram ends!\n");

    return EXIT_SUCCESS;

}


int reverse_list(sList* list) {

    if (list == NULL) {
        printf("\nList does NOT exist!\n");
        return EXIT_FAILURE;
    }

    if (list_size(list) == 0) {
        printf("\nList is empty, nothing to reverse.\n");
        return EXIT_FAILURE;
    }

    //sListElmt* pDummy    = NULL;      //Must declare an instantiation for pDummy.
                                        //Otherwise cannot directly call pDummy->next.
    sListElmt* pDummy = (sListElmt*)malloc(sizeof(sListElmt));
    pDummy->data = NULL;
    pDummy->next = NULL;
    sListElmt* pTempCur  = list->head;
    sListElmt* pTempNext = NULL;

    while (pTempCur != NULL) {
        pTempNext = pTempCur->next;
        pTempCur->next = pDummy->next;
        pDummy->next   = pTempCur;
        pTempCur      = pTempNext;
    }

    list->head = pDummy->next;
    pTempCur   = list->head;
    while (pTempCur->next != NULL) {
        pTempCur = pTempCur->next;
    }
    list->tail = pTempCur;

    display_for_int_list(list);
    printf("head data is %d\n", *(int*)list->head->data);
    printf("tail data is %d\n", *(int*)list->tail->data);
    check_list(list);

    return EXIT_SUCCESS;

}
