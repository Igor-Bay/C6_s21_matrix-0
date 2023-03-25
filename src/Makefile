CC=gcc
BUILDFLAGS=-std=c11 -Wall -Wextra -Werror
CFLAGS=$(BUILDFLAGS) -c

TESTFLAGS := -lcheck -lpthread -pthread

TESTFLAGS+=
ifeq ($(shell uname -s),Linux)
	TESTFLAGS += -lm -lrt -lsubunit
endif

GCOVFLAGS = -fprofile-arcs -ftest-coverage

HEADERS=s21_matrix.h
SOURCES=$(addprefix s21_matrix_functions/, s21_matrix_constructor.c s21_matrix_operations.c s21_matrix_determinant.c s21_matrix_helpers.c)
OBJECTS=$(SOURCES:.c=.o)
TESTS_SOURCES=test.c
# TESTS_FUNCTIONS=$(addprefix tests/, lorenttr_test.c)

FILES_TO_CHECK=$(shell find . -name '*.c' && find . -name '*.h' )

MAINFILE=${MAIN}

.PHONY: test rebuild clean stylecheck fmt
.SECONDARY: $(OBJECTS)


all: s21_matrix.a

%.out: %.o $(OBJECTS)
	$(CC) $^ -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) -g $^ -o $@ 

s21_matrix.a:  $(OBJECTS)
	ar rcs s21_matrix.a $^
	ranlib s21_matrix.a

gcov_report: test
	lcov -t test.out -o test.info -c -d . --no-external
	genhtml -o report test.info
	open report/index.html

gcovr_report: test
	mkdir gcovr/
	gcovr --html-details gcovr/report.details.html
	open gcovr/report.details.html

report_nohtml: test
	gcov *gcno > coverage.txt
	open coverage.txt

test: clean test_s21_matrix.a
	$(CC) -g $(TESTS_SOURCES) $(GCOVFLAGS) $(TESTFLAGS) -L. s21_matrix.a -o test.out
	./test.out

test_s21_matrix.a: all_functions
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

all_functions: $(SOURCES)
	$(CC) -g $(CFLAGS) $^ $(GCOVFLAGS)

rebuild: clean all

main: clean s21_matrix.a
	@[[ ! -z "$(MAINFILE)" ]] || (echo 'define MAIN env variable!' && exit 1)
	$(CC) -o main.out -g $(BUILDFLAGS) ./mainfiles/$(MAINFILE).c s21_matrix.a  

clean: 
	@rm -rf  $(OBJECTS)
	@rm -rf report/ gcovr/ s21_matrix.a *.gcda *.gcno *.gcov *.out *.info *.o coverage.txt *.dSYM
	
stylecheck:
	clang-format -n -style=Google $(FILES_TO_CHECK)
	
fmt:
	clang-format -i -style=Google $(FILES_TO_CHECK)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(FILES_TO_CHECK)

valgrind:
ifeq ($(shell uname -s),Linux)
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./main.out
endif
