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



