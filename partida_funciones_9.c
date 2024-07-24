/* 
*@autor/es: Paul Danilo Navarro Estigarribia
*/

#include "func_grupo_9.h"

void imprimir_partida(char mensaje[1000],char *tipo_mensaje){ 

    int i, countter = 0,s,j = 0,k,aux = 0,s_tablero,s_tablero_final,p = 0, auxi;
    char id[10],duration_x[10],origen[10],destino[10],
         jugada[10],turno[10],x[10],y[10],
         marca_temporal[100],programa[100],
         evento[100],estado[100],tablero[1000],
         tablero_final[1000],mensaje_final[1000],*trozos; 

    s = strlen(mensaje); 
    
    for (i = 0; i < s; i++) {
        if (mensaje[i] != '#' && mensaje[i] != '"' && mensaje[i] != '.'){
            mensaje_final[j] = mensaje[i]; 
            j++;
        }
    }

    mensaje_final[j] = '\0'; 
    trozos = strtok( mensaje_final, ";" );

    while ( trozos != NULL ){
        countter++;
        switch (countter) {
            case 1:
                strcpy(id,trozos);
                break;
            case 2:
                strcpy(marca_temporal,trozos);
                break;
            case 3:
                strcpy(duration_x,trozos);
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

   
    auxi = atoi(id);
 
    if(auxi > 1){
        printf("\n");
    }

    printf("######Programa: [%s].",programa);
    printf("\nMensaje-id: [%s]. Marca-de-tiempo: [%s]. Duracion: [%s].",id,marca_temporal,duration_x);
    printf("\nMensaje-tipo: {%s}. Mensaje-origen: [%s]. Mensaje-destino: [%s].",tipo_mensaje,origen,destino);
    printf("\nEvento: [%s]. Estado-juego: [%s]." ,evento,estado);
    printf("\n------------Turno-jugador: jugador-[%s]. Numero-jugadas: [%s]. ------------" ,turno,jugada);
    printf("\nCasilla-jugada: ([%s],[%s]).\nTablero-actual:\n\n",x,y);


    if (s_tablero > 10)
    {
        for (i = 0; i < s_tablero; i++)
        {
            if (tablero[i] != ',' && tablero[i] != '[' && tablero[i] != ']')
            {
                tablero_final[p] = tablero[i];
                p++;

            }

        }

    
        tablero_final[p] = '\0';
        s_tablero_final = strlen(tablero_final);  


        for ( i = 0; i < s_tablero_final; i++)
        {
            aux++;  

            printf("%2c", tablero_final[i]);

            if (aux % 10 == 0 )
            {
                printf( "\n"); 
            }
            
        }

    }
            
        

}

void endgame(){
    if(vertices_normales(tab_juego,Jugador,0) || vertices_inclinados(tab_juego,Jugador,0) || vertices_normales(tab_juego,versus,0) || vertices_inclinados(tab_juego,versus,0)){
       
        printf("====================fin del juego====================");
        printf("\nGrupo-ganador: %d", id_Finally);
        printf( "\nJugador-ganador: %d.", final_ganador);
        printf( "\nModalidad-partida-ganada: %s.", Finally_modalidad);
        printf( "\nTotal-jugadas-jugador1: %d.", jugadasTotales_1);
        printf("\nTotal-jugadas-jugador2: %d.", jugadasTotales_2);
        printf("\nTiempo-promedio-jugadas-jugador1: %.2f segundos.", promedioTiempo1);
        printf("\nTiempo-promedio-jugadas-jugador2: %.2f segundos.", promedioTiempo2);
        printf("\nInicio-del-juego: %s.", tiempoInicialFinally);
        printf("\nFinalizacion-del-juego: %s.", tiempoFinalFinally);
        printf("\nDuracion-total-del-juego: %.2f segundos.", total_duracion);

            switch (cuadradoNormalDetect) {
            case 1:
                printf("\nSe ha detectado un cuadrado normal!: (%d,%d) - (%d,%d) - (%d,%d) - (%d,%d).\n", coordenada_x_normal[0] + 1, coordenada_y_normal[0] + 1, coordenada_x_normal[1] + 1, coordenada_y_normal[1] + 1, coordenada_x_normal[2] + 1,coordenada_y_normal[2] + 1, coordenada_x_normal[3] + 1, coordenada_y_normal[3] + 1);   
                break;
            }
            switch (cuadradoInclinadoDetect){
            case 1:
                printf("\nSe ha detectado un cuadrado inclinado!: (%d,%d) - (%d,%d) - (%d,%d) - (%d,%d).\n", coordenada_x_inclinada[0] + 1, coordenada_y_inclinada[0] + 1, coordenada_x_inclinada[1] + 1, coordenada_y_inclinada[1] + 1, coordenada_x_inclinada[2] + 1,coordenada_y_inclinada[2] + 1, coordenada_x_inclinada[3] + 1, coordenada_y_inclinada[3] + 1);   
                break;
            }

    }
    
     
}



void server_game(){
    WSADATA wsa;
    SOCKET skt, skt2;
    int longitud_cliente, puerto = 9999, recv_tam;
    struct sockaddr_in server, cliente;
    char mensajes[1000];        
    int winner;
    bool finalizadoPorMensaje = false;
    printf("Creando partida.....");
    if(WSAStartup(MAKEWORD(2, 2),&wsa) != 0){
        printf("Error al inicializar winsock\n");
        exit(-1);
    }
    if((skt = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
        printf("Error creando socket\n");
        exit(-1);
    }
	bool partidaFinalizada = false;
    server.sin_family = AF_INET; 
    server.sin_port = htons(puerto);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(skt,(struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR){
        printf("Error al realizar el bind\n");
        exit(-1);
    }
    empezar_cero();
    printf("Partida creada.");
    printf("\nEsperando jugadores....");
    listen(skt, 1);
    
    longitud_cliente = sizeof(struct sockaddr_in);
    skt2 = accept(skt,(struct sockaddr*)&cliente, &longitud_cliente);
    if(skt2 == INVALID_SOCKET){
        printf("Fallo al aceptar la conexion\n");
    }
    printf("Jugador encontrado.");
    if((recv_tam = recv(skt2,mensajes,1000,0))== SOCKET_ERROR){
        printf("Recepcion fallida\n");
    }
    obtener_datos(mensajes);
    id++;
    fichero(mensajes,"recibido",0); 
    obtener_hora(MarcaTemporalHora);
    id++;
    duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
    strcpy(mensajes,mensaje(id, MarcaTemporalHora, duration,program, origin, origin_oponente,"iniciar","conectado",-1,-1,-1,-1,tab_nulo));             
    if(send(skt2,mensajes,1000,0)<0){
        printf("Error al enviar mensaje\n");
    }
    fichero(mensajes,"enviado",0);
    if((recv_tam = recv(skt2,mensajes,1000,0))== SOCKET_ERROR){
        printf("Recepcion fallida\n");
    }
    obtener_datos(mensajes);
    fichero(mensajes,"recibido",0);
    id++;
    while(!partidaFinalizada){
        winner = inteligencia_artificial(tab_juego, Jugador, versus);
        jugadasTotales_1++; 
        jugada++;
        obtener_hora(MarcaTemporalHora);
        if(jugada == 1){
            strcpy(tiempoInicialFinally,MarcaTemporalHora); 
        }
        duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
        duracion_total_jugador1 = duracion_total_jugador1 + duration;
        id++;
        if(vertices_normales(tab_juego,Jugador,1) || vertices_inclinados(tab_juego,Jugador,1)){
            strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"finalizar","finalizado exitoso",jugada,Jugador,xGrupo, yGrupo,tab_juego));
            if(send(skt2,mensajes,1000,0)<0){
                printf("Error al enviar mensaje\n");    
            }
            strcpy(tiempoFinalFinally,MarcaTemporalHora); 
            Variables_final_juego();
            imprimir_partida(mensajes,"enviado");
            fichero(mensajes,"enviado",0);
            fichero(mensajes,"enviado",1);
            break;
        }
        strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"jugar","activo",jugada,Jugador,xGrupo, yGrupo,tab_juego));
        imprimir_partida(mensajes,"enviado");
        if(send(skt2,mensajes,1000,0)<0){
            printf("Error al enviar mensaje\n");
        }
        fichero(mensajes,"enviado",0);
        if((recv_tam = recv(skt2,mensajes,1000,0))== SOCKET_ERROR){
            printf("Recepcion fallida\n");
        }
        obtener_datos(mensajes);
        validar_mensaje(mensajes);
        if(FALLA == 1){
            obtener_hora(MarcaTemporalHora);
            duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
            strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"finalizar","finalizado fallido",jugada,Jugador,xGrupo, yGrupo,tab_juego));
            if(send(skt2,mensajes, 1000,0)<0){
                printf("Error al enviar mensaje\n");
                exit(-1);
            }
            fichero(mensajes,"enviado",0);
            id_Finally = origin;
            final_ganador = Jugador;
            strcpy(Finally_modalidad,"servidor");
            promedioTiempo1 = duracion_total_jugador1/jugadasTotales_1;
            promedioTiempo2 = duracion_total_jugador2/jugadasTotales_2;
            strcpy(tiempoFinalFinally,MarcaTemporalHora);
            total_duracion = Hora_Segundos(tiempoFinalFinally)-Hora_Segundos(tiempoInicialFinally);
            fichero(mensajes,"enviado",1);
            break;
        }
        duracion_total_jugador2 = duracion_total_jugador2 + oponente_duracion;
        tab_juego[Xadversario][Yadversario] = versus;
        jugadasTotales_2++;
        id++;
        jugada++;
        fichero(mensajes,"recibido",0); 
        imprimir_partida(mensajes,"recibido");
        if(strcmp(oponente_evento,"finalizar") == 0){
            strcpy(tiempoFinalFinally,OponenteMarcaTemporal);
            Variables_final_juego();
            fichero(mensajes,"enviado",1);
            break;
        }
        if(vertices_normales(tab_juego,versus,1) || vertices_inclinados(tab_juego,versus,1)){
            partidaFinalizada = true;
            winner = Jugador;
            id++;
            obtener_hora(MarcaTemporalHora);
            duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
            strcpy(tiempoFinalFinally,MarcaTemporalHora);
            strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"finalizar","finalizado exitoso",jugada,Jugador,xGrupo, yGrupo,tab_juego));
            if(send(skt2,mensajes, 1000,0)<0){
                printf("Error al enviar mensaje\n");
                exit(-1);
            }
            Variables_final_juego();
            fichero(mensajes,"enviado",1);
            finalizadoPorMensaje = true;
            break;
        }
    }             
    closesocket(skt);
    WSACleanup();
}


bool existeRuta(char directorio[1000]){
    DIR * direc;
    if(direc = opendir(directorio)){
        closedir(direc);
        return true;
    }else{
        return false;
    }
}


void Variables_final_juego(){
    char modoActivoContrario[100];
    if(strcmp(program,"servidor")==0){
        strcpy(modoActivoContrario,"cliente");
    }else{
        strcpy(modoActivoContrario,"servidor");
    }


    promedioTiempo1 = duracion_total_jugador1 / jugadasTotales_1;
    promedioTiempo2 = duracion_total_jugador2 / jugadasTotales_2;

    char tiempoInicioAux[100];
    strcpy(tiempoInicioAux,tiempoInicialFinally);
    
    char tiempoFinalAux[100];
    strcpy(tiempoFinalAux,tiempoFinalFinally);
    
    total_duracion = Hora_Segundos(tiempoFinalAux) - Hora_Segundos(tiempoInicioAux);

    if(vertices_normales(tab_juego,Jugador,1) || vertices_inclinados(tab_juego,Jugador,1)){
        id_Finally = origin_oponente;
        final_ganador = versus;
        strcpy(Finally_modalidad,modoActivoContrario);
        
    }else if(vertices_normales(tab_juego,versus,1) || vertices_inclinados(tab_juego,versus,1)){
        id_Finally = origin;
        final_ganador = Jugador;
        strcpy(Finally_modalidad,program);
    }
}




void client_game(){
    WSADATA wsa;
    SOCKET skt, skt2;
    int longitud_cliente, puerto = 9999, recv_tam;
    struct sockaddr_in server, cliente;
    char mensajes[1000];        
    int winner;
    bool finalizadoPorMensaje = false;
    bool partidaFinalizada = false;
    printf("Buscando partida....");
    if(WSAStartup(MAKEWORD(2, 2),&wsa) != 0){
        printf("Error al inicializar winsock\n");
        exit(-1);
    }
    if((skt = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
        printf("Error creando socket\n");
        exit(-1);
    }
    server.sin_family = AF_INET; 
    server.sin_port = htons(puerto);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(skt, (struct sockaddr *)&server, sizeof(server))<0){
        printf("Error de conexion\n");
        exit(-1);
    }
    empezar_cero();
    printf("Partida encontrada\n");
    id++;
    obtener_hora(MarcaTemporalHora);
    strcpy(mensajes,mensaje(id,MarcaTemporalHora,-1,program,origin,-1,"conectar","pendiente",-1,-1,-1,-1,tab_nulo));
    if(send(skt,mensajes, 1000,0)<0){
        printf("Error al enviar mensaje\n");
        exit(-1);
    }
    fichero(mensajes,"enviado",0);
    id++;
    if((recv_tam = recv(skt,mensajes,1000,0))==SOCKET_ERROR){
        printf("Recepcion fallida\n");
    }
    mensajes[recv_tam] = '\0';
    obtener_datos(mensajes);
    fichero(mensajes,"recibido",0);
    id++;
    obtener_hora(MarcaTemporalHora);
    duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
    strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"empezar","activo",-1,-1,-1,-1,tab_nulo));
    if(send(skt,mensajes, 1000,0)<0){
        printf("Error al enviar mensaje\n");
        exit(-1);
    }
    fichero(mensajes,"enviado",0);
    while (!partidaFinalizada){        
        if((recv_tam = recv(skt,mensajes,1000,0))==SOCKET_ERROR){
            printf("Recepcion fallida\n");
        }
        obtener_datos(mensajes);
        validar_mensaje(mensajes);
        if(FALLA == 1){
            obtener_hora(MarcaTemporalHora);
            duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
            strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"finalizar","finalizado fallido",jugada,Jugador,xGrupo, yGrupo,tab_juego));
            if(send(skt,mensajes, 1000,0)<0){
                printf("Error al enviar mensaje\n");
                exit(-1);
            }
            fichero(mensajes,"enviado",0);
            id_Finally = origin;
            final_ganador = Jugador;
            strcpy(Finally_modalidad,"servidor");
            promedioTiempo1 = duracion_total_jugador1/jugadasTotales_1;
            promedioTiempo2 = duracion_total_jugador2/jugadasTotales_2;
            strcpy(tiempoFinalFinally,MarcaTemporalHora);
            total_duracion = Hora_Segundos(tiempoFinalFinally)-Hora_Segundos(tiempoInicialFinally);
            fichero(mensajes,"enviado",1);
            break;
        }
        id++;
        jugada++;
        if(jugada == 1){
            strcpy(tiempoInicialFinally,OponenteMarcaTemporal);  
        }
        duracion_total_jugador2 = duracion_total_jugador2 + oponente_duracion;
        tab_juego[Xadversario][Yadversario] = versus;
        jugadasTotales_2++;
        fichero(mensajes,"recibido",0);
        imprimir_partida(mensajes,"recibido");
        if(strcmp(oponente_evento,"finalizar") == 0){
            strcpy(tiempoFinalFinally,OponenteMarcaTemporal);
            Variables_final_juego();
            fichero(mensajes,"enviado",1);
            break;
        }
        
        if(vertices_normales(tab_juego,versus,1) || vertices_inclinados(tab_juego,versus,1)){
            partidaFinalizada = true;
            winner = Jugador;
            obtener_hora(MarcaTemporalHora);
            strcpy(tiempoFinalFinally,MarcaTemporalHora); 
            duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
            strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"finalizar","finalizado exitoso",jugada,Jugador,xGrupo, yGrupo,tab_juego));
            imprimir_partida(mensajes,"enviado");
            if(send(skt,mensajes, 1000,0)<0){
                printf("Error al enviar mensaje\n");
                exit(-1);
            }
            Variables_final_juego();
            
            fichero(mensajes,"enviado",1);
            finalizadoPorMensaje = true;
            break;
        }
        winner = inteligencia_artificial(tab_juego,Jugador,versus);
        jugadasTotales_1++;
        id++;
        jugada++;
        obtener_hora(MarcaTemporalHora);
        duration = Hora_Segundos(MarcaTemporalHora) - Hora_Segundos(OponenteMarcaTemporal);
        duracion_total_jugador1 = duracion_total_jugador1 + duration; 
        if(vertices_normales(tab_juego,Jugador,1) || vertices_inclinados(tab_juego,Jugador,1)){
            strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"finalizar","finalizado exitoso",jugada,Jugador,xGrupo, yGrupo,tab_juego));
            imprimir_partida(mensajes,"enviado"); 
            if(send(skt,mensajes,1000,0)<0){
                printf("Error al enviar mensaje\n");    
            }
            strcpy(tiempoFinalFinally,MarcaTemporalHora); 
            Variables_final_juego();
            fichero(mensajes,"enviado",0);
            fichero(mensajes,"enviado",1);

            break;
        }
        strcpy(mensajes,mensaje(id,MarcaTemporalHora,duration,program,origin,origin_oponente,"jugar","activo",jugada,Jugador,xGrupo, yGrupo,tab_juego));
        imprimir_partida(mensajes,"enviado");
        if(send(skt,mensajes, 1000,0)<0){
            printf("Error al enviar mensaje\n");
            exit(-1);
        }
        fichero(mensajes,"enviado",0);
    }
    closesocket(skt);
    WSACleanup();
}

