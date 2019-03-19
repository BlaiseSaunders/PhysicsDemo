CC=gcc
CFLAGS= -Wall -ansi -pedantic -Wextra -std=gnu99
LFLAGS= `sdl2-config --cflags --libs` -lSDL2_ttf -lm
SOURCES=main.c list.c input.c draw.c physics.c
OBJECTS=main.o list.o input.o draw.o physics.o
HEADERS=main.h list.h input.h draw.h physics.h
README=readme.txt
MAKEFILE=Makefile
ARCHIVE_EXT=-a3.zip
OUT_EXE=physics_demo

all: $(OUT_EXE)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

$(OUT_EXE): $(OBJECTS)
	$(CC) $^ $(LFLAGS) -o $@

debug:CFLAGS+=-g -pg
debug:clean all

optimised:CFLAGS+=-O3
optimised:clean all


.PHONY:clean install rebuild
clean:
	rm -f *.o $(OUT_EXE) $(USER)$(ARCHIVE_EXT)

install:
	cp ./$(OUT_EXE) /bin/

rebuild: clean
	make


archive:$(USER)$(ARCHIVE_EXT)
$(USER)$(ARCHIVE_EXT):
	zip $@ $(SOURCES) $(HEADERS) $(README) $(MAKEFILE)
