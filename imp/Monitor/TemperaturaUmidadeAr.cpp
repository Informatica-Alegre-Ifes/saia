#include "TemperaturaUmidadeAr.h"

TemperaturaUmidadeAr::TemperaturaUmidadeAr(uint8_t pinoEntrada, uint16_t limiar, uint16_t frequencia) : Sensor(pinoEntrada, limiar, frequencia)
{
        valorUmidade = valorTemperatura = 0;
        dht.setup(4, DHTesp::DHT11);
}

void
TemperaturaUmidadeAr::realizarMedicao(void)
{
        if (deveExecutar()) {
                setIntervalo(dht.getMinimumSamplingPeriod());
                executar();
                limiarAlcancado = valorUmidade >= getLimiar() && valorTemperatura >= getLimiar() ? true : false;
        }
}

void
TemperaturaUmidadeAr::executar(void)
{
        float valorUmidade = dht.getHumidity();
        float valorTemperatura = dht.getTemperature();
        executado();
}
