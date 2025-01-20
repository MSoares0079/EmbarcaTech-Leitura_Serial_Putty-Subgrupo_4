#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define led_green 11
#define led_blue 12
#define led_red 13
#define buzzer 21


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
        printf("Comandos: (1-9 pra LED, qwertyui pra notas, x para resetar a placa no modo bootsel):\n");
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
        else if(userInput == 'q'){
            play_note(262, 100, buzzer); // C4
            printf("Buzzer tocou C4!\n");
        }
        else if(userInput == 'w'){
            play_note(294, 100, buzzer); // D4
            printf("Buzzer tocou D4!\n");
        }
        else if(userInput == 'e'){
            play_note(330, 100, buzzer); // E4
            printf("Buzzer tocou E4!\n");
        }
        else if(userInput == 'r'){
            play_note(349, 100, buzzer); // F4
            printf("Buzzer tocou F4!\n");
        }
        else if(userInput == 't'){
            play_note(392, 100, buzzer); // G4
            printf("Buzzer tocou G4!\n");
        }
        else if(userInput == 'y'){
            play_note(440, 100, buzzer); // A4
            printf("Buzzer tocou A4!\n");
        }
        else if(userInput == 'u'){
            play_note(494, 100, buzzer); // B4
            printf("Buzzer tocou B4!\n");
        }
        else if(userInput == 'i'){
            play_note(523, 100, buzzer); // C5
            printf("Buzzer tocou C5!\n");
        }
        else if(userInput == 'x'){
            printf("Resetando a placa\n");
            reset_usb_boot(0, 0);
        }
         else if(userInput == '0'){
            gpio_put(led_red, 0);
            gpio_put(led_green, 0);
            gpio_put(led_blue, 0);
            printf("Leds desligados!\n");
        }
        else{
            printf("Entrada inválida!\n");
        }

    }
}