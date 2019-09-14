/** @file Treecode.cc
    @brief Implementación de la clase Treecode
*/

#include "Treecode.hh"

Treecode:: Treecode (){}


Treecode::Treecode(Tabla_frec& t){
  struct sort {
    bool operator() (const BinTree<pair <string, int> >a, const BinTree < pair <string, int> > b){
      if (a.value().second!=b.value().second) return a.value().second<b.value().second;
      return a.value().first<b.value().first;
    }
  };

  set <BinTree <pair <string,int> >, sort > s;
  t.it_begin();
  int n = t.tamano();
  for (int i=0; i<n; ++i){
    s.insert(BinTree<pair<string,int> >(*(t.puntero())));
    t.aumentar_it();
  }
  //CREAMOS LISTA DE BINTREES
  while (s.size()!=1){
    //CREAMOS A1 Y A2
    BinTree < pair <string, int> > a1 = *(s.begin());
    s.erase(s.begin());

    BinTree < pair <string, int> > a2 = *(s.begin());
    s.erase(s.begin());
    //CREAMOS EL BINTREE b
    string concat;
    if (a1.value().first<a2.value().first)
      concat = a1.value().first + a2.value().first;
    else
      concat = a2.value().first + a1.value().first;
    int suma = a1.value().second + a2.value().second;
    BinTree < pair <string, int> > b (make_pair(concat, suma), a1, a2);
    //COLOCAMOS EL NUEVO BINTREE EN LA LISTA
    s.insert(b);
  }
  this->tree = *(s.begin());
}


void Treecode:: imprimir_treecode_inorden(const BinTree<pair <string, int> >& a) const{
  if (not a.empty()) {
      imprimir_treecode_inorden(a.left());
      cout << a.value().first << " " << a.value().second << endl;
      imprimir_treecode_inorden(a.right());
  }
}


void Treecode:: imprimir_treecode_preorden(const BinTree<pair <string, int> >& a) const{
  if (not a.empty()) {
      cout << a.value().first << " " << a.value().second << endl;
      imprimir_treecode_preorden(a.left());
      imprimir_treecode_preorden(a.right());
  }
}


void Treecode:: escribir() const{
  if (!tree.empty()){
    //IMPRIMIR TREECODE EN PREORDEN
    cout << "recorrido en preorden:" << endl;
    imprimir_treecode_preorden (tree);
    //IMPRIMIR TREECODE EN INORDEN
    cout << "recorrido en inorden:" << endl;
    imprimir_treecode_inorden (tree);
  }
}


string Treecode::decodifica_rec(const string& palabra, BinTree< pair<string, int> > arbol, int& i, int& ultima_letra){
    if (arbol.left().empty()) {
        ultima_letra = i;
        return (arbol.value().first);
    }
    else if (i == palabra.size()) {
        return "0";
    }
    else if (palabra[i] == '0') {
        ++i;
        return decodifica_rec(palabra, arbol.left(), i, ultima_letra);
    }
    // if (palabra[i] == '1')
    else{
        ++i;
		    return decodifica_rec(palabra, arbol.right(), i, ultima_letra);
  	}
}


int Treecode::decodifica(string& palabra){
  string decode;
  int i = 0, n = palabra.length(), ultima_letra = 0;
  while (i<n){
    decode += decodifica_rec (palabra, tree, i, ultima_letra);
  }

  palabra = decode;
  return ultima_letra;
}


void Treecode::crear_codigos_rec(Codigos & cod, const BinTree< pair<string,int> >& a, string codigo){
  if (!a.left().empty())
    crear_codigos_rec (cod, a.left(), codigo+"0");
  if (!a.right().empty())
    crear_codigos_rec (cod, a.right(), codigo+"1");
  else if (a.left().empty() and a.right().empty())
     cod.anadir_codigo(make_pair(a.value().first, codigo));
}



void Treecode::crear_cod_tree(Codigos & cod){
  crear_codigos_rec(cod, tree, "");
}
