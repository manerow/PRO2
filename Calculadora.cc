#include "Calculadora.hh"
#include <locale>
#include "string"
#include <algorithm>

using namespace std;
	
	Calculadora::Calculadora() 
	{
		acabat = false;
	}
	
	bool Calculadora::es_bool_valid(Dades d) 
	{
		bool res = false;
		if (d.es_int()) {
			string s = d.consultar_str();
			int v = stoi(s);
			if (v == 0 or v == 1 or v == -0) {
				res = true;
			}
		}
		return res;
	}

	
	Calculadora::~Calculadora(){}
		
	bool Calculadora::es_atom(string entrada) 
	{
		return entrada[0] != '(';
	}
	
	void Calculadora::calcular_expresio(Variables &v, Funcions &f,string entrada) 
	{
		
		if (entrada[0] != ' ' and entrada != "" and entrada != "	") {
			
			vector<string> extreu;
			int t = entrada.find_last_of(')');
			int t1 = entrada.find_first_of('(');
			int comprova;
			if (t != std::string::npos and t1 != std::string::npos) {
				comprova = entrada.find_first_not_of("() ");
			}
			if (t != std::string::npos) {
				++t;
				entrada.erase(t);
			}
			if (entrada.find('(') == std::string::npos or entrada == "****" or comprova == std::string::npos) {
				
				extreu.push_back(entrada);
			}
			else {
				
				int pos = 1;
				string aux;
				bool acaba = false;
				
				while (not acaba) {
					aux = ext1(entrada,pos);	
					
					if (aux == "") acaba = true;		
					else extreu.push_back(aux);
				}
			}		
			
			if(extreu.size() > 0){
				if (extreu[0] == "define"){
						
						if(extreu.size() == 3){
							Dades d = operar(extreu[2],v,f);
							if (not v.existeix_var(extreu[1]) or (v.existeix_var(extreu[1]) and d.es_definit())) {
								v.afegir_var(extreu[1],d);
							}
							cout << extreu[1] << " ";
							d.escriure();
						}
						
						else if(extreu.size() == 4){
							string param = extreu[2];
							vector<string> parametres;
							int pos = 1;
							string aux;
							bool acaba = false;
							
							while (not acaba) {
								aux = ext1(param,pos);		
								
								if (aux == "") acaba = true;
								
								else parametres.push_back(aux);
							} 
							f.afegir_fun(extreu[1],extreu[2],extreu[3],parametres.size());
							cout << extreu[1] << " " << '#' << int(parametres.size()) << endl;
							}
				}
				else {
					
					if (extreu[0] == "****") {
						acabat = true;
					}
					else {
						Dades d = operar(entrada,v,f);
						d.escriure();
					}
				}
			}		
			
		}
	}

	
	bool Calculadora::fi() 
	{
		return acabat;
	}
	
	void Calculadora::llegir(string& entrada)  
	
	{
		getline(cin,entrada);
		size_t pos = entrada.find_first_of('(');	
		
		if (pos == size_t(0)) {	
			bool acabat = false;
			string aux;
			
			int pos = 1;
			int cont = 1;
			while (not acabat) {
										
				if (cont != 0) {										
					if (pos < int(entrada.size())) {
						if (entrada[pos] == '(') ++cont;
						else if (entrada[pos] == ')') --cont;
						++pos;											
						}
					else {
						getline(cin,aux);
						entrada += " " + aux;
					}
				}
				else {
					acabat = true;
					es_atomica = false;
				}
			}
		} 
		else {
			es_atomica = true;
		}
		
	}
	
	Dades Calculadora::operar(string ex, Variables &v, Funcions &f) 
	{
	string a;
	vector<string> e; 
	Dades d;
	int t = ex.find_last_of(')');
	int t1 = ex.find_first_of('(');
	int comprova;
	if (t != std::string::npos and t1 != std::string::npos) {
		comprova = ex.find_first_not_of("() ");
	}
	if (ex.find('(') == std::string::npos or comprova == std::string::npos) {
		e.push_back(ex);
		
	}
	
	else {
		int p = 1;
		bool end = false;
		while (not end) {
			a = ext1(ex,p);	
			if (a == "") end = true;
			else e.push_back(a);
		}
	}
	
	if(es_atom(ex) or comprova == std::string::npos){
		
		if(ex[0] == '-' or (ex[0] >= '0' and ex[0] <= '9')) {
			int v = stoi(ex);
			string val = to_string(v);
			d = Dades(val);
			} 
		else if (e[0] == "()" or e[0] == "( )") {
			d.crear_llista_buida();
		}	
		else {
			if (v.existeix_var(ex)) {
				d = v.consultar_var(ex);			
			}
			else d.indefinit();
		}
	}
	
	else {
		if (e[0][0] == '+' and int(e[0].size()) == 1) {
			if (int(e.size()) == 3) {
				Dades d0 = operar(e[1],v,f);
				Dades d1 = operar(e[2],v,f);
				if (d0.es_definit() and d1.es_definit()) {
					if (d0.es_int() and d1.es_int()) {
						d.sumar(d0,d1);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0][0] == '-' and int(e[0].size()) == 1) {
			if (int(e.size()) == 2) {
				Dades d0 = operar(e[1],v,f);
				if (d0.es_definit()) {
					if (d0.es_int()) {
						d.invertir(d0);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0] == "cons") {
			if (int(e.size()) == 3) { 
				Dades d0 = operar(e[1],v,f);
				Dades d1 = operar(e[2],v,f);
				if (d0.es_definit() and d1.es_definit()) {
					if (d0.es_int() and d1.es_llista()) {
						d.construir(d0,d1);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0] == "head") {
			if (int(e.size()) == 2) {
				Dades d0 = operar(e[1],v,f);
				if (d0.es_definit() and d0.es_llista()) {
					string t = d0.consultar_str();
					if (int(t.size()) > 0) {
						d.cabezera(d0);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0] == "tail") {
			if (int(e.size()) == 2) {
				Dades d0 = operar(e[1],v,f);
				if (d0.es_definit() and d0.es_llista()) {
					string t = d0.consultar_str();
					if (int(t.size()) > 0) {
						d.cua(d0);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0][0] == '=' and int(e[0].size()) == 1) {
			
			if (int(e.size()) == 3) {
				Dades d0 = operar(e[1],v,f);
				Dades d1 = operar(e[2],v,f);
				if (d0.es_definit() and d1.es_definit()) {
					if ((d0.es_int() and d1.es_int()) or (d0.es_llista() and d1.es_llista())) {
						d.igualar(d0,d1);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0][0] == '<' and int(e[0].size()) == 1) {
			if (int(e.size()) == 3) {
				Dades d0 = operar(e[1],v,f);
				Dades d1 = operar(e[2],v,f);
				if (d0.es_definit() and d1.es_definit()) {
					if ((d0.es_int() and d1.es_int()) or (d0.es_llista() and d1.es_llista())) {
						d.comparar(d0,d1);
					}
					
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0] == "not") {
			if (int(e.size()) == 2) {
				Dades d0 = operar(e[1],v,f);
				if (d0.es_definit()) {
					if (es_bool_valid(d0)) {
						d.negar(d0);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0] == "and") {
			if (int(e.size()) == 3) {
				Dades d0 = operar(e[1],v,f);
				Dades d1 = operar(e[2],v,f);
				if (d0.es_definit() and d1.es_definit()) {
					if (es_bool_valid(d0) and es_bool_valid(d1)) {
						d.fer_and(d0,d1);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0] == "or") {
			if (int(e.size()) == 3) {
				Dades d0 = operar(e[1],v,f);
				Dades d1 = operar(e[2],v,f);
				if (d0.es_definit() and d1.es_definit()) {
					if (es_bool_valid(d0) and es_bool_valid(d1)) {
						d.fer_or(d0,d1);
					}
					else d.indefinit();
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (e[0] == "if") {
		
			if (int(e.size()) == 4) {
				
				Dades d0 = operar(e[1],v,f);
				
				if (d0.es_definit() and es_bool_valid(d0)) {
					
					int v1 = stoi(d0.consultar_str());
					if (v1 == 0) {
						Dades d1 = operar(e[3],v,f);
						d.fer_if(d1);
					}
					else {
						Dades d1 = operar(e[2],v,f);
						d.fer_if(d1);
					}
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else if (f.existeix_fun(string(e[0]))) {
			Variables v2;
			string parametres_funcio = f.consultar_params(string(e[0]));
			vector<string> params_func;
			int p = 1;
			bool end = false;
			while (not end) {
				a = ext1(parametres_funcio,p);	
				if (a == "") end = true;
				else params_func.push_back(a);
			}
			int nparams_funcio = int(params_func.size());
			if(nparams_funcio == e.size()-1){
				int i = 1; 
				bool indefinit = false;
				while(i < e.size() and not indefinit){
					Dades d0 = operar(e[i],v,f);
					if(d0.es_definit()) v2.afegir_var(params_func[i-1],d0);
					else indefinit = true;
					++i;
				}
				if(not indefinit){
					d = operar(f.consultar_fun(string(e[0])),v2,f);
				}
				else d.indefinit();
			}
			else d.indefinit();
		}
		
		else {
			
			int i = 0;
			string s0;
			string s1 = "(";
			bool sortir = false;
			bool primer = true;
			while(i < e.size() and not sortir){
					Dades d0 = operar(e[i],v,f);
					if (d0.es_definit()) {
						s0 = d0.consultar_str();
						if (primer) {
							s1 += s0;
							primer = false;
						}
						else {
							s1 += ' ';
							s1 += s0;
						}
					}
					else {
						sortir = true;
					}
					++i;
			}
			int pos = s1.find_first_of('(',1);
			if (pos != std::string::npos) {
				sortir = true;
				d.indefinit();
			}
			if(not sortir) {
				s1 += ")";
				d.crear_list(s1);
			}
			else {
				d.indefinit();
			}
		}
	
	}
	return d;
}
	
bool Calculadora::dos_espais(char l, char r) 
{
	return (l == r) and (l == ' ');
}

void Calculadora::normalitzar(string& entrada) 
{
	string::iterator nou_final = unique(entrada.begin(), entrada.end(), dos_espais);
	entrada.erase(nou_final, entrada.end());
}
	
string Calculadora::ext1(const string& entrada, int& pos) 
{
	string param;
	size_t aux_pos;
	size_t len;
	if (entrada[pos] == ' ') {
		++pos;
	}
	if(entrada[pos] == '(') {
		int cont = 0;
		aux_pos = size_t(pos);
		++pos;
		while(cont != -1) {
			if (entrada[pos] == '(') ++cont;
			else if (entrada[pos] == ')') --cont;
			++pos;
		}
		len  = size_t(pos) - aux_pos;
		param = entrada.substr(aux_pos,len);
	}
	
	else if (entrada[pos] == ')') {
		param == "";
	}
	else {
		aux_pos = size_t(pos);
		while (entrada[pos] != ' ' and entrada[pos] != ')') {
			++pos;
		}
		len = size_t(pos) - aux_pos;
		param = entrada.substr(aux_pos,len);
	}
	return param;
}

