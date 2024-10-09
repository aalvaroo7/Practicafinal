#include <stdio.h>

// Declaración de la estructura
struct arrayLength {
    int arrInt[10];  // Array de enteros positivos con capacidad para 10 valores
    int arrSize;     // Número de elementos almacenados en el array
    int arrAdd;      // Suma de los elementos contenidos en el array
};

// Definición del alias utilizando typedef
typedef struct arrayLength arrayLength_t;

// Función para inicializar el array
int initArray(arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Error: puntero nulo
    }
    for (int i = 0; i < 10; ++i) {
        arr->arrInt[i] = -1;  // Inicializar todas las posiciones a -1
    }
    arr->arrSize = 0;  // Inicializar arrSize a 0
    arr->arrAdd = 0;   // Inicializar arrAdd a 0
    return 0;  // Éxito
}

// Función para imprimir el contenido de la estructura
void printArr(const arrayLength_t *arr) {
    if (arr == NULL) {
        return;  // Error: puntero nulo
    }
    printf("{[");
    for (int i = 0; i < 10; ++i) {
        printf("%d", arr->arrInt[i]);
        if (i < 9) {
            printf(", ");
        }
    }
    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd);
}

int main() {
    arrayLength_t myArray;
    if (initArray(&myArray) == 0) {
        printArr(&myArray);  // Debería imprimir: {[-1, -1, -1, -1, -1, -1, -1, -1, -1, -1], 0, 0}
    } else {
        printf("Error al inicializar el array.\n");
    }
    return 0;
}