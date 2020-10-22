CFLAGS = -c -I$(HOME)/Programming/include --std=c++17
LFLAGS = -L$(HOME)/Programming/lib
LIBS = -ldataStructures

parens: parens.o
	g++ $(LFLAGS) -o parens parens.o $(LIBS)

parens.o: parens.cc
	g++ -c $(CFLAGS) parens.cc
