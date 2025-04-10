#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLUMNS 50

// Prototipos de funciones
void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas);
void mostrarMatriz(int matriz[ROWS][COLUMNS], int filas, int columnas);
int menu();

int main(int argc, char *argv[])
{
    int selected;

    int matriz[ROWS][COLUMNS];
    int filas = 0;
    int columnas = 0;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            cargaMatrizEnteros(matriz, &filas, &columnas);
            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }
    }
    while(selected!=0);

    system("PAUSE");
    return 0;
}

int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe cargar la matriz por completo.");
    printf("\n0- SALIR");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    while(getchar() != '\n'); // Limpiar el buffer de entrada
    return input;
}


void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas)
{
    char opcion;
    int valor;
    int resultado;

    printf("Ingrese un valor para cargar la matriz \n");
    printf("Ingrese f para crear una nueva fila \n");
    printf("Ingrese n/N para terminar la carga \n");

    do {
        printf("Fila [%d] Columna [%d]: ", *filas, *columnas);

        // Intentar leer un número entero, scanf devuelve 1 si se leyo el dato correcto
        resultado = scanf("%d", &valor);

        if (resultado == 1) {
            // Se leyó un número correctamente
            matriz[*filas][*columnas] = valor;
            (*columnas)++;

            // Verificar si se alcanzó el límite de columnas
            if (*columnas >= COLUMNS) {
                printf("Se alcanzó el límite de columnas. Pasando a la siguiente fila.\n");
                (*filas)++;
                *columnas = 0;
            }
        } else {

            printf("Ingrese 'f' para nueva fila, 'n' para terminar: ");
            opcion = getchar();

            if (opcion == 'f' || opcion == 'F') {
                // Crear nueva fila solo si hay datos en la fila actual
                if (*columnas > 0) {
                    (*filas)++;
                    *columnas = 0;
                    printf("Nueva fila iniciada.\n");
                } else {
                    printf("La fila actual está vacía. Ingrese al menos un valor.\n");
                }
            } else if (opcion == 'n' || opcion == 'N') {
                printf("Carga de matriz finalizada.\n");
                break;
            } else {
                printf("Opción no reconocida. Ingrese un número, 'f' o 'n'.\n");
            }
        }
    } while (*filas < ROWS && *columnas < COLUMNS);

    // Verificar si se alcanzaron los límites
    if (*filas >= ROWS || *columnas >= COLUMNS) {
        printf("Se alcanzó el límite de la matriz. Carga finalizada.\n");
    }

}
