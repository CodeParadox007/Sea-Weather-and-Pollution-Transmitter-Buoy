#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = "k_NztFb20sJcVZsbKxgObfyR5rZRKP79";
char ssid[] = "Hasib";
char pass[] = "faukhaba?";


//create an RF24 object
RF24 radio(4, 5);  // CE, CSN


//address through which two modules communicate.
const byte address[6] = "zulas";
float temp , water_temp,water_level, tur, x , y ,pressure; 
void setup()
{


  Serial.begin(9600);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("WiFi connected");  


  Blynk.begin( auth, ssid, pass,"blynk.cloud", 80);


  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
}


void loop()
{
    Blynk.run();
  //Read the data if available in buffer
  if (radio.available())
  {
    float msg[10];
    radio.read(&msg, sizeof(msg));
    tur = msg[0];
    temp = msg[1];
    pressure = msg[2];
    water_level = msg[3];
    water_temp = msg[4];
    x = msg[5];
    y = msg[6];
    Serial.println("Turbidity");
    Serial.println(msg[0]);
    Serial.println("air temperature");
    Serial.println(msg[1]);
    Serial.println("pressure");
    Serial.println(msg[2]);
    Serial.println("water level");
    Serial.println(msg[3]);
    Serial.println("water temperature");
    Serial.println(msg[4]);
    Serial.println("gyro X");
    Serial.println(msg[5]);
    Serial.println("gyro y");
    Serial.println(msg[6]);


    Blynk.virtualWrite(V0, tur);
    Blynk.virtualWrite(V1, x);
    Blynk.virtualWrite(V2, temp);
    Blynk.virtualWrite(V3, pressure);
    Blynk.virtualWrite(V4, y);
    Blynk.virtualWrite(V5, water_level);
    Blynk.virtualWrite(V6, water_temp);
}
}
