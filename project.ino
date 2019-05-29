char data = 0;  //VARIABLE FOR STORING BLUETOOTH DATA
int directionA = 4, speedA = 5, directionB = 7, speedB = 6, Speed ; // SPEED AND DIRECTION PINS TO MOTOR A AND B
int LedV = 9, LedB = 10; // BLUE AND GREEN LED PINS
int pinBuzzer = 8; // BUZZER PIN
void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission 
    // CONFIGURATION OF BUILD&CODE 4IN1 PINS 
    pinMode ( directionA, OUTPUT);
    pinMode ( speedA, OUTPUT);
    pinMode ( directionB, OUTPUT);
    pinMode ( speedB, OUTPUT);
    pinMode (LedV, OUTPUT);
    pinMode (LedB, OUTPUT);
}
void loop()
{
   if(Serial.available() > 0)      // SEND DATA ONLY WHEN YOU RECEIVE DATA

   {
      data = Serial.read();        //READ THE INCOMING DATA AND STORE INTO DATA 

      // INTERPRETATION OF BLUETOOTH ENTRY DATA

      switch (data)
      {
        case 'F':   // FORWARD
        //MOTOR A
        analogWrite (speedA, Speed);
        digitalWrite ( directionA,LOW);

         //MOTOR B 
         analogWrite (speedB, Speed);
         digitalWrite ( directionB,HIGH);
         break;

         case 'B':  // BACK
         //MOTOR A
          analogWrite (speedA, Speed);
          digitalWrite ( directionA,HIGH);

          //MOTOR B
          analogWrite (speedB, Speed);
          digitalWrite ( directionB,LOW);
          break;

          case 'S':   // STOP
         //MOTOR A
          analogWrite (speedA, 0);
          digitalWrite ( directionA,LOW);

          //MOTOR B
          analogWrite (speedB, 0);
          digitalWrite ( directionB,HIGH);
          break;

          case 'L':   // LEFT
         //MOTOR A
          analogWrite (speedA, Speed);
          digitalWrite ( directionA,LOW);

     

          case 'R':   // RIGHT

          //MOTOR B
          analogWrite (speedB, Speed);
          digitalWrite ( directionB,HIGH);
          break;

          // CHANGE SPEED
          case '1':
          Speed = 25;
          break;

          case '2':
          Speed = 25*2;
          break;

          case '3':
          Speed = 25*3;
          break;

          case '4':
          Speed = 25*4;
          break;

          case '5':
          Speed = 25*5;
          break;

          case '6':
          Speed = 25*6;
          break;

          case '7':
          Speed = 25*7;
          break;

          case '8':
          Speed = 25*8;
          break;

          case '9':
          Speed = 25*9;
          break;

          case 'q':
          Speed = 255;
          break;

          // FORWARD LIGHT
          case'W':
          digitalWrite (LedV, HIGH);
          break;

          case'w':
          digitalWrite (LedV, LOW);
          break;

          // BACK LIGHT
          case'U':
          digitalWrite (LedB, HIGH);
          break;

          case'u':
          digitalWrite (LedB, LOW);
          break;

          // HORN
          case'V':
          tone(pinBuzzer,523.25,0);
          break;

          case'v':
          tone(pinBuzzer,0,100);
          break;       
      }
   }
}
