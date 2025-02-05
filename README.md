SEMÁFORO COM LED'S

Este programa simula um semáforo com LEDs, utilizando o Raspberry Pi Pico como plataforma de desenvolvimento.

Instruções de Uso:

Conecte os LEDs ao Raspberry Pi Pico, seguindo a seguinte configuração:
LED Vermelho: GPIO 11
LED Amarelo: GPIO 12
LED Verde: GPIO 13

O programa irá iniciar o semáforo, alternando entre os LEDs vermelho, amarelo e verde a cada 3 segundos.

Funcionamento:

O programa utiliza um temporizador para alternar entre os LEDs a cada 3 segundos. 
O temporizador é configurado para executar a função temporizador_callback a cada 3 segundos, que é responsável por atualizar o estado do semáforo.

Autor: Douglas Ramos