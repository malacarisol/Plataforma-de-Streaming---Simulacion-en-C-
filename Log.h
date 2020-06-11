#ifndef LOG_H
#define LOG_H

class Log
{
	string username;
	int tiempoUso;
	enum class tipoDeUsuario { free, basic, premium };
	enum class tipoServicio { juegos, peliculas, musica };
	enum class mes { enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre };
	enum class dia { lunes, martes, miercoles, jueves, viernes, sabado };

public:
	Log();
	~Log();
};

#endif