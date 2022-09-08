
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct nodo {
    struct nodo *izq;
    struct nodo *der;
    int valor;
}Nodo;

Nodo *crearNodo(int valor) {

    Nodo *n;
    
    n = (Nodo *) malloc(sizeof(Nodo));
    
    n->izq = NULL;
    n->der = NULL;
    n->valor = valor;
    
    return n;
}

Nodo *agregarNodo(Nodo *nodo, int valor) {
    if (nodo == NULL) {
        nodo = crearNodo(valor); 
    } else if (valor < nodo->valor) {
        nodo->izq = agregarNodo(nodo->izq, valor);
    } else {
        nodo->der = agregarNodo(nodo->der, valor);
    }
    return nodo;
}

void recorridoEnOrden(Nodo *nodo) {
    
    if (nodo == NULL) {
        return; 
    } else 
    {
        recorridoEnOrden(nodo->izq);
        printf("%d\n", nodo->valor);
        recorridoEnOrden(nodo->der);
    }
}

void recorridoPreOrden(Nodo *nodo) {
    
    if (nodo == NULL) {
        return; 
    } else 
    {
        printf("%d\n", nodo->valor);
        recorridoEnOrden(nodo->izq);
        recorridoEnOrden(nodo->der);
    }
}

void recorridoPosOrden(Nodo *nodo) {
    
    if (nodo == NULL) {
        return; 
    } else 
    {
        recorridoEnOrden(nodo->izq);
        recorridoEnOrden(nodo->der);
        printf("%d\n", nodo->valor);        
    }
}


int main(int argc, char** argv) {

    Nodo *raiz = NULL;
    
    
    raiz = crearNodo(32);

    raiz=agregarNodo(raiz, 16);
    
    raiz=agregarNodo(raiz, 98);
    raiz=agregarNodo(raiz, 60);
    raiz=agregarNodo(raiz, 76);
    raiz=agregarNodo(raiz, 63);
    raiz=agregarNodo(raiz, 73);
    raiz=agregarNodo(raiz, 76);
    raiz=agregarNodo(raiz, 14);
    
    recorridoEnOrden(raiz);
    
    
    printf("Recorrido preorden\n");
    recorridoPreOrden(raiz);
    
    printf("Recorrido posOrden\n");
    recorridoPosOrden(raiz);
    
    return (EXIT_SUCCESS);
}
