CC = g++
OBJECT_FILES = main.o format.o entity_objects.o utility.o

main: ${OBJECT_FILES}
	${CC} -o main ${OBJECT_FILES}

main.o: main.cpp
	${CC} -c main.cpp

format.o: src/format.cpp inc/format.hpp
	${CC} -c src/format.cpp

entity_objects.o: src/entity_objects.cpp inc/entity_objects.hpp
	${CC} -c src/entity_objects.cpp

utility.o: src/utility.cpp inc/utility.hpp
	${CC} -c src/utility.cpp

clean:
	rm main *.o
