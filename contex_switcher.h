#ifndef CONTEXT_SWITCHER_H
#define CONTEXT_SWITCHER_H

#include "process.h"

// Função para simular o empilhamento de registradores (salvar contexto)
void push_registers(struct process *proc);

// Função para simular desempilhamento de registradores (restaurar contexto)
void pop_registers(struct process *proc);

// Função para trocar contexto entre processos
void context_switch(struct process *from, struct process *to);

#endif
