/*
 * Project iot2_2
 * Description:
 * Author:
 * Date:
 */

int tempPIN = A0;
double tempC = 0.0;
int mode;

void setup() {
  pinMode(tempPIN,INPUT);
  Serial.begin(9600);
  Particle.variable("temp", tempC);
  Particle.function("cF_setMode", setModeFromString);
}

void loop() {
  int ADCreading = analogRead(tempPIN);
  tempC = (ADCreading - 620) * 0.0806;
  Serial.print(ADCreading);
  Serial.print(", ");
   Serial.print(tempC);
  Serial.println(" degC");
  //Serial.printf("%4d, %6.3f degC\n",ADCreading,tempC);
  delay(500);
}

int setModeFromString(String inputString) {
  //guhgfujhvkg
  return 0;
}