#include <stdio.h>
struct Estudiante{
    int codigo;
    char nombre[50];
    float promedio;
};
int main(){
    struct Estudiante e={1001, "Carlos", 17.5};
    struct Estudiante *ptr= &e;

    printf("%d%\n", ptr->codigo);
    printf("%s%\n", ptr->nombre);
    printf("%.2f%\n", ptr->promedio);

    ptr->promedio=19.0;
    printf("%.2f%\n", ptr->promedio);
    return 0;
}