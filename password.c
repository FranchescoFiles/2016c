#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Función auxiliar.
int procesar_respuesta(char respuesta[]) {
    if (strcmp(respuesta, "si") == 0) {
        return 1;
    } else if (strcmp(respuesta, "no") == 0) {
        return 0;
    } else {
        printf("incorrecto.weon, responda 'si' o 'no'.\n");
        exit(EXIT_FAILURE);
    }
}

// Funciónpitttttttt
void generar_contrasena_segura(int longitud, int incluir_mayusculas, int incluir_numeros, int incluir_simbolos) {
    const char caracteres_mayusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char caracteres_minusculas[] = "abcdefghijklmnopqrstuvwxyz";
    const char caracteres_numeros[] = "0123456789";
    const char caracteres_simbolos[] = "!@#$%^&*()-_=+[{]}|;:,<.>/?'\"`";

    //contendr-todos los caracteres
    char caracteres_disponibles[128] = "";
    char contrasena[256] = ""; // longitud máxima

    strcat(caracteres_disponibles, caracteres_minusculas);

    if (incluir_mayusculas) {
        strcat(caracteres_disponibles, caracteres_mayusculas);
    }
    if (incluir_numeros) {
        strcat(caracteres_disponibles, caracteres_numeros);
    }
    if (incluir_simbolos) {
        strcat(caracteres_disponibles, caracteres_simbolos);
    }

    srand(time(NULL)); // Inicia la semilla del generador de números aleatorios

    int total_caracteres = strlen(caracteres_disponibles);

    if (total_caracteres == 0) {
        printf("selecciona los tipos de caracteres para generar la contraseña.\n");
        return;
    }

    for (int i = 0; i < longitud; i++) {
        int indice = rand() % total_caracteres;
        contrasena[i] = caracteres_disponibles[indice];
    }
    contrasena[longitud] = '\0'; //carácter nulo

    printf("La password generada es: %s\n", contrasena);
}

int main() {
    int longitud, incluir_mayusculas, incluir_numeros, incluir_simbolos;
    char respuesta[3];

    printf("Generador de Password Seguras\n");
    printf("Ingrese la longitud para la password: ");
    scanf("%d", &longitud);

    printf("Incluir letras mayúsculas? (si , no): ");
    scanf("%s", respuesta);
    incluir_mayusculas = procesar_respuesta(respuesta);

    printf("números? (si , no): ");
    scanf("%s", respuesta);
    incluir_numeros = procesar_respuesta(respuesta);

    printf("símbolos? (si , no): ");
    scanf("%s", respuesta);
    incluir_simbolos = procesar_respuesta(respuesta);

    generar_contrasena_segura(longitud, incluir_mayusculas, incluir_numeros, incluir_simbolos);

    return 0;
}

