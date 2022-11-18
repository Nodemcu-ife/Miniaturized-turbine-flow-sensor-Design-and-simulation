volatile byte revolutions; //this is the revolution counter
unsigned int rpm; //revolutions per minute
unsigned long timeold; //needed for the differantial time
float pi;  // pi constant function for mathematical expression

void setup() {
  
Serial.begin(9600);
attachInterrupt(0, rev_counter, RISING);

revolutions=0; 
rpm=0;
timeold=0;
pi = 3.142;

}

void loop() {
  if (revolutions >= 20) { //Calculates rpm after every 20 revs.

    rpm=(revolutions/20)/(((millis() - timeold)/60)/1000); //there are 20 holes on the encoder wheel
    timeold=millis();
    revolutions=0;
    
    Serial.print(rpm,DEC);
    Serial.print('\t');
    Serial.print(((rpm/60)*(2*pi))*0.0125*60);    //converting rpm to speed of the moving water in m/min
    Serial.print('\n');
    } 
}

void rev_counter() {
  
revolutions++;  
}
