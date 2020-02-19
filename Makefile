all: test

.PHONY: clean
clean:
	rm -rf test_fizzbuzz.o test_fizzbuzz

test_fizzbuzz.o: test_fizzbuzz.c
	gcc -c test_fizzbuzz.c

test_fizzbuzz: test_fizzbuzz.o
	gcc test_fizzbuzz.o -lcgreen -o test_fizzbuzz

test: test_fizzbuzz
	./test_fizzbuzz
