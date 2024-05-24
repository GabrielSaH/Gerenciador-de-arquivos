#ifndef IO_DEVICE_H
#define IO_DEVICE_H

#include <stdlib.h>
#include "process.h"

// Representa um dispositivo de entrada/saída
struct io_device {
    char *name; // Nome do dispositivo
    struct process_queue *queue; // Fila de processos aguardando acesso ao dispositivo
};

// Cria um novo dispositivo de I/O
struct io_device *create_io_device(const char *name) {
    struct io_device *device = (struct io_device *)malloc(sizeof(struct io_device));
    if (device != NULL) {
        device->name = name; // Atribui o nome ao dispositivo
        device->queue = create_process_queue(); // Cria uma fila de processos
    }
    return device;
}

// Destrói um dispositivo de I/O
void destroy_io_device(struct io_device *device) {
    destroy_process_queue(device->queue); // Destrói a fila de processos
    free(device); // Libera a memória do dispositivo
}

#endif
