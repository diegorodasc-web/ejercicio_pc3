#include <stdio.h>
#include <windows.h>
struct Configuracion {
    unsigned int nivel : 3;
    unsigned int modo : 2;
    unsigned int prioridad : 4;
};
int main() {
    SetConsoleOutputCP(CP_UTF8); 
    
    struct Configuracion c;
    c.nivel = 5;
    c.modo = 2;
    c.prioridad = 10;
    printf("Nivel: %u\n", c.nivel);
    printf("Modo: %u\n", c.modo);
    printf("Prioridad: %u\n", c.prioridad);
    printf("Tamaño: %zu bytes\n", sizeof(c));
    return 0;
}
