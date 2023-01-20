GCC = g++ -std=c++11
PROGS = driver

driver: test.o
	$(GCC) -o driver test.o
	
test.o: test.cpp set.h set.cpp
	$(GCC) -c test.cpp

clean:
	rm $(PROGS)