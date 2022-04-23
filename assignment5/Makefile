#Makefile for assignment 5

CC = g++
WFLAG = -Wall
CFLAG = -c
OFLAG = -o
IFLAG = -I
DFLAG = -ggdb

SOURCE = src
INCLUDE = include
OBJECTS = build
BINARY = bin


${BINARY}/assignment5: ${OBJECTS}/main.o ${OBJECTS}/arraymap.o ${OBJECTS}/linkedmap.o
	${CC} ${WFLAG} ${OFLAG} ${BINARY}/assignment5 ${OBJECTS}/main.o ${OBJECTS}/arraymap.o ${OBJECTS}/linkedmap.o

${OBJECTS}/main.o: ${SOURCE}/main.cpp  ${INCLUDE}/map.h ${INCLUDE}/collection.h ${INCLUDE}/keyvalue.h
	${CC} ${WFLAG} ${CFLAG} ${IFLAG} ${INCLUDE}  ${OFLAG} ${OBJECTS}/main.o ${SOURCE}/main.cpp

${OBJECTS}/arraymap.o: ${SOURCE}/arraymap.cpp ${INCLUDE}/map.h ${INCLUDE}/collection.h ${INCLUDE}/keyvalue.h
	${CC} ${WFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/arraymap.o ${SOURCE}/arraymap.cpp

${OBJECTS}/linkedmap.o: ${SOURCE}/linkedmap.cpp ${INCLUDE}/map.h ${INCLUDE}/collection.h ${INCLUDE}/keyvalue.h ${INCLUDE}/node.h
	${CC} ${WFLAG} ${CFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/linkedmap.o ${SOURCE}/linkedmap.cpp


.PHONY: clean

clean:
	rm -r ${OBJECTS}/* ${BINARY}/*
