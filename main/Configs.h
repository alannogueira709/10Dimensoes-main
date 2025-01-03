//Versão do Codigo
const char* version = "V1.0";
//WIFI
const char* ssid = "**********";
const char* password = "**********";
const char* host = "*********";




//PWM
#define PWM_FREQ 1000
#define PWM_RESOLUTION 8

//MQTT 
bool MQTT_Connected = false;                    
WiFiClient espClient;                           
PubSubClient client(espClient);                 
IPAddress mqtt_server("Your IP Address");

//MSG
char mensagem[12];

//Portas
// Motor A
const int motor1Pin1 = 25;                      //Pino 1 motor A
const int motor1Pin2 = 26;                      //Pino 2 motor A      
// Motor B 
const int motor2Pin1 = 32;                      //Pino 1 motor B
const int motor2Pin2 = 33;                      //Pino 2 motor B
//LEDS
const int led[8] = {16,17,5,18,19,21,22,23};    //Pinos dos leds

int iled = 0;

unsigned long tempo = 0;
unsigned long timeLimit;
long lastReconnectAttempt = 0;

static const uint8_t PIN_MP3_TX = 12; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 13; // Connects to module's TX 

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;

bool otaIsOpen = false;

int eepromNumero(){
  EEPROM.begin(12);
  float temp2;
  EEPROM.get(0, temp2);
  int tempint = temp2 + 48;
  EEPROM.end();
  return tempint;
}
void gravarEeprom(int temp){
  int num = temp;
  
  EEPROM.begin(12);
  EEPROM.writeFloat(0, num);
  float temp2;
  EEPROM.get(0, temp2);
  int tempint = temp2 + 48;
  
  EEPROM.end();
}




