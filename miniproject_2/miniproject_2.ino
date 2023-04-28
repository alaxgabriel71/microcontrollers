int off_set = 0;
#define btn A0
#define led 6
#define pot A5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = digitalRead(btn);
  int value = map(analogRead(pot), 0,1023,0,255);
  if(value - off_set < 0){
    analogWrite(led, 0);
  } else {
    analogWrite(led, value - off_set);
    Serial.println(value); 
  }

  if(!button){
    off_set = value;
    analogWrite(led, 255);
    delay(1000);
  }
}
