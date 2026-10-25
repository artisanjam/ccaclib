CC=gcc
CFLAGS=-Wall -Wextra -Iqueues

test_minimal_queue: tests/test_minimal_queue.c queues/minimal_queue.c
	$(CC) $(CFLAGS) $^ -o $@
