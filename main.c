#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 5

const char SEPARATOR[] = "---------------\n";

struct Item {
    bool done;
    char title[50];
};

struct Item list[MAX_SIZE];
int size = 0;

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
    printf("5: Quit\n");
    printf("Enter Option: ");
    int option;
    scanf("%d", &option);
    clearBuffer();
    printf(SEPARATOR);
    return option;
}

void print_item_prefixed(char prefix[], struct Item item) {
    if (prefix != NULL) {
        printf("%s", prefix);
    }

    if (item.done) {
        printf("[x]");
    } else {
        printf("[ ]");
    }

    printf(" %s\n", item.title);
}

void print_item(struct Item item) {
    print_item_prefixed(NULL, item);
}

void show_list() {
    printf("Showing List:\n");

    for (int x = 0; x < size; x++) {
        print_item(list[x]);
    }

    printf(SEPARATOR);
}

void add() {
    if (size == MAX_SIZE) {
        printf("List is at max size, unable to add more items\n");
        printf(SEPARATOR);
        return;
    }
    size++;
    int index = size - 1;

    printf("Title: ");

    char title[50];
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = 0;

    printf(SEPARATOR);

    list[index].done = false;
    strcpy(list[index].title, title);
}

void check_item(int index) {
    bool done = list[index].done;
    list[index].done = !done;
}

void check() {
    for (int x = 0; x < size; x++) {
        char prefix[4];
        snprintf(prefix, 4, "%d: ", x + 1);
        print_item_prefixed(prefix, list[x]);
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
            case 5:
            default:
                return 0;
        }
    }
}
