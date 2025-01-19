#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

int main() {
    stdio_init_all();
    //Teste para comunicação serial
    for( int i =0;i<10;i++){
        printf("TESTE");
    }
    reset_usb_boot(0, 0);//Função que reseta a placa no modo bootsel
}