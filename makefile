CC=g++
INCLUDE   = -I/usr/include/
INCLUDEGL = -I/usr/include/GL/
LIBDIR    = -L/usr/lib64
LIBS      = -lGL -lGLU -lglut -lm

RAYGL_SOURCE = ./raygl.cpp
RAYGL = ./raygl.o
PGMIO = ./pgmIO.o
#RAYGL_SOURCE = raygl

COMPILERFLAGS = -Wall
CFLAGS = $(COMPILERFLAGS) $(INCLUDE)
LFLAGS = -static -c
LIBRARIES = -lglut -lGL -lGLU -lm 

hw8: hw8.o
	$(CC) $(RAYGL) $(INCLUDE) $(INCLUDEGL) $(CFLAGS) -o $@ $(LIBDIR) $(LIBS) $< $(LIBRARIES)  

template: hw8.o
	$(CC) $(RAYGL) $(PGMIO) $(INCLUDE) $(INCLUDEGL) $(CFLAGS) -o $@ $(LIBDIR) $(LIBS) $< $(LIBRARIES)  

raygl: 
	$(CC) raygl.cpp $(LFLAGS) $(INCLUDE) $(INCLUDEGL) $(CFLAGS) -o $@ $(LIBDIR) $(LIBS) $< $(LIBRARIES)  

clean:
	rm *.pov
	rm *.png
