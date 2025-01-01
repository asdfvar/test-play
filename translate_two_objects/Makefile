CC = g++
LIBS = -lGL -lGLU -lglut
DEFINES = -DGL_GLEXT_PROTOTYPES

EXE = character
all: VBO

clean:
	rm $(EXE)

VBO: character.cpp
	$(CC) $^ $(DEFINES) $(LIBS) -o $(EXE)
