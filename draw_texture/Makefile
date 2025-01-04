CC = g++
LIBS = -lGL -lGLU -lglut
DEFINES = -DGL_GLEXT_PROTOTYPES

VBO: texture.cpp
	$(CC) $^ $(DEFINES) $(LIBS) -o texture

clean:
	rm texture
