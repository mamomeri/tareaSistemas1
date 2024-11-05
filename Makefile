# Compilador
CC = gcc
# Flags
CFLAGS = -Wall -g

# Archivos objeto
OBJ = main.o datos.o calculos.o

# Ejecutable
TARGET = programa_geometrico

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c datos.h calculos.h
	$(CC) $(CFLAGS) -c main.c

datos.o: datos.c datos.h
	$(CC) $(CFLAGS) -c datos.c

calculos.o: calculos.c calculos.h
	$(CC) $(CFLAGS) -c calculos.c

clean:
	rm -f $(OBJ) $(TARGET)
