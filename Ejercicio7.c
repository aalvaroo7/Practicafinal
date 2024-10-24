
#include <stdio.h>

// Definimos la estructura arrayLength
struct arrayLength {
    int arrInt[10];  // Array de enteros con capacidad para 10 valores
    int arrSize;     // Numero de elementos en el array
    int arrAdd;      // Suma de los elementos en el array
};

// Creamos un alias para la estructura
typedef struct arrayLength arrayLength_t;

// Funcion para inicializar el array
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

// Funcion para imprimir el contenido de la estructura
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

// Funcion para anadir un elemento al array
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

// Funcion para obtener el numero de elementos en el array
int getArrSize(const arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Devolvemos -1 si el puntero es nulo
    }
    return arr->arrSize;  // Devolvemos el numero de elementos en el array
}

// Funcion para obtener la suma de los elementos en el array
int getArrAdd(const arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Devolvemos -1 si el puntero es nulo
    }
    return arr->arrAdd;  // Devolvemos la suma de los elementos en el array
}

// Funcion para obtener un elemento del array
int getElement(const arrayLength_t *arr, int position) {
    if (arr == NULL || position < 0 || position >= 10) {
        return -1;  // Devolvemos -1 si el puntero es nulo o la posicion esta fuera de los limites
    }
    if (arr->arrInt[position] <= 0) {
        return -1;  // Devolvemos -1 si el valor en la posicion no es positivo
    }
    return arr->arrInt[position];  // Devolvemos el valor en la posicion especificada
}

// Funcion para establecer un elemento en el array
int setElement(arrayLength_t *arr, int position, int newValue) {
    if (arr == NULL || position < 0 || position >= 10 || newValue <= 0) {
        return -1;  // Devolvemos -1 si el puntero es nulo, la posicion esta fuera de los limites, o el nuevo valor no es positivo
    }
    if (arr->arrInt[position] <= 0) {
        return -1;  // Devolvemos -1 si el valor en la posicion no es positivo
    }
    // Actualizamos arrAdd restando el valor antiguo y sumando el nuevo valor
    arr->arrAdd = arr->arrAdd - arr->arrInt[position] + newValue;
    // Establecemos el nuevo valor en la posicion especificada
    arr->arrInt[position] = newValue;
    return 0;  // Devolvemos 0 si la operacion fue exitosa
}

int main() {
    arrayLength_t arr;
    // Inicializamos el array y comprobamos si ha habido errores
    if (initArray(&arr) != 0) {
        printf("Error en inicializacion\n");
    } else {
        printf("Array inicializado\n");
    }
    printArr(&arr);  // Deberia imprimir: {[-1, -1, -1, -1, -1, -1, -1, -1, -1, -1], 0, 0}

    // Anadimos un elemento y comprobamos si ha habido errores
    if (addElement(&arr, 22) == 0) {
        printf("Elemento anadido\n");
    } else {
        printf("Error al anadir elemento\n");
    }
    printArr(&arr);  // Deberia imprimir: {[22, -1, -1, -1, -1, -1, -1, -1, -1, -1], 1, 22}

    // Anadimos otro elemento y comprobamos si ha habido errores
    if (addElement(&arr, 44) == 0) {
        printf("Elemento anadido\n");
    } else {
        printf("Error al anadir elemento\n");
    }
    printArr(&arr);  // Deberia imprimir: {[22, 44, -1, -1, -1, -1, -1, -1, -1, -1], 2, 66}

    // Obtenemos y mostramos el numero de elementos en el array
    int size = getArrSize(&arr);
    if (size != -1) {
        printf("Numero de elementos en el array: %d\n", size);
    } else {
        printf("Error: puntero nulo\n");
    }

    // Obtenemos y mostramos la suma de los elementos en el array
    int sum = getArrAdd(&arr);
    if (sum != -1) {
        printf("Suma de los elementos en el array: %d\n", sum);
    } else {
        printf("Error: puntero nulo\n");
    }

    // Obtenemos y mostramos el valor de un elemento en una posicion especifica
    int element = getElement(&arr, 1);
    if (element != -1) {
        printf("Elemento en la posicion 1: %d\n", element);
    } else {
        printf("Error: posicion fuera de limites o valor no positivo\n");
    }

    // Establecemos un nuevo valor en una posicion especifica y comprobamos si ha habido errores
    if (setElement(&arr, 1, 55) == 0) {
        printf("Elemento establecido\n");
    } else {
        printf("Error al establecer elemento\n");
    }
    printArr(&arr);  // Deberia imprimir: {[22, 55, -1, -1, -1, -1, -1, -1, -1, -1], 2, 77}

    return 0;
}