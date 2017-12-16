#ifndef SENSORUMIDADESOLO_H
#define SENSORUMIDADESOLO_H

#include <Arduino.h>
#include <stdint.h>

#define UMID_SENS_VCC D8
#define UMID_SENS_PWM A0

class SensorUmidadeSolo
{
	public:
		SensorUmidadeSolo(int lacos, int intervalo);
		uint16_t obterMedicao(void);

	private:
		uint8_t lacos;
		uint16_t intervalo;
};

#endif