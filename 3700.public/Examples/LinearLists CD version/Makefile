CFLAGS = -c -I$(HOME)/Programming/include
LFLAGS = -L$(HOME)/Programming/lib
LIBS = -ldataStructures

listtest: listtest.o
	g++ -o listtest $(LFLAGS) listtest.o $(LIBS)

listtest.o: listtest.cc
	g++ $(CFLAGS) listtest.cc

