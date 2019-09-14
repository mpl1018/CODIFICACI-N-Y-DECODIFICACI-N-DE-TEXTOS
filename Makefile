OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Idioma.o Tabla_frec.o Cjt_idiomas.o Treecode.o Codigos.o
	g++ -o program.exe program.o Idioma.o Tabla_frec.o Cjt_idiomas.o Treecode.o Codigos.o $(OPCIONS)
	rm *.o

program.o: program.cc Cjt_idiomas.hh Idioma.hh Tabla_frec.hh Treecode.hh Codigos.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

Cjt_idiomas.o: Cjt_idiomas.cc Idioma.hh
		g++ -c Cjt_idiomas.cc $(OPCIONS)

Idioma.o: Idioma.cc BinTree.hh Tabla_frec.hh Treecode.hh Codigos.hh
	g++ -c Idioma.cc $(OPCIONS)

Tabla_frec.o: Tabla_frec.cc
	g++ -c Tabla_frec.cc $(OPCIONS)

Treecode.o: Treecode.cc Tabla_frec.hh BinTree.hh
	g++ -c Treecode.cc $(OPCIONS)

Codigos.o: Codigos.cc Treecode.hh
	g++ -c Codigos.cc $(OPCIONS)

practica.tar: program.cc Cjt_idiomas.cc Cjt_idiomas.hh Idioma.cc Idioma.hh Tabla_frec.cc Tabla_frec.hh Treecode.cc Treecode.hh Codigos.cc Codigos.hh html.zip
	tar -cvf practica.tar program.cc Cjt_idiomas.cc Cjt_idiomas.hh Idioma.cc Idioma.hh Tabla_frec.cc Tabla_frec.hh Treecode.cc Treecode.hh Codigos.cc Codigos.hh html.zip Makefile

clean:
	rm *.o
	rm *.exe
	rm *.gch
