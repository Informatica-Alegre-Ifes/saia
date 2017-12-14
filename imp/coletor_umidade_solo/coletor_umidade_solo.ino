#include "recursos/Rede.h"
#include "recursos/SensorUmidadeSolo.h"

#define INTERVALO_LOOP 60000

Rede rede("CAYO", "XXX");
SensorUmidadeSolo sensorUmidadeSolo(5, 500);

char *endereco = "192.168.0.104";
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