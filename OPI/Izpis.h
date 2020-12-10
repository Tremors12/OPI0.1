#pragma once

#include "SkupniTipi.h"

#include <string> //Klasi�na uporaba.
#include <vector> //Klasi�na uporaba.
#include <iostream> //Klasi�na knji�nica za izpise v konzolo.

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

