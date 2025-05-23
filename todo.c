#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea;


typedef struct Nodo {
    Tarea T;
    struct Nodo * Siguiente;
}Nodo;

typedef Nodo * Head;


Head crearListaVacia();
Nodo * crearNodo(Tarea T);
Tarea solicitarTarea();
void mostrarTarea(Tarea T);
int menu();
void nuevaTarea(Head * lista);
void tareaRealizada(Head * listaPendientes, Head * listaRealizadas);
void mostrarListaTareas(Nodo * lista);
void buscarTarea(Head listaPendientes, Head listaRealizadas);
void liberarMemoria(Head *lista);
Nodo *encontrarNodoID(Head lista, int ID);
Nodo *encontrarNodoPalabra(Head lista, char palabra[]);
void moverTarea(Nodo * nodo, Head * listaRealizados);
int busquedaXID(int ID, Head lista);
int busquedaXPalabra(char palabra[], Head lista);







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
            nuevaTarea(&listaPendientes);
            break;

        case 2:
            tareaRealizada(&listaPendientes, &listaRealizadas);
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
    
    liberarMemoria(&listaPendientes);
    liberarMemoria(&listaRealizadas);
    
    return 0;
}


Head crearListaVacia()
{
    return NULL;
}

int menu(){
    int opcion;
    printf("\n################### MENU ##########################\n\n");
    printf("1)Ingresar una nueva tarea\n");
    printf("2)Seleccionar tarea realizada\n");
    printf("3)Mostrar tareas pendientes\n");
    printf("4)Mostrar tareas realizadas\n");
    printf("5)Buscar tarea\n");
    printf("6)Salir\n");
    printf("\n###################################################\n\n");
    
    
    printf("Ingrese la opcion que desee: ");
    scanf("%d", &opcion);
    printf("\n###################################################\n\n");

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
    int idTarea;
    mostrarListaTareas(*listaPendientes);
    printf("\nEscriba el ID de la tarea que fue realizada: ");
    scanf("%d", &idTarea);

    Head * Aux = listaPendientes;
    while ((*Aux)!=NULL && (*Aux)->T.TareaID != idTarea)
    {
        Aux = &(*Aux)->Siguiente;
    }

    if (*Aux)
    {
        Nodo * temp = *Aux;
        *Aux =(*Aux)->Siguiente;
        moverTarea(temp, listaRealizadas);
    }


    return;
}

void mostrarListaTareas(Nodo * lista)
{
    Nodo * Aux = lista;
    int count = 0;
    printf("\n----------TAREAS----------\n");
    while (Aux!=NULL && Aux->Siguiente)
    {
        mostrarTarea(Aux->T);
        Aux = Aux->Siguiente;
    }
    if (Aux)
    {
        mostrarTarea(Aux->T);
    }
    
    printf("\n--------------------------\n\n");

    
    return;
}

void buscarTarea(Head listaPendientes, Head listaRealizadas)
{
    int opcion;
    printf("\n-------- MENU de BUSQUEDA --------\n\n");
    printf("1)Buscar por ID\n");
    printf("2)Buscar por palabra clave\n");
    printf("\n----------------------------------\n\n");
    printf("Ingrese la opcion que desee: ");
    scanf("%d", &opcion);
    printf("\n\n");



    switch (opcion)
    {
    case 1:
        int ID;
        printf("\nIngrese el ID que desee buscar: ");
        scanf("%d", &ID);
        if (busquedaXID(ID, listaPendientes))
        {
            printf("\nLa tarea esta pendiente\n");
            
        } else if (busquedaXID(ID, listaRealizadas)) {
            printf("\nLa tarea fue realizada\n");
            
        }else{
            printf("\nNo hay ninguna tarea con ese ID\n");
            
        }
        break;

        case 2:
        char palabra[100];
        printf("\nIngrese la palabra que desee buscar: ");
        fflush(stdin);
        gets(palabra);
        fflush(stdin);
        if (busquedaXPalabra(palabra, listaPendientes))
        {
            printf("\nLa tarea esta pendiente\n");
            
        } else if (busquedaXPalabra(palabra, listaRealizadas)) {
            printf("\nLa tarea fue realizada\n");
            
        }else{
            printf("\nNo hay ninguna tarea con ese ID\n");
            
        }
        break;
    
    default:
        break;
    }

    return;
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
    char descripcion[100];
    
    printf("\n--------NUEVA TAREA PENDIENTE--------\n\n");
    printf("Ingrese la descripcion de la tarea: ");
    fflush(stdin);
    gets(descripcion);
    tareaPendiente.Descripcion = (char *)malloc(sizeof(descripcion)+1);
    strcpy(tareaPendiente.Descripcion, descripcion);
    printf("\nIngrese la duracion de la tarea: ");
    scanf("%d", &tareaPendiente.Duracion);
    printf("\n");
    
    
    tareaPendiente.TareaID = tareaID++;
    
    
    return tareaPendiente;
}

void mostrarTarea(Tarea T){
    printf("\nTarea ID: %d\n", T.TareaID);
    printf("Descripcion: %s\n", T.Descripcion);
    printf("Duracion: %d\n", T.Duracion);
}


void liberarMemoria(Head *lista) {
    Nodo *actual = *lista;
    Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->Siguiente;
        free(actual->T.Descripcion);
        free(actual);
        actual = siguiente;
    }

    *lista = NULL; // Asegurarse de que la lista quede vacía
    
}


void moverTarea(Nodo * nodo, Head * listaRealizados){
    
    nodo->Siguiente= *listaRealizados;
    *listaRealizados = nodo;

    return;
}

int busquedaXID(int ID, Head lista)
{
    Nodo *nodoEncontrado = encontrarNodoID(lista, ID);
    if (nodoEncontrado!=NULL)
    {
        mostrarTarea(nodoEncontrado->T);
        return 1;
    }
    return 0;
}

int busquedaXPalabra(char palabra[], Head lista)
{
    Nodo *nodoEncontrado = encontrarNodoPalabra(lista, palabra);
    if (nodoEncontrado!=NULL)
    {
        mostrarTarea(nodoEncontrado->T);
        return 1;
    }
    return 0;
}

Nodo *encontrarNodoID(Head lista, int ID){
    Nodo * Aux = lista;

    while (Aux !=NULL && Aux->T.TareaID != ID)
    {
        Aux = Aux->Siguiente;
    }
    
    if (Aux)
    {
        return Aux;
    }    
    return NULL;
}

Nodo *encontrarNodoPalabra(Head lista, char palabra[]){
    Nodo *Aux = lista;

    while (Aux!=NULL && !strstr(Aux->T.Descripcion, palabra))
    {
        Aux = Aux->Siguiente;
    }
    
    if (Aux)
    {
        return Aux;
    }    
    return NULL;
}