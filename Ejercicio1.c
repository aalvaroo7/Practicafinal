#include <stdio.h>

// Declaración de la estructura
struct arrayLength {
    int arrInt[10];  // Array de enteros positivos con capacidad para 10 valores
    int arrSize;     // Número de elementos almacenados en el array
    int arrAdd;      // Suma de los elementos contenidos en el array
};

// Definición del alias utilizando typedef
typedef struct arrayLength arrayLength_t;

int main() {
    // Ejemplo de uso de la estructura
    arrayLength_t myArray;
    myArray.arrSize = 0;
    myArray.arrAdd = 0;

    // Inicialización del array con algunos valores
    for (int i = 0; i < 10; ++i) {
        myArray.arrInt[i] = i + 1;
        myArray.arrSize++;
        myArray.arrAdd += myArray.arrInt[i];
    }

    // Imprimir los valores
    printf("Array Size: %d\n", myArray.arrSize);
    printf("Array Sum: %d\n", myArray.arrAdd);

    return 0;
}
