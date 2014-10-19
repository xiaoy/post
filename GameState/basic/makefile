c++="clang++ -std=c++1y"

objects=main.o player.o
all=main

main:main.o player.o
	c++ -o $@ ${objects}
main.o:main.cc
	c++ -c $<

player.o:player.cc
	c++ -c $<
clean:
	rm *.o ${all}
