#include "SensorUmidadeSolo.h"

SensorUmidadeSolo::SensorUmidadeSolo(uint8_t lacos, uint16_t intervalo)
{
	this->lacos = lacos;
	this->intervalo = intervalo;
}

uint16_t
SensorUmidadeSolo::obterMedicao(void)
{
	uint16_t soma, i;

	digitalWrite(UMID_SENS_VCC, HIGH);
	delay(intervalo);
	for (soma = i = 0; i < lacos; i++)
	{
		soma += analogRead(UMID_SENS_PWM);
		delay(intervalo);
	}
	digitalWrite(UMID_SENS_VCC, LOW);

	return (soma / lacos);
}