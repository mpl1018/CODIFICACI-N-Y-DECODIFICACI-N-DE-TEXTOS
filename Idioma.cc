/** @file Idioma.cc
    @brief Implementación de la clase Idioma
*/

#include "Idioma.hh"

Idioma::Idioma(){}

Idioma::Idioma(Tabla_frec& tabla_frecuencias){
  this->tabla_frecuencias = tabla_frecuencias;
  this-> treecode = Treecode(tabla_frecuencias);
  crear_codigos();
}

Idioma::~Idioma(){}

 void Idioma::modificar_idioma(Tabla_frec& tf){
  tabla_frecuencias.sumar_tablas(tf);
  crear_treecode ();
  Codigos c;
  treecode.crear_cod_tree(c);
  codigos = c;
}


void Idioma::crear_treecode(){
  this-> treecode = Treecode(this->tabla_frecuencias);
}


void Idioma::crear_codigos(){
  treecode.crear_cod_tree(codigos);
}

string Idioma::codifica(string& palabra){
  return codigos.codifica (palabra);
}

int Idioma::decodifica(string& palabra){
  return treecode.decodifica(palabra);
}

void Idioma::consultar_tabla() const{
  tabla_frecuencias.escribir();
}

void Idioma::consultar_codigos(const string& cod) const{
  codigos.consultar_codigos(cod);
}

void Idioma::consultar_treecode() const{
  treecode.escribir();
}
