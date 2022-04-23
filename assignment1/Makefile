#Makefile of CSCI 161 Assignment1

# Define and use macros for each GCC flag that you are going to use to compile/link your code/object. 
CC = g++ 
WFLAG = -Wall
CFLAG = -c
# Use GCC debug flag to facilitate debugging using gdb. 
DFLAG = -ggdb
# Use GCC include flag to specify the path of application’s custom header files so that your code does not need to specify relative path of these header files in #include pre-processor macro. 
IFLAG = -I
# Create individual object file (*.o) into build folder from each *.cpp file of src folder. 
OUTFLAG = -o

# Define and use macros for each sub-folder of the application, e.g., src, include, resource, build, and bin
SOURCE=src
INCLUDE=include
OBJECT = build
BINARY = bin

# Link all the object files at the build folder into a single executable file named assignment1 into bin folder. g
all: main.o arrayutility.o fileutility.o
	${CC} ${WFLAG} ${DFLAG} ${OUTFLAG}  ${BINARY}/assignment1 ${OBJECT}/main.o ${OBJECT}/arrayutility.o ${OBJECT}/fileutility.o

main.o: ${SOURCE}/main.cpp ${INCLUDE}/arrayutility.h ${INCLUDE}/fileutility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG}  ${INCLUDE} ${OUTFLAG} ${OBJECT}/main.o ${SOURCE}/main.cpp

arrayutility.o: ${SOURCE}/arrayutility.cpp ${INCLUDE}/arrayutility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG}  ${OBJECT}/arrayutility.o ${SOURCE}/arrayutility.cpp

fileutility.o: ${SOURCE}/fileutility.cpp ${INCLUDE}/fileutility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OUTFLAG}  ${OBJECT}/fileutility.o ${SOURCE}/fileutility.cpp


#  Clean or remove files from both build and bin folders using PHONY target named clean. 

.PHONY: clean

clean:
	rm -r ${OBJECT}/* ${BINARY}/* 
	
