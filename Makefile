builddir = ./build
srcdir = ./src
testdir = ./tests

all: test

.PHONY: buildclean
buildclean:
	rm -rf $(builddir)/

$(builddir):
	mkdir $(builddir)

$(builddir)/fizzbuzz.o: $(builddir) $(srcdir)/fizzbuzz.c
	gcc -c $(srcdir)/fizzbuzz.c -o $@

$(builddir)/test_fizzbuzz.o: $(builddir) $(builddir)/fizzbuzz.o $(testdir)/test_fizzbuzz.c
	gcc -I$(srcdir) -c $(testdir)/test_fizzbuzz.c -o $@

$(builddir)/test_fizzbuzz: $(builddir)/test_fizzbuzz.o
	gcc $(builddir)/test_fizzbuzz.o $(builddir)/fizzbuzz.o -lcgreen -o $@

test: $(builddir)/test_fizzbuzz
	./$(builddir)/test_fizzbuzz
