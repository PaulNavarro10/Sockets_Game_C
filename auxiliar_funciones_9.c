/* 
*@autor/es: Paul Danilo Navarro Estigarribia
*/
#include "func_grupo_9.h"

int Hora_Segundos(char *marca_temporal){ 
    
    char  hora_char[20] , minuto_char[20] , segundos_char[20],marcatempaux[100], *horario;
    int   contador = 0, hora , minuto, segundos, segundos_total;
    strcpy(marcatempaux,marca_temporal);

    horario = strtok( marcatempaux, ":" );
    while ( horario != NULL ) {
        contador++;
        switch (contador) {
                case 1:
                     strcpy(hora_char,horario);
                    break;
                case 2:
                    strcpy(minuto_char,horario);
                    break;
                case 3:
                    strcpy(segundos_char,horario);
                    break;
            }

        horario = strtok( NULL, ":" );
    }

    hora = atoi(hora_char);
    minuto = atoi(minuto_char);     
    segundos = atoi(segundos_char);
    segundos_total = (hora * 3600) + (minuto * 60) + segundos;

    return segundos_total;

}


void obtener_hora(char hora[80]){
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    strftime( cad, 80, "%H:%M:%S", tmPtr ); 
    strcpy(hora,cad);
}

void generarNombre(){
    char auxiliar[100] = "\\std_";
    char ide[10];
    strcat(auxiliar,program);
    strcat(auxiliar,"_grupo_");
    sprintf(ide,"%d", origin);
    strcat(auxiliar,ide);
    strcat(auxiliar,".txt");
    strcat(rutaArchivo,auxiliar);
}

void ajuste_de_local(){
    modus_active = "Local";
    LocalMode = true;
    VisitMode = false;
    usuario = "1";
    Jugador = 1;
    versus = 2;
    strcpy(program,"servidor");
}

void ajuste_de_visita(){
    LocalMode = false;
    VisitMode = true;
    usuario = "2";
    Jugador = 2;
    versus = 1;
    strcpy(program,"cliente");
    modus_active = "Visita";
}


void empezar_cero(){

    cuadradoNormalDetect = 0;
    cuadradoInclinadoDetect = 0;
    duracion_total_jugador2 = 0.0;
    duracion_total_jugador1 = 0.0;
    jugadasTotales_1 = 0;
    jugadasTotales_2 = 0;
    FALLA = 0;
    id = 0;
    jugada = 0;
    int i = 0,j = 0;
    for(i = 0; i < 10 ;i++){
        for(j = 0; j < 10 ; j++){
            tab_juego[i][j] = 0;
        }
    }
    for(i = 0; i < 4; i++){
        coordenada_x_inclinada[i] = 0;
        coordenada_y_inclinada[i] = 0;
        coordenada_x_normal[i] = 0;
        coordenada_y_normal[i] = 0;
    }
    for(int u = 0; u < 10; u++){
        failMensaje[u] = 0;
    }
}

void copy_mat(int m1[filas][columnas], int m2[filas][columnas]){ 
    short int i,j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            m2[i][j] = m1[i][j];
        }
    }
}

