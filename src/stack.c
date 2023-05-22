//
// Created by Asus on 22.05.2023.
//

#include "../include/stack.h"

List_t *listInit(){
    List_t *newList = malloc(sizeof(List_t));
    newList->pHead = NULL;
    newList->listLen = 0;
    return newList;
}

ListNode_t *push(List_t *pList, char *data){
    ListNode_t *curElem = pList->pHead;
    if (curElem != NULL){
        while (curElem->next != NULL){
            curElem = curElem->next;
        }
    }
    ListNode_t *newElem = malloc(sizeof(ListNode_t));
    newElem->data = malloc(sizeof(char ) * MAX_LEN + 1);
    strcpy(newElem->data, data);
    newElem->index = pList->listLen;
    newElem->next = NULL;
    if  (curElem == NULL){
        pList->pHead = newElem;
    } else {
        curElem->next = newElem;
    }
    pList->listLen++;

    return newElem;
}

ListNode_t *pop(List_t *pList){
    ListNode_t *curElem = pList->pHead;
    if (curElem == NULL){
        puts("curElem pointer to NULL");
        return NULL;
    }
    printf("%d: %s", curElem->index, curElem->data);
    ListNode_t *nextElem = curElem->next;
    free(curElem);
    curElem = nextElem;
    return curElem;
}

void addItem(List_t *pList){
    char *item = malloc(sizeof(char) * MAX_LEN + 1);
    bool correctInput = true;
    do {
        if (!correctInput){
            puts("too many symbols");
        }
        puts("Enter item:");
        scanf("%s",  item);
        correctInput  = strlen(item) <= MAX_LEN;
    } while (!correctInput);
    push(pList, item);
}

void deleteList(List_t *pList){
    ListNode_t *curElem = pList->pHead;
    while (curElem != NULL){
        ListNode_t *nextElem = curElem->next;
        free(curElem);
        curElem = nextElem;
    }
    free(pList);
}

void printList(List_t *pList){
    ListNode_t *curElem = pList->pHead;
    putchar('[');
    while (curElem != NULL){
        printf("%d: %s", curElem->index, curElem->data);
        curElem = curElem->next;
        if (curElem != NULL)
            putchar(',');
    }
    puts("]");
}

ListNode_t *get(List_t *pList, unsigned int index){
    ListNode_t *curElem = pList->pHead;
    for (int i = 0; i < index; i++){
        curElem = curElem->next;
        if (curElem == NULL){
            puts("ERROR: Wrong index");
            return NULL;
        }
    }
    return curElem;
}

void getElem(List_t *pList){
    unsigned int index;
    puts("Enter element index:");
    scanf("%d", &index);
    ListNode_t *curElem = get(pList, index);
    printf("%d: %s", curElem->index, curElem->data);
}