#include <stdio.h>
struct Procesador {
    float frecuencia;
    float amplitud;
    float (*procesar)(float, float);
};
float amplificar(float frecuencia, float amplitud) {
    return frecuencia * amplitud;
}
float atenuar(float frecuencia, float amplitud) {
    return frecuencia / amplitud;
}
int main() {
    struct Procesador p;
    p.frecuencia = 50.0f;
    p.amplitud = 2.0f;
    p.procesar = amplificar;
    printf("Resultado: %.2f\n",
    p.procesar(p.frecuencia, p.amplitud));
    p.procesar = atenuar;
    printf("Resultado: %.2f\n",
    p.procesar(p.frecuencia, p.amplitud));
    return 0;
}