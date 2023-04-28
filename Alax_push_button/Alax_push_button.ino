int led_state = 0;
int state = 0;
#define branco A2
#define amarelo A1

void setup() {
  // put your setup code here, to run once:
  pinMode(branco, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  int button = digitalRead(A0);
  switch(state){
     case 0:
      if(!button){
        state = 1;
        digitalWrite(branco, HIGH);
        digitalWrite(amarelo, LOW);
        delay(100);
      }      
      break;
    case 1:
      if(button){
        state = 2;
        delay(100);
      }
      break;
    case 2:
      if(!button){
        state = 3;
        digitalWrite(branco, LOW);
        digitalWrite(amarelo, HIGH);
        delay(100);
      }      
      break;
    case 3:
      if(button){
        state = 4;
        delay(100);
      }
      break;
    case 4:
      if(!button){
        state = 5;
        digitalWrite(branco, LOW);
        digitalWrite(amarelo, LOW);
        delay(100);
      }      
      break;
    case 5:
      if(button){
        state = 6;
        delay(100);
      }
      break;
    case 6:
      if(!button){
        state = 7;
        digitalWrite(branco, HIGH);
        digitalWrite(amarelo, HIGH);
        delay(100);
      }      
      break;
    case 7:
      if(button){
        state = 8;
        delay(100);
      }
      break;
    case 8:
       if(!button){
        state = 9;
        digitalWrite(branco, LOW);
        digitalWrite(amarelo, LOW);
        delay(100);
      }      
      break;
    case 9:
      if(button){
        state = 0;
        delay(100);
      }
      break;
  }
}
