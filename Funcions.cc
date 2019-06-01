#include "Funcions.hh"

using namespace std;

	Funcions::Funcions() {
		funcions = map<string,fun>();
	}
	
	Funcions::~Funcions() {}

	bool Funcions::existeix_fun(const string& nom) {
		return funcions.find(nom) != funcions.end();
	}
	
	void Funcions::afegir_fun(const string& nom, const string& params, const string& op, const int num) {
		auto trobat = funcions.find(nom);
		if (trobat != funcions.end()) funcions.erase(trobat);
		fun f1;
		f1.par_f = params;
		f1.exp = op;
		f1.num = num;
		funcions.insert(make_pair(nom,f1));
	}
	
	const string Funcions::consultar_fun(const string& nom) {
		return funcions[nom].exp;
	}
	
	const string Funcions::consultar_params(const string& nom){
		return funcions[nom].par_f;
	}
	
	void Funcions::escriure_funcions(){
		cout << "Operacions:" << endl;
		if (not this->funcions.empty()) {
			for(auto punt : this->funcions) {
				int npar;
				if (punt.second.par_f.size() == 2) npar = 0;
				else npar = (int(punt.second.num));
				cout << punt.first << " #" << npar << endl;
				
			}
		}
		
	}
