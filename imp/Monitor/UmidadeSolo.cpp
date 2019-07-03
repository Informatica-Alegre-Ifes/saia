#include "UmidadeSolo.h"

UmidadeSolo::UmidadeSolo(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia) : Sensor(pinoEntrada, limiar, frequencia)
{
        valorEntrada = 0;
}

void
UmidadeSolo::medir(void)
{
        if (deveExecutar()) {
                setIntervalo(getFrequencia());
                executar();
                limiarAlcancado = valorEntrada >= getLimiar() ? true : false;
        }
}

void
UmidadeSolo::executar(void)
{
        valorEntrada = analogRead(getPinoEntrada());
        executado();
}
