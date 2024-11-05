#include <stdio.h>
#include <ctype.h>
#include "datos.h"
#include "calculos.h"
#include "auth.h"  // Incluye la cabecera de autenticación

int main() {
    char usuario[50], clave[50];
    int figura;
    
    // Autenticación de usuario
    printf("Ingrese su usuario: ");
    scanf("%s", usuario);
    printf("Ingrese su clave: ");
    scanf("%s", clave);

    if (!autenticarUsuario(usuario, clave)) {
        registrarBitacora(usuario, "Ingreso fallido usuario/clave erróneo");
        printf("Usuario o clave incorrectos. Intente de nuevo.\n");
        return 1;  // Termina el programa si la autenticación falla
    }
    
    registrarBitacora(usuario, "Ingreso exitoso al sistema");

    do {
        mostrarMenu();
        printf("Ingrese una opción: ");
        scanf("%d", &figura);

        if (figura >= 1 && figura <= 13) {
            solicitarDatosFigura(figura, usuario);  // Pasa el nombre del usuario
        } else if (figura == 0) {
            registrarBitacora(usuario, "Salida del sistema");
            printf("Saliendo del programa.\n");
        } else {
            printf("Opción no válida. Intente de nuevo.\n");
        }

        if (figura != 0) {
            char respuesta;
            do {
                printf("¿Desea realizar el análisis de otra figura geométrica? (s/n): ");
                scanf(" %c", &respuesta);
                respuesta = tolower(respuesta);

                if (respuesta == 'n') {
                    figura = 0;
                    registrarBitacora(usuario, "Salida del sistema");
                } else if (respuesta == 's') {
                    break;
                } else {
                    printf("Respuesta no válida. Por favor, ingrese 's' para sí o 'n' para no.\n");
                }
            } while (respuesta != 's' && respuesta != 'n');
        }

    } while (figura != 0);

    return 0;
}
