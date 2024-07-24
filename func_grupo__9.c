/* 
*@autor/es: Paul Danilo Navarro Estigarribia
*/

#include "func_grupo_9.h"

int vertices_normales(int tab[filas][columnas],int clave, int modo){
    int i,j,p,desplazamiento,breakOn = 0;
    for (i = 0 ; i < 9; i++){
        for (j = 0; j < 9; j++){
            if( tab[i][j] == clave ){
                p = j;
                do{
                    do{
                        p++;
                        if(p > 9){
                            break;
                        }
                    }while(  p < 10 && tab[i][p] != clave   );
                    if(p > 9){
                        break;
                    }
                    if (tab[i][p] == clave){
                        desplazamiento = p-j;
                        if(  ( (p-desplazamiento) >= 0 ) && ( ( i + desplazamiento ) < 10) ){
                            if(  tab[i+desplazamiento][p] == clave && tab[i+desplazamiento][j] == clave){
                                if (modo == 1){
                                    coordenada_x_normal[0] = i; coordenada_x_normal[1] = i; coordenada_x_normal[2] = i+desplazamiento; coordenada_x_normal[3] = i+desplazamiento; coordenada_y_normal[0] = j; coordenada_y_normal[1] = p; coordenada_y_normal[2] = p; coordenada_y_normal[3] = j; cuadradoNormalDetect = 1;
                                }
                                breakOn = 1;
                                return breakOn;
                            }
                        }
                    }
                } while( p < 10);     
            }
        } 
    }
    return breakOn;
}  
int vertices_inclinados(int tablero[filas][columnas],int clave, int modo){
    short int i,j,p,breakOn=0;
    short int auxX,auxY;
    for(i = 0; i < 9 ;i++){

        for(j = 0 ;j < 9; j++){
            p = 0;
            if(tablero[i][j] == clave){
                do{
                    do{
                        p++;
                        if(i + p > 9 || j + p > 9){
                            break;
                        }
                    } while (tablero[ i + p][ j + p ] != clave && p <= 4 );
                    if(i + p > 9 || j + p >9){
                        break;
                    }
                    if(  ( ( p + i) < 10) && ( ( p + j ) < 10 ) ){
                        if(tablero[ i + p][ j + p] == clave){
                            auxX = i + p;
                            auxY = j + p;
                            if( ( (auxX + p) < 10) && ( ( j - p ) >= 0)){
                                if (tablero[p + auxX][j] == clave && tablero[auxX][j - p] == clave){

                                    if (modo == 1){
                                        coordenada_x_inclinada[0] = i; coordenada_x_inclinada[1] = i + p ; coordenada_x_inclinada[2] = auxX + p; coordenada_x_inclinada[3] = i + p; coordenada_y_inclinada[0] = j; coordenada_y_inclinada[1] = j + p; coordenada_y_inclinada[2] = j ; coordenada_y_inclinada[3] = j - p;
                                        cuadradoInclinadoDetect = 1;
                                    }

                                    breakOn = 1;
                                    return breakOn;
                                }
                            }   
                        
                        }
                   
                    }


                }while( p <= 4);


            }

        }

    }
    return breakOn;
}


int ultimo_punt(int tablero[filas][columnas], int jugador, int x, int y){
    int i,j;
    int cambio;
    int t2[filas][columnas] = {0};
    copy_mat(tablero,t2);
    for(i = 0; i < 10; i++){
        for( j = 0;j < 10; j++){
            cambio = 0;
            if(i != x && j != y){
                if(t2[i][j]==0){
                    t2[i][j] = jugador;
                    cambio = 1;
                }
                if (cambio == 1){
                    if(vertices_normales(t2,jugador,0) || vertices_inclinados(t2,jugador,0)){
                        t2[i][j] = 0;
                    }else{
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}


                                            

