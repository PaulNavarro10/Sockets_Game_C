/* 
* UNIVERSIDAD NACIONAL DE ASUNCION
* Facultad Politécnica – Ingeniería en Informática
* Lenguaje de Programación I – Año 2022
*
*Descripción: Este trabajo práctico realizado será evaluado como el examen final de la asignatura.
*
*@autor/es: Tayhana Solange Galarza (Cédula de Identidad: 43.688.054)

*@id-grupo: 9
*@versión: 10.5
*@fecha y hora última actualización: martes, 13 de diciembre de 2022 14:22.                           
*/

#include "func_grupo_9.h"


char* mensaje( int id , char marca_temporal[80], int duracion,
                       char programa[100] , int origen ,int destino,
                       char evento[100], char estado[100] ,int jugada,
                       int turno, int x, int y,
                       int tablero[10][10]){
                        
    static char mensaje[1000]; 
    char temp[100],tablero_char[1000] = "["; 
    int k,j,tablero_tipo; 
                      
    if (tablero[0][0] == -1) {
        
        tablero_tipo = -1;

        } else{     

          tablero_tipo = 0;

        }

    if (tablero_tipo == 0) {
        
        for ( k = 0; k < 10; k++){

            for ( j = 0; j < 10; j++){

                sprintf(temp,"%d", tablero[k][j]);
                strcat(tablero_char,temp);

                if (k < 9 || j < 9){
                    strcat(tablero_char,",");
                }

                if (k == 9 && j == 9){
                    strcat(tablero_char,"]");
                }
            }

        }
   
    }
    
    
    if(id != -1){

        sprintf(temp,"%d;", id);    
        strcpy(mensaje,temp);
    
    } else{
        strcpy(mensaje,"*;");
    }

    strcat(mensaje,marca_temporal);

    if (duracion != -1)
    {
        sprintf(temp,";%d;", duracion);
        strcat(mensaje,temp);
    } else{
        strcat(mensaje,";*;");
    }
    
    strcat(mensaje,programa);

    if (origen != -1)
    {
        sprintf(temp,";%d;", origen); 
        strcat(mensaje,temp);
    
    }else{
        strcat(mensaje, ";*;");
    }

    if (destino != -1)
    {
        sprintf(temp,"%d;", destino);
        strcat(mensaje,temp);
    }else{
        strcat(mensaje,"*;");
    }
    
    strcat(mensaje,evento);
    strcat(mensaje,";");

    strcat(mensaje,estado);


    if (jugada != -1)
    {
        sprintf(temp,";%d;", jugada);
        strcat(mensaje,temp);
        
    }else{
        strcat(mensaje,";*;");
    }
    

    if (turno != -1)
    {
        sprintf(temp,"%d;", turno);
        strcat(mensaje,temp);       
    } else{
        strcat(mensaje,"*;");
    }
    
    if (x != -1)
    {
        sprintf(temp,"%d;", x);
        strcat(mensaje,temp); 
    } else{
        strcat(mensaje,"*;");
    }

    if (y != -1)
    {
        sprintf(temp,"%d;", y);
        strcat(mensaje,temp);       
    } else{
        strcat(mensaje, "*;");
    }
    
    if (tablero_tipo == 0)
    {
       strcat(mensaje,tablero_char);
    }

    if (tablero_tipo == -1)
    {
        strcat(mensaje,"*");
    }
    
    strcat(mensaje,";#.");

    mensaje[strlen(mensaje)] = '\0';

    return mensaje;

}

void fichero(char mensaje[1000],char *tipo_mensaje, int end_game){ 
 
    int i, contador = 0,j = 0,k,aux = 0,s_tablero,s_tablero_final,p = 0 , s = strlen(mensaje);
    char *trozos,id[10],duracion[10],origen[10],
    destino[10],jugada[10],turno[10],x[10],y[10],
    marca_temporal[100],programa[100],evento[100],
    estado[100],tablero[1000], tablero_final[1000],
    FDM[5],mensaje_final[1000]; 

     

    for (i = 0; i < s; i++){
        if (mensaje[i] != '#' && mensaje[i] != '"' && mensaje[i] != '.') {
            mensaje_final[j] = mensaje[i]; 
            j++;
        }

    }
    
    mensaje_final[j] = '\0'; 
    trozos = strtok( mensaje_final, ";" );

    while ( trozos != NULL ) {
        contador++;
        switch (contador) {
            case 1:
                strcpy(id,trozos);
                break;
            case 2:
                strcpy(marca_temporal,trozos);
                break;
            case 3:
                strcpy(duracion,trozos);
                break;
            case 4:
                strcpy(programa,trozos);
                break;
            case 5:
                strcpy(origen,trozos);
                break;
            case 6:
                strcpy(destino,trozos);
                break;
            case 7:
                strcpy(evento,trozos);
                break;
            case 8:
                strcpy(estado,trozos);
                break;
            case 9:
                strcpy(jugada,trozos);
                break;
            case 10:
                strcpy(turno,trozos);
                break;
            case 11:
                strcpy(x,trozos);
                break;
            case 12:
                strcpy(y,trozos);
                break;
            case 13:
                strcpy(tablero,trozos);
                s_tablero = strlen(tablero);
                break;
        }
        trozos = strtok( NULL, ";" );

    }

 
    FILE *ptrFILE;  
    
    if (  ( ptrFILE = fopen(rutaArchivo,"a") )== NULL)  
    {
        printf("El archivo no se pudo abrir");

    } else{

        if( end_game == 0){

            if(atoi(id) > 1){

             fprintf(ptrFILE,"\n");

            }
       
            fprintf(ptrFILE,"######Programa: [%s].",programa);
            fprintf(ptrFILE,"\nMensaje-id: [%s]. Marca-de-tiempo: [%s]. Duracion: [%s].",id,marca_temporal,duracion);
            fprintf(ptrFILE,"\nMensaje-tipo: {%s}. Mensaje-origen: [%s]. Mensaje-destino: [%s].",tipo_mensaje,origen,destino);
            fprintf(ptrFILE,"\nEvento: [%s]. Estado-juego: [%s]." ,evento,estado);
            fprintf(ptrFILE,"\n------------Turno-jugador: jugador-[%s]. Numero-jugadas: [%s]. ------------" ,turno,jugada);
            fprintf(ptrFILE,"\nCasilla-jugada: ([%s],[%s]).\nTablero-actual:\n\n",x,y);
        

            if (s_tablero > 2) {
                for (i = 0; i < s_tablero; i++) {
                    if (tablero[i] != ',' && tablero[i] != '[' && tablero[i] != ']'){
                        tablero_final[p] = tablero[i];
                        p++;

                    }

                }

                tablero_final[p] = '\0';
                s_tablero_final = strlen(tablero_final);  


                for ( i = 0; i < s_tablero_final; i++)
                {
                    aux++;  

                    fprintf(ptrFILE,"%2c", tablero_final[i]);

                    if (aux % 10 == 0 )
                    {
                        fprintf(ptrFILE, "\n"); 
                    }
                    
                }

            }
            
        } 

         if( strcmp( evento,"finalizar" ) == 0 && end_game == 1){
      
                fprintf(ptrFILE ,"====================fin del juego====================");
                fprintf(ptrFILE ,"\nGrupo-ganador: %d", id_Finally);
                fprintf(ptrFILE ,"\nJugador-ganador: %d.", final_ganador);
                fprintf(ptrFILE ,"\nModalidad-partida-ganada: %s.", Finally_modalidad);
                fprintf(ptrFILE ,"\nTotal-jugadas-jugador1: %d.", jugadasTotales_1);
                fprintf(ptrFILE ,"\nTotal-jugadas-jugador2: %d.", jugadasTotales_2);
                fprintf(ptrFILE ,"\nTiempo-promedio-jugadas-jugador1: %.2f segundos.", promedioTiempo1);
                fprintf(ptrFILE ,"\nTiempo-promedio-jugadas-jugador2: %.2f segundos.", promedioTiempo2);
                fprintf(ptrFILE ,"\nInicio-del-juego: %s.", tiempoInicialFinally);
                fprintf(ptrFILE ,"\nFinalizacion-del-juego: %s.", tiempoFinalFinally);
                fprintf(ptrFILE ,"\nDuracion-total-del-juego: %.2f segundos.", total_duracion);

                    switch (cuadradoNormalDetect) {
                    case 1:
                        fprintf(ptrFILE,"\nSe ha detectado un cuadrado normal!: (%d,%d) - (%d,%d) - (%d,%d) - (%d,%d).\n", coordenada_x_normal[0] + 1, coordenada_y_normal[0] + 1, coordenada_x_normal[1] + 1, coordenada_y_normal[1] + 1, coordenada_x_normal[2] + 1,coordenada_y_normal[2] + 1, coordenada_x_normal[3] + 1, coordenada_y_normal[3] + 1);   
                        break;
                    }
                    switch (cuadradoInclinadoDetect){
                    case 1:
                        fprintf(ptrFILE,"\nSe ha detectado un cuadrado inclinado!: (%d,%d) - (%d,%d) - (%d,%d) - (%d,%d).\n", coordenada_x_inclinada[0] + 1, coordenada_y_inclinada[0] + 1, coordenada_x_inclinada[1] + 1, coordenada_y_inclinada[1] + 1, coordenada_x_inclinada[2] + 1,coordenada_y_inclinada[2] + 1, coordenada_x_inclinada[3] + 1, coordenada_y_inclinada[3] + 1);   
                        break;
                    }
                        
         }

         fclose(ptrFILE); //Cerramos el archivo

        
    } 
    
}

void obtener_datos(char mensaje[1000]){ 


    char *trozos;
    int i, contador = 0,s,j = 0,k,id,duracion,origen,destino,jugada,turno,x,y,aux = 0,s_tablero,s_tablero_final,p = 0;
 
    char marca_temporal[100],programa[100],evento[100],estado[100],tablero[1000], tablero_final[1000],FDM[5],mensaje_final[1000]; 

    s = strlen(mensaje); 

      
    for (i = 0; i < s; i++)
    {
        if (mensaje[i] != '#' && mensaje[i] != '"' && mensaje[i] != '.')
        {
            mensaje_final[j] = mensaje[i]; 
            j++;
        }

    }

    mensaje_final[j] = '\0'; 
    trozos = strtok( mensaje_final, ";" );

        while ( trozos != NULL ) {            
            contador++;
            switch (contador) {
                case 1:
                    id = atoi(trozos);
                    break;
                case 2:
                    strcpy(marca_temporal,trozos);
                    break;
                case 3:
                    duracion = atoi(trozos);
                    break;
                case 4:
                    strcpy(programa,trozos);
                    break;
                case 5:
                    origen = atoi(trozos);
                    break;
                case 6:
                    destino = atoi(trozos);
                    break;
                case 7:
                    strcpy(evento,trozos);
                    break;
                case 8:
                    strcpy(estado,trozos);
                    break;
                case 9:
                    jugada = atoi(trozos);
                    break;
                case 10:
                    turno = atoi(trozos);
                    break;
                case 11:
                    x = atoi(trozos);
                    break;
                case 12:
                    y = atoi(trozos);
                    break;
                case 13:
                    strcpy(tablero,trozos);
                    s_tablero = strlen(tablero);
                    break;
            }
         
          trozos = strtok( NULL, ";" );
            
    }
    
 
    Xadversario = x-1;
    Yadversario = y-1;
    oponente_id = id;
    strcpy(OponenteMarcaTemporal, marca_temporal);
    oponente_duracion = duracion;
    strcpy(oponente_programa, programa);
    origin_oponente = origen; 
    destiny_oponente = destino;
    strcpy(oponente_evento, evento);
    strcpy(oponente_estado, estado);
    oponente_jugada = jugada;
    oponente_turno = turno;


}

char validar_mensaje(char mensaje[1000]){
    FILE *ptrFILE;
    int s,i,ok = 0;

    
    if( ( (strcmp(oponente_estado,"finalizado exitoso") == 0 ) || (strcmp(oponente_estado,"finalizado fallido")==0))== 0){
        s = strlen(mensaje);
        for ( i = 0; i < s ; i++){
            if (mensaje[i] == ' '){
                if (( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
                    printf("El archivo no se pudo abrir");
                } else{
                    FALLA = 1;
                    fprintf(ptrFILE,"\nMensaje sin formato. Hay espacio(s) en el mensaje:%s",mensaje);
                    fclose(ptrFILE);
                }
                ok = 1;
                break;
            }
        }
    }
    //Verificacion de id
    if(oponente_id != id + 1){
        if (( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
            printf("El archivo no se pudo abrir");
        } else{
            FALLA = 1;
            fprintf(ptrFILE,"\nMensaje sin formato.El ID es incorrecto {ID = %d}", oponente_id);
            fclose(ptrFILE);
        }   
    }
    //Verificacion de marca temporal
    s = strlen(OponenteMarcaTemporal);
    if ( (s == 8) && (OponenteMarcaTemporal[2] == ':') && (OponenteMarcaTemporal[5] == ':')  ){
        ok = 0;
    }else{
        if (( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
            printf("El archivo no se pudo abrir");
        } else{
            FALLA = 1;
            fprintf(ptrFILE,"\nMensaje sin formato. Marca temporal no sigue el formato. Formato recibido = {%s}",OponenteMarcaTemporal);
            fclose(ptrFILE);
        }
    }
    //Verificacion de programa
    if ( strcmp(program,"servidor")==0) {
        if(!(strcmp(oponente_programa,"cliente") == 0)){
            if (  ( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
                printf("El archivo no se pudo abrir");
            } else{
                FALLA = 1;
                fprintf(ptrFILE,"\nMensaje sin formato. El programa recibido es incorrecto: {%s}", oponente_programa);
                fclose(ptrFILE);
            } 
        }
    }else if (strcmp(program,"cliente")== 0){
        if(!(strcmp(oponente_programa,"servidor") == 0)){
            if (  ( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
                printf("El archivo no se pudo abrir");
            } else{
                FALLA = 1;
                fprintf(ptrFILE,"\nMensaje sin formato. El programa recibido es incorrecto: {%s}", oponente_programa);
                fclose(ptrFILE);
            } 
        }
    }
    //Verificacion de destino
    if(destiny_oponente != origin){
        if (( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
            printf("El archivo no se pudo abrir");
        } else{
            FALLA = 1;
            fprintf(ptrFILE,"\nMensaje sin formato. El destino del oponente es incorrecto {destino recibido = %d}, el correcto es {%d}", destiny_oponente,origin);
            fclose(ptrFILE);
        } 
    }
    //Verificacion de evento
    if(strcmp(oponente_evento,"conectar")==0 || strcmp(oponente_evento,"iniciar")==0 || strcmp(oponente_evento,"empezar")==0 || strcmp(oponente_evento,"jugar")==0 || strcmp(oponente_evento,"finalizar")==0){
        ok = 0;
    }else{
        if (  ( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
            printf("El archivo no se pudo abrir");
        } else{
            FALLA = 1;
            fprintf(ptrFILE,"\nMensaje sin formato. El evento es incorrecto {evento recibido =%s}", oponente_evento);
            fclose(ptrFILE);	
        }
    }
    //Verificacion de estado
    if(strcmp(oponente_estado,"pendiente")==0 || strcmp(oponente_estado,"conectado")==0 || strcmp(oponente_estado,"activo")==0 || strcmp(oponente_estado,"finalizado exitoso")==0 || strcmp(oponente_estado,"finalizado fallido")==0){
        ok = 0;
    }else{
        if (  ( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
            printf("El archivo no se pudo abrir");
        } else{
            FALLA = 1;
            fprintf(ptrFILE,"\nMensaje sin formato. El estado es incorrecto: {%s}", oponente_estado);
            fclose(ptrFILE);	
        }
    }
    //Verificacion de la jugada del contrario
    if(tab_juego[Xadversario][Yadversario] != 0){
        if (  ( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
            printf("El archivo no se pudo abrir");
        } else{
            FALLA = 1;
            fprintf(ptrFILE,"\nMensaje sin formato. Jugada repetida o no valida. La casilla {%d,%d} ya fue jugada", Xadversario,Yadversario);
            fclose(ptrFILE);	
        }
    }
    //Verificacion de puntos
    if(Xadversario + 1 > 10 || Xadversario + 1 < 1 || Yadversario + 1 > 10 || Yadversario + 1 < 1){
        if (  ( ptrFILE = fopen(rutaArchivo,"a") )== NULL){
            printf("El archivo no se pudo abrir");
        } else{
            FALLA = 1;
            fprintf(ptrFILE,"\nMensaje sin formato. Coordenadas recibidas fuera del rango. Coordenadas recibidas: {%d,%d}", Xadversario+1,Yadversario+1);
            fclose(ptrFILE);	
        }
    }
}