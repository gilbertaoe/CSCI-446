CC=g++
LIBP=-L/usr/lib64/
LIBS=-lGL -lGLU -lglut -lm

INCP=-I/usr/include/GL/

main:
	-$(CC) $@.cpp $(INCP) $(LIBP) $(LIBS) -o $@ 

#Remove files

clean: 
#	-clear
#	-/bin/rm mssgs5 d c *.o core 
#	-clear