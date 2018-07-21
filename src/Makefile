OBJS = main.o handle.o
CFLAG = -Wall -g
CC = gcc
INCLUDE = -I ${PWD}/../inc/ 
LIBS = -lm -lpthread 
TARGET = demo_statemachine

${TARGET}:${OBJS}
	${CC} ${CFLAG} ${INCLUDE} -o $@ ${OBJS} ${LIBS}
clean:
	-rm -f *.o demo_statemachine
.c.o:
	${CC} ${CFLAG} ${INCLUDE} -c $<

