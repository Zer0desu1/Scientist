
void setup() {
  for(int i=4;i<=11;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
   for(int i=4;i<=11;i++){
      digitalWrite(i,HIGH);
    }

    if(digitalRead(2)==1){
        for(int i=4;i<=11;i++){
      digitalWrite(i,LOW);
      delay(1000);
    }
 for(int i=4;i<=11;i++){
      digitalWrite(i,HIGH);
      delay(1000);
    }
    }
 
   

}
