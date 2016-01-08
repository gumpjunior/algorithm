#include <stdio.h>
#include <string.h>
#include "linked_list.h"

//For "void (*destroy) (void* data);"
void element_destroy(void* data) {
    printf("free: data = %d\n", *(int*)data);
    free(data);
    return;
}

//Never used!
////For "int (*match)(const void* key1, const void* key2);"
//int element_match(const void* key1, const void* key2) {
//    //if () {
//    //    printf();
//    //}
//    //else {
//    //    printf();
//    //}
//    printf("This function is empty!\n");
//    return 0;
//}

//============================================================
// List initialization.
//============================================================

void list_init(sList* list, void (*destroy)(void* data)) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;
    //list->match   = //Never used.
    return;
}

//============================================================
// Note: allocate memory space for the new list item inside 
//      this function.
//============================================================

int list_ins_next(sList* list, sListElmt* element, const void* data) {

    if (list == NULL) {
        printf("List does not exists!\n");
        return -1;
    }

    sListElmt* pListElmt = malloc(sizeof(sListElmt));
    if (pListElmt == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    pListElmt->data      = (void*)data;     //"const void*" is not "void*".
    pListElmt->next      = NULL;

    //Insert at the head
    if (element == NULL) {
        //pListElmt->next = list->head->next;       //GOOD mistake.
        pListElmt->next = list->head;
        list->head      = pListElmt;
        if (list->size == 0) {
            list->tail = pListElmt;
        }
    }
    //Insert after element
    else {
        pListElmt->next = element->next;
        element->next   = pListElmt;
        //if (list_is_tail(list, element)) {          //Do not use macro in fundamental functions.
        if (pListElmt->next == NULL) {                //last_element->next MUSt equal to NULL.
            list->tail = pListElmt;
        }
    }

    list->size++;

    return 0;

}

//============================================================
// "void** data" is assigned by the address of the removed 
// element data pointer. The caller should decide how to deal
// with the memory space allocated for the struct member "data"
// of removed node.
//============================================================

int list_rem_next(sList* list, sListElmt* element, void** data) {

    if (list == NULL) {
        printf("List does not exist.\n");
        return -1;
    }

    if (list->size == 0) {
        printf("List is empty, nothing to remove\n");
        return -1;
    }

    sListElmt* temp = NULL;
    
    //Remove head element.
    if (element == NULL) {
        *data       = list->head->data;
        temp        = list->head;
        list->head  = list->head->next;
        if (list->size == 1) {
            list->tail = NULL;
        }
    }
    //Remove the item after element.
    else {
        //The item after element is NULL. Including list->size == 1, 
        //but wider than this situation.
        //if (list_is_tail(list, element)) {
        if (element->next == NULL) {
        //if (element == list->tail) {
            printf("\nPosition specified wrong.\n");
            printf("Nothing to remove.\n");
            return -1;
        }

        *data         = element->next->data;
        temp          = element->next;
        //element->next = temp->next;               //Bad style.
        element->next = element->next->next;        //Prefer this style.
        //The item need to remove is the list tail.
        if (element->next == NULL) {
            list->tail = element;
        }

    }

    free(temp);
    list->size--;
    return 0;

}

//============================================================
// Note:
//============================================================

int list_destroy(sList* list) {

    if (list == NULL) {
        printf("List does not exist.\n");
        return EXIT_FAILURE;
    }

    sListElmt* tempNext  = NULL;
    sListElmt* pListElmt = list->head;
    while (pListElmt != NULL) {
        tempNext = pListElmt->next;
        list->destroy(pListElmt->data);
        free(pListElmt);
        pListElmt = tempNext;
    }

    //list->head = NULL;            //Wrong way.
    //list->tail = NULL;
    //list->size = 0;
    //list->destroy = NULL;
    ////list->match = NULL;
    //Below is the real meaning of NO operation is allowed.
    memset(list, 0, sizeof(sList));

    return EXIT_SUCCESS;

}

//============================================================
// Note:
//============================================================

int check_list(sList* list) {

    if (list == NULL) {
        printf("\nList does not exist!\n");
        return EXIT_FAILURE;
    }

    if (list->size == 0) {
        printf("\nList is empty.\n");
        return EXIT_FAILURE;
    }

    //Check to see "list->size" matches the real list item count.
    int count = 0;
    sListElmt* pListElmt = list->head;
    while (pListElmt != NULL) {
        count++;
        pListElmt = pListElmt->next;
    }
    if (count != list->size) {
        printf("\nError: List size setting wrong!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

//============================================================
// Note: This function only applies to list in type of int.
//============================================================

int display_for_int_list(sList* list) {
    
    if (list == NULL) {
        printf("\nList does not exist!\n");
        return EXIT_FAILURE;
    }

    if (list->size == 0) {
        printf("\nList is empty, nothing to print out!\n");
        return EXIT_FAILURE;
    }

    sListElmt* pListElmt = NULL;
    pListElmt = list->head;
    int count = 0;

    printf("\n");
    printf("Call display: ");
    while (pListElmt != NULL) {
        //printf("", (*)(int*)(pListElmt->data));
        //printf("", (*)(pListElmt->data));
        printf("list[%d] = %d  ", count, *((int*)(pListElmt->data)));
        pListElmt = pListElmt->next;
        count++;
    }
    printf("\n");

    return EXIT_SUCCESS;
}
