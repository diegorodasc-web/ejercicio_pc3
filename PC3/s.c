#include <stdio.h>

typedef struct {
    int codigo;
    char nombre[30];
    float promedio;
} Estudiante;

// 1. Función para GUARDAR (escribe un arreglo de estructuras)
void guardarEstudiantes(const char *nombreArchivo, Estudiante *lista, int n) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return;
    }
    // Escribe los 'n' estudiantes de golpe en el archivo binario
    fwrite(lista, sizeof(Estudiante), n, archivo);
    fclose(archivo);
}

// 2. Función para LEER todo el archivo
void leerEstudiantes(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    Estudiante e;

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("\n--- LISTADO DESDE ARCHIVO ---\n");
    while (fread(&e, sizeof(Estudiante), 1, archivo) == 1) {
        printf("Codigo: %d | Nombre: %s | Promedio: %.2f\n", e.codigo, e.nombre, e.promedio);
    }
    fclose(archivo);
}

// 3. Función para MODIFICAR un registro específico por código
void modificarPromedio(const char *nombreArchivo, int codigoBuscado, float nuevoPromedio) {
    FILE *archivo = fopen(nombreArchivo, "rb+"); // rb+ permite leer y escribir sin borrar
    Estudiante e;
    int encontrado = 0;

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fread(&e, sizeof(Estudiante), 1, archivo) == 1) {
        if (e.codigo == codigoBuscado) {
            e.promedio = nuevoPromedio;

            // Retroceder 1 estructura hacia atrás para sobrescribir la correcta
            fseek(archivo, -(long)sizeof(Estudiante), SEEK_CUR);
            fwrite(&e, sizeof(Estudiante), 1, archivo);

            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("\nPromedio actualizado correctamente.\n");
    } else {
        printf("\nEstudiante no encontrado.\n");
    }

    fclose(archivo);
}

int main() {
    Estudiante grupo[3] = {
        {1001, "Juan Perez", 18.5},
        {1002, "Maria Lopez", 17.0},
        {1003, "Carlos Ruiz", 16.5}
    };

    // Guardar en archivo binario
    guardarEstudiantes("estudiantes.dat", grupo, 3);

    // Leer contenido original
    leerEstudiantes("estudiantes.dat");

    // Modificar la nota de Maria Lopez (código 1002)
    modificarPromedio("estudiantes.dat", 1002, 19.5);

    // Leer nuevamente para comprobar el cambio
    leerEstudiantes("estudiantes.dat");

    return 0;
}
