//
// Created by Ciro on 24/8/2023.
//

#ifndef EDYA_CACHE_CACHE_H
#define EDYA_CACHE_CACHE_H
#define NUMERO_DE_PAGINAS 128

typedef struct pagina {
    int numeroDePagina;
    struct pagina * ant;
    struct pagina * sig;
} Pagina;

typedef struct cache{
    int tamanio;
    int capacidad;
    Pagina * cache;
} Cache;

Pagina * newPagina(int numeroDePagina);
Cache * newCache (int capacidad);
void inicializarHash();

Pagina * solicitarPagina(Cache * cache, int numeroDePagina);
void apilar(Cache * cache, Pagina * paginaAInsertar);
void eliminarUltimaPagina(Cache * cache);

void imprimir(Cache * cache);
#endif //EDYA_CACHE_CACHE_H
