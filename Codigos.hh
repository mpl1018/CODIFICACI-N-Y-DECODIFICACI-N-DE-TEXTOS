/** @file Codigos.hh
    @brief Especificación de la clase Codigos
*/

#ifndef CODIGOS_HH
#define CODIGOS_HH


#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Codigos
    @brief Representa una tabla de códigos que tiene como atributo un diccionario con todos los códigos de un idioma, ordenados lexicográficamente
    por el carácter correspondiente a cada código.
*/
class Codigos {

private:

  /** @brief Un diccionario que guarda los códigos y su carácter correspondiente.
  */
  map<string,string> cod;

  /** @brief Función utilizada para el reconocimiento de caracteres especiales en la codificación de una palabra.
      @param s Es la string que contiene la palabra utilizada.
      @param i Es la posición de la palabra en la que queremos comprobar si tiene un carácter especial o no.
      @pre i=I<s.length()
      @post  Si el carácter es normal i = I+1, si es especial i = I+2
      @return La string que contiene el carácter de la posición I, sea especial o no.
  */
  string next_symbol(const string& s, int& i);

public:

  /** @brief Creadora.
      @pre <em>cierto</em>
      @post El resultado es una tabla de códigos vacía.
  */
  Codigos();


  //MODIFICADORAS

  /** @brief Modificadora del diccionario: añadir un código.
      @param p Es una pareja de strings. La primera representa al carácter y la segunda el código del carácter.
      @pre El primer elemento es un carácter, especial o no. El segudo solo está formado por una convinación de "0" y "1".
      @post El resultado es una tabla de códigos vacía.
  */
  void anadir_codigo (const pair <string, string>& p);


  //CONSULTORAS

  /** @brief Consultora de la codificación de una palabra.
      @param palabra Es la palabra que queremos codificar.
      @pre  P = palabra
      @post Si P se puede codificar, "palabra" pasa a valer la codificación de P.
      @return El último carácter de P que se puede codificar, si P no se puede codificar.
      @return "", si P se puede codificar.
  */
  string codifica(string& palabra);


  //ESCRITURA

  /** @brief Escritura de códigos.
      @param cod Es el caracter del idioma del cual queremos ver el código. O bien "todos", si se desea ver todos
      los códigos del idioma.
      @pre <em>cierto</em>.
      @post Si "cod" es un carácter, se ha escrito por el canal de salida el código del carácter, si el carácter está en el diccionario.
      Si el carácter no pertenece al diccionario, se habrá escrito un mensaje de error.
      Si "cod" == "todos", se han escrito por el canal de salida todos los códigos.
  */
  void consultar_codigos(const string& cod) const;


};
#endif
