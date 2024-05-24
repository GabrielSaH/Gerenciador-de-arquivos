#include <stdlib.h>
#include <stdio.h>
#include "process_manager.h"

// Função para criar um novo gerenciador de processos
struct process_manager *create_process_manager() {
    struct process_manager *pm = (struct process_manager *)malloc(sizeof(struct process_manager));
    if (pm != NULL) {
        pm->head = NULL; // Inicializa a cabeça da lista como NULL
    }
    return pm;
}

// Função para destruir o gerenciador de processos
void destroy_process_manager(struct process_manager *pm) {
    struct process_node *current = pm->head;

    while (current != NULL) { // Libera todos os nós
        struct process_node *temp = current;
        current = current->next;
        free(temp); // Libera memória do nó
    }

    free(pm); // Libera o gerenciador
}

// Função para adicionar um processo à lista
void add_process(struct process_manager *pm, struct process *proc) {
    struct process_node *node = (struct process_node *)malloc(sizeof(struct process_node));
    if (node == NULL) {
        printf("Falha ao criar o nó de processo.\n");
        return;
    }

    node->proc = *proc; // Copia o processo para o nó
    node->next = NULL; // Define o próximo nó como NULL

    if (pm->head == NULL) {
        pm->head = node; // Se a lista estiver vazia, o nó é o primeiro
    } else {
        struct process_node *current = pm->head;
        while (current->next != NULL) {
            current = current->next; // Procura o último nó
        }
        current->next = node; // Adiciona ao final da lista
    }
}

// Função para remover um processo pela PID
void remove_process(struct process_manager *pm, unsigned long pid) {
    struct process_node *current = pm->head;
    struct process_node *previous = NULL;

    while (current != NULL && current->proc.pid != pid) {
        previous = current;
        current = current->next; // Procura o processo com a PID correspondente
    }

    if (current == NULL) {
        printf("Processo com PID %lu não encontrado.\n", pid);
        return;
    }

    if (previous == NULL) {
        pm->head = current->next; // Remove o primeiro nó
    } else {
        previous->next = current->next; // Remove do meio ou do final
    }

    free(current); // Libera memória do nó
}

// Função para listar todos os processos
void list_processes(const struct process_manager *pm) {
    struct process_node *current = pm->head;

    printf("Lista de Processos:\n");
    while (current != NULL) {
        printf("PID: %lu, Estado: %d\n", current->proc.pid, current->proc.state);
        current = current->next; // Percorre a lista
    }
}

// Função para escalonar o processo com maior prioridade
struct process *schedule_process(const struct process_manager *pm) {
    struct process_node *current = pm->head; // Acesso ao campo 'head' com a notação de seta
    struct process_node *highest_priority_node = current; // Inicializa como o primeiro nó
    
    while (current != NULL) {
        // Para menor valor de prioridade, a prioridade é maior
        if (current->proc.prioridade < highest_priority_node->proc.prioridade) {
            highest_priority_node = current; // Atualiza para o processo com maior prioridade
        }
        current = current->next; // Continua percorrendo a lista usando a notação de seta
    }

    if (highest_priority_node != NULL) {
        return &highest_priority_node->proc; // Retorna o processo com maior prioridade
    } else {
        return NULL; // Retorna NULL se a lista estiver vazia ou houver erro
    }
}

