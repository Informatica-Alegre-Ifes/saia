#include "recursos/Rede.h"
#include "recursos/SensorUmidadeSolo.h"

#define INTERVALO_LOOP 60000

Rede rede("nucleo", "nucleo#123.");
SensorUmidadeSolo sensorUmidadeSolo(5, 500);

char *endereco = "172.16.177.239";
int porta = 80;
char *arquivo = "cadastroumidade.php";

void setup()
{
	Serial.begin(9600);
	rede.desconectar();
}

void loop()
{
	if (rede.conectar())
		rede.enviarDados(endereco, porta, arquivo, sensorUmidadeSolo.obterMedicao());
		
	delay(INTERVALO_LOOP);
}