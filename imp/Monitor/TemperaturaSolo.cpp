#include "TemperaturaSolo.h"

TemperaturaSolo::TemperaturaSolo(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia) : Sensor(pinoEntrada, limiar, frequencia)
{
        valorEntrada = 0;
        oneWire = new OneWire(pinoEntrada);
        sensores = new DallasTemperature(oneWire);
}

TemperaturaSolo::~TemperaturaSolo()
{
        delete oneWire;
        delete sensores;
}

void
TemperaturaSolo::medir(void)
{
        if (deveExecutar()) {
                setIntervalo(getFrequencia());
                executar();
                limiarAlcancado = valorEntrada >= getLimiar() ? true : false;
        }
}

void
TemperaturaSolo::executar(void)
{
        sensores->requestTemperatures();
        valorEntrada = sensores->getTempCByIndex(0);
        executado();
}
