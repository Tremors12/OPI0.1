#include "Datoteka.h"



//Edini možen konstruktor.
//Konstruktor shrani ime datoteke in jo poskuša prebrati.
Datoteka::Datoteka(string ime) {
	this->ime = ime;
}

//Funkcija za branje in analizo datoteke.
bool Datoteka::beri() {
	analiza = "";	//Pobrišemo vrednost iz morebitnih prejšnjih branj.
	this->uspelo = false; //Pobrišemo vrednost iz morebitnih prejšnjih branj.

	ifstream datoteka(this->ime);
	//Preverim ali datoteka obstaja
	if (!datoteka.is_open()) {
		this->obstojDatoteke = false; //Datoteka ne obstaja na danem naslovu.
		analiza = "Datoteka : '" + string(this->ime) + "' ne obstaja.\n";
		debug("--datoteka ne obstaja");
		debug("##v funkciji Datoteka::beri vracam false");
		return false;
	}
	else {//Datoteka obstaja
		this->obstojDatoteke = true; //Odpiranje datoteke je uspelo.
		debug("--datoteka obstaja");
		debug("##v obstojDatoteke vpisujem true");
		vector<string> vrstice;
		string vrstica;
		debug("##berem vrstice iz datoteke");

		//Berem vrstice iz datoteke
		while (getline(datoteka, vrstica))
		{
			vrstice.push_back(vrstica);
		}

		//Preverim ali je število vrstic v datoteki enako 4
		debug("##stejem stevilo vrstic v datoteki");
		if (vrstice.size() == 4) {
			debug("--stevilo vrstic v datoteki je enako 4");
		}
		else {
			this->analiza = this->analiza + string("Stevilo vrstic v datoteki ni enako 4.\n");
			debug("--stevilo vrstic v datoteki ni enako 4");
			debug("##v funkciji Datoteka::beri vracam false");
			return false;
		}
		//Preverjam ali so v vseh vrsticah samo znaki, ki so lahko vsebovani

		//Preverjam vrstico 1
		char polje1[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '}; 
		debug("--preverjam ali so v 1. vrstici samo pravilni znaki");
		if (!preveriZnake(vrstice[0], { sizeof(polje1), polje1 })) {
			debug("--v 1. vrstici so nepravilni znaki");
			this->analiza = this->analiza + string("V 1. vrstici se nahaja nedovoljen znak.\nDovoljeni znaki so : '0' .. '9', ' '.\n");
			debug("##v funkciji Datoteka::beri vracam false");
			return false;
		}
		debug("--v vrstici 1 so samo pravilni znaki");
		
		//Preverjam vrstico 2
		char polje2[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '[', ']', ','};
		debug("--preverjam ali so v 2. vrstici samo pravilni znaki");
		if (!preveriZnake(vrstice[1], { sizeof(polje2), polje2 })) {
			debug("--v 2. vrstici so nepravilni znaki");
			this->analiza = this->analiza + string("V 2. vrstici se nahaja nedovoljen znak.\nDovoljeni znaki so : '0' .. '9', ' ', '[', ']', ','\n");
			debug("##v funkciji Datoteka::beri vracam false");
			return false;
		}
		debug("--v vrstici 2 so samo pravilni znaki");

		//Preverjam vrstico 3
		debug("--preverjam ali so v 3. vrstici samo pravilni znaki");
		if (!preveriZnake(vrstice[2], { sizeof(polje2), polje2 })) {
			debug("--v 3. vrstici so nepravilni znaki");
			this->analiza = this->analiza + string("V 3. vrstici se nahaja nedovoljen znak.\nDovoljeni znaki so : '0' .. '9', ' ', '[', ']', ','\n");
			debug("##v funkciji Datoteka::beri vracam false");
			return false;
		}
		debug("--v vrstici 3 so samo pravilni znaki");

		//Preverjam vrstico 4
		debug("--preverjam ali so v 3. vrstici samo pravilni znaki");
		if (!preveriZnake(vrstice[3], { sizeof(polje2), polje2 })) {
			debug("--v 3. vrstici so nepravilni znaki");
			this->analiza = this->analiza + string("V 4. vrstici se nahaja nedovoljen znak.\nDovoljeni znaki so : '0' .. '9', ' ', '[', ']', ','\n");
			debug("##v funkciji Datoteka::beri vracam false");
			return false;
		}
		debug("--v vrstici 4 so samo pravilni znaki");
	
		//Branje ambientalnih lastnosti
		debug("--Zaèenjam brati ambientalne nastnosti iz vrstic");

		Stevila stevila1, stevila2, stevila3, stevila4;

		//Berem vrstico 1 -- željene ambienralne lastnosti
		debug("--berem stevila iz vrstice 1");
		stevila1 = beriStevila(vrstice[0]);
		debug("--preverjam veljavnost vrstica 1");
		if (stevila1.uspelo && stevila1.stevila.size() == 3) {
			debug("--vrstica 1 OK, stevil 3");
			debug("##v ambientalne lastnosti zapisujem željene ambientalne lastnosti");
			this->ambientalneLastnosti.temperatura = stevila1.stevila[0];
			this->ambientalneLastnosti.vlaga = stevila1.stevila[1];
			this->ambientalneLastnosti.osvetljenost = stevila1.stevila[2];
		}
		else {
			debug("--napaka v vrsici 1");
			debug("##v funkciji Datoteka::beri vracam false");
			this->analiza += string("V vrstici 1 je napaka.\nStevilo podatkov v vrstici 1 naj bo 3.\n");
			return false;
		}

		//Berem vrstico 2 -- interval temperature
		debug("--berem stevila iz vrstice 2");
		stevila2 = beriStevila(vrstice[1]);
		debug("--preverjam veljavnost vrstica 2");
		if (stevila2.uspelo && stevila2.stevila.size() == 2) {
			debug("--vrstica 2 OK, stevil 2");
			debug("##v ambientalne lastnosti zapisujem interval temperature");
			this->ambientalneLastnosti.temperaturaMin = stevila2.stevila[0];
			this->ambientalneLastnosti.temperaturaMax = stevila2.stevila[1];
		}
		else {
			debug("--napaka v vrsici 2");
			debug("##v funkciji Datoteka::beri vracam false");
			this->analiza += string("V vrstici 2 je napaka.\nStevilo podatkov v vrstici 2 naj bo 2.\n");
			return false;
		}
		//Berem vrstico 3 -- interval vlege
		debug("--berem stevila iz vrstice 3");
		stevila3 = beriStevila(vrstice[2]);
		debug("--preverjam veljavnost vrstica 3");
		if (stevila3.uspelo && stevila3.stevila.size() == 2) {
			debug("--vrstica 3 OK, stevil 2");
			debug("##v ambientalne lastnosti zapisujem interval vlage");
			this->ambientalneLastnosti.vlagaMin = stevila3.stevila[0];
			this->ambientalneLastnosti.vlagaMax= stevila3.stevila[1];
		}
		else {
			debug("--napaka v vrsici 3");
			debug("##v funkciji Datoteka::beri vracam false");
			this->analiza += string("V vrstici 3 je napaka.\nStevilo podatkov v vrstici 3 naj bo 2.\n");
			return false;
		}

		debug("--berem stevila iz vrstice 4");
		stevila4 = beriStevila(vrstice[3]);
		debug("--preverjam veljavnost vrstica 4");
		if (stevila4.uspelo && stevila4.stevila.size() == 2) {
			debug("--vrstica 4 OK, stevil 2");
			debug("##v ambientalne lastnosti zapisujem interval osvetljenosti");
			this->ambientalneLastnosti.osvetljenostMin = stevila4.stevila[0];
			this->ambientalneLastnosti.osvetljenostMax = stevila4.stevila[1];
		}
		else {
			debug("--napaka v vrsici 4");
			debug("##v funkciji Datoteka::beri vracam false");
			this->analiza += string("V vrstici 4 je napaka.\nStevilo podatkov v vrstici 4 naj bo 2.\n");
			return false;
		}
	}
	debug("--v ambientalne lastnosti sem zapisal vse prebrane paramete");
	debug("--funkcija se je uspesno zalkjucila");
	debug("##v funkciji Datoteka::beri vracam true");
	this->uspelo = true;
	return true;
}



void Datoteka::debug(string besedilo) {
	this->podrobnaAnaliza = this->podrobnaAnaliza + string(besedilo) + string("\n");
}

bool Datoteka::preveriZnake(string vrstica, Polje polje) {

	for (int i = 0; i < vrstica.size(); ++i) {
		bool pravilnost = false;
		for (int j = 0; j <= polje.velikost; ++j) {
			if (vrstica[i] == polje.polje[j]) {
				pravilnost = true;
			}
		}
		if (!pravilnost) {
			return false;
		}
	}
	return true;
}


Stevila Datoteka::beriStevila(string vrstica) {
	Stevila rezultat;
	string stevilo;
	for (int i = 0; i < vrstica.size(); ++i) {
		if (isdigit(vrstica[i])) {
			stevilo += vrstica[i];
			if (i == vrstica.size() - 1) {
				rezultat.stevila.push_back(stoi(stevilo));
			}
		}
		else {
			if (stevilo.size()) {
				rezultat.stevila.push_back(stoi(stevilo));
				stevilo = "";
			}
			else {
				if (vrstica[i] != '[' && vrstica[i] != ']' && vrstica[i] != ' ' && vrstica[i] != ',') {
					rezultat.uspelo = false;
				}
			}
		}
	}
	return rezultat;
}


bool Datoteka::datotekaOdprata() {
	ifstream datoteka(this->ime);
	this->obstojDatoteke = datoteka.is_open();
	return datoteka.is_open();
}