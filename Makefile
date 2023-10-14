CC = g++
OBJECT_FILES = main.o format.o entity_objects.o

main: ${OBJECT_FILES}
	${CC} -o main ${OBJECT_FILES}

main.o: main.cpp
	${CC} -c main.cpp

format.o: format.cpp format.hpp
	${CC} -c format.cpp

entity_objects.o: entity_objects.cpp entity_objects.hpp
	${CC} -c entity_objects.cpp

clean:
	rm main *.o
