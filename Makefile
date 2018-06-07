IDIR = include
ODIR = obj
SDIR = src

CC = g++
CFLAGS = -I${IDIR}

SRC := $(shell ls src)
OBJ := $(patsubst %.cpp, ${ODIR}/%.o, ${SRC})


${ODIR}/%.o: ${SDIR}/%.cpp
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}


.PHONY: clean

clean:
	rm -f ${ODIR}/*.o main
