/**
 * @file
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <values.h>
#include <fstream>
#include "funkcje.h"
#include "struktury.h"

int main(int argc, char *argv[]) {
    std::string NPlikuWej; // nazwa pliku wejściowego
    std::string NPlikuWyj; // nazwa pliku wyjściowego
    NPlikuWej = "";
    NPlikuWyj = "";
    auto *graf = new ojciec;
    graf->dane = 0;
    graf->nastepny = nullptr;
    graf->synowie = nullptr;
    std::string help;
    if(argc == 2){
    	help = argv[1];
    	if(help == "-h"){
		std::cout << "Użycie programu: \n" << "-g <plik wejściowy> \n" << "-c <plik wyjściowy>\n";
		return 0;
	}
    }
    for(int i=0; i<argc; i++){
        std::string temp = argv[i];
        if(temp=="-g"){
		if(i+1<argc){
                   NPlikuWej = argv[i+1];
		}
        }
        if(temp=="-c"){
	    if(i+1<argc){
            	NPlikuWyj = argv[i+1];
	    }
        }
    }
    wczytaj_graf(NPlikuWej, graf);
    std::ofstream plikWy;
    plikWy.open(NPlikuWyj);
    //wypisz_graf(graf);
    int counter=0;
    if (plikWy) {
        auto test = new wierzcholek;
        test->dane = 0;
        test->nastepny = nullptr;
        auto dummy = graf;
        dummy = dummy->nastepny;
        while (dummy) {
            DFS(graf, dummy->dane, test, dummy->dane, &plikWy, counter);
            wyczysc_odwiedzone(graf);
            dummy = dummy->nastepny;
        }
        usun(graf);
        usun(test);
	if(counter == 0){
		plikWy << "Brak cykli!\n";
	}
        plikWy.close();
    } else{
        std::cout << "Brak pliku wyjściowego...!\n";
    }
    return 0;
}
