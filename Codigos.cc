/** @file Codigos.cc
    @brief Implementación de la clase Codigos
*/
#include "Codigos.hh"
Codigos:: Codigos(){}

string Codigos::next_symbol(const string& s, int& i){
  if (s[i]>=0) {
    ++i;
    return string(1, s[i-1]);
  }
  else {
    i+=2;
    return string(s, i-2, 2);
  }
}

void Codigos::anadir_codigo (const pair <string, string>& p){
  cod.insert(p);
}


string Codigos::codifica(string& palabra){
  string codigo;
  int n = palabra.length();
  map<string,string>::const_iterator it;
  int i=0;
  while (i<n){
    string buscar;
    buscar = next_symbol(palabra, i);
    it = cod.find(buscar);
    if (it == cod.end()) return buscar;
    else codigo+= it->second;
    }
  palabra = codigo;
  return "";
}

void Codigos::consultar_codigos(const string& codi) const{
  if (codi == "todos"){
    for (map<string,string>::const_iterator it = cod.begin(); it!=cod.end(); ++it){
      cout << it->first << " " << it->second << endl;
    }
  }
  else {
    map<string,string>::const_iterator it = cod.find(codi);
    if (it == cod.end()){
      cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    } //MENSAJE ERROR
    else cout << it->first << " " << it->second << endl;
  }
}
