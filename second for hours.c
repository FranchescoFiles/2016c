#include <stdio.h>
//scritps.01.01.01
void convertir_tiempo() {
    int segundos, horas, minutos;

    printf("Ingrese el time en segundos: ");
    scanf("%d", &segundos);

    horas = segundos / 3600;
    minutos = (segundos % 3600) / 60;
    segundos = segundos % 60;

    printf("Tiempo_bitch: %d hora, %d minutos, %d segundos\n", horas, minutos, segundos);
}

int main() {
    convertir_tiempo();
    return 0;
}
