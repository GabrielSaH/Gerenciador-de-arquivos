#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

#include "types.h"

// Enumeração para tipos de interrupções
enum interrupt_type {
    INT_HARDWARE,
    INT_SOFTWARE
};

// Estrutura para uma interrupção
struct interrupt {
    enum interrupt_type type;
    uint32 code; // Código de interrupção
};

// Estrutura para o manipulador de interrupções
struct interrupt_handler {
    struct interrupt *interrupts;
    int interrupt_count;
    int max_interrupts; // Máximo de interrupções permitidas
};

// Declaração das funções para manipulação de interrupções
void init_interrupt_handler(struct interrupt_handler *handler, int max_interrupts);
void add_interrupt(struct interrupt_handler *handler, enum interrupt_type type, uint32 code);
void handle_interrupts(struct interrupt_handler *handler);

#endif
