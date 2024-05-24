#ifndef PROCESS_QUEUE_H
#define PROCESS_QUEUE_H

#include <stdlib.h>
#include "process.h"

// Nó de fila para processos
struct process_node {
    struct process proc; // Processo
    struct process_node *next; // Próximo nó na fila
};

// Fila de processos
struct process_queue {
    struct process_node *front; // Início da fila
    struct process_node *rear;  // Fim da fila
};

// Cria uma fila de processos
struct process_queue *create_process_queue() {
    struct process_queue *queue = (struct process_queue *)malloc(sizeof(struct process_queue));
    if (queue != NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

// Adiciona um processo à fila
void enqueue_process(struct process_queue *queue, struct process *proc) {
    struct process_node *node = (struct process_node *)malloc(sizeof(struct process_node));
    if (node == NULL) {
        return;
    }

    node->proc = *proc; // Copia o processo para o nó
    node->next = NULL; // Define o próximo como NULL

    if (queue->rear == NULL) {
        queue->front = node; // Se a fila estiver vazia, o novo nó é o primeiro
        queue->rear = node;  // O novo nó também é o último
    } else {
        queue->rear->next = node; // Adiciona ao final da fila
        queue->rear = node;      // Atualiza o fim da fila
    }
}

// Remove um processo da fila
struct process *dequeue_process(struct process_queue *queue) {
    if (queue->front == NULL) {
        return NULL; // A fila está vazia
    }

    struct process_node *node = queue->front; // Primeiro nó
    queue->front = node->next; // Atualiza o início da fila

    if (queue->front == NULL) {
        queue->rear = NULL; // Se a fila estiver vazia, atualiza o fim
    }

    struct process *proc = &node->proc; // Obtem o processo
    free(node); // Libera a memória do nó

    return proc; // Retorna o processo removido
}

// Destrói a fila de processos
void destroy_process_queue(struct process_queue *queue) {
    struct process_node *current = queue->front;

    while (current != NULL) {
        struct process_node *temp = current;
        current = current->next;
        free(temp); // Libera todos os nós
    }

    free(queue); // Libera a fila
}

#endif
