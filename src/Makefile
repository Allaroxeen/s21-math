CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
CLEAN=rm -Rf

uname_S := $(shell uname -s)
ifeq ($(uname_S), Linux)
	CHECK_LIBS=-lcheck -lm -lpthread -lsubunit -lrt
	LEAKS=valgrind $(BUILD_DIR)/test
else
	CHECK_LIBS=-lcheck -lm -lpthread
	LEAKS=CK_FORK=no leaks --atExit -- $(BUILD_DIR)/test
endif

SRC_DIR=.
TEST_DIR=../tests
BUILD_DIR=../build
SOURCES=*.c
HEADERS=*.h
OBJ=*.o
catpath=cat/*.c
greppath=grep/*.c
LIB_NAME=s21_math.a

all: clean test libss21_math.a

clean:
	$(CLEAN) $(OBJ) *.a *.gcno *.gcda *.gcov *.info
	$(CLEAN) $(BUILD_DIR)/*

$(LIB_NAME): $(SRC_DIR)/$(SOURCES) $(SRC_DIR)/$(HEADERS)
	$(CC) $(CFLAGS) -g -c $(SRC_DIR)/$(SOURCES)
	ar rc $(LIB_NAME) $(OBJ)
	$(CLEAN) $(OBJ)

libss21_math.a: $(SRC_DIR)/$(SOURCES) $(SRC_DIR)/$(HEADERS)
	$(CC) $(CFLAGS) -g -c $(SRC_DIR)/$(SOURCES)
	ar rc libss21_math.a $(OBJ)
	$(CLEAN) $(OBJ)

lib: $(LIB_NAME)

# для запуска тестов
test: $(LIB_NAME)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -g $(TEST_DIR)/tests.c -L. $(LIB_NAME) $(CHECK_LIBS) -o $(BUILD_DIR)/test
	$(BUILD_DIR)/test

# покрытие кода тестами
gcov_report: clean
	$(CC) $(CFLAGS) --coverage -c $(SRC_DIR)/$(SOURCES)
	ar rc $(LIB_NAME) $(OBJ)
	$(CC) $(CFLAGS) $(TEST_DIR)/tests.c -L. $(LIB_NAME) $(CHECK_LIBS) -lgcov -o $(BUILD_DIR)/tests
	$(CLEAN) $(OBJ)
	$(BUILD_DIR)/tests
	gcov *.gcda
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	mkdir -p $(BUILD_DIR)/report
	genhtml -o $(BUILD_DIR)/report gcov_report.info


# проверки
lint:
	python3 ../materials/linters/cpplint.py --recursive --extensions=c ../src ../tests

cppcheck:
	cppcheck --std=c11 --enable=all --suppress=missingIncludeSystem  --suppress=unusedFunction --suppress=invalidPointerCast ./

leaks:
	$(LEAKS)
build: 
	$(CC) *.c -g