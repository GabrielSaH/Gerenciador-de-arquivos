#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H
#include "process.h" 

// Estrutura para a lista de processos
struct process_node {
    struct process proc; // Processo armazenado no nó
    struct process_node *next; // Próximo nó na lista
};

// Estrutura para gerenciar a lista de processos
struct process_manager {
    struct process_node *head; // Início da lista de processos
};

// Declaração das funções para gerenciamento de processos
struct process_manager *create_process_manager(); // Criar gerenciador
void destroy_process_manager(struct process_manager *pm); // Destruir gerenciador
void add_process(struct process_manager *pm, struct process *proc); // Adicionar processo
void remove_process(struct process_manager *pm, unsigned long pid); // Remover processo
void list_processes(const struct process_manager *pm); // Listar processos
struct process *schedule_process(const struct process_manager *pm); // Escolher o processo com maior prioridade

#endif
