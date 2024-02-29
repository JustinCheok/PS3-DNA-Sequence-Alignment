CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic -std=c++11 -l boost_unit_test_framework -o2
OBJ = ED.o main.o
DEPS = ED.cpp main.cpp
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
EXE = ED

all: $(OBJ)
$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
$(CC) $(CFLAGS) -o $@ $<

main.o: main.cpp
$(CC) $(CFLAGS) -o $@ $<

 main: main.o ED.0
$(CC) $(CFLAGS) $@ main.o ED.o

clean:
rm $(OBJ) $(EXE)
