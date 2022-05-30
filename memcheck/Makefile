CFLAGS = -Wall -Werror -ggdb -g3 -fsanitize=address
CC = gcc $(CFLAGS)

test: test.c
	$(CC) -o $@ $^

clean:
	rm -rf *.o test
	
