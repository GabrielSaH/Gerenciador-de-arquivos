// Arquivo de cabeçalho para IPC
#ifndef IPC_H
#define IPC_H

#define MAX_MESSAGE_SIZE 256

typedef unsigned long pid_t;

// Estrutura para uma mensagem
struct message {
    pid_t source;   // PID do processo remetente
    pid_t destination;   // PID do processo destinatário
    char content[MAX_MESSAGE_SIZE];   // Conteúdo da mensagem
};

// Fila de mensagens para comunicação entre processos
struct message_queue {
    struct message *queue;   // Array para armazenar mensagens
    int size;   // Tamanho da fila
    int capacity;   // Capacidade máxima da fila
    int front;   // Índice do primeiro elemento
    int rear;   // Índice do último elemento
};

// Função para criar uma fila de mensagens
struct message_queue *create_message_queue(int capacity);

// Função para destruir uma fila de mensagens
void destroy_message_queue(struct message_queue *mq);

// Função para enviar uma mensagem
int send_message(struct message_queue *mq, struct message *msg);

// Função para receber uma mensagem
struct message *receive_message(struct message_queue *mq, pid_t pid);

#endif
