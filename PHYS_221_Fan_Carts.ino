// simple motor control

int motorPin02=2, motorPin03=3; 
int tF = 10E3;     // time to leave forward motor on in ms (milliseconds)
int tC = 0;       // time to leave both motors off (coasting) in ms
int tR = 4E3;     // time to leave reverse motor on in ms
int wait = 20E3;  // time between restarting the entire program in ms

// equation 1 \
x_f = x_i + v_i * t + 1/2 * a * t^2 <- speeding up, x_f == x_i in next eq \
  x_i = 0 \
  t = ? \
  a = need to find 0.1332 m/s^2 \
  v_i = 0

int xFin = 100;
double xFinHalf = xFin / 2;
double acc = 0.1322;
double tFrwd = sqrt((xFinHalf * acc)/2);

double velFinalHalf = acc * tFrwd;

// equation 2 \
x_f = x_i + v_i * t + 1/2 * a * t^2 <- slowing down \
  x_i = prev x_f \
  t = ? \
  a = need to find \
  v_i = derive from prev eq ... comes from v_f = v_i + a * t

//int tF = tFrwd * 1000;
//int tR = tF;

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
