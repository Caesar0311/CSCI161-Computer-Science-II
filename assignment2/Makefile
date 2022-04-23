#Makefile of CSCI 161 Assignment1
#micro defination of flag
CC = g++ 
WFLAG = -Wall
CFLAG = -c
DFLAG = -ggdb
IFLAG = -I
OUTFLAG = -o
#miciro defination of file building
SOURCE=src
INCLUDE=include
OBJECT = build
BINARY = bin


all: ${BINARY}/sort_bubble ${BINARY}/sort_selection ${BINARY}/sort_insertion ${BINARY}/sort_merge ${BINARY}/sort_quick


${BINARY}/sort_bubble: ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_bubble.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_bubble ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_bubble.o


${BINARY}/sort_selection:${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_selection.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_selection ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_selection.o


${BINARY}/sort_insertion: ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_insertion.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_insertion ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_insertion.o


${BINARY}/sort_merge: ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_merge.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_merge ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_merge.o


${BINARY}/sort_quick: ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_quick.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/sort_quick ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o ${OBJECT}/sorting_quick.o




${OBJECT}/main.o: ${SOURCE}/main.cpp ${INCLUDE}/arrayutility.h ${INCLUDE}/fileutility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG}  ${INCLUDE} ${OUTFLAG} ${OBJECT}/main.o ${SOURCE}/main.cpp

${OBJECT}/arrayutility.o: ${SOURCE}/arrayutility.cpp ${INCLUDE}/arrayutility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG}  ${OBJECT}/arrayutility.o ${SOURCE}/arrayutility.cpp

${OBJECT}/fileutility.o: ${SOURCE}/fileutility.cpp ${INCLUDE}/fileutility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG}  ${OBJECT}/fileutility.o ${SOURCE}/fileutility.cpp

${OBJECT}/sorting_bubble.o: ${SOURCE}/sorting_bubble.cpp ${INCLUDE}/sorting.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${OBJECT}/sorting_bubble.o ${SOURCE}/sorting_bubble.cpp

${OBJECT}/sorting_selection.o: ${SOURCE}/sorting_selection.cpp ${INCLUDE}/sorting.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${OBJECT}/sorting_selection.o ${SOURCE}/sorting_selection.cpp

${OBJECT}/sorting_insertion.o: ${SOURCE}/sorting_insertion.cpp ${INCLUDE}/sorting.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${OBJECT}/sorting_insertion.o ${SOURCE}/sorting_insertion.cpp


${OBJECT}/sorting_merge.o: ${SOURCE}/sorting_merge.cpp ${INCLUDE}/sorting.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${OBJECT}/sorting_merge.o ${SOURCE}/sorting_merge.cpp


${OBJECT}/sorting_quick.o: ${SOURCE}/sorting_quick.cpp ${INCLUDE}/sorting.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG} ${OBJECT}/sorting_quick.o ${SOURCE}/sorting_quick.cpp


.PHONY: clean

clean:
	rm -r ${OBJECT}/* ${BINARY}/* 
	
