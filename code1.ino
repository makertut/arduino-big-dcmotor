  
int RPWM_Output = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)

String inString = "";    // string to hold input
int motorPWM = 0;
 
void setup()
{
  Serial.begin(9600);
  pinMode(RPWM_Output, OUTPUT);
  pinMode(LPWM_Output, OUTPUT);
  
}
 
void loop()
{
    int pwm = readSerialValue();

    if( pwm != -1){

       if( pwm > 255) pwm = 255;
       else if( pwm < -1) pwm = 0;

       motorPWM = pwm;
    }
     analogWrite(LPWM_Output, 0);
     analogWrite(RPWM_Output, motorPWM);
 
    // forward rotation
   
    // analogWrite(RPWM_Output, 0);
    // analogWrite(LPWM_Output, motorPWM);

}

int readSerialValue()
{
     int v= -1;
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("String: ");
      Serial.println(inString);
      v = inString.toInt();
      Serial.print("Value:");
      Serial.println(v);
      
           
      // clear the string for new input:
      inString = "";
    }
  }
   return v;
}
