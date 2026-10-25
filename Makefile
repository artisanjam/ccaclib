CC=gcc
CPPFLAGS=-Iqueues

CFLAGS=-Wall -Wextra
DEBUGFLAGS=-g -fsanitize=address
RELEASE_FLAGS=-O2 -DNDEBUG

ifdef DEBUG
CFLAGS += $(DEBUGFLAGS)
else
CFLAGS += $(RELEASEFLAGS)
endif

all: test_minimal_queue

.PHONY: clean

test_minimal_queue: \
	tests/test_minimal_queue.c \
	queues/minimal_queue.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

run_minimal_queue: test_minimal_queue
	./test_minimal_queue

clean:
	rm -f test_minimal_queue
