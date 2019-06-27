#include "Sensor.h"

Sensor::Sensor(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia)
{
      	this->pinoEntrada = pinoEntrada;
      	this->limiar = limiar;
      	this->frequencia = frequencia;
      	limiarAlcancado = false;
      	pinMode(this->pinoEntrada, INPUT);
}

uint8_t
Sensor::getPinoEntrada()
{
        return (pinoEntrada);
}

uint16_t
Sensor::getLimiar()
{
        return (limiar);
}

uint16_t
Sensor::getFrequencia()
{
        return (frequencia);
}

bool
Sensor::alcancouLimiar(void)
{
        return (limiarAlcancado);
}
