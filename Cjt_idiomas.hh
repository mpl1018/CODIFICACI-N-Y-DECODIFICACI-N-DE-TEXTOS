/** @file Cjt_idiomas.hh
    @brief Especificación de la clase Cjt_idiomas
*/

#ifndef CJT_IDI_HH
#define CJT_IDI_HH

#include "Idioma.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#include <iostream>
#endif

/** @class Cjt_idiomas
    @brief Representa un conjunto de idiomas que tiene como atributo un diccionario
    con los idiomas que contiene.
*/

class Cjt_idiomas {
private:

  /** @brief Un diccionario que guarda los idiomas y los ordena en función de su nombre.
  */
  map <string, Idioma> vidi;

public:

  /** @brief Creadora.
      @pre <em>cierto</em>
      @post El resultado es un conjunto de idiomas vacío.
  */
  Cjt_idiomas();

  //Modificadoras

  /** @brief Modificadora del conjunto de idiomas.
      @pre En el canal de entrada por defecto hay una string y una tabla de frecuencias.
      @post Si el idioma introducido pertenece al conjunto, se modificará este último sumando la tabla de frecuencias de ambos.
      En caso contrario, se añadirá el nuevo idioma al conjunto.
  */
  void anadir_idioma ();


  //Consultoras

  /** @brief Consultora de la codificación de una palabra en un idioma.
      @param nombre Es el nombre del idioma en el que queremos codificar "palabra".
      @param palabra Es la palabra que queremos codificar.
      @pre "nombre" Es el nombre de uno de los idiomas del conjunto. P = palabra
      @post Si P se puede codificar, "palabra" pasa a valer la codificación de P.
      @return El último carácter de P que se puede codificar, si P no se puede codificar.
      @return "", si P se puede codificar.
  */
  string codifica(const string& nombre, string& palabra);

  /** @brief Consultora de la decodificación de un código en un idioma.
      @param nombre Es el nombre del idioma en el que queremos decodificar "palabra".
      @param palabra Es la palabra que queremos decodificar.
      @pre "nombre" Es el nombre de uno de los idiomas del conjunto. P = palabra
      @post Si P se puede decodificar, "palabra" pasa a valer la decodificación de P.
      @return La última posición de P que se puede decodificar, si P no se puede decodificar.
      @return La última posición de P, si P se puede decodificar.
  */
  int decodifica(const string& nombre, string& palabra);


  /** @brief Consultora de la existencia de un idioma.
      @param nombre_id Es el nombre del idioma que queremos buscar.
      @pre <em>cierto</em>
      @post Se ha buscado "nombre_id" en el conjunto.
      @return <b stryle="color: #602020;"> true Si "nombre_id" es el nombre de un idioma que está en el conjunto.
      @return <b stryle="color: #602020;"> false Si "nombre_id" no es el nombre de un idioma que está en el conjunto.
  */
  bool esta_idioma (const string& nombre_id) const;


  //Lectura

  /** @brief Operación de lectura

      \pre Hay preparados por el canal de entrada un entero n (que reprenta el número de
      datos que leeremos).
      \post Se han incluido en el vector del parametro implícito los
      datos leídos.
  */
  void leer_idiomas ();


  //Escritura


  /** @brief Escritura de la tabla de frecuencias de un idioma.
      @param nombre Es el nombre del idioma del cual queremos ver la tabla de frecuencias.
      @pre "nombre" Es el nombre de uno de los idiomas del conjunto.
      @post Se ha escrito por el canal de salida la tabla de frecuencias del idioma solicitado.
  */
  void consultar_tabla(const string& nombre);


  /** @brief Escritura del treecode de un idioma.
      @param nombre Es el nombre del idioma del cual queremos ver el treecode.
      @pre "nombre" Es el nombre de uno de los idiomas del conjunto.
      @post Se ha escrito por el canal de salida el treecode del idioma solicitado en preorden y en inorden.
  */
  void consultar_treecode(const string& nombre);


  /** @brief Escritura de los códigos de un idioma.
      @param nombre Es el nombre del idioma del cual queremos ver el treecode.
      @param comando Es el caracter del idioma del cual queremos ver el código. O bien "todos", si se desea ver todos
      los códigos del idioma.
      @pre "nombre" Es el nombre de uno de los idiomas del conjunto.
      @post Si "comando" es un carácter, se ha escrito por el canal de salida el código del carácter, si el carácter pertenece al idioma.
      Si el carácter no pertenece al idioma, se habrá escrito un mensaje de error.
      Si "comando" == "todos", se han escrito por el canal de salida todos los códigos del idioma. 
  */
  void consultar_codigos(const string& nombre, const string& comando);


};
#endif
