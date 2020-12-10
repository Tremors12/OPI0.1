
//#define imeDatoteke "besedilo.txt"

#include <iostream> //Klasièna knjižnica za izpise v konzolo.
#include <string> //Potrebujemo podatkovne tipe "string".
#include <vector>
#include <cstdlib> //Random
#include <ctime> //Random

#include "Datoteka.h"
#include "Izpis.h"
#include "Rezim.h"


using namespace std; //Vlkjuèimo imenski postor std, da se izognemo veèkratnemu pisanju "std::".



int main() {
	srand(time(0)); //Potrebujemo za random generator


	/*
	Rezim program;
	AmbientalneLastnosti ambientalneLastnosti;	
	ambientalneLastnosti.osvetljenost = 1000;
	ambientalneLastnosti.temperatura = 30;
	ambientalneLastnosti.vlaga = 60;

	TrenutneAmbientalneLastnosti trenutneAmbientalneLastnosti;

	trenutneAmbientalneLastnosti.trenutnaVlaga = 70;
	trenutneAmbientalneLastnosti.trenutnaTemperatura = 30;
	trenutneAmbientalneLastnosti.trenutnaOsvetljenost = 500;

	Odstopanje odstopanje = program.avtomatskiNacin(ambientalneLastnosti, trenutneAmbientalneLastnosti);
	cout << "Odstopanja : " << endl;
	cout << "Temperatura : " << odstopanje.temperatura << ", Vlaga : " << odstopanje.vlaga << ", Osvetljenost : " << odstopanje.osvetljenost << endl;
	*/


	Rezim program; //Program
	Izpis izpis;
	string rezim;
	bool pravilnost = false;
	while (!pravilnost) {
		rezim = izpis.pozdrav();
		if (rezim == "simulator") {
			pravilnost = true;
			//Avtomatki naèin
			program.vrstaRezima.testiranje.avtomatski = true;
			program.vrstaRezima.testiranje.testni = false;
		}
		else if (rezim == "simulator -t") {
			pravilnost = true;
			//Testni režim
			program.vrstaRezima.testiranje.avtomatski = false;
			program.vrstaRezima.testiranje.testni = true;
		}
		else {
			cout << "Vnesli ste moznost, ki ni na razpolago." << endl;
		}
	}
	pravilnost = false;
	while (!pravilnost) {
		char menu = izpis.glavniMeni();
		if (menu == '1') {
			pravilnost = true;
			//Navadni avtomatksi naèin
			program.vrstaRezima.nacin.napredni = false;
			program.vrstaRezima.nacin.navaden = true;
		}
		else if (menu == '2') {
			pravilnost = true;
			//Napredi covid naèin
			program.vrstaRezima.nacin.napredni = true;
			program.vrstaRezima.nacin.navaden = false;
		}
		else if (menu == '*') {
			cout << "Prosili ste za dodatno pomoc." << endl; 
			cout << "Izberite med dvema naèinoma delovanja programa." << endl;
			cout << "Vnesite (1) za navaden nacin oz. vnesite (2) za napredni covid nacin." << endl;
		}
		else if (menu == '0') {
			//Zapri program
			return 0;
		}
		else {
			cout << "Vnesli ste možnost, ki ni na razpolago." << endl;
		}
	}

	//Naredimo vmesen izpis, da se bo uporabnik zavedal kaj je izbral.
	cout << "Izbrali ste " << (program.vrstaRezima.nacin.navaden ? "navaden" : "napreden") << " ";
	cout << (program.vrstaRezima.testiranje.avtomatski ? "avtomatski" : "testni") << " rezim" << endl; 




	string imeDatoteka = izpis.imeDatoteke();
	Datoteka datoteka(imeDatoteka);
	while (!datoteka.datotekaOdprata()) {
		cout << "Datoteka ne obstaja." << endl;
		imeDatoteka = izpis.imeDatoteke();
		datoteka.ime = imeDatoteka;
	}

	while(!datoteka.beri()) {
		cout << datoteka.analiza << endl;
		cout << "Branje ni uspelo. Popravite napake in pritisnite enter." << endl;
		cin.get();
		cin.get();
	}
	


	LastnostiSimulacije lastnostiSimulacije = izpis.lastnostiSimulacije();


	program.avtomatskiNacinVse(datoteka.ambientalneLastnosti, lastnostiSimulacije);


}