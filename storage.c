#include "storage.h"
#include <stdio.h>
#include <string.h>

#include "list.h"

void load() {
    FILE *file = fopen("list.txt", "r");

    if (file != NULL) {
        char line[100];
        while (fgets(line, 100, file)) {
            char done_str[1];
            fgets(done_str, 50, file);

            char title[50];
            fgets(title, 50, file);
            title[strcspn(title, "\n")] = 0;

            if (done_str[0] == 'Y') {
                add_item(true, title);
            } else {
                add_item(false, title);
            }
        }
    }

    fclose(file);
}

void save() {
    FILE *file = fopen("list.txt", "w");
    int size = get_size();

    for (int x = 0; x < size; x++) {
        struct Item item = get_item(x);
        fprintf(file, "item:\n");

        if (item.done) {
            fprintf(file, "Y\n");
        } else {
            fprintf(file, "N\n");
        }
        fprintf(file, item.title);
        fprintf(file, "\n");
    }

    fclose(file);
}