/**
 * @mainpage Codificación y decodificación de textos.

Consiste en un programa modular que ofrece un menú de opciones para gestionar codificador de textos en varios idiomas. En este programa se ha intentado poner
en práctica los fundamentos de programación modular, utilizando una serie de módulos funcionales combinados para resolver el problema planteado.
En este programa se han utilizado cinco clases o módulos, los que se han considerado apropiados para resolver el problema de forma organizada e intuitiva.
Las clases utilizadas han sido las siguientes:

- <em>Cjt_idiomas</em> 

- <em>Idioma</em>

- <em>Tabla_frec</em>

- <em>Treecode</em>

- <em>Codigos</em>

*/

#include "Cjt_idiomas.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

/** @brief Programa principal con menú de opciones.
*/
int main (){
  Cjt_idiomas c;
  c.leer_idiomas();
  string op;
  while (cin >> op and op != "fin"){
    //añadrir/modificar Idioma
    if (op == "anadir/modificar"){
      c.anadir_idioma();
    }
    //codificar
     if (op == "codifica"){
      string nombre_id, palabra;
      cin >> nombre_id >> palabra;
      cout << "Codifica en " << nombre_id << " el texto:" << endl;
      cout << palabra << endl;
      if (c.esta_idioma(nombre_id)){
        string i = c.codifica(nombre_id, palabra);
        if (i=="") cout << palabra << endl;
        else cout << "El texto no pertenece al idioma; primer caracter que falla: " << i << endl;
      }
      else {
        cout << "El idioma no existe" << endl;
      }
    }
    //decodificar
    else if (op == "decodifica"){
      string nombre_id, palabra;
      cin >> nombre_id >> palabra;
      cout << "Decodifica en " << nombre_id << " el texto:" << endl;
      cout << palabra << endl;
      int n = palabra.length();
      if (c.esta_idioma(nombre_id)) {
        int i = c.decodifica(nombre_id, palabra);
        if (i==n) cout << palabra << endl;
        else cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << i << endl;
      }
      else {
        cout << "El idioma no existe" << endl;
      }
    }
    //consultar tabla de frecuencias
    else if (op == "tabla_frec"){
      string nombre_id;
      cin >> nombre_id;
      cout << "Tabla de frecuencias de " << nombre_id << ":" << endl;
      if (c.esta_idioma(nombre_id)) c.consultar_tabla(nombre_id);
      else {
        cout << "El idioma no existe" << endl;
      }
    }
    //consultar treecode
    else if (op == "treecode"){
      string nombre_id;
      cin >> nombre_id;
      cout << "Treecode de " << nombre_id << ":" << endl;
      if (c.esta_idioma(nombre_id)) c.consultar_treecode(nombre_id);
      else {
        cout << "El idioma no existe" << endl;
      }
    }
    //consultar codigos
    else if(op == "codigos"){
      string nombre_id, consulta;
      cin >> nombre_id >> consulta;

      if (consulta == "todos")
        cout << "Codigos de " << nombre_id << ":" << endl;
      else
        cout << "Codigo de " << consulta << " en " << nombre_id << ":" << endl;

      if (c.esta_idioma(nombre_id)) c.consultar_codigos(nombre_id, consulta);
      else {
        if (consulta == "todos")
          cout << "El idioma no existe" << endl;
        else
          cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
      }
    }
    cout << endl;
  }
}
