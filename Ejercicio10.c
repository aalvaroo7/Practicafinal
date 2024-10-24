#include <stdio.h>

// Definimos la estructura arrayLength
struct arrayLength {
    int arrInt[10];  // Array de enteros con capacidad para 10 valores
    int arrSize;     // Numero de elementos en el array
    int arrAdd;      // Suma de los elementos en el array
};

// Creamos un alias para la estructura
typedef struct arrayLength arrayLength_t;

// Función para inicializar el array
int initArray(arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Devolvemos -1 si el puntero es nulo
    }
    // Inicializamos todas las posiciones del array a -1
    for (int i = 0; i < 10; ++i) {
        arr->arrInt[i] = -1;
    }
    // Inicializamos arrSize y arrAdd a 0
    arr->arrSize = 0;
    arr->arrAdd = 0;
    return 0;  // Devolvemos 0 si todo ha ido bien
}

// Función para imprimir el contenido de la estructura
void printArr(const arrayLength_t *arr) {
    if (arr == NULL) {
        return;  // No hacemos nada si el puntero es nulo
    }
    printf("{[");
    // Imprimimos cada elemento del array
    for (int i = 0; i < 10; ++i) {
        printf("%d", arr->arrInt[i]);
        if (i < 9) {
            printf(", ");
        }
    }
    // Imprimimos arrSize y arrAdd
    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd);
}

// Función para añadir un elemento al array
int addElement(arrayLength_t *arr, int newValue) {
    if (arr == NULL || newValue <= 0) {
        return -1;  // Devolvemos -1 si el puntero es nulo o el valor no es positivo
    }
    if (arr->arrSize >= 10) {
        return -1;  // Devolvemos -1 si no hay espacio en el array
    }
    // Anadimos el nuevo valor en la siguiente posicion disponible
    arr->arrInt[arr->arrSize] = newValue;
    // Incrementamos el tamano del array
    arr->arrSize++;
    // Actualizamos la suma de los elementos
    arr->arrAdd += newValue;
    return 0;  // Devolvemos 0 si todo ha ido bien
}

// Función para establecer un elemento en el array
int setElement(arrayLength_t *arr, int position, int newValue) {
    if (arr == NULL || position < 0 || position >= 10 || newValue <= 0) {
        return -1;  // Devolvemos -1 si el puntero es nulo, la posicion esta fuera de los limites, o el nuevo valor no es positivo
    }
    // Actualizamos arrAdd restando el valor antiguo y sumando el nuevo valor
    arr->arrAdd = arr->arrAdd - arr->arrInt[position] + newValue;
    // Establecemos el nuevo valor en la posicion especificada
    arr->arrInt[position] = newValue;
    return 0;  // Devolvemos 0 si la operacion fue exitosa
}

int main() {
    arrayLength_t al1, al2;

    // Inicializamos al1 y al2
    initArray(&al1);
    initArray(&al2);

    // a) Almacenar los valores 0, 10, 20, ..., 90 en al1
    for (int i = 0; i < 10; ++i) {
        addElement(&al1, i * 10);
    }

    // b) Mostrar la estructura almacenada en al1
    printf("al1 after initialization:\n");
    printArr(&al1);

    // c) Actualizar las posiciones impares del array al1
    for (int i = 1; i < 10; i += 2) {
        setElement(&al1, i, i);
    }

    // d) Mostrar de nuevo la estructura al1
    printf("al1 after updating odd positions:\n");
    printArr(&al1);

    // e) Añadir las posiciones pares de al1 a al2
    for (int i = 0; i < 10; i += 2) {
        addElement(&al2, al1.arrInt[i]);
    }

    // f) Actualizar las posiciones finales de al2 con valores 0 a 4
    for (int i = al2.arrSize; i < 10 && i < al2.arrSize + 5; ++i) {
        setElement(&al2, i, i - al2.arrSize);
    }

    // g) Mostrar la estructura al2
    printf("al2 after adding even positions and updating final positions:\n");
    printArr(&al2);

    return 0;
}