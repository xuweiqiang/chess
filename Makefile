CC=gcc
CFLAGS=
LDFLAGS=
SOURCES=chess.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=chess

all:
	gcc -g draw.c game.c chess.c -o chess
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o chess
