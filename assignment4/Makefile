#Makefile for Assignment 4


CC = g++
WFLAG = -Wall -std=c++11
CFLAG = -c 
OFLAG = -o
IFLAG = -I
DFLAG = -ggdb

SOURCE = src
INCLUDE = include
OBJECTS = build
BINARY = bin

all: ${BINARY}/simpleset ${BINARY}/dynamicarray

${BINARY}/simpleset: ${OBJECTS}/main.o ${OBJECTS}/simplesettests.o ${OBJECTS}/simpleset.o ${OBJECTS}/dynamicarray.o ${OBJECTS}/fileutility.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/simpleset ${OBJECTS}/main.o ${OBJECTS}/simplesettests.o ${OBJECTS}/simpleset.o \
		${OBJECTS}/dynamicarray.o ${OBJECTS}/fileutility.o

${BINARY}/dynamicarray: ${OBJECTS}/main.o ${OBJECTS}/dynamicarraytests.o ${OBJECTS}/dynamicarray.o ${OBJECTS}/fileutility.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/dynamicarray ${OBJECTS}/main.o ${OBJECTS}/dynamicarraytests.o  \
		${OBJECTS}/dynamicarray.o ${OBJECTS}/fileutility.o



${OBJECTS}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/tests.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/main.o ${SOURCE}/main.cpp


${OBJECTS}/simplesettests.o: ${SOURCE}/simplesettests.cpp ${INCLUDE}/simpleset.h ${INCLUDE}/dynamicarray.h ${INCLUDE}/fileutility.h ${INCLUDE}/tests.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/simplesettests.o ${SOURCE}/simplesettests.cpp


${OBJECTS}/dynamicarraytests.o: ${SOURCE}/dynamicarraytests.cpp ${INCLUDE}/dynamicarray.h ${INCLUDE}/fileutility.h ${INCLUDE}/tests.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/dynamicarraytests.o ${SOURCE}/dynamicarraytests.cpp



${OBJECTS}/simpleset.o: ${SOURCE}/simpleset.cpp ${INCLUDE}/simpleset.h ${INCLUDE}/dynamicarray.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/simpleset.o ${SOURCE}/simpleset.cpp


${OBJECTS}/dynamicarray.o: ${SOURCE}/dynamicarray.cpp  ${INCLUDE}/dynamicarray.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/dynamicarray.o ${SOURCE}/dynamicarray.cpp


${OBJECTS}/fileutility.o: ${SOURCE}/fileutility.cpp  ${INCLUDE}/fileutility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/fileutility.o ${SOURCE}/fileutility.cpp



.PHONY: clean

clean:
	rm -rf ${OBJECTS}/* ${BINARY}/*
