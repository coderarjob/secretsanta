# Make file to build secret santa application

objects = main.o getRandom.o readNames.o

santa:$(objects)
	gcc -o santa $(objects)

# Implicit rules are used here.
# Learn more about here
# (https://www.gnu.org/software/make/manual/make.html#Rule-Introduction)
main.o: ss.h
getRandom.o: ss.h
readNames.o: ss.h
clean:
	rm -f santa main.o getRandom.o readNames.o
