#define pot A0
int led = 6;
int period = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int duty_cycle = map(analogRead(pot),0,1023,0,100);
  digitalWrite(led, HIGH);
  delay(period*(duty_cycle/100.));
  digitalWrite(led, LOW);
  delay(period*((100 - duty_cycle)/100.));
}
