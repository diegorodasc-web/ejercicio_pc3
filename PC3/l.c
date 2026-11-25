#include <stdio.h>

struct Estado {
    unsigned int activo : 1;
    unsigned int bloqueado : 1;
    unsigned int conectado : 1;
};

int main() {
    struct Estado e;
    e.activo = 1;
    e.bloqueado = 0;
    e.conectado = 1;
    printf("Activo: %u\n", e.activo);
    printf("Bloqueado: %u\n", e.bloqueado);
    printf("Conectado: %u\n", e.conectado);
    printf("Tamano: %zu bytes\n", sizeof(e));
    return 0;
}