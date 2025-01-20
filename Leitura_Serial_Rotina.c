#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define led_green 11//Pino do LED verde
#define led_blue 12//Pino do LED azul
#define led_red 13//Pino do Led vermelho
#define buzzer 21//Pino do buzzer

void play_note(int frequency, int duration, int pin);//Declarando a função que toca o buzzer

int main() {
    stdio_init_all();//Incializando a comunicação serial 
    //Inicializando os pinos e definindo como saída
    gpio_init(led_green);
    gpio_set_dir(led_green, GPIO_OUT);
    gpio_init(led_blue);
    gpio_set_dir(led_blue, GPIO_OUT);
    gpio_init(led_red);
    gpio_set_dir(led_red, GPIO_OUT);
    gpio_init(buzzer);
    gpio_set_dir(buzzer, GPIO_OUT);

    char userInput;//Declarando variavel para ler o caracter do teclado

    while(1){
        printf("Comandos: (1-9 pra LED, qwertyui pra notas, x para resetar a placa no modo bootsel):\n");
        userInput = getchar();//Obtendo o caracter do teclado digitado pelo usuário

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
        }else if(userInput == '4'){
            gpio_put(led_green, 1);
            gpio_put(led_blue, 1);
            gpio_put(led_red, 0);
            printf("LED ciano ligado!\n");
        }
        else if(userInput == '5'){
            gpio_put(led_green, 1);
            gpio_put(led_blue, 0);
            gpio_put(led_red, 1);
            printf("LED amarelo ligado!\n");
        }
        else if(userInput == '6'){
            gpio_put(led_green, 0);
            gpio_put(led_blue, 1);
            gpio_put(led_red, 1);
            printf("LED magenta ligado!\n");
        }
        else if(userInput == '7'){
            gpio_put(led_green, 1);
            gpio_put(led_blue, 1);
            gpio_put(led_red, 1);
            printf("LED branco ligado!\n");
        }
        else if(userInput == '8'){
            for (int i = 0; i < 5; i++) {
                gpio_put(led_red, 1);
                sleep_ms(100);
                gpio_put(led_red, 0);
                gpio_put(led_green, 1);
                sleep_ms(100);
                gpio_put(led_green, 0);
                gpio_put(led_blue, 1);
                sleep_ms(100);
                gpio_put(led_blue, 0);
            }
            printf("LEDs vermelho, verde e azul piscando rapidamente!\n");
        }
        else if(userInput == '9'){
            int colors[8][3] = {
                {1, 0, 0}, 
                {0, 1, 0},
                {0, 0, 1},
                {1, 1, 0},
                {1, 0, 1},
                {0, 1, 1},
                {1, 1, 1},
                {0, 0, 0}
            };
            for (int i = 0; i < 8; i++) {
                gpio_put(led_red, colors[i][0]);
                gpio_put(led_green, colors[i][1]);
                gpio_put(led_blue, colors[i][2]);
                sleep_ms(100);
            }
            printf("LEDs de todas as cores piscando!\n");
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
void play_note(int frequency, int duration, int pin)
{
    if (frequency == 0) {
        sleep_ms(duration);  // Pausa (silêncio)
        return;
    }

    int delay = 1000000 / frequency / 2; // Meio ciclo da frequência
    int cycles = (frequency * duration) / 1000;

    for (int i = 0; i < cycles; i++) {
        gpio_put(pin, 1);
        sleep_us(delay);
        gpio_put(pin, 0);
        sleep_us(delay);
    }
}