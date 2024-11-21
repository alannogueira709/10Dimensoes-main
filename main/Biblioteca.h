#include <WiFi.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>                            //Adição da biblioteca WiFiUdp.h usada para enviar e receber dados de um servidor
#include <PubSubClient.h>  
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <EEPROM.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Update.h>


// Cuidado com a ordem
#include "Configs.h"
#include "mp3.h"

#include "Movimento.h"
#include "Coreo.h"
#include "WifiSetup.h"
#include "OtaSetup.h"

