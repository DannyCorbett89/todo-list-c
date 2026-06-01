#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char SEPARATOR[] = "---------------\n";

struct Item {
    bool done;
    char name[50];
};

int print_menu() {
    printf("Menu:\n");
    printf("1: List\n");
    printf("5: Quit\n");
    printf("Enter Option: ");
    int option;
    scanf("%d", &option);
    printf(SEPARATOR);
    return option;
}

void print_item(struct Item item) {
    if (item.done) {
        printf("[x] %s\n", item.name);
    } else {
        printf("[ ] %s\n", item.name);
    }
}

void show_list(struct Item *items, int size) {
    printf("Showing List\n");

    for (int x = 0; x < size; x++) {
        print_item(items[x]);
    }

    printf(SEPARATOR);
}

int main(void) {
    printf("TODO List\n");
    printf(SEPARATOR);

    int size = 0;
    struct Item *items = malloc(size * sizeof(struct Item));

    if (items == NULL) {
        printf("Error allocating memory for item list");
        return 1;
    }

    while (true) {
        int option = print_menu();

        switch (option) {
            case 1:
                show_list(items, size);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            default:
                free(items);
                return 0;
        }
    }
}
