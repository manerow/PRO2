#include "Variables.hh"

using namespace std;

	Variables::Variables() {
		var = map<string,Dades>();
	}
	
	Variables::~Variables() {}
	
	const Dades Variables::consultar_var(const string nom) { 
		
		return var[nom];
	}
		
	bool Variables::existeix_var(const string nom) {
		return var.find(nom) != var.end();
	}		
	
	void Variables::afegir_var(const string nom, Dades val) {
		auto trobat = var.find(nom);
		if (trobat != var.end() and val.es_definit()) var.erase(trobat);
		var.insert(make_pair(nom,val));
	}
	
	void Variables::escriure_variables(){
		cout << "Variables:" << endl;
		if (not this->var.empty()) {
			for(auto punt : this->var) {
				cout << punt.first << " ";
				punt.second.escriure();
				
			}
		}
	}
