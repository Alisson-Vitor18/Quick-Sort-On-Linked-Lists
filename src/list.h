#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node{
    char* nd_str;
    struct Node* nd_next;
} Node;

typedef struct {
    Node* lst_head;
    Node* lst_tail;
    size_t lst_size;
} List;

List* lst_create();
bool lst_is_empty(List* list);
bool lst_add(List* list, const char* nd_str);
bool lst_remove(List* list, const char* nd_str);
bool lst_print(List* list);
bool lst_free(List* list);

#endif