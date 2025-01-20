# Leitura da comunicação serial do Raspberry Pi Pico W com computador
Este projeto tem como objetivo verificar e testar o funcionamento da comunicação serial do Raspberru Pi Pico W

# Como baixar e executar o código
    1-Baixar ou utilizar git clone no repositório.
          git clone https://github.com/MSoares0079/EmbarcaTech-Leitura_Serial_Putty-Subgrupo_4.git
    2-Ter o VS Code instalado e configurado.
    3-Ter a extensão do Raspberry Pi Pico instalada.
    4-Compilar o arquivo "Leitura_Serial_Rotina.c" utilizando o compilador do Raspberry Pi Pico.
    5-Apesar de ser possivel simular pelo "diagram.json" apartir da extensão Wokwi,
        é recomendado compilar o código em uma placa Raspberry Pi Pico W.
    6-Para executar o código é necessário a comunicação serial com o dispositivo, 
        recomenda-se o uso do software putty ou utilizar a monitor serial do VS Code.

# Estrutura do código
O código consiste em ler a entrada do caractere digitado pelo usuário, no qual aciona LEDs e um buzzer dependendo do caractere apertado. Entretanto para visualizar e comunicar com o programa é necessário a presença de uma comunicação serial com o Raspberry Pi Pico W.

# Funcionalidades
    1- Acende o LED verde
    2- Acende o LED azul
    3- Acende o LED vermelho
    4- Acende o LED ciano(verde+azul)
    5- Acende o LED amarelo(verde+vermelho)
    6- Acende o LED magenta(azul+vermelho)
    7- Acende o LED branco(verde+azul+vermelho)
    8- LEDs verde, azul e vermelho piscam rapidamente
    9 -LEDs de todas as cores piscam
    q- Buzzer toca nota C4(Dó)
    w- Buzzer toca nota D4(Ré)
    e- Buzzer toca nota E4(Mi)
    r- Buzzer toca nota F4(Fá)
    t- Buzzer toca nota G4(Sol)
    y- Buzzer toca nota A4(Lá)
    u- Buzzer toca nota B4(Si)
    i- Buzzer toca nota C5(Dó)
    x- Reinicia o Raspberry em modo Bootsel
      Observação: a opção de reiniciar o Raspberry não funciona na simulação do Wokwi,
                  porque a função afeta a porta USB já a comunicação da simulação é através da UART. 
# Link de um vídeo demostrando o funcionamento do código
https://drive.google.com/file/d/1KtKvW7qeH8SCul4AlFUwnvlVl28l1hjR/view?usp=drive_link
