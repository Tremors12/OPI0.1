#pragma once

#include <iostream> //Klasièna knjižnica za izpise v konzolo.
#include <string> //Potrebujemo podatkovne tipe "string".
#include <vector>
#include <cstdlib> //Random
#include <ctime> //Random

using namespace std;

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
	int trenutnaTemperatura, trenutnaVlaga, trenutnaOsvetljenost;
} TrenutneAmbientalneLastnosti;

typedef struct Polje {
	int velikost;
	char* polje;
}Polje;

typedef struct Stevila {
	vector<int> stevila;
	bool uspelo = true;
} Stevila;

typedef struct AmbientalneLastnosti {
	int temperatura, vlaga, osvetljenost;
	int temperaturaMin, temperaturaMax;
	int vlagaMin, vlagaMax;
	int osvetljenostMin, osvetljenostMax;
} AmbientalneLastnosti;

typedef struct Povprecje{
	typedef struct Dejanske{
		int temperatura, vlaga, osvetljenost;
	}Dejanske;
	typedef struct Zeljene{
		int temperatura, vlaga, osvetljenost;
	}Zeljene;

	Dejanske dejanske;
	Zeljene zeljene;

}Povprecje;
