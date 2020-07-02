#include <iostream>
#include <stdlib.h>
#include <string>
#include "cService.h"
#include <vector>
#include <ctime>

using namespace std;

typedef enum { free, basic, premium }eTipoUsuario;

class cUsuario
{
	friend class cService;
private:
	
	int edad;
	string usuario;
	string hashpassword;
	bool conectado;

	const string pais;
	const string apellido;
	const string nombre;

	bool anuncios;
	int cuota;
	time_t tiempoON;//registra la hora cuando ingresa a un servicio
	time_t tiempoOFF;//registra la hora cuando sale del mismo
	double difftime(time_t time2, time_t time1);
	int  tiempoLimite;
	eTipoUsuario tipo;
	vector<string> descargas;
	vector<string> favoritos;
public:
	
	cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo);
	~cUsuario();
//void Play(cService *serv);
	
	void setCuota(int c);
	time_t offline();
	time_t online();
	
	string getPassword();
	eTipoUsuario getTipo();
	//friend void cService::Descargar(cUsuario* user1, string nombre);
	//friend void c
	string getPais()const { return pais; };
	string getUsername()const { return usuario; }; //Para acceder al nombre de usuario desde Streaming y asi checkear password
	string getNombre() const { return nombre; };
	void getanuncios() {
		if(anuncios!=true)
		anuncios = true;
	};	

	vector<string> getVectorFavoritos() { return favoritos; };
	vector<string> getVectorDescargas() { return descargas; };

};
