

int Motor1_A  = 13;
int Motor1_B  = 12;
int Motor2_A  = 11;
int Motor2_B  = 10;
int Motor3_A  = 9;
int Motor3_B  = 8;
int Motor4_A  = 7;
int Motor4_B  = 6;

int EntradaA  = 5;
int EntradaB  = 4;

void Adelante();
void Atras();
void Stop();

void setup()
{
  pinMode(Motor1_A,OUTPUT);
  pinMode(Motor1_B,OUTPUT);
  pinMode(Motor2_A,OUTPUT);
  pinMode(Motor2_B,OUTPUT);
  pinMode(Motor3_A,OUTPUT);
  pinMode(Motor3_B,OUTPUT);
  pinMode(Motor4_A,OUTPUT);
  pinMode(Motor4_B,OUTPUT);
  pinMode(EntradaA,INPUT);
  pinMode(EntradaB,INPUT);
  
}

void loop()
{ 
  if      (digitalRead(EntradaA) == 0 && digitalRead(EntradaB) == 1) Adelante();
  else if (digitalRead(EntradaA) == 1 && digitalRead(EntradaB) == 0) Atras();
  else    Stop();
}

void Adelante()
{
  digitalWrite(Motor1_A,HIGH);
  digitalWrite(Motor1_B,LOW);
  digitalWrite(Motor2_A,HIGH);
  digitalWrite(Motor2_B,LOW);
  digitalWrite(Motor3_A,HIGH);
  digitalWrite(Motor3_B,LOW);
  digitalWrite(Motor4_A,HIGH);
  digitalWrite(Motor4_B,LOW);
}

void Atras()
{
  digitalWrite(Motor1_A,LOW);
  digitalWrite(Motor1_B,HIGH);
  digitalWrite(Motor2_A,LOW);
  digitalWrite(Motor2_B,HIGH);
  digitalWrite(Motor3_A,LOW);
  digitalWrite(Motor3_B,HIGH);
  digitalWrite(Motor4_A,LOW);
  digitalWrite(Motor4_B,HIGH);
}
void Stop()
{
  digitalWrite(Motor1_A,LOW);
  digitalWrite(Motor1_B,LOW);
  digitalWrite(Motor2_A,LOW);
  digitalWrite(Motor2_B,LOW);
  digitalWrite(Motor3_A,LOW);
  digitalWrite(Motor3_B,LOW);
  digitalWrite(Motor4_A,LOW);
  digitalWrite(Motor4_B,LOW);
}

