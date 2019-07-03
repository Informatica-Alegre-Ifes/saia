#include <vector>
#include "TemperaturaSolo.h"
#include "UmidadeSolo.h"
#include "TemperaturaUmidadeAr.h"
#include "Rede.h"

std::vector<std::shared_ptr<Sensor>> sensores;
Rede rede("DEPTINFO", "1984DEPTINFO");
bool dadosEnviados;

void setup()
{
        Serial.begin(115200);
        
        sensores.push_back(std::make_shared<TemperaturaSolo>(5, 300, 15000));
        sensores.push_back(std::make_shared<UmidadeSolo>(13, 300, 15000));
        sensores.push_back(std::make_shared<TemperaturaUmidadeAr>(10, 10, 15000));
}

void loop()
{
        for (std::vector<std::shared_ptr<Sensor>>::iterator sensor = sensores.begin(); sensor != sensores.end(); ++sensor)
                (*sensor)->medir();

        if (rede.conectar()) {
                rede.enviarDados("192.168.0.121", 8080, "cadastrodeteccao.jsp", 10);
                rede.desconectar();
        }
}
