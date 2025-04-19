#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea;

typedef struct {
    Tarea T;
    Nodo *Siguiente;
}Nodo;

typedef struct Nodo * Head;


Head crearListaVacia();
Nodo * crearNodo(Tarea T);
Tarea solicitarTarea();
void mostrarTarea(Tarea T);
int menu();

int tareaID = 1000;


int main(){




    return 0;
}


Head crearListaVacia()
{
    return NULL;
}

Nodo *crearNodo(Tarea T)
{
    Nodo * nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    return nuevoNodo;
}

Tarea solicitarTarea()
{
    Tarea tareaPendiente;

    printf("\nIngrese una nueva tarea pendiente:\n");
    printf("Ingrese la descripcion de la tarea: ");
    fflush(stdin); //Limpia el buffer porque queda guardado el salto de linea '\n'
    gets(tareaPendiente.Descripcion);
    fflush(stdin);
    printf("\nIngrese la duracion de la tarea: ");
    scanf("%d", &tareaPendiente.Duracion);
    printf("\n");



    tareaPendiente.TareaID = tareaID++;


    return tareaPendiente;
}

void mostrarTarea(Tarea T){
    printf("\nTarea %d:\n", T.TareaID);
    printf("Drescripcion: %d\n", T.Descripcion);
    printf("Duracion %d:\n", T.Duracion);
}

int menu(){
    printf("\n###################################################\n");
    printf("\nIngrese la opcion que desee\n");
}


