/** @file Variables.hh
    @brief Especificació de la clase Variables 
*/
#ifndef CLASS_variables_HH
#define  CLASS_variables_HH

#include <string>
#include <map>
#include "Dades.hh"

/** @class Variables.
    @brief Utilitzarem aquesta clase per emmagatzemar i utilitzar variables.
*/

using namespace std;

class Variables {

private:
	map<string,Dades> var;
	
public:
	
	/**
	 @brief Creadora per defecte.
	 
		Crea un Contenidor de variables.
	 \pre <em>Cert</em>
	 \post El resultat es un objecte Variable.
	*/
	Variables();
	
	~Variables();
	
	/**
	 @brief	Consulta el valor d'una variable (en cas que existeixi).
	 \pre <em>Cert</em>
	 \post Si existeix la variable "nom" retorna el seu valor, si no, retorna "indefinit".
	*/
	const Dades consultar_var(const string nom);
	
	/**
	 @brief	Consulta l'existència d'una variable.
	 \pre <em>Cert</em>
	 \post Retorna cert si existeix la variable o fals altrament.
	*/
	bool existeix_var(const string nom);
	
	/**
	 @brief	Afegeix una nova variable al conjunt de variables.
	 \pre <em>Cert</em>
	 \post El resultat es una variable amb nom = "nom" i valor = "val".
	*/
	void afegir_var(const string nom, Dades val);
	
	/**
	 @brief	Escriu totes les variables per ordre lexicografic de nom.
	 \pre <em>Cert</em>
	 \post S'han imprimit totes les variables per el canal estandard de sortida.
	*/
	void escriure_variables();

};
#endif
