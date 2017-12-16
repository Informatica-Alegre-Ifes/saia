#ifndef SENSORUMIDADESOLO_H
#define SENSORUMIDADESOLO_H

#include <Arduino.h>

#define UMID_SENS_VCC D8
#define UMID_SENS_PWM A0

class SensorUmidadeSolo
{
	public:
		SensorUmidadeSolo(int lacos, int intervalo);
		int obterMedicao(void);

	private:
		int lacos;
		int intervalo;
};

#endif