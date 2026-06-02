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
    printf("5: Quit\n");
    printf("Enter Option: ");
    int option;
    scanf("%d", &option);
    clearBuffer();
    printf(SEPARATOR);
    return option;
}

void print_item(struct Item item) {
    if (item.done) {
        printf("[x] %s\n", item.title);
    } else {
        printf("[ ] %s\n", item.title);
    }
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
            case 4:
            case 5:
            default:
                return 0;
        }
    }
}
