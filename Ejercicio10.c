#include <stdio.h>

// Definimos la estructura arrayLength
struct arrayLength {
    int arrInt[10];  // Array de enteros con capacidad para 10 valores
    int arrSize;     // Número de elementos en el array
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
    // Añadimos el nuevo valor en la siguiente posición disponible
    arr->arrInt[arr->arrSize] = newValue;
    // Incrementamos el tamaño del array
    arr->arrSize++;
    // Actualizamos la suma de los elementos
    arr->arrAdd += newValue;
    return 0;  // Devolvemos 0 si todo ha ido bien
}

// Función para obtener el número de elementos en el array
int getArrSize(const arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Devolvemos -1 si el puntero es nulo
    }
    return arr->arrSize;  // Devolvemos el número de elementos en el array
}

// Función para obtener la suma de los elementos en el array
int getArrAdd(const arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Devolvemos -1 si el puntero es nulo
    }
    return arr->arrAdd;  // Devolvemos la suma de los elementos en el array
}

// Función para obtener un elemento del array
int getElement(const arrayLength_t *arr, int position) {
    if (arr == NULL || position < 0 || position >= 10) {
        return -1;  // Devolvemos -1 si el puntero es nulo o la posición está fuera de los límites
    }
    if (arr->arrInt[position] <= 0) {
        return -1;  // Devolvemos -1 si el valor en la posición no es positivo
    }
    return arr->arrInt[position];  // Devolvemos el valor en la posición especificada
}

// Función para establecer un elemento en el array
int setElement(arrayLength_t *arr, int position, int newValue) {
    if (arr == NULL || position < 0 || position >= 10 || newValue <= 0) {
        return -1;  // Devolvemos -1 si el puntero es nulo, la posición está fuera de los límites, o el nuevo valor no es positivo
    }
    if (arr->arrInt[position] <= 0) {
        return -1;  // Devolvemos -1 si el valor en la posición no es positivo
    }
    // Actualizamos arrAdd restando el valor antiguo y sumando el nuevo valor
    arr->arrAdd = arr->arrAdd - arr->arrInt[position] + newValue;
    // Establecemos el nuevo valor en la posición especificada
    arr->arrInt[position] = newValue;
    return 0;  // Devolvemos 0 si la operación fue exitosa
}

// Función para resetear el array
void resetArr(arrayLength_t *arr) {
    if (arr == NULL) {
        return;  // No hacemos nada si el puntero es nulo
    }
    // Inicializamos todas las posiciones del array a -1
    for (int i = 0; i < 10; ++i) {
        arr->arrInt[i] = -1;
    }
    // Inicializamos arrSize y arrAdd a 0
    arr->arrSize = 0;
    arr->arrAdd = 0;
}

int main() {
    // a) Declarar dos estructuras de tipo arrayLength_t de nombre al1 y al2
    arrayLength_t al1, al2;

    // Inicializar ambos arrays
    initArray(&al1);
    initArray(&al2);

    // b) Hacer que el array de al1 almacene los valores 0, 10, 20, ..., 90
    for (int i = 0; i < 10; ++i) {
        addElement(&al1, i * 10);
    }

    // c) Mostrar la estructura almacenada en al1
    printArr(&al1);

    // d) Actualizar las posiciones impares del array para que almacenen 1, 3, 5, 7, 9
    for (int i = 1; i < 10; i += 2) {
        setElement(&al1, i, i);
    }

    // e) Mostrar de nuevo la estructura
    printArr(&al1);

    // f) Añadir al array de al2 las posiciones pares del array al1
    for (int i = 0; i < 10; i += 2) {
        addElement(&al2, al1.arrInt[i]);
    }

    // g) Actualizar las posiciones finales del array de al2 para que almacenen los valores de 0 a 4
    for (int i = al2.arrSize; i < 10; ++i) {
        addElement(&al2, i - al2.arrSize);
    }

    // h) Mostrar la estructura al2
    printArr(&al2);

    return 0;
}