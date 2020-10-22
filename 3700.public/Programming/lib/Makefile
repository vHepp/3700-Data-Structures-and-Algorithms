CFLAGS = -c -I$(HOME)/Programming/include --std=c++17
LFLAGS = -L$(HOME)/Programming/lib
LIBS = -ldataStructures

OBJS = ../obj/fraction.o ../obj/simpleStack.o

libdataStructures.a: $(OBJS)
	ar r libdataStructures.a $(OBJS)
	ranlib libdataStructures.a

../obj/fraction.o: ../src/fraction.cc ../include/fraction.h
	g++ $(CFLAGS) -o ../obj/fraction.o ../src/fraction.cc

../obj/simpleStack.o: ../src/simpleStack.cc ../include/simpleStack.h
	g++ $(CFLAGS) -o ../obj/simpleStack.o ../src/simpleStack.cc

clean:
	rm *.a ../obj/*

