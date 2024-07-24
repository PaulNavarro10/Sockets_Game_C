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
*@fecha y hora última actualización: martes, 13 de diciembre de 2022 14:22   VERIFICAR.                               
*/
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define ide_grupo 9
#define filas 10
#define columnas 10

extern char* usuario;
extern char* modus_active;
extern char rutaArchivo[1000];
extern bool valid_directory;
extern bool VisitMode; 
extern bool LocalMode; 
extern int Jugador;
extern int versus;
extern int xGrupo, yGrupo;
extern bool bandera; 
extern int id; 
extern char MarcaTemporalHora[80]; 
extern float duration; 
extern char program[100];
extern int origin; 
extern int destiny; 
extern char* evento; 
extern char* estado; 
extern int jugada;
extern int turno; 
extern int oponente_id;
extern char OponenteMarcaTemporal[80];
extern int oponente_duracion;
extern char oponente_programa[100];
extern int origin_oponente; 
extern int destiny_oponente; 
extern char oponente_evento[100];
extern char oponente_estado[100];
extern int oponente_jugada; 
extern int oponente_turno; 
extern int Xadversario, Yadversario; 
extern int id_Finally;
extern int final_ganador;
extern char Finally_modalidad[100];
extern int jugadasTotales_1;
extern int jugadasTotales_2;
extern float promedioTiempo1;
extern float promedioTiempo2;
extern char tiempoInicialFinally[100];
extern char tiempoFinalFinally[100];
extern float total_duracion;
extern float duracion_total_jugador1;
extern float duracion_total_jugador2;
extern int tab_juego[filas][columnas];
extern int tab_nulo[filas][columnas];
extern int failMensaje[10];
extern int FALLA;
extern int coordenada_x_normal[4];
extern int coordenada_y_normal[4];
extern int coordenada_x_inclinada[4];
extern int coordenada_y_inclinada[4];
extern int cuadradoNormalDetect;  
extern int cuadradoInclinadoDetect;

/*PROTOTIPADO DE FUNCIONES*/

int vertices_normales(int [filas][columnas], int,int);
int vertices_inclinados(int [filas][columnas],int,int);
int ultimo_punt(int tablero[filas][columnas],int,int,int);
int inteligencia_artificial(int tablero[filas][columnas], int jugador, int contrario);
int Hora_Segundos(char *marca_temporal);

void copy_mat(int m1[filas][columnas], int m2[filas][columnas]);
void menu_principal(void);
void parametros();
void autores();
void help();
void obtener_hora(char hora[80]);
void imprimir_partida(char mensaje[1000],char *envi_reci);
void endgame(void);
void primerMenu(void);
void generarNombre(void);
void ajuste_de_visita(void);
void ajuste_de_local(void);
void fichero(char mensaje[1000],char* tipo_mensaje, int end_game);
void Variables_final_juego();
void server_game(void);
void client_game(void);
void empezar_cero(void);
void obtener_datos(char mensaje[1000]);

bool existeRuta(char[1000] );

char validar_mensaje(char mensaje[1000]);
char* mensaje( int id , char marca_temporal[100], int duracion , char programa[100] , int origen , int destino , char evento[100], char estado[100] ,int jugada, int turno, int x, int y, int tablero[10][10]);

