CC=gcc
CPPFLAGS=-Iinclude -Iqueues -Istacks

CFLAGS=-Wall -Wextra
DEBUGFLAGS=-g -fsanitize=address
RELEASEFLAGS=-O2 -DNDEBUG

ifdef DEBUG
CFLAGS += $(DEBUGFLAGS)
else
CFLAGS += $(RELEASEFLAGS)
endif

all: test_minimal_queue test_minis

.PHONY: clean

test_minimal_queue: \
	tests/test_minimal_queue.c \
	src/slink_item.c \
	queues/minimal_queue.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

test_minis: \
	tests/test_minis.c \
	src/slink_item.c \
	stacks/minimal_stack.c \
	queues/minimal_queue.c 
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

run_minimal_queue: test_minimal_queue
	./test_minimal_queue

run_test_minis: test_minis
	./test_minis

clean:
	rm -f test_minimal_queue
	rm -f test_minis
