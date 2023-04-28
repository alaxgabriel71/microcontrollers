#define POT A5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(POT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(POT));
  Serial.print(" - ");
  Serial.println(map(analogRead(POT),0,1023,0,255));
  delay(100);
}
