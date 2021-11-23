CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_MY_MAT = my_mat.o
OBJECTS_HEADER = my_mat.h
FLAGS = -Wall -g

 all: connections
connections: $(OBJECTS_MAIN) libmy_mat.so
	$(CC) $(FLAGS) -0 connections $(OBJECTS_MAIN) libmy_mat.a

make_static_lib: libmy_mat.a

make_dynamic_lib: libmy_mat.so

libmy_mat.a: $(OBJECTS_MY_MAT)
	 $(AR) -rcs libmy_mat.a $(OBJECTS_MY_MAT) # creates static library

libmy_mat.so: $(OBJECTS_MY_MAT)
	 $(CC) $(FLAGS) -shared -o libmy_mat.so $(OBJECTS_MY_MAT)  # creates dynamic library

main.o: main.c $(OBJECTS_HEADER)
	$(CC) $(FLAGS)	-c main.c

 my_mat.o: my_mat.c $(OBJECTS_HEADER)
		$(CC) $(FLAGS) -c my_mat.c
clean:
	rm -f *.o *.a *.so connections