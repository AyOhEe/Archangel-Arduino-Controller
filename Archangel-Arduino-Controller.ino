#include <Servo.h>

const unsigned int N_SERVOS = 3;
const unsigned int SERVO_PINS[N_SERVOS] = {9, 10, 11};
Servo SERVOS[N_SERVOS];


void setup(){
   
  // Set the baud rate  
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  //attach the servos
  for (int i = 0; i < N_SERVOS; i++){
    SERVOS[i].attach(SERVO_PINS[i]);
    SERVOS[i].write(0);
  }
   
}

void loop(){
 
  int servo = -1;
  int value = -1;
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
    //ensure the string is properly terminated
    buffer[index] = "\0";

    //subtracting 0 gives us the difference in value between 0 and the given byte, 
    //i.e. the numerical difference between the numbers the characters represent
    servo = buffer[0] - '0';
    //this skips a character (the one which we just used to get the servo index)
    value = atoi(buffer + 1);
  }

  if (servo != -1 && servo < N_SERVOS) {
    SERVOS[servo].write(value);
  }

  //this doesn't need to run too often
  delay(20);
}