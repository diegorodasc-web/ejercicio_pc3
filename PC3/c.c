#include <stdio.h>
struct Estudiante{
    int codigo;
    char nombre[50];
    float promedio;
};
void mostrar(struct Estudiante e){
    printf("%d\n", e.codigo);
     printf("%s\n", e.nombre);
      printf("%.2f\n", e.promedio);
};
int main(){
    struct Estudiante e= {1001, "Carlos", 17.5};
    mostrar(e);
    return 0;
}