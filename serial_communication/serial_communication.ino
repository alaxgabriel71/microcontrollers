int count = 0;
int state = 0;
#define led A4
#define amarelo A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  /*
  // shows on serial monitor the value off count on button press
  int button = digitalRead(A0);
  switch(state){
     case 0:
      if(!button){
        state = 1;
        delay(50);
      }      
      break;
    case 1:
      if(button){
        state = 0;
        count++;
        Serial.println(count);
        delay(50);
      }
  }*/

  // turns on/off a LED from a key press serial read
  if(Serial.available()>0){
      char incomingByte = Serial.read();
      switch(incomingByte){
          case 'a':
            digitalWrite(led, HIGH);
            break;
          case 'r':
            digitalWrite(led, LOW);
            break;
        }
      
    }
}
