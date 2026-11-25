#include <stdio.h>
#include <stdlib.h>
struct Departamento {
    int codigo;
    char nombre[50];
};
struct Empleado {
    int codigo;
    char nombre[50];
    struct Departamento *departamento;
};
int main() {
    struct Departamento d = {10, "Sistemas"};
    struct Empleado e = {.codigo = 1001,.nombre = "Carlos",.departamento = &d};
    printf("Empleado: %s\n", e.nombre);
    printf("Departamento: %s\n", e.departamento->nombre);
    return 0;
}
