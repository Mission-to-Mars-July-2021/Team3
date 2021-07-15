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
int TurnL = 0;
int TurnR = 255;
int squareloop = 0;

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
  if(millis() > 1000){
    
    }

  Serial.print("Left Counter ");
  Serial.println(leftcounter); //This is Printing then a new line after
  
  Serial.print("Right Counter ");
  Serial.println(rightcounter);
    
  FWD3(0, 255);
}

void FWD3(int TurnL, int TurnR)//square driving
{
  while(squareloop !=4)
  {
  FWD2(200,200);
  delay(2000);
  STOP();
  delay(1000); //Time Driving
  analogWrite(ENABLEL, TurnL);
  analogWrite(ENABLER, TurnR);
  digitalWrite(FORWARDL, HIGH);
  digitalWrite(REVERSEL, LOW);
  digitalWrite(FORWARDR, HIGH);
  digitalWrite(REVERSER, LOW);
  delay(1250); //TIME FOR TURNING
  squareloop++;
  }
 delay(2000);
  STOP();
  exit(0);
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
