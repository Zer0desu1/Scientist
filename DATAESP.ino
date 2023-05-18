#include <dht11.h> 
#define DHT11PIN 25 
#include<ESP32Servo.h>
#include "BluetoothSerial.h"
dht11 DHT11;
Servo s;
//HATA BASKISI
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif


BluetoothSerial SerialBT;//bluetooth objesi tanımlama
void setup()
{
s.attach(33);
  Serial.begin(115200);
  SerialBT.begin("ROVER"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);

  //data yollama
 

  
  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)(DHT11.temperature), 2);
 SerialBT.print((float)(DHT11.temperature));

 Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);
  SerialBT.print((float)DHT11.humidity);
 
  int value=analogRead(36);
 int temp=(-0.0244)*value+100;
 SerialBT.print((float)(temp));
 Serial.print("SOİL moisture  ");
Serial.println(temp);

//data 1 ise topraktan veri al
int a=SerialBT.read();
Serial.println(a);

if(a==1){//veri için aşağı in
s.write(95);
delay(3000);
s.write(180);
}

  delay(1000);
  
}
