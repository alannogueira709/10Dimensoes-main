
#include "Biblioteca.h"

void setup() {
  Serial.begin(115200);
  
  //gravarEeprom();//grava o numero do carrinho no endereço 0 da Eeprom --- Descomente para regravar// Atualmente fuciona de 0 a 9
  
  OTASetup();
  SetupLeds();
  Mp3Setup(); 
}

void loop() {
  if(otaIsOpen){
    server.handleClient();
  }
  
  delay(1);
  if (!client.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      lastReconnectAttempt = now;
      // Attempt to reconnect
      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    // Client connected
    client.loop();
  }  
  
}