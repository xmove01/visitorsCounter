// Подключаем библиотеку для работы с ультразуковыми датчиками
#include <Ultrasonic.h>

// Инициализируем датчики
Ultrasonic ultrasonic1(12, 11);
Ultrasonic ultrasonic2(10, 9);

// Переменные для хранения значений датчиков
int firstSensor1, firstSensor2;
int sensor1, sensor2;
void setup() {
  Serial.begin(9600);
  // Получаем значения датчиков первого запуска
  firstSensor1 = ultrasonic1.read();
  firstSensor2 = ultrasonic2.read();
}

// Проходит циклично
void loop() {
  // Каждый круг получаем новые значения датчиков
  sensor1 = ultrasonic1.read();
  sensor2 = ultrasonic2.read();
  // Если пересекли первый датчик, а второй нет(Зашли в помещение) то
  if (firstSensor1 - sensor1 > 5 && firstSensor2 - sensor2 < 5 )
  {
    // Отправляем единицу
    Serial.println(1);
    // Ждём когда значение датчика вернется в исходное положение
    while (firstSensor1 - ultrasonic1.read() > 5) {
      delay(100);
    }
    delay(500);
    // Если пересекли второй датчик, а первый нет(Вышли из помещения)
  } else if (firstSensor2 - sensor2 > 5 && firstSensor1 - sensor1 < 5)
  {
    // Отправляем -1
    Serial.println(-1);
    // Ждём когда значение датчика вернется в исходное положение
    while (firstSensor2 - ultrasonic2.read() > 5) {
      delay(100);
    }
    delay(500);
    // Если значения датчиков в исходном положении(Нет "движения")
  } else {
    // Отправляем 0(для сброса стиля датчиков на фронте)
    Serial.println(0);
    delay(500);
  }
// Код для отладки
  //  Serial.print(firstSensor1); Serial.print(" "); Serial.println(sensor1);
  //  Serial.print(firstSensor2); Serial.print(" "); Serial.println(sensor2);
  //  Serial.print(sensor1); Serial.print(" "); Serial.print(sensor2);
}
