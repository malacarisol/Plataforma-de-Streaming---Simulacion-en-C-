#include <iostream>
#include <stdlib.h>
#include <string>
#include "cService.h"
#include <vector>
#include <ctime>

using namespace std;

enum eTipoUsuario { free, basic, premium };

class cUsuario
{
private:
	int edad;
	string usuario;
	string hashpassword;
	bool conectado;

	const string pais;
	const string apellido;
	const string nombre;
	vector<string> descargas;
	bool anuncios;
	int cuota;
	time_t tiempoON;//registra la hora cuando ingresa a un servicio
	time_t tiempoOFF;//registra la hora cuando sale del mismo
	double difftime(time_t time2, time_t time1);
	int  tiempoLimite;
	eTipoUsuario tipo;
public:
	vector<string> favoritos;
	cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo);
	~cUsuario();
//void Play(cService *serv);
	bool AgregarFavoritos(cService *ser);
	void setCuota(int c);
	time_t offline();
	time_t online();
	string getUsername();
	
	string getPassword();
	eTipoUsuario getTipo();
	string getPais()const { return pais; };
	string getNombre() const { return nombre; };
	void getanuncios() {
		if(anuncios!=true)
		anuncios = true;
	};

};
