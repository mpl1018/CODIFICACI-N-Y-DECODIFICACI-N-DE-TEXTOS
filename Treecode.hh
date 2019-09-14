/** @file Treecode.hh
    @brief Especificación de la clase Treecode
*/

#ifndef TREECODE_HH
#define TREECODE_HH

#include "Tabla_frec.hh"
#include "Codigos.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <list>
#endif

/** @class Treecode
    @brief Representa un idioma con el atributo tree, un arbol binario de pares string int.
*/
class Treecode {
private:

  /** @brief Es un árbol binario creado a partir de una tabla de frecuencias.
  */
  BinTree< pair<string,int> > tree;

  /** @brief Función recursiva utilizada en la escritura en inorden.
      @param a Es el árbol que vamos a imprimir.
      @pre <em>cierto</em>
      @post Se ha imprimido el árbol en inorden por el canal de salida.
  */
  void imprimir_treecode_inorden (const BinTree<pair <string, int> >& a) const;


  /** @brief Función recursiva utilizada en la escritura en preorden.
      @param a Es el árbol que vamos a imprimir.
      @pre <em>cierto</em>
      @post Se ha imprimido el árbol en preorden por el canal de salida.
  */
  void imprimir_treecode_preorden(const BinTree<pair <string, int> >& a) const;

  /** @brief Función recursiva utilizada en la creación de códigos.
      @param cod Es la tabla de códigos en la que guardaremos los códigos creados.
      @param a Es el árbol que utilizaremos en la creación de códigos.
      @param codigo String utilizada para guardar los códigos que se van creando.
      @pre C = cod
      @post Se han guardado en C, los códigos creados.
  */
  void crear_codigos_rec(Codigos& cod, const BinTree< pair<string,int> >& a, string codigo);


  /** @brief Función recursiva utilizada en la decodificación de palabras.
      @param palabra Es la palabra que queremos decodificar.
      @param a Es el árbol que utilizaremos en la decodificación.
      @param i Es la posición de palabra que estamos decodificando.
      @param ultima_letra Es la última posición de la palabra que hemos podido decodificar.
      @pre 0<= I=i <= palabra.length().
      @post Se ha devuelto la decodificación de palabra desde la posición I hasta que se llega a una hoja o bien se acaba la palabra.
  */
  string decodifica_rec(const string& palabra, BinTree< pair<string, int> > a, int& i, int& ultima_letra);

public:

  //Constructoras.

  /** @brief Creadora.
      @pre <em>cierto</em>
      @post Se ha creado un objeto de la clase treecode.
  */
  Treecode ();

  /** @brief Creadora con valores concretos.
      @param tabla Es la tabla de frecuencias a partir de la cual se generará el treecode.
      @pre la tabla contiene al menos dos caracteres.
      @post Se ha creado un treecode a partir de "tabla".
  */
  Treecode (Tabla_frec& tabla);

  //Modificadoras


  /** @brief Rellena una tabla de códigos vacía.
      @param cod Es la tabla de códigos vacía que queremos rellenar usando el treecode.
      @pre "cod" es una tabla de códigos vacía.
      @post "cod" contiene los códigos correspondientes.
  */
  void crear_cod_tree(Codigos& cod);



  //Consultoras

  /** @brief Consultora de la decodificación de un código.
      @param palabra Es la palabra que queremos decodificar.
      @pre P = palabra
      @post Si P se puede decodificar, "palabra" pasa a valer la decodificación de P.
      @return La última posición de P que se puede decodificar, si P no se puede decodificar.
      @return La última posición de P, si P se puede decodificar.
  */
  int decodifica (string& palabra);


  //Escritura

  /** @brief Escritura del treecode.
      @pre <em>cierto</em>
      @post Se ha escrito por el canal de salida el treecode del parametro implícito en preorden y en inorden.
  */
  void escribir() const;

};
#endif
