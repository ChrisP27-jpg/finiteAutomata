# Specifiy the target
all: painter_p1

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
painter_p1: painter_p1.o
	g++ painter_p1.o -o painter_p1

# Specify how the object files should be created from source files
painter_p1.o: painter_p1.cpp
	g++ -c painter_p1.cpp


# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o p1
