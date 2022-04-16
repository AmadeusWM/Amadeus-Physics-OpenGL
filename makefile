IDIR =./include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=./src
LDIR =./src

LIBS=-lm -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl

_DEPS = game.h \
	opengl/shader.h \
	shapes/shape.h \
	shapes/shape_cube.h \
	spring_mass/springs_connected.h \
	spring_mass/mass_cube.h \
	spring_mass/spring.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = glad.o \
	main.o \
	game.o \
	shapes/shape.o \
	shapes/shape_cube.o \
	spring_mass/springs_connected.o \
	spring_mass/mass_cube.o \
	spring_mass/spring.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

springMass: $(OBJ)
	$(CC) -o ./bin/$@ $^ $(CFLAGS) $(LIBS) \
	&& find . -name '*.o' -delete

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 