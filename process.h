#ifndef PROCESS_H
#define PROCESS_H
#include "types.h"

// Definindo estados de processo
enum process_state {
    P_EXEC = 1,    
    P_ENDED = 3
};


// Estrutura de processo
struct registradores {
    unsigned long pid; // Process ID
  
    
    // Registradores de uso geral
   
    uint32 edi;
    uint32 esi;
    uint32 ebp;
    uint32 esp;
    uint32 ebx;
    uint32 edx;
    uint32 ecx;
    uint32 eax;

    // Registradores de segmento
    uint32 cs, ds, ss, es, fs, gs;
    
    // Instruction Pointer (contador de programa)
    uint32 eip;
    uint32 eflags;
   
};

struct processo{
    unsigned long pid; // Process ID

    // Estado do processo
    enum process_state state;

    struct registradores regs;

};


// Declaração das funções

void createProcess(struct process *p, unsigned long pid, int prioridade); // Criar processo com prioridade
void destroyProcess(struct process *p); // Destruir processo
void stateCheck(const struct process *p); // Verificar estado do processo
void p_Exec(struct process *p); // Definir estado como executando
void p_Ended(struct process *p); // Definir estado como terminado


#endif
