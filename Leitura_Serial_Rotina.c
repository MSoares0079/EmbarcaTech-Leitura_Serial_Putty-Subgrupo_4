#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define led_green 11
#define led_blue 12
#define led_red 13

int main() {
    stdio_init_all(); 

    gpio_init(led_green);
    gpio_set_dir(led_green, GPIO_OUT);
    gpio_init(led_blue);
    gpio_set_dir(led_blue, GPIO_OUT);
    gpio_init(led_red);
    gpio_set_dir(led_red, GPIO_OUT);
    gpio_init(buzzer);
    gpio_set_dir(buzzer, GPIO_OUT);

    char userInput;

    while(1){
        userInput = getchar();

        if(userInput == '1'){
            gpio_put(led_green, 1); 
            gpio_put(led_blue, 0);
            gpio_put(led_red, 0);
            printf("LED verde ligado!\n");
        }
        else if(userInput == '2'){
            gpio_put(led_green, 0);
            gpio_put(led_blue, 1);
            gpio_put(led_red, 0);
            printf("LED azul ligado!\n");
        }
        else if(userInput == '3'){
            gpio_put(led_green, 0);
            gpio_put(led_blue, 0);
            gpio_put(led_red, 1); 
            printf("LED vermelho ligado!\n");
        }
    }
}