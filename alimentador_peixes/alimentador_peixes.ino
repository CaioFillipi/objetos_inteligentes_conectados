#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>

const char* ssid = "*******"; //Aqui você deve passar como valor o nome da sua rede wifi
const char* password = "*******"; // Aqui você deve passar como valor a senha da sua rede wifi
int MOTOR = 14;
int SENSOR = 13;
int timeStartAutomatic = 0;

OneWire onewire(SENSOR);
DallasTemperature sensors(&onewire);


WiFiServer server(80);
 
void setup() {
  pinMode(MOTOR,OUTPUT);
  sensors.begin();
  Serial.begin(115200);
  
  
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi conectada.");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
}

void loop() {
  timeStartAutomatic++;

  startEngineAutomatic(timeStartAutomatic);
  
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.println("<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Alimentador para peixes</title>");
            client.println("<style>*{margin: 0; padding: 0;} header{ width: 100%; height: 90px; background-color: darkcyan; position: fixed; z-index: 9999;} header p{color: white; text-decoration: none; font-family: 'Barlow', sans-serif; font-size: 1.2em; text-align: center; margin-top: 30px;}");
            client.println(" #media{ width: 35px; border: 1px solid gray; background:white; margin-top:300px; position: fixed; z-index: 9999999;} .container {width: 100vw; height: 100vh; background: #cfe7fa; display: flex; flex-direction: row; justify-content: center; align-items: center;}");
            client.println(" .box {margin-top: 70px; width: 49vw; height: 49vh; background: #fff; border-radius: 5px;} .box p{font-family: 'Barlow', sans-serif; font-size:0.9em; padding: 15px;} .box button{border-radius:3px;font-family: 'Barlow', sans-serif;cursor:pointer;background-color: darkcyan;padding: 5px 15px;border-radius: 5px; font-weight:bold;font-size:0.9em;color: white;margin:15px}");
            client.println("</style></head><body><header><p>Bem Vindo ao Alimentor de Peixes</p></header><div class=\"container\"><div class=\"box\"><p>Temperatura da Água: ");
            client.println(sensors.getTempCByIndex(0));
            client.println(" Cº</p><a href=\"/H\"><button>Acionar Motor</button></a></div></div></body></html>");
            
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        if (currentLine.endsWith("GET /H")) {
          startEngine();
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

void startEngine(){
  digitalWrite(MOTOR,1);
  delay(1500);
  digitalWrite(MOTOR,0);
}

void startEngineAutomatic(int timeToStart){
  if(timeToStart == 28800000){//esse valor corresponde a 8 horas em milisegundos
    startEngine();
  }
}

  
