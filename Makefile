CC = g++
OBJECT_FILES = main.o entity_objects.o user_io.o data_handlers.o

main: ${OBJECT_FILES}
	${CC} -o main ${OBJECT_FILES}

main.o: main.cpp
	${CC} -c main.cpp

entity_objects.o: src/entity_objects.cpp inc/entity_objects.hpp
	${CC} -c src/entity_objects.cpp

data_handlers.o: src/data_handlers.cpp inc/data_handlers.hpp
	${CC} -c src/data_handlers.cpp

user_io.o: src/user_io.cpp inc/user_io.hpp
	${CC} -c src/user_io.cpp

clean:
	rm main *.o
