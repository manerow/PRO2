/** 
	@mainpage Practica PRO2 Tardor 2016.
	
	L'objectiu d'aquesta pràctica es construir una calculadora d'expresions en "Lisp" completament funcional, per fer-ho ens basarem en 4 clases
	i un fitxer main anomenat "program.cc".
	
	@file main.cc
	
    @brief Fitxer main del programa. El main s'encarrega d'anar executant la funció
		"llegir" per tal d'anar llegint el canal d'entrada i posteriorment procedeix a
		calcular el valor de la expresió llegida mitjançant la expressió "calcular_expresio"
		el main farà això en forma de bucle mentres no rebi els caracters
		centinella que indiquen que hem acabat de utilitzar la calculadora ("****").
*/ 

#include "Calculadora.hh"
#include "Funcions.hh"

using namespace std;
int main() {
	Variables v;
	Funcions f;
	Calculadora calc;
	string entrada; 

	while (not calc.fi()) {
		calc.llegir(entrada);
		calc.normalitzar(entrada);
		calc.calcular_expresio(v,f,entrada);
		entrada = "";
		
	}
	v.escriure_variables();
	f.escriure_funcions();
}
