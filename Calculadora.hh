/** @file Calculadora.hh
    @brief Especificación de la clase Calculadora.
*/
#ifndef CLASS_Calculadora_HH
#define  CLASS_Calculadora_HH

#include <iostream>
#include "Variables.hh"
#include "Funcions.hh"
#include <vector>
#include <algorithm>


/** @class Calculadora.
    @brief Utilitzarem aquesta clase per fer els processos relacionats amb
    l'execució de l'expresió introduïda i l'obtenció del resultat, tot a partir
    de la relacio d'aquesta clase amb la resta de clases.
*/

class Calculadora {

private:
	vector<string> extreu;
	bool acabat = true;
	bool es_atomica;
	
	
	static bool dos_espais(char l, char r);
	bool es_bool_valid(Dades d);
 
	string ext1(const string& entrada, int& pos);

	bool es_atom(string entrada);
	Dades operar(string ex, Variables &v, Funcions &f);
	
public:

	
	/** 
	 @brief Creadora per defecte.
	 \pre <em>Cert</em>
	 \post El resultat es un objecte calculadora.
	*/
	Calculadora();

	~Calculadora();
		
	/**
	 @brief	Executa l'expresió introduida i en dona el seu resultat.
	 \pre La entrada ha estat llegida completament.
	 \post Si l'entrada és correcta ha processat l'expressió, altrament l'expresió te valor indefinit.
	*/
	void calcular_expresio(Variables &v, Funcions &f,string entrada);
	
	/**
	 @brief	Posa els espais correctament a l'instruccio introduida.
	 \pre La entrada ha estat llegida completament.
	 \post L'instruccio llegida ha estat normalitzada.
	*/
	void normalitzar(string& entrada);
	
	/** 
	 @brief Consulta si hem acabat de fer servir la calculadora.
	 \pre <em>Cert</em>
	 \post Retorna cert si hem acabat o fals altrament. 
	*/
	bool fi();
	
	/**
	 @brief Llegeix i descifra l'expresió introduida al canal d'entrada
	 \pre Hi ha preparat al canal d'entrada una entrada = ENTRADA per a la calculadora
	      en una o diverses linies.
	 \post El parametre implicit passa a tenir els atributs llegits en el canal
		   estandard d'entrada.
	*/
	void llegir(string& i);

};
#endif
