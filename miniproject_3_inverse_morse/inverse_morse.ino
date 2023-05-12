int state = 0;
int led = 6;
int btn = 4;
int u_init = 0;
int u_end = 1000*1000;
int u_start = 0;
int u_stop = 0;
int total_pulse = 0;
int short_pulse = 300;
int long_pulse = 1000;
int pulse_buffer[] = {0,0,0};
int index = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button = digitalRead(btn);
  u_init = millis();
 
    switch(state){
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
          u_stop = millis();
          state = 0;
          if(index>2) {
            index = 0;
          }
          total_pulse = u_stop - u_start - 100;
          //Serial.println(total_pulse);
          if(total_pulse <= short_pulse){
            //Serial.println("Short");
            shortPulse();
            pulse_buffer[index] = 1;
            index++;
          } else if(total_pulse <= long_pulse) {
             //Serial.println("Long");
             longPulse();
             pulse_buffer[index] = 2;
             index++;
          }       
        }
        //Serial.print(pulse_buffer[0]);
        //Serial.print(" ");
        //Serial.print(pulse_buffer[1]);
        //Serial.print(" ");
        //Serial.println(pulse_buffer[2]);
        if(pulse_buffer[0] == 2 && pulse_buffer[1] == 2 && pulse_buffer[2] == 2) {
           Serial.println('O');
           clearBuffer();
        }
        if(pulse_buffer[0] == 1 && pulse_buffer[1] == 2 && pulse_buffer[2] == 1) {
           Serial.println('R');
           clearBuffer();
        }
        if(pulse_buffer[0] == 1 && pulse_buffer[1] == 1 && pulse_buffer[2] == 1) {
           Serial.println('S');
           clearBuffer();
        }
        if(pulse_buffer[0] == 1 && pulse_buffer[1] == 1 && pulse_buffer[2] == 2) {
           Serial.println('U');
           clearBuffer();
        }
        delay(100);
        break;
  }
}

void shortPulse() {
  digitalWrite(led, HIGH);
  delay(short_pulse);
  digitalWrite(led, LOW);
}

void longPulse() {
  digitalWrite(led, HIGH);
  delay(long_pulse);
  digitalWrite(led, LOW);
}

void clearBuffer() {
  pulse_buffer[0] = 0;
        pulse_buffer[1] = 0;
        pulse_buffer[2] = 0;
}
