/* 
*@autor/es: Paul Danilo Navarro Estigarribia
*/

#include "func_grupo_9.h"

void primerMenu(){
    char opcion;
    do{
        menu_principal();
        opcion = getche();
        switch (opcion){
            case '1':
                if((VisitMode || LocalMode) && valid_directory){
                    if(LocalMode){
                		server_game(); 
                    }else if (VisitMode){
                        client_game();
                    }
                    printf("\n");
                    endgame();
                }else{
                    printf("\nConfigura los parametros de la partida.");
                }
                printf("\n");
                system("pause");
                break;
            case '2':
                do{
                    system("cls");
                    parametros();
                    opcion = getche();
                    switch (opcion){
                        case '1':
                            system("cls");
                            printf("\nModo local establecido\n");
                            ajuste_de_local();
                            system("pause");
                            break;
                        case '2':
                            system("cls");
                            printf("\nModo visita establecido\n");
                            ajuste_de_visita();
                            system("pause");
                            break;
                        case '3':
                            if(strcmp(modus_active, "No configurado")!=0){
                                do{
                                    system("cls");
                                    parametros();
                                    printf("\nIngrese ruta(close = 0)>:");
                                    gets(rutaArchivo);
                                    if(existeRuta(rutaArchivo)){
                                        valid_directory = true;
                                    }else{
                                        valid_directory = false;
                                        if (strcmp(rutaArchivo,"0")==0){
                                            break;
                                        }
                                        printf("\nRuta no encontrada.\n");
                                        system("pause");
                                    }
                                    
                                    
                                }  while(!valid_directory);
                                if(valid_directory){
                                    generarNombre();
                                }
                            }else{
                                printf("\nConfigure el modo primero.\n");
                                system("pause");
                            }
                            break;
                        case '4':
                            break;
                        default:
                            printf("\nOpcion de navegacion invalida.\n");
                            system("pause");
                            break;
                    }
                } while (opcion != '4');
                break;
            case '3':
                do{
                    system("cls");
                    autores();
                    opcion = getche();
                    if(opcion != '1'){
                        printf("\nOpcion de navegacion invalida.\n");
                        system("pause");
                    }
                } while (opcion != '1');
                break;
            case '4':
                do{
                    system("cls");
                    help();
                    opcion = getch();
                    if(opcion != '1'){
                        printf("\nOpcion de navegacion invalida.\n");
                        system("pause");
                    }
                } while (opcion != '1');
                break;
            case '5':
                break;
            default:
                printf("\nOpcion de navegacion invalida.\n");
                system("pause");
                break;
        }
        system("cls");
    } while (opcion != '5');  
}

void menu_principal(){
    printf("\nID Grupo: %d.\t\t\tJugador: %s.",ide_grupo,usuario);
    printf("\nModo activo: %s.\n",modus_active);
    printf("\n\t\tMENU PRINCIPAL DEL PROGRAMA\n");
    printf("\nOpciones de navegacion:");
    printf("\n    1.    Empezar partida.");
    printf("\n    2.    Configurar parametros.");
    printf("\n    3.    Autores");
    printf("\n    4.    Ayuda.");
    printf("\n    5.    Salir.");
    printf("\n\nElegir una opcion (1-5)>:");
}

void parametros(){
    printf("\n\t\tConfigurar parametros.");
    printf("\nOpciones de navegacion:");
    printf("\n    1.    Modo Local.");
    printf("\n    2.    Modo Visita.");
    printf("\n    3.    Directorio de archivos.");
    printf("\n    4.    Ir atras.");
    printf("\n\nElegir una opcion (1-4)>:");
}

void autores(){
    printf("\n\t\tAutores.");
    printf("\n\n  -   Paul Danilo Navarro Estigarribia"); 
    printf("\n\n1.    Ir atras.");
    printf("\n\nElegir una opcion (1)>:");
}

void help(){
    printf("\n\t\tAyuda.");
    printf("\n\n-Formato de directorio: C:\\Users\\Mi usuario\\Desktop");
    printf("\n\n1.    Ir atras.");
    printf("\n\nElegir una opcion (1)>:");
}
