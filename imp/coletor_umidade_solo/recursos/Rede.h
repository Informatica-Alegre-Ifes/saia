#ifndef REDE_H
#define REDE_H

#include <ESP8266WiFi.h>

class Rede
{
	public:
		Rede(char *nome, char *senha);
		bool conectar(void);
		bool enviarDados(char *endereco, int porta, char *arquivo, float dados);
		void desconectar(void);

	private:
		char *nome;
		char *senha;
		void criarConexao(void);
		bool estahConectado(void);
};

#endif