int const REVERSEL = 12;
int const FORWARDL = 11;
int const ENABLEL = 10;
int const ENABLER = 9;
int const REVERSER = 8;
int const FORWARDR = 7;

void setup()
{
  pinMode(REVERSEL, OUTPUT);
  pinMode(FORWARDL, OUTPUT);
  pinMode(ENABLEL, OUTPUT);
  pinMode(ENABLER, OUTPUT);
  pinMode(REVERSER, OUTPUT);
  pinMode(FORWARDR, OUTPUT);
}



void loop()
{
  FWD();
  delay(5000);
  STOP();
  delay(1000);
  REV();
  delay(2000);
  STOP();
  delay(1000);
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
