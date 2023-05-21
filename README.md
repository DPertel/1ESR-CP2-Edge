CheckPoint 02:

- Deivison Pertel – RM 550803
- Eduardo Akira Murata – RM 98713
- Guilherme Jacob Soares da Costa – RM 84581
- Fabrizio El Ajouri Romano – RM 550410
- Wesley Souza de Oliveira – RM 97874

# Sistema de Monitoramento Ambiental
Este repositório contém um código em Arduino para um sistema de monitoramento ambiental que utiliza diversos sensores para medir temperatura, luminosidade e umidade. O sistema exibe as leituras em um display LCD e aciona LEDs e um buzzer para indicar condições ambientais específicas.

[Link para o Projeto no Tinkercad]([http://google.com/](https://www.tinkercad.com/things/g6WkUIUNhM3-teste-checkpoint2/editel?sharecode=hPT0RZawvk_LGobn3Pr2RnJmoK-4cah-GPdFZFbOCDc))

---

## Requisitos
- Placa Arduino compatível
- Módulo LCD (baseado no controlador HD44780)
- Sensor de temperatura
- Sensor de luz
- Fotorresistor
- LED vermelho
- LED amarelo
- LED verde
- Buzzer
- Potenciômetro

---

## Conexões
LCD:

- Pino RS do LCD -> Pino digital 12 do Arduino
- Pino Enable do LCD -> Pino digital 11 do Arduino
- Pinos D4, D5, D6, D7 do LCD -> Pinos digitais 10, 5, 4, 3 do Arduino
Outras conexões:

- Pino do fotorresistor -> Pino analógico A3 do Arduino
- Pino do sensor de temperatura -> Pino analógico A0 do Arduino
- Pino do sensor de luz -> Pino analógico A1 do Arduino
- Pino do potenciômetro -> Pino analógico A2 do Arduino
- Pino do LED vermelho -> Pino digital 6 do Arduino
- Pino do LED amarelo -> Pino digital 7 do Arduino
- Pino do LED verde -> Pino digital 8 do Arduino
- Pino do buzzer -> Pino digital 9 do Arduino

Certifique-se de conectar os componentes corretamente conforme as instruções acima.

---
## Funcionamento
O código configura os pinos necessários, inicializa o LCD e inicia a comunicação serial. Em seguida, entra em um loop infinito onde realiza as seguintes ações:

1. Lê os valores dos sensores de temperatura, luz e potenciômetro.
2. Converte o valor do sensor de temperatura para graus Celsius.
3. Verifica o valor do fotorresistor para determinar o estado da luminosidade do ambiente.
4. Com base no valor do fotorresistor, acende os LEDs correspondentes e emite um som de buzzer.
5. Exibe as informações no LCD de acordo com o estado da luminosidade.
6. Aguarda 5 segundos e limpa o LCD.
7. Verifica o valor do sensor de luz para determinar o estado da umidade.
8. Com base no valor do sensor de luz, acende os LEDs correspondentes e emite um som de buzzer.
9. Exibe as informações no LCD de acordo com o estado da umidade.
10. Aguarda 5 segundos e limpa o LCD.
11. Verifica o valor do sensor de temperatura para determinar o estado da temperatura.
12. Com base no valor do sensor de temperatura, acende os LEDs correspondentes e emite um som de buzzer.
13. Exibe as informações no LCD de acordo com o estado da temperatura.
14. Aguarda 5 segundos e limpa o LCD.

O ciclo se repete continuamente, fornecendo um monitoramento contínuo das condições ambientais.

----
## Ajuste do Potenciômetro
O potenciômetro é utilizado para ajustar a umidade. Gire o potenciômetro para ajustar a umidade conforme necessário.

----
## Observações
- Certifique-se de ter as bibliotecas necessárias instaladas, como a biblioteca LiquidCrystal.

- As conexões devem ser feitas corretamente para garantir o funcionamento adequado do sistema.
As condições de luminosidade, umidade e temperatura para acionamento dos LEDs e do buzzer podem ser ajustadas no código conforme necessário.

- O código está configurado para imprimir as leituras dos sensores na porta serial. Você pode visualizar essas leituras através de um monitor serial no software Arduino IDE ou outro software de comunicação serial.

---

