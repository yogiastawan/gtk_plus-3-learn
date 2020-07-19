CC= gcc
CFLAGS= -Wall -Werror -Wextra -v -std=c99
DBGCFLAGS= -g

app:
	$(CC) $(CFLAGS) -o app main.c `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm -f app