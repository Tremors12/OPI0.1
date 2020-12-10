#pragma once

#include "SkupniTipi.h"

#include <string> //Klasièna uporaba.
#include <vector> //Klasièna uporaba.
#include <iostream> //Klasièna knjižnica za izpise v konzolo.

using namespace std;

typedef struct VpisaneALastnosti{
	int temperatura;
	int vlaznost;
	int osvetljenost;
} VpisaneALastnosti;

 
class Izpis
{
public :
	Izpis(); //Konstruktor
	char glavniMeni();
	string pozdrav();
	char vpisAliBranje();
	VpisaneALastnosti vpisiALastnosti();
	string imeDatoteke();
	LastnostiSimulacije lastnostiSimulacije();
};

