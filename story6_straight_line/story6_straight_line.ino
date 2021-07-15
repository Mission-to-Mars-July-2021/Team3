int const REVERSEL = 12;
int const FORWARDL = 11;
int const ENABLEL = 10;
int const ENABLER = 9;
int const REVERSER = 8;
int const FORWARDR = 7;

int basespeedL = 150;
int basespeedR = 150;
int CorrectionL = 250;
int CorrectionR = 250;

const int LEFT_FEEDBACK = 3; //Pin numbers on Rover
const int RIGHT_FEEDBACK = 2;

volatile int leftcounter = 0; //initiate counter to zero for start
volatile int rightcounter = 0; //counter could always be reset

void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  pinMode(REVERSEL, OUTPUT);
  pinMode(FORWARDL, OUTPUT);
  pinMode(ENABLEL, OUTPUT);
  pinMode(ENABLER, OUTPUT);
  pinMode(REVERSER, OUTPUT);
  pinMode(FORWARDR, OUTPUT);
}

void loop()
{
  Serial.println(millis());
  if(millis() > 10000){
    STOP();
        delay(500);
        exit(0);
    }

  Serial.print("Left Counter ");
  Serial.println(leftcounter); //This is Printing then a new line after
  
  Serial.print("Right Counter ");
  Serial.println(rightcounter);
    
 
  
  if(leftcounter < rightcounter){ //GO LEFT
    FWD2(250,150);
  }
  
  else if(rightcounter < leftcounter){ //GO RIGHT
    FWD2(150,250);
  }
      
  else { // straight line
    FWD2(150, 150);
  }
}

void FWD2(int basespeedL, int basespeedR) //The new Forward because the other one goes in a zigzag
{
 
  analogWrite(ENABLEL, basespeedL); //motor runs at 150
  analogWrite(ENABLER, basespeedR);
  digitalWrite(FORWARDL, HIGH);
  digitalWrite(REVERSEL, LOW);
  digitalWrite(FORWARDR, HIGH);
  digitalWrite(REVERSER, LOW);
}

void FWD()
{
  int speedLeft = 200;
  int speedRight = 200;
  
  if(speedLeft < 250){
    speedLeft = speedLeft + 20;
    analogWrite(ENABLEL, speedLeft); //motor runs at 220
  digitalWrite(FORWARDL, HIGH);
  digitalWrite(REVERSEL, LOW);
    delay(1000);
    speedLeft = 50;
  analogWrite(ENABLEL, speedLeft); //motor runs at 220
  }
    
  if(speedRight < 250){
    speedRight = speedRight + 20;
    analogWrite(ENABLER, speedRight); //motor runs at 220
  digitalWrite(FORWARDR, HIGH);
  digitalWrite(REVERSER, LOW);
    delay(1000);
    speedRight = 50;
  analogWrite(ENABLER, speedRight); //motor runs at 220
}
}

void check2m(){
 if(leftcounter >= 870){
    Serial.println("Rover has Reached Goal on Track L");
    STOP();
    delay(1000);
    exit(0);
  }
   if(rightcounter >= 870){
    Serial.println("Rover has Reached Goal on Track R");
    STOP();
    delay(1000);
    exit(0);
  }  
}


void REV()
{
  analogWrite(ENABLEL, 0);
  analogWrite(ENABLER, 0);
  digitalWrite(REVERSEL, HIGH);
  digitalWrite(REVERSER, HIGH);
}

void STOP()
{
  analogWrite(ENABLEL, 0);
  analogWrite(ENABLER, 0);
  digitalWrite(FORWARDL, LOW);
  digitalWrite(FORWARDR, LOW);
  digitalWrite(REVERSEL, LOW);
  digitalWrite(REVERSER, LOW);
}

void LeftMotorISR(){
  leftcounter++;
}

void RightMotorISR(){
  rightcounter++;
}
