/** @file Funcions.hh
    @brief Especificació de la clase Funcions 
*/
#ifndef CLASS_funcions_HH
#define  CLASS_funcions_HH

#include <list>
#include "Variables.hh"

/** @class Funcions.
    @brief Utilitzarem aquesta clase per emmagatzemar, operar i utilitzar funcions.
*/
using namespace std;

class Funcions {

private:
	struct fun {
		string par_f;
		string exp;
		int num;
	};
	map<string,fun> funcions;

public:

	/**
	 @brief Creadora per defecte. Crea un contenidor de funcions.
	 \pre <em>Cert</em>
	 \post S'ha creat un objecte Funció.
	*/
	Funcions();

	~Funcions();

	/**
	 @brief Consultora de funcions definides prèviament.
	 \pre <em>Cert</em>
	 \post Retorna cert si la funcio "nom" està definida o fals altrament.
	*/
	bool existeix_fun(const string& nom);
	
	/**
	 @brief	Afegeix una nova funció al conjunt de funcións no primitives.
	 \pre <em>Cert</em>
	 \post S'ha creat una funció amb nom = "nom", Parametres = "param" i executa l'expresió "exp" i nombre de parametres "num".
	*/
	void afegir_fun(const string& nom, const string& param, const string& exp, const int num);
	
	/**
	 @brief Consulta l'operacio que realitza una funcio i la passa en forma d'string.
	 \pre La funcio "nom" està definida.
	 \post Ha retornat l'operació a realitzar en forma d'string.
	*/
	const string consultar_fun(const string& nom);
	
	/** 
	 @brief Consulta els parametres que fa servir la funcio amb Nom = "nom".
	 \pre La funcio "nom" està definida
	 \post  Ha retornat els paràmetres de la funció en forma d'String.
	*/
	const string consultar_params(const string& nom);
	
	/** 
	 @brief Escriu totes les funcions no primitives que hem guardat en diccionari de la clase Funcions.
	 \pre Cert.
	 \post  S'han escrit per el canal estandard de sortida totes les funcions que hem introduït al programa.
	*/
	void escriure_funcions();
	
};
#endif
