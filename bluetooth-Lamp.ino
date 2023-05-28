
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif


BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(33,OUTPUT);

}

void loop() {

  if (SerialBT.available()) {
    
    int s=SerialBT.read();
 if(s==1){
  digitalWrite(33,HIGH);Serial.println(s);
 }
 else if(s==2){
    digitalWrite(33,LOW);Serial.println(s);
 }
 Serial.println(s);
 
 delay(50);
}

}
