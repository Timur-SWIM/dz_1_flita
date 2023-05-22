#include <stdio.h>
#include "include/stack.h"

int main() {
    List_t *pList = listInit();
    List_t *pList2 = listInit();
    bool flag = false;

    while (!flag){
        puts("Choose one of the option:");
        puts("Push_1 (1) Push_2 (6)");
        puts("Pop_1 (2) Pop_2 (7)");
        puts("Get Element_1 (3) Get Element_1 (8)");
        puts("Print list_1 (4) Print list_1(9)");
        puts("Exit (5)");

        char *cInput = malloc(sizeof(char) * 16);
        scanf("%s", cInput);
        int input = atoi(cInput);
        free(cInput);

        switch (input) {
            case 1:
                addItem(pList);
                break;
            case 2:
                pop(pList);
                break;
            case 3:
                getElem(pList);
                break;
            case 4:
                printList(pList);
                break;
            case 5:
                deleteList(pList);
                deleteList(pList2);
                flag = true;
                break;
            case 6:
                addItem(pList2);
                break;
            case 7:
                pop(pList2);
                break;
            case 8:
                getElem(pList2);
                break;
            case 9:
                printList(pList2);
                break;
            default:
                puts("Something went wrong!");
        }
        putchar('\n');
    }
    return 0;
}
