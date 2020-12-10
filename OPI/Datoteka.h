#pragma once

#include "SkupniTipi.h"

#include <string> //Klasièna uporaba.
#include <vector> //Klasièna uporaba.
#include <fstream> //Potrebujemo za branje iz datoteke. 
#include <iostream> //Klasièna knjižnica za izpise.
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
	string ime;	//Ime datoteke, ki je želimo prebrati.
	Datoteka(string ime);	//Edini možni konstruktor
	bool beri();			//Funkcija za branje in analizo podatkov v datoteki.
	bool obstojDatoteke;
	string analiza;			//Analiza branja podatkov iz datoteke; pomoè uporabniku.
	string podrobnaAnaliza;	//Podrobna analiza branja podatkov iz datoteke; pomoè razhrošèevanju.
	bool uspelo;			//Lastnost, ki opisuje èe je odpiranje datoteke uspelo in èe je pravilno zasnovana.
	AmbientalneLastnosti ambientalneLastnosti; //Konèen rezultat
	bool datotekaOdprata(); //Funkcija, ki vrne ali datoteka obstaja.
private :
	void debug(string besedilo);	//Funkcija za za zapis podrobnega dogajanja v programu.
	bool preveriZnake(string vrstica, Polje polje);
	Stevila beriStevila(string vrstica);
};

