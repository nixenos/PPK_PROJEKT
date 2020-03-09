//
// Wojciech Janota, 2019r.
//
/**
 * @file
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "funkcje.h"

ojciec *wyszukaj_ojca(ojciec *grafHead, int ojciec_dane) {
    while (grafHead) {
        if (grafHead->dane == ojciec_dane) {
            return grafHead;
        } else {
            grafHead = grafHead->nastepny;
        }
    }
    return nullptr;
}

void dodaj_ojca(ojciec *&grafHead, int ojciec_dane) {
    auto p = grafHead;
    if (p) {
        if (wyszukaj_ojca(p, ojciec_dane) ==
            nullptr) {                                                          //jeżeli jeszcze nie istnieje
            while (p->nastepny) {
                p = p->nastepny;                                                //przechodź do ostatniego
            }
            p->nastepny = new ojciec;                                           //stwórz nowego ojca
            p->nastepny->nastepny = nullptr;
            p->nastepny->dane = ojciec_dane;
            p->nastepny->synowie = nullptr;
            p->nastepny->odwiedzony = false;
        } else {
            std::cerr << "Znaleziono ojca, nie dodawaj.\n";
        }
    } else {
        grafHead = new ojciec;
        grafHead->dane = ojciec_dane;
        grafHead->synowie = nullptr;
        grafHead->nastepny = nullptr;
        grafHead->odwiedzony = false;
    }
}

void dodaj_syna(ojciec *&ojciecSyna, int synDane) {
    if (ojciecSyna) {
        if (ojciecSyna->synowie) {
            auto temp = ojciecSyna->synowie;
            while (temp->nastepny) {
                temp = temp->nastepny;
            }
            temp->nastepny = new wierzcholek;
            temp->nastepny->nastepny = nullptr;
            temp->nastepny->dane = synDane;
        } else {
            ojciecSyna->synowie = new wierzcholek;
            ojciecSyna->synowie->nastepny = nullptr;
            ojciecSyna->synowie->dane = synDane;
        }
    }
}

void dodaj_dane(int ojciecDane, int synDane, ojciec *&grafHead) {
    auto ojciecSzukany = wyszukaj_ojca(grafHead, ojciecDane);
    auto dummyOjciec = wyszukaj_ojca(grafHead, synDane);
    if (not dummyOjciec) {
        dodaj_ojca(grafHead, synDane);
    }
    if (not ojciecSzukany) {
        dodaj_ojca(grafHead, ojciecDane);
        ojciecSzukany = wyszukaj_ojca(grafHead, ojciecDane);
    }
    dodaj_syna(ojciecSzukany, synDane);
    auto dummy = wyszukaj_ojca(grafHead, synDane);
}

void wczytaj_graf(std::string plik, ojciec *&start_grafu) {
    std::fstream plikGraf;
    plikGraf.open(plik);
    int ojc=0, syn=0;
    char temp;
    std::string helper;
    helper="";
    int i = 0;
    if (plikGraf) {
        while (plikGraf.peek() != std::ifstream::traits_type::eof()) {
           plikGraf >> temp;
           if(temp<'0' || temp>'9'){
               temp=' ';
           }
           helper+=temp;
        }
        helper[helper.size()-1]=' ';
        //std::cerr << helper << std::endl;
        std::stringstream wczytywanie(helper);
        int pomoc;
        while(wczytywanie >> pomoc){
            if(i%2==0){
                ojc=pomoc;
            }
            else{
                syn=pomoc;
                //std::cerr << "ojciec: " << ojc << ", syn: " << syn << std::endl;
                dodaj_dane(ojc, syn, start_grafu);
            }
            i++;
        }
        plikGraf.close();
    } else {
        std::cerr << "Błąd: nie znaleziono pliku!\n";
    }
}

void wypisz_graf(ojciec *grafHead) {
    if (grafHead) {
        std::cout << grafHead->dane << ": ";
        auto p = grafHead->synowie;
        while (p) {
            std::cout << p->dane << " ";
            p = p->nastepny;
        }
        std::cout << std::endl;
        wypisz_graf(grafHead->nastepny);
    }
}

void dodaj_do_listy(ojciec *&listaHead, wierzcholek *&cykl, int iterator) {
    auto temp = listaHead;
    while (temp->nastepny) {
        temp = temp->nastepny;
    }
    temp->dane = iterator;
    temp->synowie = cykl;
}

void wypisz_stos_od_tylu(wierzcholek *stos, std::ofstream *plikWy){
    if(stos) {
        if (stos->nastepny) {
            wypisz_stos_od_tylu(stos->nastepny, plikWy);
        }
        if(stos->dane) {
            *plikWy << stos->dane << "->";
            std::cerr << stos->dane << "->";
        }
    }
}

void dodaj_do_stosu(wierzcholek *&stos, int wartosc) {
    if (stos) {
        auto head = new wierzcholek;
        head->dane = wartosc;
        head->nastepny = stos;
        stos = head;
    } else {
        auto head = new wierzcholek;
        head->nastepny = nullptr;
        head->dane = wartosc;
    }
}

void zdejmij_ze_stosu(wierzcholek *&stos){
    if(stos){
        auto temp = stos;
        stos=stos->nastepny;
        delete temp;
    }
}
/*
void usun_liste(wierzcholek *&pHead) {
    if (pHead) {
        usun_liste(pHead->nastepny);
        delete pHead;
        pHead = nullptr;
    }
    auto head = new wierzcholek;
    head->nastepny = nullptr;
    head->dane = 0;
    pHead = head;
}

 */
void DFS(ojciec *&grafHead, int poczatek, wierzcholek *&lista, int pierwszy, std::ofstream *plikWy, int &counter) {
    dodaj_do_stosu(lista, poczatek);
    auto temp = grafHead;
    auto obecny = wyszukaj_ojca(temp, poczatek);
    obecny->odwiedzony = true;
    auto synowie = obecny->synowie;
    while (synowie) {
        auto temp1 = grafHead;
        auto pelny = wyszukaj_ojca(temp1, synowie->dane);
        if (not pelny->odwiedzony) {
            DFS(grafHead, pelny->dane, lista, pierwszy, plikWy, counter);
        } else {
            if (pelny->dane == pierwszy) {
                wypisz_stos_od_tylu(lista, plikWy);
                *plikWy << pelny->dane;
                *plikWy << std::endl;
                std::cerr << pelny->dane;
                std::cerr << std::endl;
		counter++;
            } else {
            }
        }
        synowie = synowie->nastepny;
    }
    zdejmij_ze_stosu(lista);
}

void wyczysc_odwiedzone(ojciec *& grafHead){
    auto temp = grafHead;
    while(temp){
        temp->odwiedzony = false;
        temp=temp->nastepny;
    }
}

void usun(ojciec *&grafHead){
    while(grafHead){
        auto temp = grafHead;
        auto iterator = grafHead->synowie;
        while(iterator){
            auto temp1 = iterator;
            iterator = iterator->nastepny;
            delete(temp1);
        }
        grafHead = grafHead->nastepny;
        delete(temp);
    }
}

void usun(wierzcholek *& grafHead){
    if(grafHead){
        if(grafHead->nastepny){
            usun(grafHead->nastepny);
        }
        else{
            delete(grafHead);
        }
    }
}
