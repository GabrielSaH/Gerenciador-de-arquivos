#include <time.h>
#include "timer.h"

// Iniciar o timer com uma duração específica
void start_timer(struct timer *t, uint32 duration) {
    t->start_time = (uint32)time(NULL);  // Pega o tempo atual
    t->duration = duration;  // Define a duração do timer
    t->running = true;  // Marca o timer como em execução
}

// Parar o timer
void stop_timer(struct timer *t) {
    t->running = false;  // Marca o timer como parado
}

// Verificar se o timer expirou
bool is_timer_expired(const struct timer *t) {
    if (!t->running) {
        return false;  // Se não estiver rodando, não expirou
    }

    uint32 current_time = (uint32)time(NULL);  // Pega o tempo atual
    return (current_time - t->start_time) >= t->duration;  // Verifica se expirou
}

// Obter o tempo decorrido desde o início do timer
uint32 get_elapsed_time(const struct timer *t) {
    if (!t->running) {
        return 0;  // Se não estiver rodando, tempo é zero
    }

    uint32 current_time = (uint32)time(NULL);  // Pega o tempo atual
    return current_time - t->start_time;  // Calcula o tempo decorrido
}
