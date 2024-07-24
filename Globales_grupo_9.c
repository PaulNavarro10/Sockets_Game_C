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

#include <stdbool.h>
#define filas 10
#define columnas 10
#define ide_grupo 9

bool valid_directory = false;
bool VisitMode = false; 
bool LocalMode = false;
bool bandera = true;

char program[100];
char* evento; 
char* estado; 
char* usuario = "No configurado";
char* modus_active = "No configurado";
char MarcaTemporalHora[80]; 
char OponenteMarcaTemporal[80];
char oponente_programa[100];
char oponente_evento[100]; 
char oponente_estado[100];
char Finally_modalidad[100];
char tiempoInicialFinally[100];
char tiempoFinalFinally[100];
char rutaArchivo[1000];

int jugada = 0;
int turno; 
int oponente_id;
int oponente_duracion;
int origin_oponente;  
int destiny_oponente; 
int oponente_jugada;
int oponente_turno;
int Xadversario, Yadversario; 
int id_Finally;
int final_ganador;
int jugadasTotales_1 = 0;
int jugadasTotales_2 = 0;
int tab_juego[filas][columnas] = {0}; 
int tab_nulo[filas][columnas] = {-1};
int failMensaje[10]= {0};
int FALLA = 0;
int coordenada_x_normal[4] = {0};
int coordenada_y_normal[4] = {0};
int coordenada_x_inclinada[4] = {0};
int coordenada_y_inclinada[4] = {0};
int cuadradoNormalDetect = 0;  
int cuadradoInclinadoDetect = 0;
int id=0; 
int origin = ide_grupo;
int destiny = 0; 
int Jugador;
int versus; 
int xGrupo, yGrupo;

float promedioTiempo1 = 0;
float promedioTiempo2 = 0;
float total_duracion;
float duracion_total_jugador1 = 0.0;
float duracion_total_jugador2 = 0.0;
float duration;