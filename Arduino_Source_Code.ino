/*
 * Pin definition
 * Pin 30 and 31 for left motor
 * Pin 32 and 33 for right motor
 * Pin 10 for PWM to control the motor speed  
 * LED pin is 13 to indicate system status
 */


#define CompressorOn 4
#define OutValve 5
#define HandOpenLED 6
#define HandHoldLED 7
#define HandCloseLED 8
#define RX 0
#define TX 1

/*
 * Variable definition
 */
char data;  //for bluetooth data

/*
 * Setup code
 * 
 */
void setup()
 {
  pinMode(CompressorOn, OUTPUT);
  pinMode(OutValve, OUTPUT);
  pinMode(HandCloseLED, OUTPUT);
  pinMode(HandHoldLED, OUTPUT);
  pinMode(HandOpenLED, OUTPUT);
  Serial.begin(38400);
  /*Serial.println("started");*/
}

void HandClose() 
 {
  digitalWrite(CompressorOn, HIGH);
  digitalWrite(OutValve, LOW);
  digitalWrite(HandCloseLED, HIGH);
  digitalWrite(HandHoldLED, LOW);
  digitalWrite(HandOpenLED, LOW);
 }
 

void HandHold() 
 {
  digitalWrite(CompressorOn, LOW);
  digitalWrite(OutValve, LOW);
  digitalWrite(HandCloseLED, LOW);
  digitalWrite(HandHoldLED, HIGH);
  digitalWrite(HandOpenLED, LOW);
 }

 void HandOpen() 
 {
  digitalWrite(CompressorOn, LOW);
  digitalWrite(OutValve,HIGH);
  digitalWrite(HandCloseLED, LOW);
  digitalWrite(HandHoldLED, LOW);
  digitalWrite(HandOpenLED, HIGH);
 }

 void AllOFF() 
 {
  digitalWrite(CompressorOn, LOW);
  digitalWrite(OutValve,LOW);
  digitalWrite(HandCloseLED, LOW);
  digitalWrite(HandHoldLED, LOW);
  digitalWrite(HandOpenLED, LOW);
 }
 

void loop()
{
  if (Serial.available() > 0)
  {
    data = Serial.read();  // Reads the character data from the serial port
    switch (data)
     {
      case '1':
       HandClose();
        break;
      case '2':
        HandHold();
        break;
      case '3':
        HandOpen();
        break;  
      case '4':
        AllOFF();
        break;      
      default:
        break;
    }
  }
}
