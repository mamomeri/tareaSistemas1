# Variables
CC = gcc
CFLAGS = -Wall
OBJFILES = main.o auth.o datos.o calculos.o
ASMFILES = main.s auth.s datos.s calculos.s

# Generar el ejecutable
programa: $(OBJFILES)
	$(CC) $(OBJFILES) -o programa

# Generar archivos .o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

auth.o: auth.c
	$(CC) $(CFLAGS) -c auth.c -o auth.o

datos.o: datos.c
	$(CC) $(CFLAGS) -c datos.c -o datos.o

calculos.o: calculos.c
	$(CC) $(CFLAGS) -c calculos.c -o calculos.o

# Generar archivos .s (ensamblador)
main.s: main.c
	$(CC) -S main.c -o main.s

auth.s: auth.c
	$(CC) -S auth.c -o auth.s

datos.s: datos.c
	$(CC) -S datos.c -o datos.s

calculos.s: calculos.c
	$(CC) -S calculos.c -o calculos.s

# Regresar de .o a .s usando objdump
main_from_o.s: main.o
	objdump -d main.o > main_from_o.s

auth_from_o.s: auth.o
	objdump -d auth.o > auth_from_o.s

datos_from_o.s: datos.o
	objdump -d datos.o > datos_from_o.s

calculos_from_o.s: calculos.o
	objdump -d calculos.o > calculos_from_o.s

# Limpiar archivos generados
clean:
	rm -f programa *.o *.s *_from_o.s
