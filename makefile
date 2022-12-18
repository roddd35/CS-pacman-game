PP=g++
CFLAGS= -Wall
TESTFLAGS= -lgtest -lpthread
DOC=doxygen
OTHERS= fantasma.cpp labirinto.cpp pacman.cpp partida.cpp personagem.cpp arquivo.cpp

################################

OBJS=arquivo.o fantasma.o labirinto.o pacman.o partida.o personagem.o
DOXYFILE=Doxyfile
MAIN=ep4.cpp

################################

.PHONY: clean

all: jogo

arquivo.o: arquivo.h

fantasma.o: fantasma.h

labirinto.o: labirinto.h

pacman.o: pacman.h

partida.o: partida.h

personagem.o: personagem.h

ep4.o: ep4.cpp
		
jogo: ${OBJS} 
		${PP} ${CFLAGS} -o ep4 ${MAIN} ${OTHERS}

tests: jogoTestes

jogoTestes: ${OBJS} ${MAIN}
		${PP} ${CFLAGS} -o ep4 ${MAIN} ${OTHERS} ${TESTFLAGS} -DTESTES_ON

doc:
	${DOC} -g 
	${DOC} ${DOXYFILE}

clean:
	@rm -rf *.o html latex ep4 ${DOXYFILE} ${DOXYFILE}.bak