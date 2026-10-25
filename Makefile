CC=gcc
CPPFLAGS=-Iinclude

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
	src/common/slink_item.c \
	src/queues/minimal_queue.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

test_minis: \
	tests/test_minis.c \
	src/common/slink_item.c \
	src/stacks/minimal_stack.c \
	src/queues/minimal_queue.c 
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

run_minimal_queue: test_minimal_queue
	./test_minimal_queue

run_test_minis: test_minis
	./test_minis

clean:
	rm -f test_minimal_queue
	rm -f test_minis
