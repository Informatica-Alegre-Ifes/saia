#include "SensorUmidadeSolo.h"

SensorUmidadeSolo::SensorUmidadeSolo(int lacos, int intervalo)
{
	this->lacos = lacos;
	this->intervalo = intervalo;
}

float
SensorUmidadeSolo::obterMedicao(void)
{
	float soma;
	int i;

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