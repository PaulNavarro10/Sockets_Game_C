/* 
*@autor/es: Paul Danilo Navarro Estigarribia
*/
#include "func_grupo_9.h"

int inteligencia_artificial(int tablero[filas][columnas], int jugador, int contrario){ 
    int jugadaTerminada;
    int x,y;
    int ganador = 0;
    bool cambio;
    char hora[80];
    char horaAux[80];
    obtener_hora(hora);
    int tiempoinicial = Hora_Segundos(hora);
    int tiemposecundario;
    srand(time(NULL));
    do{
        cambio = false;
        jugadaTerminada = 1;
        x = rand()%10;
        y = rand()%10;
        if (tablero[x][y]==0){
            tablero[x][y] = jugador;
            cambio = true;
            obtener_hora(horaAux);
            tiemposecundario = Hora_Segundos(horaAux);
            if((tiemposecundario-tiempoinicial)>1){
                break;
            }
        }else{
            jugadaTerminada = 0;
        }
        if( vertices_normales(tablero,jugador,0)){
            tablero[x][y] = 0;
            if(ultimo_punt(tablero,jugador,-1,-1)==0){
                ganador = contrario;
                break;
            }
            jugadaTerminada = 0;

        }else if (vertices_inclinados(tablero,jugador,0) ){
            tablero[x][y] = 0;
            if(ultimo_punt(tablero,jugador,-1,-1)==0){
                ganador = contrario;
                break;
            }
            jugadaTerminada = 0;
        }

    } while (jugadaTerminada == 0);
    xGrupo = x + 1;
    yGrupo = y + 1;
    if(ganador == contrario){
        tablero[x][y] = jugador;
    }
    return ganador;
}
