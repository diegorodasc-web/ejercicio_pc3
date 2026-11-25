#include <stdio.h>

struct estudiante {
    int codigo;
    char nombre[50];
    int edad;
    float promedio;
};

void procesarEstudiantes(struct estudiante *e, int n) {
    int indice_mayor = 0;
    float prom_general = 0;

    printf("--- Lista de Estudiantes ---\n");
    for (int i = 0; i < n; i++) {

        printf("%d - %s - %d - %.2f\n", (e + i)->codigo, (e + i)->nombre, (e + i)->edad, (e + i)->promedio);

        if ((e + i)->promedio > (e + indice_mayor)->promedio) {
            indice_mayor = i;
        }

        prom_general += (e + i)->promedio;
    }

    prom_general = prom_general / n;

    printf("\nEstudiante con mayor promedio: %s (Codigo: %d) con %.2f\n", (e + indice_mayor)->nombre, (e + indice_mayor)->codigo, (e + indice_mayor)->promedio);
           
    printf("El promedio general es: %.2f\n", prom_general);
}

int main() {

    struct estudiante e[5] = {
        {12, "Jose", 15, 13.0},
        {13, "Maria", 16, 15.0},
        {14, "Pepe", 15, 11.2},
        {15, "Eduardo", 15, 9.0},
        {16, "Medusa", 15, 13.2}
    };

    procesarEstudiantes(e, 5);

    return 0;
}
