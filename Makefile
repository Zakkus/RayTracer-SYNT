CC=g++
CFLAGS=-std=c++11 
LIBS=-lSDL2 -lSDL2_image
SRC= point3.cc ray.cc camera.cc sphere.cc plane.cc main.cc
OBJ=$(SRC:.cc=.o)
EXE=rt

all:
	$(CC) $(CFLAGS) -o $(EXE) $(SRC) $(LIBS)

clean:
	rm -f $(OBJ) *.out *.core $(EXE)
