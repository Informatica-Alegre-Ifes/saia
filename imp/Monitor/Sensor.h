#ifndef SENSOR_H
#define SENSOR_H

#include "Thread.h"

class Sensor: public Thread
{
public:
        Sensor(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia);

        bool alcancouLimiar(void);
        virtual void realizarMedicao(void) = 0;

protected:
        bool limiarAlcancado;

        uint8_t getPinoEntrada(void);
        uint16_t getLimiar(void);
        uint16_t getFrequencia(void);

private:
        uint8_t pinoEntrada;
        uint16_t limiar;
        uint16_t frequencia;
};

#endif
