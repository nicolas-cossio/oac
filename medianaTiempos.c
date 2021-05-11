// Este codigo permitirá hallar la mediana de los elementos de un arreglo de tamaño N

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (1024*1024*128)

void func1(int*);
double obtenerMed(double *, int);

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double cpu_time;
    int tamArr = 100;
    double arrC[tamArr], arrC2[tamArr], tMedC1, tMedC2;

    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));

    // Llenamos el primer arreglo
    for (int i = 0; i < tamArr; i++)
    {
        //Iniciamos el contador del reloj
        start = clock();    
        
        func1(arr);
        //Finalizamos el contador del reloj
        end = clock();  
        //Hallamos el tiempo transcurrido y lo almacenamos
        arrC[i] = ((double) (end - start)) / CLOCKS_PER_SEC;   
        
    }
    
    tMedC1 = obtenerMed(arrC, tamArr); 
    printf("Median of the CPU time for loop 1 is: %.6f secs.\n", tMedC1);

    return 0;
}

void func1(int *arr){
    for (int i = 0; i < MAX_SIZE; i++)
        arr[i] *= 3;
}

// Obtenemos la mediana y la devolvemos
double obtenerMed(double *arr, int tamArr){
    int mitad = tamArr / 2;
    double temp, tMed;

    // Ordenamos el arreglo de menor a mayor
    for (int i = 0; i < tamArr; i++){
        for (int j = i + 1; j < tamArr; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    } 
    
    // Hallamos la mediana 
    if (tamArr % 2 == 0){   // Si es par
        tMed = (arr[mitad] + arr[mitad + 1]) / 2;
    }
    else //Caso impar
        tMed = arr[mitad];

    return tMed; 
}