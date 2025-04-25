#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include<Adafruit_BMP085.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(9, 8);  // CE, CSN
float msg[10];
const byte address[6] = "zulas";


#define seaLevelPressure_hpa 1013.25
#define ONE_WIRE_BUS 2


Adafruit_MPU6050 mpu;
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
Adafruit_BMP085 bmp;
int sensorPin = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();


    sensors.begin();
   if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
  // pinMode(buzzer,OUTPUT);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens


  Serial.println("Adafruit MPU6050 test!");


  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");


  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }


  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }


  Serial.println("");
  delay(100);  


}


void loop() {
  // put your main code here, to run repeatedly:
//TDS
  int sensorValue=analogRead(sensorPin);
  Serial.print("Turbidity :");


int turbidity=map(sensorValue,0, 750, 100, 0);
Serial.println(turbidity);
msg[0]=turbidity; // Turbidity
 delay(500);
   if (turbidity < 20) {
    Serial.println(" its CLEAR ");
  }
  if ((turbidity > 20) && (turbidity < 50)) {
    Serial.println(" its CLOUDY ");
  }
  if (turbidity > 50) {;
    Serial.println(" its DIRTY ");
  }


//bmp
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature()); msg[1]=bmp.readTemperature();
    Serial.println(" *C");  
    
Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());msg[2]=bmp.readSealevelPressure();
    Serial.println(" Pa");


    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude()); msg[3]=bmp.readAltitude();
    Serial.println(" meters");


        Serial.println();


//WaterTemp
sensors.requestTemperatures(); 
  Serial.print("Water Temp");
  Serial.println(sensors.getTempCByIndex(0));msg[4]=sensors.getTempCByIndex(0);


  //Gyro
sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);


  /* Print out the values */
  int X=a.acceleration.x*100; msg[5]=X;
  int Y=(a.acceleration.y*100); msg[6]=Y;
  int Z=(a.acceleration.z*100);
  Serial.print("Acceleration X: ");
  Serial.print(X);
  Serial.print(", Y: ");
  Serial.print(Y);
  Serial.print(", Z: ");
  Serial.print(Z);
  Serial.println(" m/s^2");  
  Serial.println("______________________________________________________");
  radio.write(&msg, sizeof(msg));
        
    delay(1000);
  
}
