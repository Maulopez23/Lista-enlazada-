// Lista enlazada.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//paso por referencia indica pasarle la dirección de memoria a donde está dicho valor

#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

struct nodo 
{
    int dato;
    nodo* siguiente;
};

//prototipo de funciones
void insertarLista(nodo*&, int);
void mostrarLista(nodo*);
void buscarLista(nodo* lista, int n);
void borrarElemento(nodo*& lista, int n);

nodo* lista = NULL;


void insertarLista(nodo*& lista, int n)
{
    nodo* nuevo_nodo = new nodo();//nos reserva el espacio en memoria para almacenar ese nodo
    nuevo_nodo->dato = n;//aquí se asgina nuevo_nodo-> para incluir el elemento que se quiere incluir en la lista

    nodo* aux1 = lista;//lo igualamos a lista para indicar que nuestra lista está vacía
    nodo* aux2 = lista;

    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;//aux2 estaría en el lugar que apunta el aux1
        aux1 = aux1->siguiente;//y aquí el aux1 apuntaría al aiguiente, o sea, null
    }
    if (lista == aux1)//esta condición se va a cumplir solamente si el elemento va al principio de la lista
    {
        //para insertar un elemento al principio de la lista//
        lista = nuevo_nodo; //asignamos estos valores para indicar que queremos agregar el nuevo_nodo a la lista
    }
    else //este else nos indicar que el n ha entrado al while, por lo tanto ha corrido una posición más
    {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1; //aquí el nuevo nodo va a señalar al siguiente debido a que le asignamos el aux1, es decir, para que apunte a null


}

void mostrarLista(nodo* lista)
{
    nodo* actual = new nodo();
    actual = lista;//para que actual apunte a la primera posición de la lista

    if (actual == NULL)
    {
        cout << "No hay elementos en la lista\n";
    }
    else 
    {
        while (actual != NULL)//la condición solo se cumple mientras el actual apunte a los elementos que hay en la lista
        {
            cout << actual->dato << " -> ";//muestra el elemento al que está apuntando
            actual = actual->siguiente;//se mueve al siguiente elemento 
        }
    }
}

void buscarLista(nodo* lista, int n)
{
    bool band = false;
    nodo* actual = new nodo();
    actual = lista;//para que apunte a la misma posicion que la lista
    if (actual == NULL)
    {
        cout << "No hay elementos que mostrar\n";
    }
    else 
    {
        while ((actual != NULL) && (actual->dato <= n))//la primera condicion indicar que va a buscar los elementos mientras la lista los posea
            //la segunda condicion es para que los elementos se mantengan en orden
        {
            if (actual->dato == n)
            {
                band = true;//para determinar si el elemento existe o no en la lista
            }
            actual = actual->siguiente;//si no era el número que quería mostrar, actual se movia al siguiente numero en la lista
        }
        if (band == true)
        {
            cout << "Elemento " << n << " ha sido encontrado en la lista\n";
        }
        else
        {
            cout << "Elemento " << n << " no ha sido encontrado en la lista";
        }
    }
    
}

void borrarElemento(nodo*& lista, int n) 
{
    //mientras lista sea diferente de null, podremos eliminar los elementos 
    if (lista != NULL)
    {
        nodo* aux_borrar;
        nodo* anterior = NULL;
        aux_borrar = lista; //para que aux_borrar apunte al mismo sitio que lista

        //recorrer la lista
        while ((aux_borrar != NULL) && (aux_borrar->dato != n))
            //la primer condicion indica que se haga hasta que la lista se encuentre vacia
            //la segunda condicion indica que se recorra la lista hasta encontrar el dato q se quiere eliminar
        {
            anterior = aux_borrar;//apunta al sitio que esta apuntando aux_borrar
            aux_borrar = aux_borrar->siguiente;//si no se encuentra el dato, aux_borrar avanza al siguiente
        }

        if (aux_borrar == NULL)//esta condicion se cumple cuando aux_borrar apunta a null
            //o sea, que el elemento no existe
        {
            cout << "No existe el elemento que quieres eliminar";
        }
        else if (anterior == NULL)
        //esta condicion nos indica que el elemento a eliminar es el primero 
        {
            lista = lista->siguiente;//lista apunta al siguiente elemento 
            delete aux_borrar;//borra el elemento que está apuntando el aux_borrar
        }
        else //este else es para borrar un elemento que este posicionado en un lugar diferente al primer numero 
        {
            anterior->siguiente = aux_borrar->siguiente; //anteior->siguiente apuntará al mismo elemento que aux_borrar
            delete aux_borrar;
        }
    }
}

void menu()
{
    int slc, dato, src, elm;
    do
    {
        cout << "\t Menu \n";
        cout << "Seleccione una de las opciones: \n";
        cout << "1. Insertar elemento a la lista\n";
        cout << "2. Mostrar elementos de la lista\n";
        cout << "3. Buscar elemento de la lista\n";
        cout << "4. Eliminar elemento de la lista\n";
        cout << "5. Salir de la aplicacion\n";
        cout << "\n";
        cout << "Opcion: ";
        cin >> slc;

        switch (slc)
        {
        case 1: 
                system("cls");
                cout << "Digitame un numero: ";
                cin >> dato;
                insertarLista(lista, dato);
                cout << "\n";
                system("pause");
                break;
        case 2:
            system("cls");
            mostrarLista(lista);
            cout << "\n";
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Digite el elemento que quiere buscar: ";
            cin >> src;
            buscarLista(lista, src);
            cout << "\n ";
            system("pause");
            break;

        case 4: 
            system("cls");
            cout << "Digite elemento que desea eliminar: ";
            cin >> elm;
            borrarElemento(lista, elm);
            cout << "\n";
            system("pause");
            break;

        }
        system("cls");
    } while (slc != 5);
}


int main()
{
    menu();
    return 0;
}
