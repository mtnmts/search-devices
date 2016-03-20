CC=gcc
CFLAGS=-Werror -Wall -lbluetooth
SOURCES=bondsafe.c util.c
OUTPUT=bondsafe

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

clean: $(OUTPUT)
	rm $(OUTPUT)

all: $(OTPUT)
