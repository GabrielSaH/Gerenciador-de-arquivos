#include <stdio.h>
#include "context_switcher.h"

// Função para simular empilhamento de registradores (salvar contexto do processo atual)
void push_registers(struct process *proc) {
    asm("push %eax");
    asm("push %ebx");
    asm("push %ecx");
    asm("push %edx");
    asm("push %edi");
    asm("push %esi");
    asm("push %cs");
    asm("push %ds");
    asm("push %ss");
    asm("push %es");
    asm("push %fs");
    asm("push %eip");

    // Armazena o contexto nos registradores da estrutura de processo
    proc->eax = asm("mov %eax, %0" : "=m"(proc->eax));
    proc->ebx = asm("mov %ebx, %0" : "=m"(proc->ebx));
    proc->ecx = asm("mov %ecx, %0" : "=m"(proc->ecx));
    proc->edx = asm("mov %edx, %0" : "=m"(proc->edx));
    proc->edi = asm("mov %edi, %0" : "=m"(proc->edi));
    proc->esi = asm("mov %esi, %0" : "=m"(proc->esi));
    proc->cs = asm("mov %cs, %0" : "=m"(proc->cs));
    proc->ds = asm("mov %ds, %0" : "=m"(proc->ds));
    proc->ss = asm("mov %ss, %0" : "=m"(proc->ss));
    proc->es = asm("mov %es, %0" : "=m"(proc->es));
    proc->fs = asm("mov %fs, %0" : "=m"(proc->fs));
    proc->eip = asm("mov %eip, %0" : "=m"(proc->eip));
}

// Função para simular desempilhamento de registradores (restaurar contexto do próximo processo)
void pop_registers(struct process *proc) {
    asm("pop %eip");
    asm("pop %fs");
    asm("pop %es");
    asm("pop %ss");
    asm("pop %ds");
    asm("pop %cs");
    asm("pop %esi");
    asm("pop %edi");
    asm("pop %edx");
    asm("pop %ecx");
    asm("pop %ebx");
    asm("pop %eax");

    // Restaura o contexto nos registradores da estrutura de processo
    proc->eax = asm("mov %eax, %0" : "=m"(proc->eax));
    proc->ebx = asm("mov %ebx, %0" : "=m"(proc->ebx));
    proc->ecx = asm("mov %ecx, %0" : "=m"(proc->ecx));
    proc->edx = asm("mov %edx, %0" : "=m"(proc->edx));
    proc->edi = asm("mov %edi, %0" : "=m"(proc->edi));
    proc->esi = asm("mov %esi, %0" : "=m"(proc->esi));
    proc->cs = asm("mov %cs, %0" : "=m"(proc->cs));
    proc->ds = asm("mov %ds, %0" : "=m"(proc->ds));
    proc->ss = asm("mov %ss, %0" : "=m"(proc->ss));
    proc->es = asm("mov %es, %0" : "=m"(proc->es));
    proc->fs = asm("mov %fs, %0" : "=m"(proc->fs));
    proc->eip = asm("mov %eip, %0" : "=m"(proc->eip));
}

// Função para trocar o contexto entre dois processos
void context_switch(struct process *from, struct process *to) {
    // Salva o contexto do processo atual
    push_registers(from);

    // Restaura o contexto do próximo processo
    pop_registers(to);
}
