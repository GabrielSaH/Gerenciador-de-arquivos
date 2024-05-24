#ifndef PROCESS_H
#define PROCESS_H
#include "types.h"

// Definindo estados de processo
enum process_state {
    P_EXEC = 1,
    P_PAUSE = 2,
    P_ENDED = 3
};

// Estrutura de processo
struct process {
    unsigned long pid; // Process ID
    int prioridade; // Prioridade do processo
    
    // Registradores de uso geral
    uint32 eax;
    uint32 ebx;
    uint32 ecx;
    uint32 edx;
    uint32 edi;
    uint32 esi;
    uint32 ebp;
    uint32 esp;

    // Registradores de segmento
    uint32 cs, ds, ss, es, fs;
    
    // Instruction Pointer (contador de programa)
    uint32 eip;

    // Estado do processo
    enum process_state state;
};

// Declaração das funções
void pushProc(struct process a); // Função para empilhar registradores
void CreateProcess(struct process *p, unsigned long pid, int prioridade); // Criar processo com prioridade
void DestroyProcess(struct process *p); // Destruir processo
void StateCheck(const struct process *p); // Verificar estado do processo
void P_Exec(struct process *p); // Definir estado como executando
void P_Pause(struct process *p); // Definir estado como pausado
void P_Ended(struct process *p); // Definir estado como terminado


#endif
