#include <stdio.h>
#include <ctype.h>  
#include "datos.h"
#include "calculos.h"

int main() {
    int figura;

    do {
        mostrarMenu();
        printf("Ingrese una opción: ");
        scanf("%d", &figura);

        switch (figura) {
            case 1 ... 13:
                solicitarDatosFigura(figura);
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }

        if (figura != 0) {
            char respuesta;
            do {
                printf("¿Desea realizar el análisis de otra figura geométrica? (s/n): ");
                scanf(" %c", &respuesta);
                respuesta = tolower(respuesta);  // Convertir a minúscula

                if (respuesta == 'n') {
                    figura = 0;  // Salir del bucle
                } else if (respuesta == 's') {
                    break;  // Continuar con otro análisis
                } else {
                    printf("Respuesta no válida. Por favor, ingrese 's' para sí o 'n' para no.\n");
                }
            } while (respuesta != 's' && respuesta != 'n');
        }

    } while (figura != 0);

    return 0;
}
