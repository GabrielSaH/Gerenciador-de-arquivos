#ifndef INTERRUPT_TABLE_H
#define INTERRUPT_TABLE_H

#include "interrupt_handler.h"

// Estrutura para a tabela de interrupções
struct interrupt_table {
    struct interrupt_handler *handlers;  // Array de manipuladores de interrupções
    int size;  // Tamanho da tabela
    int capacity;  // Capacidade máxima
};

// Funções para operações com a tabela de interrupções
struct interrupt_table *create_interrupt_table(int capacity); // Criar tabela
void add_interrupt_handler(struct interrupt_table *table, struct interrupt_handler *handler); // Adicionar manipulador
void handle_all_interrupts(const struct interrupt_table *table); // Manipular todas as interrupções

#endif
