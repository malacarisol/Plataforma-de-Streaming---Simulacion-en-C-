#include <iostream>
#include <stdlib.h>
#include <string>
#include "cService.h"
#include <vector>

using namespace std;

enum eTipoUsuario { free, basic, premium };

class cUsuario
{
private:
	int edad;
	string usuario;
	string hashpassword;
	bool conectado;
	vector<string> favoritos;
	const string pais;
	const string apellido;
	const string nombre;
	vector<string> descargas;
	bool anuncios;
	int cuota;
	int  tiempoLimite;
	eTipoUsuario tipo;
public:
	cUsuario(int edad, string usuario, string hashpassword, bool conectado, string pais, string apellido, string nombre, eTipoUsuario tipo);
	~cUsuario();
	void Play(cService serv);
	bool AgregarFavoritos();
	void setCuota(int c);
	void offline();
	void online();
	string getUsername();
	string getPassword();
	eTipoUsuario getTipo();
	string getPais()const { return pais; }
	void anuncios() {
		if(anuncios!=true)
		anuncios = true;
	};

};
