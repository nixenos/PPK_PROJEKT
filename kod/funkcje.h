//
// Wojciech Janota, 2019r.
//
/**
 * @headerfile
 */

#ifndef PROJEKT_FUNKCJE_H
#define PROJEKT_FUNKCJE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "struktury.h"

/**
 * Funkcja wczytująca graf z podanego pliku do pamięci programu.
 * @param plik nazwa pliku, z którego należy wczytać graf
 * @param graf wskaźnik na listę, w której trzymany będzie graf
 */
void wczytaj_graf(std::string plik, ojciec *& start_grafu);

/**
 * Funkcja wyszukująca adres ojca listy do której należy dodać kolejny wierzchołek.
 * @param grafHead graf w którym szukamy ojca
 * @param ojciecDane wartość ojca, którego szukamy
 * @return adres ojca, którego szukano
 */
ojciec * wyszukaj_ojca(ojciec * grafHead, int ojciecDane);

/**
 * Funkcja dodająca ojca do grafu
 * @param grafHead graf, w którym dodajemy ojca
 * @param ojciecDane wartość ojca, którą dodajemy do grafu
 */
void dodaj_ojca(ojciec *& grafHead, int ojciecDane);

/**
 * Funkcja dodająca syna do list adjacencji ojca
 * @param ojciecSyna adres ojca, do listy którego dodajemy syna
 * @param synDane wartość syna, którego dodajemy do list ojca
 */
void dodaj_syna(ojciec *& ojciecSyna, int synDane);

/**
 * Funkcja dodająca syna do listy ojca
 * @param ojciecDane wartość ojca
 * @param synDane wartość syna
 * @param grafHead adres grafu
 */
void dodaj_dane(int ojciecDane, int synDane, ojciec *& grafHead);

/**
 * Funkcja wypisująca tablicę adjacencji (debugging)
 * @param grafHead graf do wypisania
 */
void wypisz_graf(ojciec * grafHead);

/**
 * Funkcja będąca implementacją algorytmu DFS na listach podwieszanych
 * @param grafHead graf, którym przechodzimy
 * @param poczatek początkowy wierzchołek do przechodzenia grafu
 * @param lista pomocnicza lista do trzymania stosu wierzchołków
 * @param pierwszy początkowy wierzchołek, do którego ścieżki szukamy
 * @param plikWy plik wyjściowy
 * @param counter licznik cykli
 */
void DFS(ojciec *& grafHead, int poczatek, wierzcholek *& lista, int pierwszy, std::ofstream *plikWy, int &counter);

/**
 * Funkcja dodająca listę z cyklem do listy głównej, zawierającej wszystkie cykle
 * @param listHead lista, do której dodajemy cykle
 */
void dodaj_do_listy(ojciec *& listaHead, wierzcholek *& cykl, int iterator);

/**
 * Funkcja zerująca znacznik `odwiedzony` w grafie
 * @param grafHead graf
 */
void wyczysc_odwiedzone(ojciec *& grafHead);

/**
 * Funkcja usuwająca graf
 * @param grafHead graf do usunięcia
 */
void usun(ojciec *& grafHead);

/**
 * Funkcja usuwająca listę wierzchołków
 * @param grafHead lista do usunięcia
 */
void usun(wierzcholek *& grafHead);

#endif //PROJEKT_FUNKCJE_H
