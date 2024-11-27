CC := GCC
CFLAGS := -O2 -g -Wall -Wextra -fopenmp

BIN_DIR := bin
SRC_DIR := src

.SILENT: sc mp

sc:
	echo "Compiling single core scripts..."
	$(CC) $(CFLAGS) -o $(BIN_DIR)/quicksort $(SRC_DIR)/quicksort.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/matrix_mul_sc $(SRC_DIR)/matrix_mul_sc.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/fibonacci $(SRC_DIR)/fibonacci.c
	echo "Starting execution..."
	./$(BIN_DIR)/quicksort
	./$(BIN_DIR)/matrix_mul_sc
	./$(BIN_DIR)/fibonacci

mp:
	echo "Compiling multi-core scripts..."
	$(CC) $(CFLAGS) -o $(BIN_DIR)/mergesort $(SRC_DIR)/mergesort.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/matrix_mul_mp $(SRC_DIR)/matrix_mul_mp.c
	echo "Starting execution..."
	./$(BIN_DIR)/mergesort
	./$(BIN_DIR)/matrix_mul_mp

clean:
	rm -f $(BIN_DIR)/*

.PHONY: sc mp clean
