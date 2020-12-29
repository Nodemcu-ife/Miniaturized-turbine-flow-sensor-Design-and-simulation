int motorPin = 9;
void setup(){
 pinMode(motorPin, OUTPUT);
}
void loop() {
 for(int motorValue = 0 ; motorValue <= 255; motorValue +=5){
 analogWrite(motorPin, motorValue);
 delay(30);
 }
 for(int motorValue = 255 ; motorValue >= 0; motorValue -=5){
 analogWrite(motorPin, motorValue);
 delay(30);
 }
}
