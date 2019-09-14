/** @file Tabla_frec.cc
    @brief Implementación de la clase Tabla_frec
*/

#include "Tabla_frec.hh"
#include <algorithm>

Tabla_frec::Tabla_frec(){}

int Tabla_frec::tamano() const{
  return this->size;
}

void Tabla_frec::leer(){
  int n, f;
  string c;
  cin >> n;
  this->size = n;
  for (int i=0; i<n; ++i){
    cin >> c >> f;
    mf.insert(make_pair (c,f));
  }
}

void Tabla_frec::escribir() const{
  for (map<string,int>::const_iterator it = mf.begin(); it != mf.end(); ++it){
    cout << it->first << " " << it->second << endl;
  }
}

void Tabla_frec::it_begin(){
  this->it = mf.begin();
}
void Tabla_frec::aumentar_it(){
  ++this->it;
}
map <string, int>::const_iterator Tabla_frec::puntero(){
  return this->it;
}


void Tabla_frec:: sumar_tablas(Tabla_frec& b){
  b.it_begin();
  int n = b.tamano();
  map <string, int>::iterator it;

  for (int i=0; i<n; ++i){
    it = mf.find ((*(b.puntero())).first);
    if (it==mf.end()) {
      mf.insert(*(b.puntero()));
      ++size;
    }
    else (*it).second += (*(b.puntero())).second;
    b.aumentar_it();
  }
}
