#include <SPI.h> //INCLUSÃO DE BIBLIOTECA
#include <MFRC522.h> //INCLUSÃO DE BIBLIOTECA
#include <Servo.h>  //importa a biblioteca do servo motor
#include "DHT.h" //importa biblioteca do sensor de temp/umidade
#include <ArduinoJson.h> //importa biblioteca do Json

#define DHTPIN  7  //define o pino usado no DHT
#define DHTTYPE DHT11
#define SS_PIN 10 //PINO SDA
#define RST_PIN 9 //PINO DE RESET

MFRC522 rfid(SS_PIN, RST_PIN); //PASSAGEM DE PARÂMETROS REFERENTE AOS PINOS
DHT dht(DHTPIN, DHTTYPE); //declara a objeto da classe
Servo myservo;  

const int TAMANHO = 50;  //define o tamanho do buffer para o json

long tempoAnterior=0;
long tempo=30000; // tempo equivalente a 30 segundos
 
void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  SPI.begin(); //INICIALIZA O BARRAMENTO SPI
  dht.begin(); //INICIALIZA O sensor DHT
  rfid.PCD_Init(); //INICIALIZA MFRC522
  myservo.attach(6);    //associa servo ao pino 9
  myservo.write(0);
}

void loop() {
  // Json
  StaticJsonDocument<TAMANHO> json; //Aloca buffer para objeto json

  //Logica para contornar o delay
  if (millis() >= tempoAnterior+30000) {
    tempoAnterior = millis();

    // Faz a leitura da temperatura  
    float temp = dht.readTemperature();
    // faz a leitura da humidade
    float umi = dht.readHumidity();
    
    //formato de escrita do json
    json["temperatura"] = temp;
    json["umidade"] = umi;
      
    serializeJson(json, Serial);
    Serial.println();
    
    }
    
  if(Serial.available() > 0) {
    deserializeJson(json, Serial);
    if(json.containsKey("posicao")) {
      
      int valor = json["posicao"];
      
      if (valor > 0 && valor < 180) {
        
          myservo.write(valor);
          
          }
    }
  } //end if serial available
  
  // RFID
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) //VERIFICA SE O CARTÃO PRESENTE NO LEITOR É DIFERENTE DO ÚLTIMO CARTÃO LIDO. CASO NÃO SEJA, FAZ
    return; //RETORNA PARA LER NOVAMENTE
 
  /***INICIO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();
  /***FIM DO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/
 
  //Serial.print("Identificador (UID) da tag: "); //IMPRIME O TEXTO NA SERIAL
  //Serial.println(strID); //IMPRIME NA SERIAL O UID DA TAG RFID
 
  rfid.PICC_HaltA(); //PARADA DA LEITURA DO CARTÃO
  rfid.PCD_StopCrypto1(); //PARADA DA CRIPTOGRAFIA NO PCD
 
  //formato de escrita do json
  json["uidtag"] = strID;
   
  serializeJson(json, Serial);
  Serial.println();

}

/*
https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-kit-rfid-mfrc522
https://arnaldojr.github.io/IoT/aulas/lab6/
https://www.youtube.com/watch?v=rkicyLRCkHI
https://www.youtube.com/watch?v=24ZY3CEsiow
https://stevesnoderedguide.com/node-red-example-flows
https://www.youtube.com/watch?v=kNfP1vw2Img
*/
