#Makefile of CSCI 161 Assignment 3

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

${BINARY}/assignment3: ${OBJECTS}/main.o ${OBJECTS}/fileutility.o ${OBJECTS}/linkedlist.o
	${CC} ${WFLAG} ${DFLAG} ${OFLAG} ${BINARY}/assignment3 ${OBJECTS}/main.o ${OBJECTS}/fileutility.o ${OBJECTS}/linkedlist.o

${OBJECTS}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/fileutility.h ${INCLUDE}/linkedlist.h ${INCLUDE}/listnode.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/main.o ${SOURCE}/main.cpp

${OBJECTS}/fileutility.o: ${SOURCE}/fileutility.cpp ${INCLUDE}/fileutility.h ${INCLUDE}/listnode.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/fileutility.o ${SOURCE}/fileutility.cpp

${OBJECTS}/linkedlist.o: ${SOURCE}/linkedlist.cpp ${INCLUDE}/linkedlist.h ${INCLUDE}/listnode.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${OBJECTS}/linkedlist.o ${SOURCE}/linkedlist.cpp

.PHONY: clean

clean:
	rm -rf ${OBJECTS}/* ${BINARY}/*
