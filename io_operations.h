#ifndef IO_OPERATIONS_H
#define IO_OPERATIONS_H

#include "io_device.h"
#include "process_queue.h"

// Função para simular uma operação de leitura
void io_read(struct io_device *device, struct process *proc) {
    enqueue_process(device->queue, proc); // Adiciona o processo à fila
    printf("Process %lu is reading from device: %s\n", proc->pid, device->name);
}

// Função para simular uma operação de escrita
void io_write(struct io_device *device, struct process *proc) {
    enqueue_process(device->queue, proc); // Adiciona à fila
    printf("Process %lu is writing to device: %s\n", proc->pid, device->name);
}

// Função para simular uma liberação de dispositivo de I/O
void release_io(struct io_device *device) {
    struct process *proc = dequeue_process(device->queue); // Remove um processo da fila
    if (proc != NULL) {
        printf("Process %lu has completed I/O operation\n", proc->pid);
    } else {
        printf("No processes waiting for device: %s\n", device->name);
    }
}

#endif
