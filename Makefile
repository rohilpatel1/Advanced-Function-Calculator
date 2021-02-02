files = main.cpp

start:
	g++ -std=c++17 $(files) && ./a.out

build:
	g++ -std=c++17 $(files)

run:
	./a.out

clean:
	rm a.out