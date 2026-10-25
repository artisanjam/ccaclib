CC=gcc
CFLAGS=-Wall -Wextra -Iqueues

test_minimal_queue: \
	tests/test_minimal_queue.c \
	queues/minimal_queue.c
	$(CC) $(CFLAGS) $^ -o $@

run_minimal_queue: test_minimal_queue
	./test_minimal_queue

clean:
	rm -f test_minimal_queue
