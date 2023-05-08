#include <dht11.h> 
#define DHT11PIN 25 
#include "BluetoothSerial.h"
dht11 DHT11;
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
BluetoothSerial SerialBT;
void setup()
{

  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{

  Serial.println("\n");

  int chk = DHT11.read(DHT11PIN);
  
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);
  SerialBT.println((float)DHT11.humidity);


  
  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);
 SerialBT.println((float)DHT11.temperature);
  Serial.print("Sicaklik (Fahrenheit): ");
  Serial.println(DHT11.fahrenheit(), 2);


  Serial.print("Sicaklik (Kelvin): ");
  Serial.println(DHT11.kelvin(), 2);

  // Çiğ Oluşma Noktası, Dew Point
  Serial.print("Cig Olusma Noktasi: ");
  Serial.println(DHT11.dewPoint(), 2);
  
  // 2 saniye bekliyoruz. 2 saniyede bir veriler ekrana yazdırılacak.
  delay(2000);
  
}
