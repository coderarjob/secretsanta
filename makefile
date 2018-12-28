# Make file to build secret santa application

santa: main.o getRandom.o readNames.o
	gcc -o santa main.o getRandom.o readNames.o

main.o: main.c ss.h
	gcc -c main.c

getRandom.o: getRandom.c ss.h
	gcc -c getRandom.c

readNames.o: readNames.c ss.h
	gcc -c readNames.c

clean:
	rm santa main.o getRandom.o readNames.o
