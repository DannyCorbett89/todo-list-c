#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

const char SEPARATOR[] = "---------------\n";

struct Item list[MAX_SIZE];
int size = 0;

int get_size() {
    return size;
}

struct Item get_item(int index) {
    return list[index];
}

void print_item_prefixed(char prefix[], int index) {
    if (prefix != NULL) {
        printf("%s", prefix);
    }

    if (list[index].done) {
        printf("[x]");
    } else {
        printf("[ ]");
    }

    printf(" %s\n", list[index].title);
}

void print_item(int index) {
    print_item_prefixed(NULL, index);
}

void show_list() {
    if (size == 0) {
        printf("List is empty\n");
        printf(SEPARATOR);
        return;
    }
    printf("Showing List:\n");

    for (int x = 0; x < size; x++) {
        print_item(x);
    }

    printf(SEPARATOR);
}

void add_item(bool done, char title[50]) {
    size++;
    int index = size - 1;

    list[index].done = done;
    strcpy(list[index].title, title);
}

void check_item(int index) {
    bool done = list[index].done;
    list[index].done = !done;
}

void remove_item_from_list(int index) {
    for (int x = index + 1; x < size; x++) {
        list[x - 1].done = list[x].done;
        strcpy(list[x - 1].title, list[x].title);
    }
    size--;
}