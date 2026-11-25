#include <stdio.h>
struct Estudiante{
    int codigo;
    char nombre[50];
    int edad;
    float promedio;
};
int main(){
    struct Estudiante e1;
    e1.codigo = 100;
    snprintf(e1.nombre, sizeof(e1.nombre), "Carlos");
    e1.edad = 16;
    e1.promedio = 15.3;

    printf("Codigo e1: %d\n", e1.codigo);
    printf("Nombre e1: %s\n", e1.nombre);
    printf("Edad e1: %d\n", e1.edad);
    printf("Promedio e1: %.2f\n", e1.promedio);

    return 0;
}