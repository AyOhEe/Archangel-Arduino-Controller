void setup(){
   
  // Set the baud rate  
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
   
}

unsigned int blink_delay = 100;

void loop(){
 
  if(Serial.available() > 0) {
    //faster reimplementation of Serial.readStringUntil
    char buffer[Serial.available() + 1];

    int index = 0;
    while(Serial.available() > 0){
      if (Serial.peek() == "\n")
        break;

      buffer[index] = Serial.read();
      index += 1;
    }
    buffer[index] = "\0";

    //don't forget to set the delay;
    blink_delay = atoi(buffer);
  }

  delay(blink_delay);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blink_delay);
  digitalWrite(LED_BUILTIN, LOW);

}