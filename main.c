#include <stdio.h>
#include "cache.h"

int main() {
    Cache *cache = newCache(4);
    inicializarHash();

    solicitarPagina(cache, 1);
    imprimir(cache);
    solicitarPagina(cache, 34);
    imprimir(cache);
    solicitarPagina(cache, 26);
    imprimir(cache);
    solicitarPagina(cache, 2);
    imprimir(cache);
    solicitarPagina(cache, 1);
    imprimir(cache);
    solicitarPagina(cache, 34);
    imprimir(cache);
    solicitarPagina(cache, 58);
    imprimir(cache);
    solicitarPagina(cache, 15);
    imprimir(cache);
    solicitarPagina(cache, 1);
    imprimir(cache);
    return 0;
}
