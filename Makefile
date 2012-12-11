CC=gcc
CFLAGS=
LDFLAGS=
SOURCES=chess.c draw.c calc_moves.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=chess

all:
	$(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o chess
