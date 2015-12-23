
#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <stdlib.h>

//============================================================
// Define a structure for linked list element.
//============================================================

typedef struct ListElmt_ {
    void*             data;
    struct ListElmt_* next;
} sListElmt;

//============================================================
// Define linked list structure.
//============================================================

typedef struct List_ {
    int         size;
    sListElmt*  head;
    sListElmt*  tail;
    void        (*destroy) (void* data);
    //int         (*match)(const void* key1, const void* key2);
} sList;

//============================================================
// Public interface
//============================================================

void element_destroy (void* data);

//Never used!
//int element_match (const void* key1, const void* key2);

void list_init (sList* list, void (*destroy)(void* data));

int list_destroy (sList* list);

int list_ins_next (sList* list, sListElmt* element, const void* data);

int list_rem_next (sList* list, sListElmt* element, void** data);

int display_for_int_list (sList* list);

int check_list(sList* list);

#define list_size(list) ((list)->size)      //Parenthesis are required.
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((list)->head==element)?1:0
#define list_is_tail(list, element) ((list)->tail==element)?1:0
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)


#endif
