#ifndef TODO_LIST_C_LIST_H
#define TODO_LIST_C_LIST_H

#include <stdbool.h>

#define MAX_SIZE 5

extern const char SEPARATOR[];

struct Item {
    bool done;
    char title[50];
};

int get_size();
void print_item_prefixed(char prefix[], int index);
void print_item(int index);
void show_list();
void add_item(char title[50]);
void check_item(int index);
void remove_item_from_list(int index);

#endif //TODO_LIST_C_LIST_H