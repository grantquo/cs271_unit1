GCC = g++ -std=c++11
PROGS = driver

driver: test_minqueue.o
	$(GCC) -o driver test_minqueue.o
	
test.o: test.cpp minqueue.h minqueue.cpp 
	$(GCC) -c test_minqueue.cpp

clean:
	rm $(PROGS)
