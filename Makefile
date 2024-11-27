CC = gcc
CFLAGS = -fopenmp -O2

TARGETS = sorting

# source files
SORTING_SRC = sorting.c
OPENMP_TEST_SRC = openmp_test.c

# executable files
SORTING_EXEC = sorting
OPENMP_TEST_EXEC = openmp_test

all: $(TARGETS)

sorting:
	$(CC) $(CFLAGS) -o $(SORTING_EXEC) $(SORTING_SRC)

openmp_test:
	$(CC) $(CFLAGS) -o $(OPENMP_TEST_EXEC) $(OPENMP_TEST_SRC)

run_sorting:
	./$(SORTING_EXEC)

run_openmp_test:
	./$(OPENMP_TEST_EXEC)

clean:
	rm -f $(SORTING_EXEC) $(OPENMP_TEST_EXEC)

.PHONY: all clean run_sorting run_openmp_test
