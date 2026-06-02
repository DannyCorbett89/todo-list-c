#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

void clearBuffer() {
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}

int print_menu() {
    printf("Menu:\n");
    printf("1: List\n");
    printf("2: Add\n");
    printf("3: Check\n");
    printf("4: Remove\n");
    printf("5: Quit\n");
    printf("Enter Option: ");
    int option;
    scanf("%d", &option);
    clearBuffer();
    printf(SEPARATOR);
    return option;
}

void add() {
    int size = get_size();
    if (size == MAX_SIZE) {
        printf("List is at max size, unable to add more items\n");
        printf(SEPARATOR);
        return;
    }

    printf("Title: ");

    char title[50];
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    printf(SEPARATOR);

    add_item(title);
}

void check() {
    int size = get_size();
    for (int x = 0; x < size; x++) {
        char prefix[4];
        snprintf(prefix, 4, "%d: ", x + 1);
        print_item_prefixed(prefix, x);
    }

    printf("Pick a task to check:\n");

    int option;
    scanf("%d", &option);
    clearBuffer();

    if (option <= size) {
        check_item(option - 1);
        show_list();
    } else {
        printf("Invalid choice: %d", option);
        printf(SEPARATOR);
    }
}

void remove_item() {
    int size = get_size();
    if (size == 0) {
        printf("List is empty\n");
        printf(SEPARATOR);
        return;
    }

    for (int x = 0; x < size; x++) {
        char prefix[4];
        snprintf(prefix, 4, "%d: ", x + 1);
        print_item_prefixed(prefix, x);
    }

    printf("Pick a task to remove:\n");

    int option;
    scanf("%d", &option);
    clearBuffer();

    if (option <= size) {
        remove_item_from_list(option - 1);
        show_list();
    } else {
        printf("Invalid choice: %d\n", option);
        printf(SEPARATOR);
    }
}

int main(void) {
    printf("TODO List\n");
    printf(SEPARATOR);

    while (true) {
        int option = print_menu();

        switch (option) {
            case 1:
                show_list();
                break;
            case 2:
                add();
                break;
            case 3:
                check();
                break;
            case 4:
                remove_item();
                break;
            case 5:
            default:
                return 0;
        }
    }
}
