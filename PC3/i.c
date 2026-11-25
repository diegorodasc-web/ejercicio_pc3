#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};
int main() {
    struct Nodo *n1 = malloc(sizeof(struct Nodo));
    struct Nodo *n2 = malloc(sizeof(struct Nodo));
    struct Nodo *n3 = malloc(sizeof(struct Nodo));
    if (n1 == NULL || n2 == NULL || n3 == NULL) {
        free(n1);
        free(n2);
        free(n3);
        return 1;
    }
    n1->dato = 10;
    n2->dato = 20;
    n3->dato = 30;
    n1->siguiente = n2;
    n2->siguiente = n3;
    n3->siguiente = NULL;
    struct Nodo *actual = n1;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
    free(n1);
    free(n2);
    free(n3);
    return 0;
}
