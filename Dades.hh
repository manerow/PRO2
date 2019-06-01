/** @file Dades.hh
    @brief Especificació de la clase Dades. 
*/
#ifndef CLASS_Dades_HH
#define  CLASS_Dades_HH
#include <string>
#include <iostream>
#include <list>

/** @class Dades.
    @brief Utilitzarem aquesta clase per saber si estem treballant en les dades correctes.
*/

using namespace std;

class Dades {

private:
	private:
	bool definit;
	bool llista;
	bool integer;
	string dada;

public:
	
	/**
	 @brief Creadora per defecte.
	\pre <em>Cert</em>
	\post Crea una dada de tipus Dada.
	*/
	Dades();
	
	/** 
	 @brief Creadora d'un element de tipus dades amb valor = "ent".
	 \pre El valor dades a crear ha de ser de tipus boolea, llista o enter.
	 \post  S'ha creat un element de tipus dades amb valor = "ent".
	*/
	Dades (string ent);
	
	~Dades();
	
	/**
	 @brief Ens diu si el parametre implícit te un valor definit.
	\pre El P.I es un element de tipus Dades.
	\post Retorna cert si el p.i. te un valor definit o fals altrament.
	*/
	bool es_definit();

	/**
	 @brief Ens diu si el p.i. és de tipus list.
	\pre El P.I es un element de tipus Dades.
	\post Retorna cert si el p.i. és de tipus list o fals altrament.
	*/
	bool es_llista();
	
	/** 
	 @brief Ens diu si el p.i es de tipus enter.
	 \pre El P.I es un element de tipus Dades.
	 \post Retorna cert si el p.i. és de tipus enter o fals altrament.
	*/
	bool es_int();
	
	/** 
	 @brief Consultor del valor en format string d'un element de tipus Dades.
	 \pre L'element de tipus Dades és definit.
	 \post Ha retornat un string amb valor igual al valor de l'element que hem consultat.
	*/
	string consultar_str();
	
	/** 
	 @brief Escriu un element de tipus dades per el canal estàndard de sortida.
	 \pre <em>Cert</em>
	 \post  En cas que sigui definit, en el canal de sortida hi ha escrit un element de tipus int, bool o list. Altrament s'ha escrit "indefinit".
	*/
	void escriure();
	
	/** 
	 @brief Crea una llista buida amb valor definit.
	 \pre <em>Cert</em>
	 \post S'ha creat un element de tipus dades amb valor igual a llista buida "()".
	*/
	void crear_llista_buida();
	
	/** 
	 @brief Funcio que efectua la operació "+".
	 \pre Ambdós elements tenen valors definits i són de tipus enter.
	 \post El valor de l'element de tipus dades en el que efectuem la operació és el resultat de fer (+ d0 d1).
	*/
	void sumar(Dades d0, Dades d1);
		
	/** 
	 @brief Funcio que efectua la operació "-".
	 \pre L'element de tipus enter a tractar té un valor definit.
	 \post El valor de l'element de tipus dades en el que efectuem la operació és el resultat de fer "(- d0)".
	*/
	void invertir(Dades d0);
		
	/** 
	 @brief Funció que efectua la operació "=".
	 \pre Els elements tipus dades a tractar tenen un valor definit.
	 \post El valor de l'element de tipus dades en el que efectuem la operació es un boolea resultat de fer (= d0 d1).
	*/
	void igualar(Dades d0, Dades d1);
	
	/** 
	 @brief Funció que efectua la operació "cons".
	 \pre d0 es un element de tipus enter i d1 un element de tipus list ambdós amb valors definits.
	 \post El valor de l'element de tipus dades en el que efectuem la operacio es una llista resultat de fer (cons d0 d1).
	*/
	void construir(Dades d0, Dades d1);
	
	/** 
	 @brief Funció que efectua la operació "head".
	 \pre d0 es un element amb valor definit de tipus list.
	 \post El valor de l'element de tipus dades en el que efectuem la operacio és un enter resultat de fer (head d0).
	*/
	void cabezera(Dades d0);
	
	/** 
	 @brief Funció que efectua la operació "tail".
	 \pre d0 es un element amb valor definit de tipus llista i aquesta no és buida.
	 \post El valor de l'element de tipus dades en el que efectuem la operacio és una llista resultat de fer (tail d0).
	*/
	void cua(Dades d0);
	
	/** 
	 @brief Funció que efectua la operació "<".
	 \pre Ambdós elements, amb valors definits, a comparar son del mateix tipus.
	 \post El valor de l'element de tipus dades en el que efectuem la operació és un booleà resultat de fer (< d0 d1).
	*/
	void comparar(Dades d0, Dades d1);
	
	/** 
	 @brief Funció que efectua la operació "not".
	 \pre d0 es un element de tipus boolea.
	 \post El valor de l'element de tipus dades en el que efectuem la operació és un boolea resultat de fer (not d0).
	*/
	void negar(Dades d0);
	
	/** 
	 @brief Funció que efectua la operació "and".
	 \pre d0 i d1 són elements amb valors definits de tipus boolea.
	 \post El valor de l'element de tipus dades en el que efectuem la operació és un boolea resultat de fer (and d0 d1).
	*/
	void fer_and(Dades d0, Dades d1);
	
	/** 
	 @brief Funció que efectua la operació "or".
	 \pre d0 i d1 són elements amb valors definits de tipus boolea.
	 \post El valor de l'element de tipus dades en el que efectuem la operació és un boolea resultat de fer (or d0 d1).
	*/
	void fer_or(Dades d0, Dades d1);
	
	/** 
	 @brief Funció que efectua la operació "if".
	 \pre d1 és un element de tipus Dades amb valor definit.
	 \post  El valor de l'element de tipus dades en el que efectuem la operació és d1.
	*/
	void fer_if(Dades d1);
	
	/** 
	 @brief Funció que crea una llista amb valor definit.
	 \pre s1 és un string que conté una llista amb un valor definit.
	 \post El valor de l'element de tipus dades en el que efectuem la operació correspon al valor de la llista guardada en s1.
	*/
	void crear_list(const string s1);
	
	/** 
	 @brief Funció que converteix el paràmetre implicit en un element de tipus dades amb valor indefinit.
	 \pre <em>Cert</em>
	 \post El parametre implicit, de tipus Dades, te un valor indefinit.
	*/
	void indefinit();
	

};
#endif
