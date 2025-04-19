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
void nuevaTarea(Head * lista);
void tareaRealizada(Head * listaPendientes, Head * listaRealizadas);
void mostrarListaTareas(Head * lista);
void buscarTarea(Head * listaPendientes, Head * listaRealizadas);




int tareaID = 1000;


int main(){

    Head listaPendientes = crearListaVacia();
    Head listaRealizadas = crearListaVacia();

    int salida = 0;

    while (salida!=1)
    {
        switch (menu())
        {
        case 1:
            nuevaTarea(listaPendientes);
            break;

        case 2:
            tareaRealizada(listaPendientes, listaRealizadas);
            break;

        case 3:
            mostrarListaTareas(listaPendientes);
            break;

        case 4:
            mostrarListaTareas(listaRealizadas);
            break;
            
            case 5:
            buscarTarea(listaPendientes, listaRealizadas);
            break;
            
            default:
            salida = 1; 
            break;
        }
        
    }
    
    
    
    return 0;
}


Head crearListaVacia()
{
    return NULL;
}

int menu(){
    int opcion;
    printf("\n###################################################\n");
    printf("1)Ingresar una nueva tarea\n");
    printf("2)Seleccionar tarea realizada\n");
    printf("3)Mostrar tareas pendientes\n");
    printf("4)Mostrar tareas realizadas\n");
    printf("5)Buscar tarea\n");
    printf("6)Salir\n");
    printf("\n###################################################\n\n");
    
    
    printf("Ingrese la opcion que desee: ");
    scanf("%d", &opcion);
    return opcion;
}

void nuevaTarea(Head * lista)
{
    Nodo * nuevoNodo = crearNodo(solicitarTarea());
    nuevoNodo->Siguiente= *lista;
    *lista = nuevoNodo;

    return;
}


void tareaRealizada(Head * listaPendientes, Head * listaRealizadas)
{
    
    return;
}

void mostrarListaTareas(Head * lista)
{
}

void buscarTarea(Head * listaPendientes, Head * listaRealizadas)
{
}


Nodo *crearNodo(Tarea T)
{
    Nodo * nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T=T;
    nuevoNodo->Siguiente=NULL;
    return nuevoNodo;
}


Tarea solicitarTarea()
{
    Tarea tareaPendiente;
    
    printf("\nIngrese una nueva tarea pendiente\n");
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


