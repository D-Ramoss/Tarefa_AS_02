#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

#define TEMPORIZADOR 3000 // 3 segundos

bool temporizador_callback(struct repeating_timer *t) {
    static int estado = 0;

    switch (estado) {
        case 0:
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 0);
            estado = 1;
            break;
        case 1:
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 1);
            gpio_put(LED_VERDE, 0);
            estado = 2;
            break;
        case 2:
            gpio_put(LED_VERMELHO, 0);
            gpio_put(LED_AMARELO, 0);
            gpio_put(LED_VERDE, 1);
            estado = 0;
            break;
    }

    return true;
}

int main() {
    stdio_init_all();

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(-TEMPORIZADOR, temporizador_callback, NULL, &timer);

    while (true) {
        printf("Atualizando estado do semáforo...\n");
        sleep_ms(1000);
    }

    return 0;
}