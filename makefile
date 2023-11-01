flags = -std=c++17 -Wall -I .

weight.o : weight.cc weight.h
	g++ $(flags) -c $< -I .

testweight1 : testweight1.cc weight.o
	g++ $(flags) $^
	./a.out

testweight2 : testweight2.cc weight.o
	g++ $(flags) $^
	./a.out

testweight3 : testweight3.cc weight.o
	g++ $(flags) $^
	./a.out

weightrange.o : weightrange.cc weightrange.h weight.h
	g++ $(flags) -c $< -I .

testweightrange1 : testweightrange1.cc weightrange.o weight.o
	g++ $(flags) $^
	./a.out

testweightrange2 : testweightrange2.cc weightrange.o weight.o
	g++ $(flags) $^
	./a.out

testweightrange3 : testweightrange3.cc weightrange.o weight.o
	g++ $(flags) $^
	./a.out

testweightrange4 : testweightrange4.cc weightrange.o weight.o
	g++ $(flags) $^
	./a.out

clean :
	rm  *.o a.out studentoutput.txt

