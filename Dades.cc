#include "Dades.hh"


	Dades::Dades() {
		definit = false;
	}
	
	Dades::~Dades() {}

	Dades::Dades(string ent) {
		this->definit = true;
		
		if (ent[0] == '(') {
			llista = true;
			integer = false;
			if (ent == "( )") {
				ent = "()";
			}
		}
		else {
			llista = false;
			integer = true;
			
		}
		dada = ent;
	}
	bool Dades::es_definit() {
		return definit;
	}
	bool Dades::es_llista() {
		return llista;
	}
	bool Dades::es_int() {
		return integer;
	}
	string Dades::consultar_str() {
		return dada;
	}
	void Dades::escriure () {
		if (definit) {
			cout << dada << endl;
		}
		else cout << "indefinit" << endl;
	}
	
	void Dades::crear_llista_buida() {
		this->definit = true;
		this->integer = false;
		this->llista = true;
		this->dada = "()";
	}
	
	void Dades::sumar(Dades d0, Dades d1) {
		this->definit = true;
		this->integer = true;
		this->llista = false;
		
		string s0 = d0.consultar_str();
		string s1 = d1.consultar_str();
		int v1 = stoi(s0);
		int v2 = stoi(s1);
		v1 += v2;
		this->dada = to_string(v1);
	}
	void Dades::invertir(Dades d0) {
		this->definit = true;
		this->integer = true;
		this->llista = false;
		
		string s0 = d0.consultar_str();
		int v1 = stoi(s0);
		v1 = -v1;
		this->dada = to_string(v1);
	}
	void Dades::igualar(Dades d0, Dades d1) {
		this->definit = true;
		this->integer = true;
		this->llista = false;
		
		string s0 = d0.consultar_str();
		string s1 = d1.consultar_str();
		if (s0 == s1) this->dada = to_string(1);
		else this->dada = to_string(0);		
	}
	void Dades::construir(Dades d0, Dades d1) {
		this->definit = true;
		this->integer = false;
		this->llista = true;
		
		string s0 = d0.consultar_str();
		string s1 = d1.consultar_str();
		if (s1 != "()") {
			s0 += ' ';
		}
		s1.insert(1,s0);
		this->dada = s1;
	}
	void Dades::cabezera(Dades d0) {
		this->definit = d0.es_definit();
		this->integer = true;
		this->llista = false;
		string s0 = d0.consultar_str();
		int trobat = s0.find(' ');
		if (int(s0.size()) < 3) this->definit = false;
		else {
			if (trobat == std::string::npos) {
				trobat = s0.find(')');
				this->dada = s0.substr(1,trobat-1);
			}
			else {
				this->dada = s0.substr(1,trobat-1);
			}
		}
	}
	void Dades::cua(Dades d0) {
		this->definit = d0.es_definit();
		this->integer = false;
		this->llista = true;
		
		string s0 = d0.consultar_str();
		if (s0 != "()") {
			int trobat = s0.find_first_of(' ');
			
			if (trobat == std::string::npos) {
				trobat = s0.find(')');
				s0.erase(1,trobat-1);
				
			}
			else s0.erase(1,trobat);
			this->dada = s0;
		}
		else this->definit = false;
	}
	void Dades::comparar(Dades d0, Dades d1) {
		this->definit = true;
		this->integer = true;
		this->llista = false;
		if (d0.integer) {
			int v0 = stoi(d0.consultar_str());
			int v1 = stoi(d1.consultar_str());
			if(v0 < v1) this->dada = to_string(1);
			else this->dada = to_string(0);
		}
		else {
			string s0 = d0.consultar_str();
			string s1 = d1.consultar_str();
			list<int> l1;
			list<int>::iterator it1 = l1.begin();
			if (int(s0.size()) > 2) {
				int j = 1;
				string aux;
				while (s0[j] != ')') {
					if(s0[j] == ' ') {
						l1.insert(it1,stoi(aux));
						aux.clear();
						++j;
					}
					else {
						aux += s0[j];
						++j;
					}
				}
				l1.insert(it1,stoi(aux));
			}
			list<int> l2;
			list<int>::iterator it2 = l2.begin();
			if(int(s1.size()) > 2) {
				int i = 1;
				string aux1;
				while (s1[i] != ')') {
					if(s1[i] == ' ') {
						l2.insert(it2,stoi(aux1));
						aux1.clear();
						
						++i;
					}
					else {
						aux1 += s1[i];
						++i;
					}
				}
				l2.insert(it2,stoi(aux1));
			}
			if (l1 < l2) this->dada = to_string(1);
			else this->dada = to_string(0);
		}
	}
	void Dades::negar(Dades d0) {
		this->definit = d0.es_definit();
		this->integer = d0.es_int();
		this->llista = d0.es_llista();
		
		string s0 = d0.consultar_str();
		int v0 = stoi(s0);
		
		if (v0 == 0 or v0 == -0) this->dada = to_string(1);
		else this->dada = to_string(0);
		
	}
	void Dades::fer_and(Dades d0, Dades d1) {
		this->definit = d0.es_definit();
		this->integer = true;
		this->llista = false;
		
		string s0 = d0.consultar_str();
		string s1 = d1.consultar_str();
		int v0 = stoi(s0);
		int v1 = stoi(s1);
		
		if (v0 == 1 and v1 == 1) this->dada = to_string(1);
		else this->dada = to_string(0);
	}
	void Dades::fer_or(Dades d0, Dades d1) {
		this->definit = d0.es_definit();
		this->integer = true;
		this->llista = false;
		
		string s0 = d0.consultar_str();
		string s1 = d1.consultar_str();
		int v0 = stoi(s0);
		int v1 = stoi(s1);
		
		if (v0 == 1 or v1 == 1) this->dada = to_string(1);
		else this->dada = to_string(0);
	}
	void Dades::fer_if(Dades d1) {
		this->definit = d1.es_definit();
		this->integer = d1.es_int();
		this->llista = d1.es_llista();
		this->dada = d1.consultar_str();
	}
	void Dades::crear_list(const string s1) {
		this->definit = true;
		this->integer = false;
		this->llista = true;
		this->dada = s1;
		
	}
	
	void Dades::indefinit() {
		this->definit = false;
	}
	
	
	
	
