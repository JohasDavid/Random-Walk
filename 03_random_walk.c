#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 10
#define COLUMNAS 10

int main(){
    int step = 0;
    char letra = 'A';
    char tablero[FILAS][COLUMNAS];
    int fila = 0, columna = 0;
    int i_d = 0, i_i = 0, i_a = 0, i_ab = 0;

    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            tablero[i][j] = '.'; 
        }
    }

    srand((unsigned) time(NULL));

    for (int k = 0; k < 26; ){
        
        if (tablero[fila][columna] == '.'){
            tablero[fila][columna] = letra;
            letra += 1;
            k++;
            i_d = i_i = i_a = i_ab = 0;
        }

        step = rand() % 4;


        if (step == 0){
            if (fila != 0){
                fila -= 1;
                if (tablero[fila][columna] != '.'){
                    i_a = 1;
                    fila +=1;
                }
            } else {
                i_a = 1;
            }
        }


        if(step == 1){
            if(columna != 0){
                columna -= 1;
                if(tablero[fila][columna] != '.'){
                    i_i = 1;
                    columna += 1;
                }
            } else{
                i_i = 1;
            }
        }

        if (step == 2){
            if (columna != 9){
                columna += 1;
                if (tablero[fila][columna] != '.'){
                    i_d = 1;
                    columna -= 1;
                }
            } else {
                i_d = 1;
            }
        }

        if(step == 3){
            if(fila != 9){
                fila += 1;
                if(tablero[fila][columna] != '.'){
                    i_ab = 1;
                    fila -= 1;
                }
            } else {
                i_ab = 1;
            }
        }

        if ((i_a == 1) && (i_ab == 1) && (i_d == 1) && (i_i == 1)){
            break;
        }
    }
    
    printf("\n\n");
   for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            printf("%c ", tablero[i][j]); 
        }
        printf("\n");
   }

   printf("\n\n");

    return 0;
}