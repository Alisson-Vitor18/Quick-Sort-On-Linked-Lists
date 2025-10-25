#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

static Node* nd_create(const char* nd_str) {
    if(nd_str == NULL) {
        fprintf(stderr, "Erro de inserção: o nó informado é 'null'\n");
        return NULL;
    }

    Node* new_node = malloc(sizeof(Node));

    if(new_node == NULL) {
        fprintf(stderr, "Erro de alocação: não foi possível alocar memória para um novo nó\n");
        return NULL;
    }

    new_node->nd_str = strdup(nd_str);

    if(new_node->nd_str == NULL) {
        fprintf(stderr, "Erro de alocação: falha na alocação 'strdup' da string %s\n", nd_str);
        free(new_node);
        return NULL;
    }

    new_node->nd_next = NULL;

    return new_node;
}

List* lst_create() {
    List* new_list = malloc(sizeof(List));
    
    if(new_list == NULL) {
        fprintf(stderr, "Erro de alocação: não foi possível alocar memória para a estrutura da lista encadeada\n");
        return NULL;
    }

    new_list->lst_head = NULL;
    new_list->lst_tail = NULL;
    new_list->lst_size = 0;

    return new_list;
}

bool lst_is_empty(List* list) {
    return (list == NULL) || (list->lst_head == NULL) || (list->lst_size == 0);
}

bool lst_add(List* list, const char* nd_str) {
    if(list == NULL) {
        fprintf(stderr, "Erro de inserção: a lista informada é 'null'\n");
        return false;
    }

    if(nd_str == NULL) {
        fprintf(stderr, "Erro de inserção: string informada é 'null'\n");
        return false;
    }

    Node* new_node = nd_create(nd_str);

    if(lst_is_empty(list)) {
        list->lst_head = new_node;
        list->lst_tail = new_node ;
    } else {
        list->lst_tail->nd_next = new_node;
        list->lst_tail = new_node;
    }

    list->lst_size++;

    return true;
}

bool lst_remove(List* list, const char* nd_str) {
    if(list == NULL) {
        fprintf(stderr, "Erro de remoção: a lista informada é 'null'\n");
        return false;
    }

    if(nd_str == NULL) {
        fprintf(stderr, "Erro de remoção: string informada é 'null'\n");
        return false;
    }

    if(lst_is_empty(list)) {
        fprintf(stderr, "Erro de remoção: a lista está vazia\n");
        return false;
    }

    Node* current = list->lst_head;
    Node* prev = NULL;

    while(current != NULL) {
        if(strcmp(current->nd_str, nd_str) == 0) {
            if(prev) {
                prev->nd_next = current->nd_next;
            } else {
                list->lst_head = current->nd_next;
            }

            if(current == list->lst_tail) {
                list->lst_tail = prev;  
            }
            free(current->nd_str);
            free(current);

            list->lst_size--;

            return true;
        }

        prev = current;
        current = current->nd_next;
    }

    fprintf(stderr, "Erro de remoção: o nó \"%s\" não foi encontrado\n", nd_str);

    return false;
}

bool lst_print(List* list) {
    if(list == NULL) {
        fprintf(stderr, "Erro de impressão: a lista informada é 'null'\n");
        return false;
    }
    int first = 1;

    printf("{ ");
    for(Node* current = list->lst_head; current != NULL; current = current->nd_next) {
        if(!first) {
            printf(", ");
        }

        printf("\"%s\"", current->nd_str);
        first = 0;
    }
    printf(" }\n");
    
    return true;
}

bool lst_free(List* list) {
    if(list == NULL) {
        fprintf(stderr, "Erro de liberação: a lista informada é 'null'\n");
        return false;
    }

    Node* current = list->lst_head;
    
    while(current != NULL) {
        Node* next = current->nd_next;

        free(current->nd_str);
        free(current);

        current = next;
    }

    free(list);
    
    return true;
}

