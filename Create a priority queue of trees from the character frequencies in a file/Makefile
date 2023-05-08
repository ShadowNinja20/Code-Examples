BASE_NAME = huffman
ASG_NICKNAME = HW55
SRC_C = huffman.c priority_queue.c frequencies.c
SRC_H = huffman.h priority_queue.h frequencies.h clog.h miniunit.h
TEST_C = test_huffman.c
TEST_EXPECTED = expected.txt
SUBMIT_FILES = $(SRC_C) $(TEST_C) $(TEST_EXPECTED) clog.h miniunit.h makefile
TEST_ACTUAL = actual.txt
EXECUTABLE = test_huffman
EXECUTABLE_DBG = $(EXECUTABLE)_dbg
EXECUTABLE_GCOV = $(EXECUTABLE)_gcov
CC = gcc
CFLAGS = -g -std=c11 -Wall -Wshadow -Wvla -Werror -pedantic -Wno-unused-function
CFLAGS_GCOV = $(CFLAGS) -fprofile-arcs -ftest-coverage
SHELL = /bin/bash

$(EXECUTABLE): $(TEST_C) $(SRC_H)
	$(CC) -o $(EXECUTABLE) $(SRC_C) $(TEST_C) $(CFLAGS)

test: $(EXECUTABLE) $(TEST_EXPECTED) 
	@# if actual output matches expected output then count it as a success
	@if diff -a -B <("./$(EXECUTABLE)") $(TEST_EXPECTED) &> /dev/null ; then \
		echo "Test passed: output of $(EXECUTABLE) matches $(TEST_EXPECTED)" ; \
	else \
		echo "Test failed: output of $(EXECUTABLE) does NOT match $(TEST_EXPECTED)" ; \
	fi

submit: clean $(EXECUTABLE)
	264submit $(ASG_NICKNAME) $(SUBMIT_FILES)

pretest: submit
	264test $(ASG_NICKNAME)

coverage: clean $(SRC_C) $(TEST_C)
	$(CC) -o $(EXECUTABLE_GCOV) $(SRC_C) $(TEST_C) $(CFLAGS_GCOV) -DNDBUG ; \
	./$(EXECUTABLE_GCOV) ; \
	gcov -f $(SRC_C) 

debug: $(TEST_C) $(SRC_H)
	$(CC) -o $(EXECUTABLE_DBG) $(SRC_C) $(TEST_C) $(CFLAGS) -DDEBUG

clean: 
	rm -f -v $(EXECUTABLE) $(EXECUTABLE_DBG) $(EXECUTABLE_GCOV)

.PHONY: test submit coverage clean debug
