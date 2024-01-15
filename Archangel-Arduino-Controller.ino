//#include <Servo.h>

//Servo myservo;



void setup(){
   
  // Set the baud rate  
  Serial.begin(115200);
  //myservo.attach(9)
   
}

unsigned char servo_state = 0;
 
void loop(){
 
  if(Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    servo_state = (unsigned char)data[0];
    Serial.print("Setting servo state to: ");
    Serial.println(String(servo_state));
  }

  //myservo.write(servo_state);
  //delay(20);
}