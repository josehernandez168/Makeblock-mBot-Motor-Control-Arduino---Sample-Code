
//Motor driver
#define enA 5
#define enB 6
#define in1 7
#define in2 4


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
    
    forwardAssault(255, 1000);
    rotateRight(255, 500);
    forwardAssault(255, 1000);
    rotateRight(255, 500);
    forwardAssault(255, 1000);
    rotateRight(255, 500);
    forwardAssault(255, 1000);
    rotateRight(255, 500);
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
