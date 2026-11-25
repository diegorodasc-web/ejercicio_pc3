#include <stdio.h>
typedef float (*FuncionCalculo)(float, float);
typedef struct {
    float peso;
    float distancia;
    FuncionCalculo calcular;
} Transporte;
float costoTerrestre(float peso, float distancia) {
    return peso * distancia * 0.50f;
}
float costoAereo(float peso, float distancia) {
    return peso * distancia * 2.00f;
}
float costoMaritimo(float peso, float distancia) {
    return peso * distancia * 0.20f;
}

float ejecutarCalculo(Transporte *t) {
    if (t == NULL || t->calcular == NULL) {
        return -1.0f;
    }
    return t->calcular(t->peso, t->distancia);
}
int main() {
    Transporte t;
    t.peso = 100.0f;
    t.distancia = 200.0f;
    
    t.calcular = costoTerrestre;
    printf("Costo terrestre: %.2f\n",ejecutarCalculo(&t));
    
    t.calcular = costoAereo;
    printf("Costo aereo: %.2f\n",ejecutarCalculo(&t));
    
    t.calcular = costoMaritimo;
    printf("Costo maritimo: %.2f\n",ejecutarCalculo(&t));
    return 0;
}
