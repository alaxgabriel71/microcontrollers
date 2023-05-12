int C = 264;
int D = 297;
int E = 330;
int F = 352;
int G = 396;
int A = 440;
int B = 495;
int note = 0;

int buzzer = 3;

char music_1[] = "CCGGAAGFFEEDDC ";
int beats_1[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<15;i++){
    int note = music_1[i];
    switch(music_1[i]) {
      case 'C':
        note = C;
        break;
      case 'D':
        note = D;
        break;
      case 'E':
        note = E;
        break;
      case 'F':
        note = F;
        break;
      case 'G':
        note = G;
        break;
      case 'A':
        note = A;
        break;
      case 'B':
        note = B;
        break;
      case ' ':
        note = 0;
        break;
    }
    int duration = beats_1[i];
    Serial.println(note);
    tone(buzzer, note, duration*500);
    delay(600);
  }
}
