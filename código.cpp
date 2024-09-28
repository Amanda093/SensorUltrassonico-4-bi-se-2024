// C++ code
//

const int trig = 5;
const int echo = 6;

int led_vermelho = 4;
int led_amarelo = 3;
int led_verde = 2;
int buzzer = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(6);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  ligaLed();
}

void ligaLed(){
 int duracao = pulseIn(echo, HIGH);
 int distanciaCM = (duracao/2) / 29.1;
 Serial.println(distanciaCM);
 
 // led verde
 if (distanciaCM >= 40 and distanciaCM <= 50)
   ligaLedBuzzer(led_verde);
 else
   digitalWrite(led_verde, LOW);
  
 // led amarelo
 if (distanciaCM >= 30 and distanciaCM <= 39)
    ligaLedBuzzer(led_amarelo);
 else
    digitalWrite(led_amarelo, LOW);
 
 // led vermelho 
 if (distanciaCM >= 20 and distanciaCM <= 29)
   ligaLedBuzzer(led_vermelho);
 else
   digitalWrite(led_vermelho, LOW);
  
  delay(500);
}

// liga e desliga a led e o buzzer
void ligaLedBuzzer(int led){
  digitalWrite(led, HIGH);
  tone(buzzer, 500);
  delay(750);
  noTone(buzzer);
}
