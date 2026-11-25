#include <stdio.h>
struct Calculadora {
    int (*operacion)(int, int);
};
int sumar(int a, int b) {
    return a + b;
}
int restar(int a, int b) {
    return a - b;
}
int multiplicar(int a, int b) {
    return a * b;
}

int main(){
    struct Calculadora c;
    c.operacion = sumar;
    printf("Suma: %d\n", c.operacion(10, 5));
    c.operacion = restar;
    printf("Resta: %d\n", c.operacion(10, 5));
    c.operacion = multiplicar;
    printf("Multiplicacion: %d\n", c.operacion(10, 5));
    return 0;

}