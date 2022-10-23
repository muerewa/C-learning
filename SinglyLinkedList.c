#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct  island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create(char *name) {
    island *i = malloc(sizeof(island)); // Создаем место в куче размером с размером структуры
    i->name = strdup(name); // Создаем копию имени, т.к. иначе у всех островов будет одно имя
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void display(island *start) {
    island *i = start;
    for(;i != NULL; i = i->next) {
        printf("Name: %s open: %s-%s\n", i->name, i->opens,i->closes);
    }
}

void release(island *start) {
    island *i = start;
    island *next= NULL;
    for(;i != NULL; i = next) {
        next = i->next;
        free(i->name); // Освобождаем имя из кучи
        free(i); // Освобождаем экземпляр структуры
    }
}

int main() {
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];
    for (;fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start == NULL) {
            start = next;
        }
        if(i != NULL) {
            i->next = next;
        }
    }
    display(start);
    release(start);
    return 0;
}