#pragma once

#include <iostream> //Klasièna knjižnica za izpise v konzolo.
#include "SkupniTipi.h"
#include<windows.h>

using namespace std;


//Slednji definirani uporabniški tipi se nahajajo v datoteki SkupniTipi.h
/*
typedef struct LastnostiSimulacije {
	int stevilo;
	int zakasnitev;
} LastnostiSimulacije;

typedef struct Testiranje {
	bool testni, avtomatski;
} Testiranje;

typedef struct Nacin {
	bool navaden, napredni;
} Nacin;

typedef struct VrstaRezima { //Uporabniski tip, ki hrani podatke o nacinih testiranja
	Testiranje testiranje;
	Nacin nacin;
}VrstaRezima;

typedef struct Odstopanje {
	int temperatura, vlaga, osvetljenost;
} Odstopanje;

typedef struct TrenutneAmbientalneLastnosti {
	int temperatura, vlaga, osvetljenost;
	int temperaturaMin, temperaturaMax;
	int vlagaMin, vlagaMax;
	int osvetljenostMin, osvetljenostMax;
} TrenutneAmbientalneLastnosti;
*/

class Rezim
{
public : 
	VrstaRezima vrstaRezima; //Tip ki hrani podatke kako naj program deluje
	void izracunaj();
	Odstopanje avtomatskiNacin(AmbientalneLastnosti ambientalneLastnosti, TrenutneAmbientalneLastnosti trenutneAmbientalneLastnosti); // Daj nazaj med private

	Povprecje avtomatskiNacinVse(AmbientalneLastnosti ambientalneLastnosti, LastnostiSimulacije lastnostiSimulacije);
private : 
	//Odstopanje avtomatskiNacin(TrenutneAmbientalneLastnosti ambientalneLastnosti);
	int odstopanje(int trenutna, int zeljena);
	int nakljucnaVrednost(int min, int max); 
};

