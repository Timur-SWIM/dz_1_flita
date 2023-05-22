//
// Created by Asus on 22.05.2023.
//

#ifndef DZ_1_STACK_H
#define DZ_1_STACK_H
#define MAX_LEN 12
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct ListNode_t{
    char *data;
    unsigned int index;
    struct ListNode_t *next;
}ListNode_t;

typedef struct List_t{
    int listLen;
    struct ListNode_t *pHead;
}List_t;

List_t *listInit();

ListNode_t *push(List_t *pList, char *data);

ListNode_t *pop(List_t *pList);

void addItem(List_t *pList);

void deleteList(List_t *pList);

void printList(List_t *pList);

ListNode_t *get(List_t *pList, unsigned int index);

void getElem(List_t *pList);

#endif //DZ_1_STACK_H
