CC=gcc
CFLAGS=-c -g
LDFLAGS=-g
SOURCES=chess.c draw.c game.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=chess

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o chess
