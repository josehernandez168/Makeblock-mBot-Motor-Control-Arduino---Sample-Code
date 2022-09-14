
//Motor driver
#define enA 5
#define enB 6
#define in1 7
#define in2 4

//Ultrasonic Sensor
#define trig_echo 12
long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}

void loop() {  
  if(getdistance()<30){
    rotateRight(255, 250);
  }
  else{
    moveForward(255);
  }
}

//Movement Functions
void forwardAssault (int velocity, int duration){
  accelerateForward();
  moveForward(velocity);
  delay(duration);
  //deAccelerate();
}
void reverseAssault (int velocity, int duration){
  accelerateReverse();
  moveReverse(velocity);
  delay(duration);
  //deAccelerate();
}
void rotateRight (int velocity, int duration){
  accelerateRight();
  moveRight(velocity);
  delay(duration);
  //deAccelerate();
}
void rotateLeft (int velocity, int duration){
  accelerateLeft();
  moveLeft(velocity);
  delay(duration);
  //deAccelerate();
}

//Core actuation functions
void moveReverse (int velocity){
  analogWrite(enA, velocity);
  analogWrite(enB, velocity);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void moveForward (int velocity){
  analogWrite(enA, velocity);
  analogWrite(enB, velocity);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void moveLeft (int velocity){
  analogWrite(enA, velocity);
  analogWrite(enB, velocity);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
}
void moveRight (int velocity){
  analogWrite(enA, velocity);
  analogWrite(enB, velocity);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void deAccelerate (){
  for (int i=0; i<100; i = i+2.5){
    analogWrite(enA, 255-i);
    analogWrite(enB, 255-i);
    delay(5);
  }
  delay(500);
}
void accelerateForward (){
  for (int i=0; i<100; i = i+2.5){
    analogWrite(enA, i);
    analogWrite(enB, i);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(5);
  }
}
void accelerateReverse (){
  for (int i=0; i<100; i = i+2.5){
    analogWrite(enA, i);
    analogWrite(enB, i);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(5);
  }
}
void accelerateRight (){
  for (int i=0; i<100; i = i+2.5){
    analogWrite(enA, i);
    analogWrite(enB, i);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    delay(5);
  }
}
void accelerateLeft (){
  for (int i=0; i<100; i = i+2.5){
    analogWrite(enA, i);
    analogWrite(enB, i);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(5);
  }
}
int getdistance(){
  pinMode(trig_echo, OUTPUT);
  // Clears the trigPin
  digitalWrite(trig_echo, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig_echo, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_echo, LOW);
  
  delayMicroseconds(1);
  pinMode(trig_echo, INPUT);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(trig_echo, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance_1: ");
  Serial.println(distance);

  return distance;
}
