//
// Created by Ciro on 24/8/2023.
//

#include "cache.h"
#include <stdio.h>
#include <stdlib.h>

Pagina * hash[NUMERO_DE_PAGINAS];

Pagina * newPagina(int valor) {
    Pagina *aux = malloc(sizeof(Pagina));
    if (aux == NULL) {
        printf("No hay espacio de memoria disponible");
        exit - 1;
    }

    aux->numeroDePagina = valor;
    aux->sig = NULL;
    aux->ant = NULL;
}

Cache * newCache(int capacidad){
    Cache *aux = malloc(sizeof(Cache));
    if (aux == NULL) {
        printf("No hay espacio de memoria disponible");
        exit - 1;
    }

    aux->capacidad = capacidad;
    aux->tamanio = 0;
    aux->cache = NULL;
}

void inicializarHash(){
    for (int i = 0; i<NUMERO_DE_PAGINAS;i++){
        hash[i]=NULL;
    }
}

Pagina * solicitarPagina(Cache *cache, int numeroDePagina){
    Pagina * pagina = hash[numeroDePagina];
    if (pagina == NULL){
        //inicializar la pagina
        pagina = newPagina(numeroDePagina);

        if (cache->capacidad == cache->tamanio){
            eliminarUltimaPagina(cache);
        }
        apilar(cache, pagina);
    }else{
        //insertarla a la cache
        if (cache->cache != pagina){
            pagina->ant->sig = pagina->sig;
            if (pagina->sig!=NULL){
                pagina->sig->ant = pagina->ant;
            }
            //opcion 1: bajo tamanio y apilo
            cache->tamanio --;
            apilar(cache, pagina);

            //opcion 2: asigno el puntero de la cache a la pagina
            //cache->cache = pagina;
        }
    }
    return pagina;
}

void apilar(Cache *cache, Pagina * paginaAInsertar){
    if (cache->cache != NULL){
        cache->cache->ant= paginaAInsertar;
    }

    paginaAInsertar->sig = cache->cache;
    paginaAInsertar->ant = NULL;
    cache->cache=paginaAInsertar;
    hash[paginaAInsertar->numeroDePagina]=paginaAInsertar;
    cache->tamanio ++;
}

void eliminarUltimaPagina(Cache * cache){
    //opción 1: recorrer la cache y eliminar el último
    Pagina * aux = cache->cache;
    if (aux != NULL){
        for (;aux->sig != NULL; aux=aux->sig){}
        aux->ant->sig=NULL;
        hash[aux->numeroDePagina]=NULL;
        free(aux);
        cache->tamanio --;
    }
    //opción 2: teniendo un puntero al ultimo elemento:
    //no olvidarse de cambiar el comportamiento de apilar
}

void imprimir(Cache * cache){
    Pagina * aux = cache->cache;
    printf("\nPáginas de la cache: \n");
    for (;aux!= NULL; aux=aux->sig){
        printf("\t%d", aux->numeroDePagina);
    }
}
