int const REVERSEL = 12;
int const FORWARDL = 11;
int const ENABLEL = 10;
int const ENABLER = 9;
int const REVERSER = 8;
int const FORWARDR = 7;

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
  Serial.print("Left Counter ");
  Serial.println(leftcounter); //This is Printing then a new line after
  
  Serial.print("Right Counter ");
  Serial.println(rightcounter);
  
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
  
 FWD();
}

void FWD()
{
  digitalWrite(ENABLEL, HIGH);
  digitalWrite(ENABLER, HIGH);
  digitalWrite(FORWARDL, HIGH);
  digitalWrite(FORWARDR, HIGH);
  
}

void REV()
{
  digitalWrite(ENABLEL, HIGH);
  digitalWrite(ENABLER, HIGH);
  digitalWrite(REVERSEL, HIGH);
  digitalWrite(REVERSER, HIGH);
}

void STOP()
{
  digitalWrite(ENABLEL, LOW);
  digitalWrite(ENABLER, LOW);
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
