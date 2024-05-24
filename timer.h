#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include "types.h"

// Estrutura para um timer
struct timer {
    uint32 start_time;  // Tempo de início do timer
    uint32 duration;  // Duração do timer (quantum)
    bool running;  // Indica se o timer está rodando
};

// Funções para operações com o timer
void start_timer(struct timer *t, uint32 duration); // Iniciar timer
void stop_timer(struct timer *t); // Parar timer
bool is_timer_expired(const struct timer *t); // Verificar se o timer expirou
uint32 get_elapsed_time(const struct timer *t); // Obter tempo decorrido

#endif
