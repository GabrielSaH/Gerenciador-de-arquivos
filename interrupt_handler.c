#include <stdlib.h> 
#include <stdio.h> 
#include "interrupt_handler.h"

// Inicializa o manipulador de interrupções
void init_interrupt_handler(struct interrupt_handler *handler, int max_interrupts) {
    handler->interrupts = (struct interrupt *)malloc(sizeof(struct interrupt) * max_interrupts);
    handler->interrupt_count = 0;
    handler->max_interrupts = max_interrupts;
}

// Adiciona uma interrupção ao manipulador
void add_interrupt(struct interrupt_handler *handler, enum interrupt_type type, uint32 code) {
    if (handler->interrupt_count < handler->max_interrupts) {
        struct interrupt *new_interrupt = &handler->interrupts[handler->interrupt_count];
        new_interrupt->type = type;
        new_interrupt->code = code;
        handler->interrupt_count++;
    } else {
        printf("Limite de interrupções atingido.\n");
    }
}

// Manipula todas as interrupções registradas
void handle_interrupts(struct interrupt_handler *handler) {
    printf("Manipulando %d interrupções.\n", handler->interrupt_count);
    for (int i = 0; i < handler->interrupt_count; i++) {
        struct interrupt *current_interrupt = &handler->interrupts[i];
        switch (current_interrupt->type) {
            case INT_HARDWARE:
                printf("Manipulando interrupção de hardware, código: %u\n", current_interrupt->code);
                break;
            case INT_SOFTWARE:
                printf("Manipulando interrupção de software, código: %u\n", current_interrupt->code);
                break;
            default:
                printf("Tipo de interrupção desconhecido.\n");
                break;
        }
    }

    // Reinicia a contagem de interrupções
    handler->interrupt_count = 0;
}

