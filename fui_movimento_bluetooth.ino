int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int pwm1 = 5;
int pwm2 = 10;

byte command = 'P';


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    byte c = Serial.read();
    switch (c) {
      case 'W':
        frente();
        break;

      case 'S':
        tras();
        break;

      case 'A':
        mvd();
        mvet();
        break;

      case 'D':
        mve();
        mvdt();
        break;


      case 'P':
        parar();
        break;

      default:
        break;
    }
  }

}
void frente(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(pwm2, 150);
}
void tras(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm1, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, 150);
}
void parar(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(pwm1, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, 0);
}

void mvd(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(pwm2, 150);
}
void mvdt(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(pwm2, 150);
}
void mve(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm1, 150);
}
void mvet(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm1, 150);
}
