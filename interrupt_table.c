#include <stdlib.h>
#include <stdio.h>
#include "interrupt_table.h"

// Criar uma nova tabela de interrupções
struct interrupt_table *create_interrupt_table(int capacity) {
    struct interrupt_table *table = (struct interrupt_table *)malloc(sizeof(struct interrupt_table));
    if (table == NULL) {
        return NULL;  // Falha ao alocar memória
    }

    table->handlers = (struct interrupt_handler *)malloc(sizeof(struct interrupt_handler) * capacity);
    if (table->handlers == NULL) {
        free(table);
        return NULL;  // Falha ao alocar memória para os manipuladores
    }

    table->size = 0;  // Inicializa o tamanho da tabela
    table->capacity = capacity;  // Define a capacidade máxima

    return table;  // Retorna a nova tabela
}

// Adicionar um manipulador de interrupções à tabela
void add_interrupt_handler(struct interrupt_table *table, struct interrupt_handler *handler) {
    if (table->size < table->capacity) {
        table->handlers[table->size] = *handler;  // Adiciona o manipulador
        table->size++;  // Aumenta o tamanho da tabela
    } else {
        printf("Tabela de interrupções está cheia.\n");
    }
}

// Manipular todas as interrupções na tabela
void handle_all_interrupts(const struct interrupt_table *table) {
    for (int i = 0; i < table->size; i++) {
        handle_interrupts(&table->handlers[i]);  // Manipula as interrupções para cada manipulador
    }
}
