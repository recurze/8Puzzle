IDIR = include
ODIR = obj
SDIR = src

CC = g++
CFLAGS = -IDIR${IDIR}

_OBJ = 

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}


.PHONY: clean

clean:
	rm -f ${ODIR}/*.o ${SDIR}/main
