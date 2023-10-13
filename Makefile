CC = g++
OBJECT_FILES = main.o format.o

main: ${OBJECT_FILES}
	${CC} -o main ${OBJECT_FILES}

main.o: main.cpp
	${CC} -c main.cpp

format.o: format.cpp format.hpp
	${CC} -c format.cpp

clean:
	rm main *.o
