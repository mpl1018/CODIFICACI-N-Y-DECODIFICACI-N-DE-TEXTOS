/** @file Idioma.hh
    @brief Especificación de la clase Idioma
*/

#ifndef IDIOMA_HH
#define IDIOMA_HH

#include "Treecode.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <string>
#include <iostream>
#include <map>
#endif

/** @class Idioma
    @brief Representa un idioma con atributos: treecode,
    tabla_frecuencias y codigos.
*/
class Idioma {


private:

  /** @brief Es un treecode creado a partir de la tabla de frecuencias y utilizado para crear los códigos de nuestro idioma.
  */
  Treecode treecode;

  /** @brief En ella se guardan pares de caracteres y numeros que representan la frecuencia de cada caracter en el idioma.
  */
  Tabla_frec tabla_frecuencias;

  /** @brief Es una tabla de códigos creada a partir del "treecode" en el cual la cual se guardan todos los códigos del idioma.
  */
  Codigos codigos;


  /** @brief Creadora del treecode del idioma
      @pre <em>cierto</em>
      @post Se ha creado el treecode del parámetro implicito.
  */
    void crear_treecode();

    /** @brief Creadora de los códigos
        @pre <em>cierto</em>
        @post Se crean los "codigos" del parametro implícito.
    */
    void crear_codigos();


public:

    //Constructores


    /** @brief Creadora.
        @pre <em>cierto</em>
        @post Se ha creado un objeto de la clase idioma.
    */
    Idioma();


    /** @brief Creadora con valores concretos.
        @param tabla_frecuencias es la tabla de frecuencias a partir de la cual se creará el idioma.
        @pre <em>cierto</em>
        @post Se ha creado un idioma con tabla de frecuencias "tabla_frecuencias". Además, también se crean los códigos y el treecode a partir de la
        tabla de frecuencias.
    */
    Idioma(Tabla_frec& tabla_frecuencias);


    //Destructora

    /** @brief Destructora.
        @pre <em>cierto</em>
        @post Elimina el idioma.
    */
    ~Idioma();

    //Modificadores

    /** @brief Modificadora de la tabla de frecuencias del idioma.
        @pre <em>cierto</em>
        @post Se modifica el idioma del parámetro implícito sumando la tabla_frecuencias de "id" con la tabla de frecuencias del
        parametro implicito.
    */
   void modificar_idioma (Tabla_frec& id);


    //Consultores

    /** @brief Consultora de la codificación de una palabra.
        @param palabra Es la palabra que queremos codificar.
        @pre P = palabra
        @post Si P se puede codificar, "palabra" pasa a valer la codificación de P.
        @return El último carácter de P que se puede codificar, si P no se puede codificar.
        @return "", si P se puede codificar.
    */
    string codifica(string& palabra);



    /** @brief Consultora de la decodificación de un código en un idioma.
        @param palabra Es la palabra que queremos decodificar.
        @pre P = palabra
        @post Si P se puede decodificar, "palabra" pasa a valer la decodificación de P.
        @return La última posición de P que se puede decodificar, si P no se puede decodificar.
        @return La última posición de P, si P se puede decodificar.
    */
    int decodifica(string& palabra);

    //Escritura

    /** @brief Escritura de la tabla de frecuencias.
        @pre <em>cierto</em>
        @post Se ha escrito por el canal de salida la tabla de frecuencias del parámetro implícito.
    */
    void consultar_tabla() const;

    /** @brief Escritura de los códigos de un idioma.
        @param cod Es el caracter del idioma del cual queremos ver el código. O bien "todos", si se desea ver todos
        los códigos del idioma.
        @pre <em>cierto</em>
        @post Si "cod" es un carácter, se ha escrito por el canal de salida el código del carácter, si el carácter pertenece a la tabla de códigos
        del parámetro implícito.
        Si el carácter no pertenece al idioma, se habrá escrito un mensaje de error.
        Si "cod" == "todos", se han escrito por el canal de salida todos los códigos del idioma.
    */
    void consultar_codigos(const string& cod) const;


    /** @brief Escritura del treecode.
        @pre <em>cierto</em>
        @post Se ha escrito por el canal de salida el treecode del parametro implícito en preorden y en inorden.
    */
    void consultar_treecode() const;

};
#endif
