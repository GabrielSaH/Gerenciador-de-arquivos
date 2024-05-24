#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ipc.h"

// Função para criar uma fila de mensagens
struct message_queue *create_message_queue(int capacity) {
    struct message_queue *mq = (struct message_queue *)malloc(sizeof(struct message_queue));
    if (mq == NULL) {
        return NULL;
    }

    mq->queue = (struct message *)malloc(sizeof(struct message) * capacity);
    if (mq->queue == NULL) {
        free(mq);
        return NULL;
    }

    mq->capacity = capacity;
    mq->size = 0;
    mq->front = 0;
    mq->rear = -1;

    return mq;
}

// Função para destruir uma fila de mensagens
void destroy_message_queue(struct message_queue *mq) {
    if (mq != NULL) {
        free(mq->queue);   // Libera o array de mensagens
        free(mq);   // Libera a estrutura de fila
    }
}

// Função para enviar uma mensagem para a fila
int send_message(struct message_queue *mq, struct message *msg) {
    if (mq->size == mq->capacity) {   // Verifica se a fila está cheia
        return -1;   // Fila cheia, não é possível enviar mensagem
    }

    mq->rear = (mq->rear + 1) % mq->capacity;   // Avança o índice do último elemento
    mq->queue[mq->rear] = *msg;   // Adiciona a mensagem à fila
    mq->size++;   // Aumenta o tamanho da fila

    return 0;   // Mensagem enviada com sucesso
}

// Função para receber uma mensagem de uma fila
struct message *receive_message(struct message_queue *mq, pid_t pid) {
    if (mq->size == 0) {   // Verifica se a fila está vazia
        return NULL;   // Fila vazia, sem mensagens para receber
    }

    struct message *msg = &mq->queue[mq->front];   // Pega a primeira mensagem

    if (msg->destination != pid) {
        return NULL;   // Se o destinatário não é o processo, não retorna mensagem
    }

    mq->front = (mq->front + 1) % mq->capacity;   // Avança o índice do primeiro elemento
    mq->size--;   // Diminui o tamanho da fila

    return msg;   // Retorna a mensagem para o processo
}
