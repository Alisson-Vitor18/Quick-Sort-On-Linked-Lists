#include <stdio.h>
#include "quicksort.h"
#include "list.h"

int main() {
    List* new_list = lst_create();

    lst_add(new_list, "Maria");
    lst_add(new_list, "Marcos");
    lst_add(new_list, "Kaik");
    lst_add(new_list, "Alisson");
    lst_add(new_list, "Assembly");
    lst_add(new_list, "Julia");
    lst_add(new_list, "Java");
    lst_add(new_list, "Haskell");
    lst_add(new_list, "COBOL");

    printf("\n=== Original ===\n");
    printf("Lista: ");
    lst_print(new_list);
    
    Node* tail = finds_tail(new_list->lst_head);
    new_list->lst_head = quick_sort(new_list->lst_head, tail);
    new_list->lst_tail = finds_tail(new_list->lst_head);

    printf("\n=== Ordenada ===\n");
    printf("Lista: ");
    lst_print(new_list);

    lst_free(new_list);

    return 0;
}