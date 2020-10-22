CFLAGS = -c -I$(HOME)/Programming/include
LFLAGS = -L$(HOME)/Programming/lib
LIBS = -ldataStructures

qtest: qtest.o
	g++ -o qtest $(LFLAGS) qtest.o $(LIBS)

qtest.o: qtest.cc
	g++ $(CFLAGS) qtest.cc

