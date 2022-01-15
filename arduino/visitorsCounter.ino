#include <Ultrasonic.h>


Ultrasonic ultrasonic1(12, 11);
Ultrasonic ultrasonic2(10, 9);


int firstSensor1, firstSensor2;
int sensor1, sensor2;
void setup() {
  Serial.begin(9600);
  firstSensor1 = ultrasonic1.read();
  firstSensor2 = ultrasonic2.read();
}

void loop() {
  sensor1 = ultrasonic1.read();
  sensor2 = ultrasonic2.read();
  if (firstSensor1 - sensor1 > 5 && firstSensor2 - sensor2 < 5 )
  {
    Serial.println(1);
    while (firstSensor1 - ultrasonic1.read() > 5) {
      delay(100);
    }
    delay(500);
  } else if (firstSensor2 - sensor2 > 5 && firstSensor1 - sensor1 < 5)
  {
    Serial.println(-1);
    while (firstSensor2 - ultrasonic2.read() > 5) {
      delay(100);
    }
    delay(500);
  } else {
    Serial.println(0);
    delay(500);
  }

  //  Serial.print(firstSensor1); Serial.print(" "); Serial.println(sensor1);
  //  Serial.print(firstSensor2); Serial.print(" "); Serial.println(sensor2);
  //  Serial.print(sensor1); Serial.print(" "); Serial.print(sensor2);

}
