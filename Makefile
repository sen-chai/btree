program := main.c
binary := main.o

all:
	gcc -o $(binary) $(program) -lm -I.
go:
	gcc -o $(binary) $(program) -lm -I. && ./$(binary)

test:
	gcc -o ./testing/test.o ./testing/test.c && ./testing/test.o

test2:
	gcc -o ./testing/test.o ./testing/test2.c && ./testing/test.o

test3:
	gcc -o ./testing/test.o ./testing/test3.c && ./testing/test.o

in:
	# make clear
	gcc -o $(binary) $(program)
	./$(binary) < ./input.in

clear:
	rm *.dat *.o

O:
	vim -O3 *.dat

o:
	vim -o3 *.dat
