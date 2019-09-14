/** @file Cjt_idiomas.cc
    @brief Implementación de la clase Cjt_idiomas
*/

#include "Cjt_idiomas.hh"

Cjt_idiomas::Cjt_idiomas(){}



void Cjt_idiomas::anadir_idioma(){
  string id_nombre;
  Tabla_frec tf;
  cin >> id_nombre;
  tf.leer();
  map <string, Idioma>:: iterator it = vidi.find(id_nombre);

  if (it == vidi.end()){
    Idioma id (tf);
    vidi.insert(make_pair(id_nombre, id));
    cout << "Anadido " << id_nombre << endl;
  }
  else{
    (*it).second.modificar_idioma(tf);
    cout << "Modificado " << id_nombre << endl;
  }
}


void Cjt_idiomas::leer_idiomas(){
  int nidi;
  cin >> nidi;
  for (int i=0; i<nidi; ++i){
    Tabla_frec tf;
    string name;
    cin >> name;
    tf.leer();
    Idioma id (tf);
    vidi.insert(make_pair(name, id));
  }
}

bool Cjt_idiomas::esta_idioma(const string& nombre_id) const{
  map <string, Idioma>:: const_iterator it = vidi.find(nombre_id);
  if (it == vidi.end()) return false;
  return true;
}

string Cjt_idiomas::codifica(const string& nombre, string& palabra){
  return vidi[nombre].codifica(palabra);
}
int Cjt_idiomas::decodifica(const string& nombre, string& palabra){
  return vidi[nombre].decodifica(palabra);
}

void Cjt_idiomas::consultar_tabla(const string& nombre){
  vidi[nombre].consultar_tabla();
}
void Cjt_idiomas::consultar_treecode(const string& nombre){
  vidi[nombre].consultar_treecode();
}
void Cjt_idiomas::consultar_codigos(const string& nombre, const string& comando){
  vidi[nombre].consultar_codigos (comando);
}
