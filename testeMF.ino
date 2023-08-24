#include <RGBsensor.h>
RGBsensor sensorL;
RGBsensor sM;
RGBsensor sensorR;
//A5 MEIO , A4 direito,A3 esquerdo

manyRGBsensors ldrsensors;

char colorL;
char colorM;
char colorR;
bool Lblack;
bool Mblack;
bool Rblack;

void setup() {
  Serial.begin(9600);

  sensorR.setHighTime(2);
  sensorR.setLowTime(0);
  sM.setHighTime(2);
  sM.setLowTime(0);
  sensorL.setHighTime(2);
  sensorL.setLowTime(0);

  sensorL.setLDRpin(A5);
  sM.setLDRpin(A3);
  sensorR.setLDRpin(A4);

  sensorL.setRGBpins(A2, A1, A0);  //8vermelho, 11verde e 13azul
  sM.setRGBpins(A2, A1, A0);
  sensorR.setRGBpins(A2, A1, A0);

  ldrsensors.addSensor(&sensorL);
  ldrsensors.addSensor(&sM);
  ldrsensors.addSensor(&sensorR);
  sensorR.setBlackPercentage(50);
  sM.setBlackPercentage(70);
  sensorL.setBlackPercentage(60);
  ldrsensors.setBlank();
  sM.setMinColorVariation(5);
}
void loop() {
  
  colorL = sensorL.getColor();
  colorM = sM.getColor();
  colorR = sensorR.getColor();
  
  ldrsensors.readColor();
  Lblack = sensorL.isBlack();
  Mblack = sM.isBlack();
  Rblack = sensorR.isBlack();

 // Serial.print(colorL);
 // Serial.println(" sensor esquerdo");
  //Serial.print(colorM);
 // Serial.println(" sensor meio");
 // Serial.print(colorR);
  //Serial.println(" sensor direito");
  
if(sM.isBlack()){
  Serial.println("is black");
}
 /*Serial.print("esquerdo");
  Serial.println(Lblack);
  Serial.print("meio");
  Serial.println(Mblack);
  Serial.print("direito");
  Serial.println(Rblack);
  */
}