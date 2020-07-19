CC= gcc
CFLAGS= -Wall -Werror -Wextra -v -std=c99
DBGCFLAGS= -g
GTK_FLAGS=`pkg-config --cflags --libs gtk+-3.0`

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)
EXEC= app

app: $(EXEC)

$(EXEC): $(OBJ)
	@echo -e "=>\e[94mCreate \"\e[4m$(@F)\e[24m\" executable\e[0m"
	$(CC) $(CFLAGS) -o $@ $< $(GTK_FLAGS)
	@echo -e "=>\e[92mCreating \"\e[4m$(@F)\e[24m\" Success\e[0m"

%.o: %.c	
	@echo -e "=>\e[94mPreparing \"\e[4m$<\e[24m\"\e[0m"
	@mkdir -p $(RELBUILDDIR)/$(<D)
	$(CC) $(CFLAGS) -c $< -o $@ $(GTK_FLAGS)
	@echo -e "=>\e[92mBuilding \"\e[4m$(@F)\e[24m\" Success\e[0m"

clean:
	rm -f $(EXEC) $(OBJ)