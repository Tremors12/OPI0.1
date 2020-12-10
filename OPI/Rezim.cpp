#include "Rezim.h"


void Rezim::izracunaj() {
	
}

Odstopanje Rezim::avtomatskiNacin(AmbientalneLastnosti ambientalneLastnosti, TrenutneAmbientalneLastnosti trenutneAmbientalneLastnosti) {
	Odstopanje odstopanje;
	odstopanje.temperatura = this->odstopanje(trenutneAmbientalneLastnosti.trenutnaTemperatura , ambientalneLastnosti.temperatura);
	odstopanje.vlaga = this->odstopanje(trenutneAmbientalneLastnosti.trenutnaVlaga, ambientalneLastnosti.vlaga);
	odstopanje.osvetljenost = this->odstopanje(trenutneAmbientalneLastnosti.trenutnaOsvetljenost, ambientalneLastnosti.osvetljenost);

	//Sedaj naredimo izpise
	//Temperatura
	if (odstopanje.temperatura == 0) {
		cout << "Temperatura v prostoru je optimalna." << endl;
	}
	else if (odstopanje.temperatura > 0) {
		cout << "Izklop grelca." << endl;
	}
	else if (odstopanje.temperatura < 0) {
		cout << "Vklop grelca." << endl;
	}
	//Vlaga
	if (odstopanje.vlaga == 0) {
		cout << "Temperatura v prostoru je optimalna." << endl;
	}
	else if (odstopanje.vlaga > 0) {
		cout << "Izklop vlazilca." << endl;
	}
	else if (odstopanje.vlaga < 0) {
		cout << "Vklop vlazilca." << endl;
	}
	//Osvetljenoz
	if (trenutneAmbientalneLastnosti.trenutnaOsvetljenost > 8000) { //- Izklop luèi in zatemnitev rolet (8000 lx+)
		cout << "Izklop luci in zatemnitev rolet." << endl;
	}
	else if (trenutneAmbientalneLastnosti.trenutnaOsvetljenost >= 501) { //- Izklop luèi (501 – 7999 lx)
		cout << "Izklop luci" << endl;
	}
	else if (trenutneAmbientalneLastnosti.trenutnaOsvetljenost == 500) { //V primeru, da je osvetljenost 500 lx: Osvetljenost prostora je optimalna
		cout << "Osvetljenost prostora je optimalna" << endl;
	}
	else if (trenutneAmbientalneLastnosti.trenutnaOsvetljenost >= 101) {//- Prižig luèi (101 – 499 lx)
		cout << "Prižig luci" << endl;
	}
	else if (trenutneAmbientalneLastnosti.trenutnaOsvetljenost >= 10) {
		cout << "Prizig luci in odprtje rolet (10 – 100 lx)" << endl;
	}
	return odstopanje;
}


Povprecje Rezim::avtomatskiNacinVse(AmbientalneLastnosti ambientalneLastnosti, LastnostiSimulacije lastnostiSimulacije)
{
	Povprecje povprecje;
	
	int stevec = 0;
	while (stevec < lastnostiSimulacije.stevilo) {
		cout << "Simulacija " << (stevec + 1) << "." << endl;
		TrenutneAmbientalneLastnosti trenutneAmbientalneLastnosti; 
		trenutneAmbientalneLastnosti.trenutnaTemperatura = nakljucnaVrednost(ambientalneLastnosti.temperaturaMin, ambientalneLastnosti.temperaturaMax);
		trenutneAmbientalneLastnosti.trenutnaVlaga = nakljucnaVrednost(ambientalneLastnosti.vlagaMin, ambientalneLastnosti.vlagaMax);
		trenutneAmbientalneLastnosti.trenutnaOsvetljenost = nakljucnaVrednost(ambientalneLastnosti.osvetljenostMin, ambientalneLastnosti.osvetljenostMax);
		cout << "Ambientalne vrednosti : Temperatura : " << trenutneAmbientalneLastnosti.trenutnaTemperatura << ", Svetloba : " << trenutneAmbientalneLastnosti.trenutnaOsvetljenost << ", Vlaga : " << trenutneAmbientalneLastnosti.trenutnaVlaga << endl;


		povprecje.dejanske.temperatura += trenutneAmbientalneLastnosti.trenutnaTemperatura;
		povprecje.dejanske.osvetljenost += trenutneAmbientalneLastnosti.trenutnaOsvetljenost;
		povprecje.dejanske.vlaga += trenutneAmbientalneLastnosti.trenutnaVlaga;
		Odstopanje odstopanje = avtomatskiNacin(ambientalneLastnosti, trenutneAmbientalneLastnosti);
		povprecje.zeljene.temperatura = odstopanje.temperatura;
		povprecje.zeljene.vlaga = odstopanje.vlaga;
		povprecje.zeljene.osvetljenost = odstopanje.osvetljenost;
		cout << "Zakasnitev : " << lastnostiSimulacije.zakasnitev << "ms" << endl;
		Sleep(lastnostiSimulacije.zakasnitev);
		++stevec;
	}

	povprecje.zeljene.temperatura /= lastnostiSimulacije.stevilo;
	povprecje.zeljene.vlaga /= lastnostiSimulacije.stevilo;
	povprecje.zeljene.osvetljenost /= lastnostiSimulacije.stevilo;

	cout << "Povprecje odstopanja od zeljene vrednosti : " << endl;
	cout << "Temperatura : " << povprecje.zeljene.temperatura << ", Vlaga : " << povprecje.zeljene.vlaga << ", Svetloba" << povprecje.zeljene.osvetljenost << "." << endl;
		
	povprecje.dejanske.temperatura /= lastnostiSimulacije.stevilo;
	povprecje.dejanske.vlaga /= lastnostiSimulacije.stevilo;
	povprecje.dejanske.osvetljenost/= lastnostiSimulacije.stevilo;

	cout << "Povprecje odstopanja od dejanske vrednosti : " << endl;
	cout << "Temperatura : " << povprecje.dejanske.temperatura << ", Vlaga : " << povprecje.dejanske.vlaga << ", Osvetljenost :" << povprecje.dejanske.osvetljenost << "." << endl;

	return povprecje;
}

int Rezim::odstopanje(int trenutna, int zeljena)
{
	return trenutna - zeljena;
}

int Rezim::nakljucnaVrednost(int min, int max)
{
	int razlika = max - min;
	int random = rand() % (razlika + 1);
	return random + min;
}
