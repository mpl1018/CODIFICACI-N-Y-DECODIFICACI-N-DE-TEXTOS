/** @file Tabla_frec.hh
    @brief Especificación de la clase Tabla_frec
*/

#ifndef TABLA_FREC_HH
#define TABLA_FREC_HH

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#include "BinTree.hh"
#include <iostream>
#endif

/** @class Tabla_frec
    @brief Representa una tabla de frecuencias con atributos: mf (tabla de frecuencias), it (iterador) y un entero que representa el tamaño del diccionario.
*/

class Tabla_frec {
private:

  /** @brief Es un diccionario creado en la inicialización de cada idioma en el que el primer elemento corresponde a un caracter del idioma
  y el segundo elemento a su frecuencia.
  */
  map <string, int> mf;

  /** @brief Es un iterador que apunta a alguno de los elementos del diccionario.
  */
  map <string, int>::const_iterator it;

  /** @brief Es un entero que nos indica el tamaño del diccionario.
  */
  int size;

public:
  //Constructora

  /** @brief Creadora por defecto.
      @pre <em>cierto</em>
      @post El resultado es una tabla de frecuencias vacía.
  */
  Tabla_frec();

  //Consultora

  /** @brief Consultora del tamaño del diccionario.
      @pre <em>cierto</em>
      @post Se ha retornado el tamaño de la tabla.
  */
  int tamano() const;


  /** @brief Consultora del iterador.
      @pre <em>cierto</em>
      @post Se ha retornado el iterador del parámetro implícito.
  */
  map <string, int>::const_iterator puntero();

  //Modificadoras

  /** @brief Modificadora del valor del iterador (apuntar al principio).
      @pre <em>cierto</em>
      @post El iterador del parametro implícito pasa a apuntar al primer elemento de la tabla.
  */
  void it_begin();



  /** @brief Modificadora del valor del iterador (aumentar iterador).
      @pre this->it<this->mf.end()
      @post El iterador pasa a apuntar al siguiente elemento del diccionario.
  */
  void aumentar_it();



  /** @brief Sumar dos tablas de frecuencias.
      @param b Es la tabla de frecuencias cuyas frecuencias se quieren sumar a las del parámetro implícito.
      @pre <em>cierto</em>
      @post Se han sumado las frecuencias de b a las del parámetro implicito. Si hay algún carácter de b que no pertenecía al diccionario del
      parámetro implícito, se añade.
  */
  void sumar_tablas(Tabla_frec& b);



  //Lectura y Escritura

  /** @brief Operación de lectura

      @pre Hay preparados por el canal de entrada un entero n (que reprenta el número de
      datos que leeremos) y n pares de string, int.
      @post Se han incluido en el diccionario del parametro implícito los datos leídos.
  */
  void leer();

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se ha escrito la tabla de frecuencias ordenada lexicográficamente.
  */
  void escribir() const;

};
#endif
