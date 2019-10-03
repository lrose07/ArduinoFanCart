// simple motor control

int motorPin02=2, motorPin03=3; 
int tF = 4E3;     // time to leave forward motor on in ms (milliseconds)
int tC = 0;       // time to leave both motors off (coasting) in ms
int tR = 4E3;     // time to leave reverse motor on in ms
int wait = 2000E3;  // time between restarting the entire program in ms

void setup() {
  pinMode(motorPin02,OUTPUT);
  pinMode(motorPin03,OUTPUT);
  digitalWrite(motorPin02,LOW); // starts off
  digitalWrite(motorPin03,LOW); // starts off
}

void loop() {

  delay(1000);                     // how long to wait before firing first motor
      
  digitalWrite(motorPin02,HIGH);   // turn forward motor ON
  digitalWrite(motorPin03,LOW);
  delay(tF);                       // time to leave forward motor on

  digitalWrite(motorPin02,LOW);    // turn forward motor OFF
  digitalWrite(motorPin03,LOW); 
  delay(tC);                       // time to leave both motors off (coasting)

  digitalWrite(motorPin02,LOW);    // turn reverse motor ON
  digitalWrite(motorPin03,HIGH);
  delay(tR);                       // time to leave reverse motor on

  digitalWrite(motorPin02,LOW);    // turn reverse motor OFF
  digitalWrite(motorPin03,LOW); 
  delay(0);                        // time to leave motor off between directions

  delay(wait);                     // time between the restarting the for loop in ms
}
