#include <stdio.h>

// Definimos la estructura arrayLength
// Esto representa la estructura de datos, similar a la forma en que se organizan datos en la memoria principal.
// En un sistema operativo, la memoria se asigna de manera estructurada para cada proceso; de igual forma,
// esta estructura organiza y asigna memoria para almacenar datos, controlando el tamaño y la suma de los elementos.
struct arrayLength {
    int arrInt[10];  // Array de enteros con capacidad para 10 valores. Ejemplo de organización de datos en un bloque continuo de memoria.
    int arrSize;     // Número de elementos actuales en el array, manteniendo un estado sobre el tamaño en uso.
    int arrAdd;      // Suma de los elementos en el array, análoga a un registro de estado acumulativo.
};

// Creamos un alias para la estructura
typedef struct arrayLength arrayLength_t;

// Función para inicializar el array
// initArray actúa como una "función de biblioteca" que permite preparar y gestionar la estructura de datos
// de forma que el programador no necesita gestionar directamente la memoria.
int initArray(arrayLength_t *arr) {
    if (arr == NULL) {
        return -1;  // Validación para evitar errores de memoria, devolviendo -1 si el puntero es nulo.
    }
    // Inicializamos todas las posiciones del array a -1
    // Esto establece un valor por defecto, gestionando la memoria para evitar valores residuales.
    for (int i = 0; i < 10; ++i) {
        arr->arrInt[i] = -1;
    }
    // Inicializamos arrSize y arrAdd a 0
    // Asignación inicial para tener control de estado, similar a los registros en una CPU.
    arr->arrSize = 0;
    arr->arrAdd = 0;
    return 0;  // Devolvemos 0 si todo ha ido bien
}

// Función para imprimir el contenido de la estructura
// Aunque no hay interacción directa con el usuario, la impresión de resultados muestra el estado actual de la estructura,
// ofreciendo una forma de comunicación entre el programa y el usuario, similar a una interfaz en un sistema operativo.
void printArr(const arrayLength_t *arr) {
    if (arr == NULL) {
        return;  // Validación del puntero, evitando errores de memoria.
    }
    printf("{[");
    // Imprimimos cada elemento del array
    // Bucle for para recorrer secuencialmente el array, un ejemplo de flujo de control en programación.
    for (int i = 0; i < 10; ++i) {
        printf("%d", arr->arrInt[i]);
        if (i < 9) {
            printf(", ");
        }
    }
    // Imprimimos arrSize y arrAdd, que son el estado actual del array.
    printf("], %d, %d}\n", arr->arrSize, arr->arrAdd);
}

// Función para añadir un elemento al array
// addElement es otra "función de biblioteca" que sirve como interfaz para la manipulación de la estructura de datos
// y libera al programador de realizar la gestión directa de la memoria, de forma similar a cómo las funciones
// del sistema operativo permiten trabajar con datos sin necesidad de saber el detalle de su almacenamiento.
int addElement(arrayLength_t *arr, int newValue) {
    if (arr == NULL || newValue < 0) {
        return -1;  // Validación del puntero y el valor, para evitar errores y preservar el estado adecuado.
    }
    if (arr->arrSize >= 10) {
        return -1;  // Validación para evitar sobrepasar la capacidad del array.
    }
    // Añadimos el nuevo valor en la siguiente posición disponible
    arr->arrInt[arr->arrSize] = newValue;
    // Incrementamos el tamaño del array
    arr->arrSize++;  // Actualización del estado, como un registro de estado en hardware.
    // Actualizamos la suma de los elementos
    arr->arrAdd += newValue;  // Mantener la suma de elementos refleja cómo el estado se mantiene en memoria.
    return 0;  // Devolvemos 0 si todo ha ido bien
}

// Función para establecer un elemento en el array
// setElement también actúa como una interfaz modular que permite modificar datos sin necesidad de manejar
// directamente la memoria, simplificando el trabajo del programador y reflejando cómo las funciones de alto nivel
// en un sistema operativo permiten la interacción indirecta con la memoria.
int setElement(arrayLength_t *arr, int position, int newValue) {
    if (arr == NULL || position < 0 || position >= 10 || newValue < 0) {
        return -1;  // Validación del puntero, posición y valor para evitar errores de memoria.
    }
    // Actualizamos arrAdd restando el valor actual antes de cambiarlo
    if (arr->arrInt[position] != -1) {
        arr->arrAdd -= arr->arrInt[position];
    }
    // Actualizamos arrAdd sumando el nuevo valor
    arr->arrAdd += newValue;
    // Establecemos el nuevo valor en la posición especificada
    arr->arrInt[position] = newValue;  // Gestión de memoria para asignar el valor en una posición específica.
    return 0;  // Devolvemos 0 si la operación fue exitosa
}

int main() {
    // a) Declarar dos estructuras de tipo arrayLength_t de nombre al1 y al2
    // Ejemplo de creación de instancias de estructuras en memoria principal.
    arrayLength_t al1, al2;

    // Inicializar al1 y al2
    initArray(&al1);
    initArray(&al2);

    // b) Almacenar en al1 los valores 0, 10, 20, ..., 90
    // Se emplea un bucle para asignar valores secuenciales, un ejemplo de control de flujo.
    for (int i = 0; i < 10; ++i) {
        addElement(&al1, i * 10);
    }

    // c) Mostrar la estructura almacenada en al1
    printArr(&al1);

    // d) Actualizar las posiciones impares del array para que almacenen, respectivamente, los valores 1, 3, 5, 7 y 9
    // Utilización de un bucle for para modificar elementos específicos, aplicando modularidad y flujo de control.
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
    for (int i = al2.arrSize; i < 10 && i < al2.arrSize + 5; ++i) {
        setElement(&al2, i, i - al2.arrSize);
    }

    // h) Mostrar la estructura al2
    printArr(&al2);

    return 0;
}