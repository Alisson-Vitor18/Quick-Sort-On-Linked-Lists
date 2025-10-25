#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "quicksort.h"
#include "list.h"

Node* finds_tail(Node* tail) {
    while(tail != NULL && tail->nd_next != NULL) {
        tail = tail->nd_next;
    }

    return tail;
}

static Node* finds_middle(Node* head, Node* tail) {
    Node* slow = head;
    Node* fast = head;

    while(fast != tail && fast->nd_next != tail) {
        fast = fast->nd_next->nd_next;
        slow = slow->nd_next;
    }

    return slow;
}

static Node* median_of_three(Node* head, Node* tail) {
    Node* lst_mid = finds_middle(head, tail);

    char* lst_head_str = head->nd_str;
    char* lst_mid_str = lst_mid->nd_str;
    char* lst_tail_str = tail->nd_str;

    if((strcmp(lst_head_str, lst_mid_str) > 0) != (strcmp(lst_head_str, lst_tail_str) > 0)) return head;
    if((strcmp(lst_mid_str, lst_head_str) > 0) != (strcmp(lst_mid_str, lst_tail_str) > 0)) return lst_mid;

    return tail;
}

static void partition(Node* head, Node* tail, Node** less_head, Node** less_tail, 
Node** equal_head, Node** equal_tail, Node** greater_head, Node** greater_tail) {
    Node* nd_pivot = median_of_three(head, tail);
    char* pivot_val = nd_pivot->nd_str;

    *less_head = *less_tail = *equal_head = *equal_tail = *greater_head = *greater_tail = NULL;
    Node* current = head;

    while(current != tail->nd_next) {
        Node* next = current->nd_next;
        current->nd_next = NULL;

        int cmp = strcmp(current->nd_str, pivot_val);

        if(cmp < 0) {
            if(!*less_head) *less_head = *less_tail = current;
            else {(*less_tail)->nd_next = current; *less_tail = current;}
        } else if( cmp == 0) {
            if(!*equal_head) *equal_head = *equal_tail = current;
            else {(*equal_tail)->nd_next = current; *equal_tail = current; }
        } else {
            if (!*greater_head) *greater_head = *greater_tail = current;
            else { (*greater_tail)->nd_next = current; *greater_tail = current; }
        }

        current = next;
    }

    if(*less_tail) (*less_tail)->nd_next = NULL;
    if(*equal_tail) (*equal_tail)->nd_next = NULL;
    if(*greater_tail) (*greater_tail)->nd_next = NULL;
}   

static Node* concat_lists(Node* less, Node* equal, Node* greater) {
    Node* head = NULL;
    Node* tail = NULL;

    Node* lists[] = {less, equal, greater};

    for(size_t i = 0; i < 3; i++) {
        if(lists[i]) {
            if(!head) {
                head = lists[i];
                tail = finds_tail(lists[i]);
            } else {
                tail->nd_next = lists[i];
                tail = finds_tail(lists[i]);
            }
        }
    }

    return head;
}

Node* quick_sort(Node* head, Node* tail) {
    if(!head || head == tail) {
        return head;
    }

    Node* less_h, *less_t, *equal_h, *equal_t, *greater_h, *greater_t;
    partition(head, tail, &less_h, &less_t, &equal_h, &equal_t, &greater_h, &greater_t);

    if(less_h) less_h = quick_sort(less_h, less_t);
    if(greater_h) greater_h = quick_sort(greater_h, greater_t);

    return concat_lists(less_h, equal_h, greater_h);
}
                    