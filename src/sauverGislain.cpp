#include <Arduino.h>

int digitalPin = D4; // pour le relais
int analogPin = A0; // pour le capteur de l'humidité du sol
int digitalVal; // digital readings
int analogVal; //analog readings

void setup()
{
    Serial.begin(115200);
    pinMode(digitalPin, OUTPUT);
    digitalWrite(digitalPin, HIGH);
}

// uint8_t pinState = LOW;
void loop()
{
    analogVal = analogRead(analogPin);//lire la valeur retournée par le capteur de l'humidité
    Serial.println(analogVal);

    if (analogVal<500){//si la capteur de l'humidité retourne une valeur<500
        // Serial.print('test', analogVal);
        digitalWrite(digitalPin, LOW);//La pompe à eau arrose la plante
    } else { // sinon
        // Serial.print('arrose pas frère');
        digitalWrite(digitalPin, HIGH);//La //La pompe à eau arrête l'arrosage
    }

    delay(100);
}