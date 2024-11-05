#include <stdio.h>
#include <string.h>
#include <time.h>
#include "auth.h"

// Función para autenticar usuario leyendo de un archivo
int autenticarUsuario(char *usuario, char *clave) {
    FILE *archivo = fopen("usuarios.txt", "r");
    if (!archivo) {
        perror("No se pudo abrir el archivo de usuarios");
        return 0;  // Retorna 0 en caso de error al abrir el archivo
    }
    
    char archivoUsuario[50], archivoClave[50];
    int autenticado = 0;

    // Lee cada línea del archivo y compara con el usuario y clave ingresados
    while (fscanf(archivo, "%s %s", archivoUsuario, archivoClave) != EOF) {
        if (strcmp(usuario, archivoUsuario) == 0 && strcmp(clave, archivoClave) == 0) {
            autenticado = 1;
            break;
        }
    }
    
    fclose(archivo);
    return autenticado;  // Retorna 1 si fue autenticado correctamente, 0 si no
}

// Función para registrar acciones en la bitácora
void registrarBitacora(const char *usuario, const char *accion) {
    FILE *archivo = fopen("bitacora.txt", "a");  // Abre la bitácora en modo de adición
    if (!archivo) {
        perror("No se pudo abrir el archivo de bitácora");
        return;  // Termina la función si no se pudo abrir el archivo
    }

    // Obtener la fecha y hora actuales
    time_t tiempo = time(NULL);
    struct tm *tm = localtime(&tiempo);

    // Formato: YYYY/MM/DD HH:MM:SS - Usuario - Acción
    fprintf(archivo, "%04d/%02d/%02d %02d:%02d:%02d: %s – %s\n",
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec,
            usuario, accion);
    
    fclose(archivo);  // Cierra el archivo de bitácora
}
