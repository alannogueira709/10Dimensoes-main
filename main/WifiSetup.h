
bool reconnect() {
    
  // Loop repetido até o estabelecimento da reconexão ->
  if (!client.connected()) {
    MQTT_Connected = false;
    Serial.print("Attempting MQTT connection...");

    // Criação de um "Client ID" randômico:
    String clientId = "dan1";
    clientId += String(random(0xffff), HEX);

    // Tentativa de conexão:
    if(client.connect(clientId.c_str())) {
      MQTT_Connected = true;
      Serial.println("connected");
           
      char init[10] = "DN0-V0.0";
      init[2] = eepromNumero(); 
      init[5] = version[1];
      init[7] = version[3];
      client.publish("status", init);
      
      // ... e reescreva dentro do tópico:
      client.subscribe("cmd"); 
    }else{
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
    }
  }
  return client.connected();
}



void callback(char* topic, byte* payload, unsigned int length) {

 
  for (int i = 0; i < length; i++) {
     mensagem[i] = char(payload[i]);
  }

  //Serial.println();

  if (mensagem[0] == 'D' and mensagem[1] == 'N') {
    if (mensagem[2] == 'X') {
      if(mensagem[4] == 'X' and mensagem[7] == 'Y'){
        if(mensagem[5] == '+' and mensagem[8] == '+') {
          PWM(int(mensagem[6])-48,int(mensagem[9])-48);
        }
        if(mensagem[5] == '+' and mensagem[8] == '-') {
          PWM(int(mensagem[6])-48,-(int(mensagem[9])-48));
        }
        if(mensagem[5] == '-' and mensagem[8] == '+') {
          PWM(-(int(mensagem[6])-48),int(mensagem[9])-48);
        }
        if(mensagem[5] == '-' and mensagem[8] == '-') {
          PWM(-(int(mensagem[6])-48),-(int(mensagem[9])-48));
        }
      }
        
      if(mensagem[4] == 'C' and mensagem[5] == 'G' ) {
        coreo();
      }
      if(mensagem[4] == 'C' and mensagem[5] == '1' ) {
        
      }
      if(mensagem[4] == 'C' and mensagem[5] == '2' ) {
        
      }
      if(mensagem[4] == 'C' and mensagem[5] == '3' ) {
        
      }
      if(mensagem[4] == 'C' and mensagem[5] == '4' ) {
        
      }
      if(mensagem[4] == 'O' and mensagem[5] == 'T'){
        otaIsOpen = true;
      }
      if (mensagem[4] == 'M' and mensagem[5] == 'F') {
        movF(1);
      }
      if (mensagem[4] == 'M' and mensagem[5] == 'T') {
        movT(1);
      }
      if (mensagem[4] == 'G' and mensagem[5] == 'D') {
        girD(1);
      }
      if (mensagem[4] == 'G' and mensagem[5] == 'E') {
        girE(1);
      }
      if (mensagem[4] == 'P' and mensagem[5] == 'A') {
        para();
      }
      if (mensagem[4] == 'L') {
        digitalWrite(led[int(mensagem[5])-48], HIGH);
        Serial.println(int(mensagem[5])-48);
      }
      if (mensagem[4] == 'D') {
        digitalWrite(led[int(mensagem[5])-48], LOW);
      }
    }
    if (mensagem[2] == eepromNumero()) {
      if(mensagem[4] == 'X' and mensagem[7] == 'Y'){
        if(mensagem[4] == 'O' and mensagem[5] == 'T'){
        otaIsOpen = true;
        }
        if(mensagem[5] == '+' and mensagem[8] == '+') {
          PWM(int(mensagem[6])-48,int(mensagem[9])-48);
        }
        if(mensagem[5] == '+' and mensagem[8] == '-') {
          PWM(int(mensagem[6])-48,-(int(mensagem[9])-48));
        }
        if(mensagem[5] == '-' and mensagem[8] == '+') {
          PWM(-(int(mensagem[6])-48),int(mensagem[9])-48);
        }
        if(mensagem[5] == '-' and mensagem[8] == '-') {
          PWM(-(int(mensagem[6])-48),-(int(mensagem[9])-48));
        }
      }
        
      if(mensagem[4] == 'C' and mensagem[5] == 'G' ) {
        coreo();
      }
      if(mensagem[4] == 'C' and mensagem[5] == '1' ) {
        
      }
      if(mensagem[4] == 'C' and mensagem[5] == '2' ) {
        
      }
      if(mensagem[4] == 'C' and mensagem[5] == '3' ) {
        
      }
      if(mensagem[4] == 'C' and mensagem[5] == '4' ) {
        
      }
      if (mensagem[4] == 'M' and mensagem[5] == 'F') {
        movF(1);
      }
      if (mensagem[4] == 'M' and mensagem[5] == 'T') {
        movT(1);
      }
      if (mensagem[4] == 'G' and mensagem[5] == 'D') {
        girD(1);
      }
      if (mensagem[4] == 'G' and mensagem[5] == 'E') {
        girE(1);
      }
      if (mensagem[4] == 'P' and mensagem[5] == 'A') {
        para();
      }
      if (mensagem[4] == 'L') {
        digitalWrite(led[int(mensagem[5])-48], HIGH);
        Serial.println(int(mensagem[5])-48);
      }
      if (mensagem[4] == 'D') {
        digitalWrite(led[int(mensagem[5])-48], LOW);
      }
    }
  }
}
