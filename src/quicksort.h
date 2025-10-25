#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdbool.h>
#include <stddef.h>
#include "list.h"

Node* finds_tail(Node* tail);
Node* quick_sort(Node* head, Node* tail);

#endif