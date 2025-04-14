#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLUMNS 50

// Prototipos de funciones
void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas);
void mostrarMatrizEnteros(int matriz[ROWS][COLUMNS], int filas, int columnas);
float promedioMatrizEnteros (int matriz[ROWS][COLUMNS], int filas, int columnas);
int buscarElementoEnMatriz(int matriz[ROWS][COLUMNS], int filas, int columnas, int dato);
int menu();

int main(int argc, char *argv[])
{
    int selected;

    int matrizEnterosVacia[ROWS][COLUMNS];
    int filas = 0;
    int columnas = 0;

    int matrizEnterosCargada[ROWS][COLUMNS]=
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int filasEnterosCargada=3;
    int columnasEnterosCargada=4;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            cargaMatrizEnteros(matrizEnterosVacia, &filas, &columnas);
            system("PAUSE");
            break;
        case 2:
            cargaMatrizEnteros(matrizEnterosVacia, &filas, &columnas);
            mostrarMatrizEnteros(matrizEnterosVacia, filas, columnas);
            system("PAUSE");
            break;
        case 3:
            cargaMatrizEnterosRandom(matrizEnterosVacia,&filas, &columnas);
            mostrarMatrizEnteros(matrizEnterosVacia, filas, columnas);
            system("PAUSE");
            break;
        case 4:
        {
            mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            int suma = sumarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            printf("La suma de todos los elementos de la matriz es: %d\n", suma);  // A�adir %d para mostrar el valor
            system("PAUSE");
        }
        break;
        case 5:
        {
            mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            float promedio = promedioMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            printf("Promedio de los elementos de la matriz: %.2f \n",promedio);
            system("PAUSE");
        }
        break;
        case 6:{
            int dato=0;
            printf("Ingrese un dato a buscar en la matriz: ");
            scanf("%d",&dato);
            if(buscarElementoEnMatriz(matrizEnterosCargada,filasEnterosCargada,columnasEnterosCargada,dato)){
                printf("El elemento: %d se encuentra en la matriz. \n",dato);
                mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            } else{
                printf("El elemento: %d NO se encuentra en la matriz. \n",dato);
                mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            }
            system("PAUSE");
        }
            break;
            case 7:{

                system("PAUSE");
            }
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
    printf("\n1-Hacer una funci�n que reciba como par�metro una matriz de n�meros enteros y permita que el usuario ingrese valores al mismo por teclado. La funci�n debe cargar la matriz por completo.");
    printf("\n2- Hacer una funci�n que reciba como par�metro una matriz de n�meros enteros y la muestre por pantalla (en formato matricial).");
    printf("\n3- Hacer una funci�n que reciba como par�metro una matriz de n�meros enteros y que cargue la misma con n�meros aleatorios (sin intervenci�n del usuario). La funci�n debe cargar la matriz por completo.");
    printf("\n4- Hacer una funci�n tipo int que sume el contenido total de una matriz de n�meros enteros.");
    printf("\n5- Hacer una funci�n tipo float que calcule el promedio de una matriz de n�meros enteros.");
    printf("\n6- Hacer una funci�n que determine si un elemento se encuentra dentro de una matriz de n�meros enteros. La funci�n recibe la matriz y el dato a buscar.");
    printf("\n7- Hacer una funci�n que cargue un arreglo de palabras (strings). La funci�n debe retornar cuantas palabras se cargaron.  (puede ser a trav�s del par�metro como puntero).");
    printf("\n0- SALIR");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);

    return input;
}



/*
void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas)
{
    char opcion;
    int valor;
    int resultado;

    // Inicializar filas y columnas a 0
    *filas = 0;
    *columnas = 0;

    printf("Ingrese un valor para cargar la matriz \n");
    printf("Ingrese f para crear una nueva fila \n");
    printf("Ingrese n/N para terminar la carga \n");

    do
    {
        printf("Fila [%d] Columna [%d]: ", *filas, *columnas);

        // Intentar leer un n�mero entero
        resultado = scanf("%d", &valor);

        if (resultado == 1)
        {
            // Se ley� un n�mero correctamente
            matriz[*filas][*columnas] = valor;
            (*columnas)++;

            // Verificar si se alcanz� el l�mite de columnas
            if (*columnas >= COLUMNS)
            {
                printf("Se alcanz� el l�mite de columnas. Pasando a la siguiente fila.\n");
                (*filas)++;
                *columnas = 0;
            }
        }
        else
        {
            // Limpiar el buffer de entrada
            while(getchar() != '\n');

            printf("Ingrese 'f' para nueva fila, 'n' para terminar: ");
            opcion = getchar();
            while(getchar() != '\n'); // Limpiar el buffer despu�s de leer el car�cter

            if (opcion == 'f' || opcion == 'F')
            {
                // Crear nueva fila solo si hay datos en la fila actual
                if (*columnas > 0)
                {
                    (*filas)++;
                    *columnas = 0;
                    printf("Nueva fila iniciada.\n");
                }
                else
                {
                    printf("La fila actual est� vac�a. Ingrese al menos un valor.\n");
                }
            }
            else if (opcion == 'n' || opcion == 'N')
            {
                printf("Carga de matriz finalizada.\n");
                // Si hay datos en la �ltima fila, incrementar filas para contar correctamente
                if (*columnas > 0) {
                    (*filas)++;
                    *columnas = 0;
                }
                break;
            }
            else
            {
                printf("Opci�n no reconocida. Ingrese un n�mero, 'f' o 'n'.\n");
            }
        }
    }
    while (*filas < ROWS);

    // Verificar si se alcanzaron los l�mites
    if (*filas >= ROWS)
    {
        printf("Se alcanz� el l�mite de la matriz. Carga finalizada.\n");
    }
}
*/



void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas)
{
    printf("Ingrese dimension de la matriz a cargar \n");
    printf("Filas: ");
    scanf("%d", filas);
    printf("Columnas: ");
    scanf("%d", columnas);

    for(int i = 0; i < *filas; i++)
    {
        for(int j = 0; j < *columnas; j++)
        {
            printf("Fila[%d] Columna[%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


void mostrarMatrizEnteros(int matriz[ROWS][COLUMNS], int filas, int columnas)
{
    printf("Matriz [%d x %d]:\n", filas, columnas);

    for (int i = 0; i < filas; i++)
    {
        printf("| ");
        for (int j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i][j]); // %4d para alinear los n�meros
        }
        printf("|\n"); // Cierra la fila con | y un salto de l�nea
    }
}
void cargaMatrizEnterosRandom(int matriz[ROWS][COLUMNS], int *filas, int *columnas)
{
    // Inicializar la semilla para n�meros aleatorios
    srand(time(NULL));

    printf("Ingrese la dimension de la matriz a cargar: \n");
    printf("Filas: ");
    scanf("%d", filas);
    printf("Columnas: ");
    scanf("%d", columnas);

    for(int i = 0; i < *filas; i++)
    {
        for(int j = 0; j < *columnas; j++)
        {
            matriz[i][j] = rand() % 11;  // Genera n�meros entre 0 y 10
        }
    }
}

int sumarMatrizEnteros (int matriz[ROWS][COLUMNS], int filas, int columnas)
{
    int suma=0;

    for (int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            suma+=matriz[i][j];
        }
    }

    return suma;
}

float promedioMatrizEnteros (int matriz[ROWS][COLUMNS], int filas, int columnas)
{

    float suma=sumarMatrizEnteros(matriz,filas,columnas);

    float promedio=suma/(filas*columnas) ;



    return promedio;
}

int buscarElementoEnMatriz(int matriz[ROWS][COLUMNS], int filas, int columnas, int dato){
    int flag=0;

    for(int i =0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (dato==matriz[i][j]){
                flag=1;
            }
        }
    }


    return flag;
}
