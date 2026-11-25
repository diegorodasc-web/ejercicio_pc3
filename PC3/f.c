#include <stdio.h>
#include <stdlib.h>
struct Estudiante {
    int codigo;
    char nombre[50];
    float promedio;
};
int main() {
    struct Estudiante *ptr;
    ptr = malloc(sizeof(struct Estudiante));
    if (ptr == NULL) {
        printf("Error al reservar memoria\n");
        return 1;
    }
    ptr->codigo = 1001;
    snprintf(ptr->nombre, sizeof(ptr->nombre), "Carlos");
    ptr->promedio = 18.5;
    printf("%d - %s - %.2f\n",ptr->codigo,ptr->nombre,ptr->promedio);
    free(ptr);
    ptr = NULL;
    return 0;
 }
