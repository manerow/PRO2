OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Calculadora.o Dades.o Funcions.o Variables.o
	g++ -o program.exe program.o Calculadora.o Dades.o Funcions.o Variables.o

program.o:program.cc
	g++ -c program.cc $(OPCIONS)

Variables.o: Variables.cc Variables.hh
	g++ -c Variables.cc $(OPCIONS)

Funcions.o: Funcions.cc Funcions.hh
	g++ -c Funcions.cc $(OPCIONS)

Dades.o: Dades.cc Dades.hh
	g++ -c Dades.cc $(OPCIONS)

Calculadora.o: Calculadora.cc Calculadora.hh
	g++ -c Calculadora.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
