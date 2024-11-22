# 10 Dimensões - Baile dos Robôs
Repositório da versão atual utlilizada pelo projeto de extensão da UFRN, 10 Dimensões. O projeto já conta com 2 versões e estamos desenvolvendo a terceira utilizando ROS (Robotic Operating System) e diversas melhorias de hardware, especificadas nos projetos elétricos e de circuitos.

![WhatsApp Image 2024-11-19 at 13 06 19](https://github.com/user-attachments/assets/978d407a-de41-4fa7-83e1-df29f089213e)

# Documentação 

Segue na figura abaixo a arquitetura do protocolo de comunicação utilizado por nós, sendo esta, O MQTT (Message Queueing Telemetry Transport).

![mqtt drawio](https://github.com/user-attachments/assets/9964ef8b-1a0e-4fba-a47b-982c3fb37b0d)

O Baile dos Robôs consiste na criação de uma plataforma robótica de Internet das Coisas (IoT) e para isso, faz-se necessário a inclusão de um protocolo de mensagens rápido e eficiente, o que justifica o apelo popular e generalizado pelo MQTT ao tratar de soluções em IoT.

# Dependências 

Abaixo, segue os primeiros passos de como configurar seu ambiente de trabalho para utilizar nossa plataforma de desenvolvimento.

1. Instale o MQTT;
2. Instale as bibliotecas utilizadas;
3. Certifique-se de que o ESP32 (microcontrolador que utilizamos) esteja configurado em sua IDE de preferência.
> **(Recomendamos utilizar Arduino IDE ou PlatformIO, porém para esta documentação levaremos como referência a IDE do Arduino)**.

## MQTT
> Para instalar o MQTT, utilizaremos como base o tutorial de [instalação](https://mosquitto.org/download/) e configuração do [Mosquitto](https://youtu.be/hyJhKWhxAxA?si=Onx3wufYUxWc94CO)

## Bibliotecas
> As bibliotecas utilizadas pelo nosso software foram as que estão presentes no arquivo header Biblioteca.h
```
#include <WiFi.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>                            
#include <PubSubClient.h>  
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <EEPROM.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Update.h>
```
>> Existem algumas bibliotecas próprias da biblioteca Arduino IDE, outras é necessário fazer a instalação dessas bibliotecas pelo Gerenciador de Bibliotecas do Arduino IDE ou então instalá-las via .zip.

## ESP32 no Arduino IDE
> Para verificar se o ESP32 está configurado para rodar no Arduino IDE, siga o tutorial presente nesse [exemplo](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/).

## Download do software

No seu diretório de uso, faça:

```
$git clone https://github.com/alannogueira709/10Dimensoes-main.git
```

# Como Usar?
O MQTT é um serviço de mensageria, logo os callbacks (funções que são chamadas a partir de uma ação específica) são recebidos através de uma String em C++ que é recebida em forma de array e manipulada baseada em dois paramêtros:

* O que você quer chamar?
* Quem você quer chamar? (qual dispositivo)

Logo, para isso foram definidas algumas regras de uso. A primeira parte das mensagens recebidas é 'DNX' referindo-se ao qual dos dispositivos será chamado, 'DN' é o prefixo do dispositivo e 'X' é o sufixo que se refere ao número do dispositivo ou no caso queira utilizar todos ao mesmo tempo, recebendo as mensagens simultâneamente utilizando o comando 'DNX'. A segunda parte da mensagem é seguida de um caractere '=' e o resto da mensagem que se refere às funções disponíveis de serem chamadas.

> Lista de funções:

>> MF = Mover Frente;

>> MT = Mover Trás;

>> PA = Para;

>> CG = Todas as coreografias;

>> C1 - C4 = Escolhe a coreografia desejada;

>> OT = Permite a conexão OTA (over the air);

>> GD = Mover no próprio eixo para a direita;

>> GE = Mover no próprio eixo para a esquerda;

>> L0 - L7 = Liga os leds de acordo com seu número de identificação;

>> D0 - D7 = Desliga os leds de acordo com seu número de identificação;

>> XY = Recebe os valores _signed_ de X e Y baseados em um controle externo que recebe dados de acelerômetro e giroscópio.

# Interface Gráfica
Nós utilizamos uma interface gráfica para dispositivos pessoais e movéis para facilitar o uso do MQTT e transmissão de payloads (_à depender do sistema utilizado_).

* No Windows utilizaremos como base o aplicativo MQTT Box disponível na Microsoft Store gratuitamente

![image](https://github.com/user-attachments/assets/e209a0ee-9a6f-456a-b104-0b16dab691dc)
_Logo do aplicativo MQTT Box_

* Já tanto no Android como no IOS, utilizaremos o aplicativo IoT MQTT Panel 

![image](https://github.com/user-attachments/assets/3de5654f-9f20-4344-a3e8-a5bbd82afa7e)
_Página do aplicativo IoT MQTT Panel na Google Play Store_

# Configurando a interface gráfica
Para configurar a interface gráfica para melhor utilizá-la em conformidade com o software feito siga o passo a passo a seguir.

## Windows:

No Windows ao entrar na home page do aplicativo você irá se deparar com a seguinte tela.

![image](https://github.com/user-attachments/assets/c27981a8-762f-4143-be44-92a457224f6f)

Clique no botão que se encontra na parte superior da tela "Create MQTT Client", e você será redirecionado para a página de criação do seu cliente MQTT.

![Captura de tela 2024-11-22 165158](https://github.com/user-attachments/assets/691f1f7b-0b3e-471d-97b2-85e180a4d704)

Preencha os campos de acordo com sua utilização

![image](https://github.com/user-attachments/assets/61c275ff-f984-45b0-ba5d-f77866d449c4)

Depois configure os tópicos de publish

![image](https://github.com/user-attachments/assets/85d8cae6-7202-4905-860e-9f0a275ae034)

e subscribers.

![image](https://github.com/user-attachments/assets/5cc25270-93ab-4f30-b8c6-bd31b1978f39)


## Dispositivos Movéis

Para dispositivos movéis ao abrir a página inicial você irá se deparar com essa tela:

![image](https://github.com/user-attachments/assets/d2c3f736-615d-4cc1-819a-39ca31ec99f8)

e irá clicar no ícone que possui um '+' na parte inferior direita da tela. Logo após, você será redirecionado à tela de criação de cliente MQTT:

![image](https://github.com/user-attachments/assets/785e7af5-1bc6-4c7d-87cf-1df46ca4e18a)

Preencha com os dados do seu broker MQTT e logo após isso o aplicativo irá te redirecionar ao seu dashboard, lá você poderá editar e criar seus payloads, um exemplo disto segue abaixo:

![image](https://github.com/user-attachments/assets/8da5d6ee-dd38-4162-87af-d43a352498cf)











