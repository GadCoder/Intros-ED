#include <iostream>
#include <string>
#include <stdlib.h> // para generar numeros random
#include <time.h> // para generar numeros random

using namespace std;

struct Nodo{
    /*
     * Struct nodo usada para trabajar con nuestra lista enlazada
     */
    int valor;
    Nodo* next_nodo = NULL;
};


// Declaración de funciones
void recorrerLista(Nodo *head);
void agregarNodoFinal(Nodo *head);
int generarNumeroRandom();



int main(){
    srand (time(NULL)); // Para generar numeros randaom
    // Creando head de la lista enlazada
    Nodo *head = new Nodo();
    head->valor = 21;

    // Recorriendo la lista para mostrar que se creó correctamente
    recorrerLista(head);

    // Insertando 10 elementos al final de la lista
    for(int i = 0; i < 10; i++)
        agregarNodoFinal(head);

    // Recorriendo la lista para mostrar los elementos insertados
    recorrerLista(head);
    return 0;
}


int generarNumeroRandom(){
    // Devuelve un entero aleatorio entre 10 y 100
    return rand() % 100 + 10;
}

void recorrerLista(Nodo *head){
    // Creamos variable temporal
    Nodo *copy_head = head;
    cout<<endl;
    // Recorremos hasta que nuestro puntero copia sa NULL (llegó al final de la lista)
    while(copy_head != NULL){
        cout << "["<<copy_head->valor <<"]->";
        copy_head = copy_head->next_nodo; // Actualizando el valor del puntero con el nodo siguiente
    }
}

void agregarNodoFinal(Nodo *head){
    // Creamos variable temporal
    Nodo *copy_head = head;

    // Recorremos hasta que puntero a siguiente nodo apunte a NULL
    while(copy_head->next_nodo != NULL)
        copy_head = copy_head->next_nodo;

    // Creando nuevo nodo
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->valor = generarNumeroRandom();

    // Apuntando el ultimo puntero de la lista a nuevo nodo
    copy_head->next_nodo = nuevo_nodo;
}

