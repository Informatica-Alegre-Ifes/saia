#ifndef UMIDADESOLO_H
#define UMIDADESOLO_H

#include "Sensor.h"

class UmidadeSolo: public Sensor
{
public:
        UmidadeSolo(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia);
        
        void realizarMedicao(void);

private:
        uint16_t valorEntrada;
        void executar(void);
};

#endif
