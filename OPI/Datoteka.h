#pragma once

#include "SkupniTipi.h"

#include <string> //Klasi�na uporaba.
#include <vector> //Klasi�na uporaba.
#include <fstream> //Potrebujemo za branje iz datoteke. 
#include <iostream> //Klasi�na knji�nica za izpise.
using namespace std; 


/*
typedef struct Polje{
	int velikost;
	char* polje;
}Polje;

typedef struct Stevila{
	vector<int> stevila;
	bool uspelo = true;
} Stevila;

typedef struct AmbientalneLastnosti {
	int temperatura, vlaga, osvetljenost;
	int temperaturaMin, temperaturaMax;
	int vlagaMin, vlagaMax;
	int osvetljenostMin, osvetljenostMax;
} AmbientalneLastnosti;
*/


class Datoteka
{
public : 
	string ime;	//Ime datoteke, ki je �elimo prebrati.
	Datoteka(string ime);	//Edini mo�ni konstruktor
	bool beri();			//Funkcija za branje in analizo podatkov v datoteki.
	bool obstojDatoteke;
	string analiza;			//Analiza branja podatkov iz datoteke; pomo� uporabniku.
	string podrobnaAnaliza;	//Podrobna analiza branja podatkov iz datoteke; pomo� razhro��evanju.
	bool uspelo;			//Lastnost, ki opisuje �e je odpiranje datoteke uspelo in �e je pravilno zasnovana.
	AmbientalneLastnosti ambientalneLastnosti; //Kon�en rezultat
	bool datotekaOdprata(); //Funkcija, ki vrne ali datoteka obstaja.
private :
	void debug(string besedilo);	//Funkcija za za zapis podrobnega dogajanja v programu.
	bool preveriZnake(string vrstica, Polje polje);
	Stevila beriStevila(string vrstica);
};

