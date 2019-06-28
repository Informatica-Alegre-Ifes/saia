#ifndef TEMPERATURASOLO_H
#define TEMPERATURASOLO_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "Sensor.h"

class TemperaturaSolo: public Sensor
{
public:
        TemperaturaSolo(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia);
        ~TemperaturaSolo();
        
        void realizarMedicao(void);

private:
        float valorEntrada;
        void executar(void);
        
        OneWire *oneWire;
        DallasTemperature *sensores;
};

#endif
