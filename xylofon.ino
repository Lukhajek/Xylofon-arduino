// Konstanty pro délku sepnutí každé klávesy
int delays[8] = {40, 50, 60, 60, 50 ,50, 50, 40};

// int tones[] = {číslo tónu, délka pauzy, ...}
// Čísla tónů:
// 0 - C1
// 1 - D1
// 2 - E1
// 3 - F1
// 4 - G1
// 5 - A1
// 6 - H1
// 7 - C2
// 11 - zvonek

// Happy Birthday
//int tones[] = {0,75,0,25,1,100,0,100,3,100,2,200,0,75,0,25,1,100,0,100,4,100,3,200,0,75,0,25,7,100,5,100,3,100,2,100,1,100,6,75,6,25,5,200,3,200,4,100,3,200};

// Vysoký jalovec
int tones[] = {7,50,7,50,6,100,5,100,4,100,2,400,7,50,7,50,6,100,5,100,4,100,6,400,6,50,6,50,6,100,6,100,7,100,6,400,7,50,7,50,6,100,5,100,4,100,2,400,7,50,7,50,6,100,5,100,4,100,2,400,7,50,7,50,6,100,5,100,4,100,6,400,6,50,6,50,6,100,6,100,7,100,5,400,7,50,7,50,6,100,5,100,6,100,7,400};


int ctone = 0;

void setup() {
  for(int i =2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200);
   pinMode(10, OUTPUT);
}

void loop() {

  int currentTone = tones[ctone * 2];
  int currentDelay = tones[ctone * 2 + 1];

  if(currentTone == 11) {
    digitalWrite(10, HIGH);
    delay(50); 
    digitalWrite(10, LOW);
    delay(currentDelay * 4);
  } else {
    digitalWrite(currentTone + 2, HIGH);
    delay(delays[currentTone]); 
    digitalWrite(currentTone + 2, LOW);
    delay(currentDelay * 4);
  }

  
  

  if((ctone * 2 + 2) == (sizeof(tones) / sizeof(int))){
    ctone = 0;
  }else
    ctone++;
  
}
