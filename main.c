#include <stdio.h>
#include "include/stack.h"

int main() {
    List_t *pList = listInit();
    bool flag = false;

    while (!flag){
        puts("Choose one of the option:");
        puts("Push (1)");
        puts("Pop (2)");
        puts("Get Element (3)");
        puts("Print list (4)");
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
                flag = true;
                break;
            default:
                puts("Something went wrong!");
        }
        putchar('\n');
    }
    return 0;
}
