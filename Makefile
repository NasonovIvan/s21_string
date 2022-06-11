CC = gcc
CFLAGS = -Wall -Wextra -Werror
# ASAN = -fsanitize=address -g
.PHONY: clean

all: clean gcov_report

gcov_report: test
	gcov -f *.gcda
	gcovr -r . --html --html-details -o report.html

test: clean s21_string.a
	$(CC) -c tests.c -o tests.o
	$(CC) $(CFLAGS) tests.o s21_string.o -o tests -lcheck
	$(CC) -c -fprofile-arcs -ftest-coverage s21_string.c
	$(CC) -Wall -fprofile-arcs tests.o s21_string.o -o tests -lcheck
	./tests

s21_string.a:
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o
	ar rc s21_string.a s21_string.o

clean:
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f tests
	rm -f *.a
	rm -f *.css
	rm -f *.html
	rm -f *.out

brew:
	git clone https://github.com/Homebrew/brew ~/goinfre/homebrew
	~/goinfre/homebrew/bin/brew install gcovr
	eval "$(~/goinfre/homebrew/bin/brew shellenv)"
	chmod -R go-w "$(brew --prefix)/bin/brew"

cpplint:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

valgrind:
	CK_FORK=no leaks --atExit -- ./tests
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests

my_mac_test:
	gcc -c s21_string_test.c -o tests_add.o      
	gcc -Wall -fprofile-arcs tests_add.o s21_string.o -o tests_add -lcheck
	./tests_add

