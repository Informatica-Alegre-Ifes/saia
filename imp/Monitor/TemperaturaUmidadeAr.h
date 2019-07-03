#ifndef TEMPERATURAUMIDADEAR_H
#define TEMPERATURAUMIDADEAR_H

#include <DHTesp.h>
#include "Sensor.h"

class TemperaturaUmidadeAr: public Sensor
{
public:
        TemperaturaUmidadeAr(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia);
        
        void medir(void);

private:
        float valorUmidade;
        float valorTemperatura;
        DHTesp dht;
        
        void executar(void);
};

#endif
