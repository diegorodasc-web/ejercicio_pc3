#include <stdio.h>
struct Estudiante{
    int codigo;
    char nombre[50];
    float promedio;
};
int main(){
    struct Estudiante alumnos[3]={ {1001, "Carlos", 17.5},{1002, "Maria", 18.0},{1003, "Pedro", 15.5}};
    for(int i=0; i<3;i++){
        printf("%d - %s - %.2f\n", alumnos[i].codigo, alumnos[i].nombre, alumnos[i].promedio);
    }

    return 0;
}