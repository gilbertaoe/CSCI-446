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

main: main.o
	$(CC) $(RAYGL) $(INCLUDE) $(INCLUDEGL) $(CFLAGS) -o $@ $(LIBDIR) $(LIBS) $< $(LIBRARIES)  

template: main.o
	$(CC) $(RAYGL) $(PGMIO) $(INCLUDE) $(INCLUDEGL) $(CFLAGS) -o $@ $(LIBDIR) $(LIBS) $< $(LIBRARIES)  

raygl: 
	$(CC) raygl.cpp $(LFLAGS) $(INCLUDE) $(INCLUDEGL) $(CFLAGS) -o $@ $(LIBDIR) $(LIBS) $< $(LIBRARIES)  

clean:
	rm main
	rm *.pov
	rm *.png

