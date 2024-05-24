#include "process.h"
#include <stdio.h> // Para uso de printf

// Função para empilhar os registradores (simulação de contexto)
void pushProc(struct process a) {
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
}

// Função para criar um processo
void CreateProcess(struct process *p, unsigned long pid) {
    p->pid = pid;
    p->state = P_EXEC; // Estado inicial é "em execução"
}

// Função para destruir um processo (simulação)
void DestroyProcess(struct process *p) {
    p->state = P_ENDED; // O processo termina
}

// Função para verificar o estado do processo
void StateCheck(const struct process *p) {
    switch (p->state) {
        case P_EXEC:
            printf("Process %lu is executing\n", p->pid);
            break;
        case P_PAUSE:
            printf("Process %lu is paused\n", p->pid);
            break;
        case P_ENDED:
            printf("Process %lu has ended\n", p->pid);
            break;
        default:
            printf("Unknown state for process %lu\n", p->pid);
            break;
    }
}

// Funções para transições de estado
void P_Exec(struct process *p) {
    p->state = P_EXEC;
}

void P_Pause(struct process *p) {
    p->state = P_PAUSE;
}

void P_Ended(struct process *p) {
    p->state = P_ENDED;
}
