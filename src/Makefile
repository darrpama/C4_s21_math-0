OS := $(shell uname -s)
CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror -std=c11

ifeq ($(OS), Darwin)
	CHKFLAGS = -lcheck
else
	CHKFLAGS = -lcheck -lrt -lm -lpthread -lsubunit
endif

all: clean s21_math.a test gcov_report


s21_math.a: s21_math.o
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

s21_math.o: s21_math.c s21_math.h
	$(CC) $(CFLAGS) -c s21_math.c -o s21_math.o $(CHKFLAGS)

math_test.o:
	checkmk clean_mode=1 math_test.check > math_test.c
	$(CC) $(CFLAGS) -c math_test.c -o math_test.o $(CHKFLAGS)

test: s21_math.o math_test.o
	$(CC) $(CFLAGS) s21_math.o math_test.o -o test.out $(CHKFLAGS)
	./test.out

clean: 
	rm -rf *.o *.gcda *.gcno *.out *.gch *.info
	rm -rf test
	rm -rf report
	rm -rf math_test.c

gcov_report: math_test.o
	$(CC) $(CFLAGS) --coverage -l check s21_math.c math_test.c -o test
	./test
	lcov -t "./test" -o test.info -c -d .
	genhtml -o report test.info

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_lcov:
	brew install lcov

install_valgrind:
	brew install --HEAD LouisBrunner/valgrind/valgrind

install_cppcheck:
	brew install cppcheck
