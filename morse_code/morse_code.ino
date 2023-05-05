int led = 7;
int btn = 4;
int state = 0;
int u_start = 0;
int u_stop = 0;
int short_pulse = 100;
int long_pulse = 300;
int total_pulse = 0;
char vowel_buffer[100];
int index = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int button = digitalRead(btn);
  /*switch(state){
     case 0:
      u_start = 0;
      u_stop = 0;
      if(!button){
        state = 1;
        u_start = millis();
        delay(100);
      }      
      break;
    case 1:
      if(button){
        state = 2;
        u_stop = millis();
        total_pulse = u_stop - u_start - 100;
        if(total_pulse <= short_pulse){
          digitalWrite(led, HIGH);
          delay(short_pulse);
        } else if(total_pulse <= long_pulse) {
           digitalWrite(led, HIGH);
           delay(long_pulse);
        }       
      }
      break;
     case 2:
      digitalWrite(led, LOW);
      state = 0;
      break;
  }*/
  int button = digitalRead(btn);
  char letter;
  switch(state){
    case 0:
      letter = Serial.read();
      switch(letter){
        case 'a':
          //blink_A();
          //delay(1000);
          vowel_buffer[index] = letter;
          index++;
          break;
        case 'e':
          //blink_E();
          //delay(1000);
          vowel_buffer[index] = letter;
          index++;
          break;
        case 'i':
          //blink_I();
          //delay(1000);
          vowel_buffer[index] = letter;
          index++;
          break;
        case 'o':
          //blink_O();
          //delay(1000);
          vowel_buffer[index] = letter;
          index++;
          break;
        case 'u':
          //blink_U();
          //delay(1000);
          vowel_buffer[index] = letter;
          index++;
          break;
      }
      if(!button){
        state = 1;
        delay(100);
      }
      break;
    case 1:
      for(int i = 0; i < index; i++){
        switch(vowel_buffer[i]){
          case 'a':
            blink_A();
            delay(1000);
            break;
          case 'e':
            blink_E();
            delay(1000);
            break;
          case 'i':
            blink_I();
            delay(1000);
            break;
          case 'o':
            blink_O();
            delay(1000);
            break;
          case 'u':
            blink_U();
            delay(1000);
            break;
        }
      }
      index = 0;
      state = 2;
      delay(100);
      break;
    case 2:
      state = 0;
      delay(100);
  }
}

void long_blink(){
  digitalWrite(led, HIGH);
  delay(long_pulse);
  digitalWrite(led, LOW);
}

void short_blink(){
  digitalWrite(led, HIGH);
  delay(short_pulse);
  digitalWrite(led, LOW);
}
void blink_A() {
  long_blink();
  delay(short_pulse);
  short_blink();
}

void blink_E() {
  short_blink();
}

void blink_I() {
  short_blink();
  delay(short_pulse);
  short_blink();
}

void blink_O() {
  long_blink();
  delay(short_pulse);
  long_blink();
  delay(short_pulse);
  long_blink();
  delay(short_pulse);
}

void blink_U() {
  short_blink();
  delay(short_pulse);
  short_blink();
  delay(short_pulse);
  long_blink();
}
