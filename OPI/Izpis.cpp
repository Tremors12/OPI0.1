#include "Izpis.h"



Izpis::Izpis() {

}



string Izpis::pozdrav() {
	//Izbira med režimi uporabe
	cout << "Simulator, v1.0 " << endl;
	cout << "---------------------------------------" << endl;
	cout << "Dobrodosli v programu simulator. Za delovanje programa v " << endl;
	cout << "testnem rezimu vtipkajte <simulator -t>. Za delovanje programa" << endl;
	cout << "v avtomatskem rezimu vtipkajte <simulator>. Za pomoc pritisni *." << endl;
	string rezim;
	getline(cin, rezim);
	return rezim;
}


char Izpis::glavniMeni() {
	cout << "GLAVNI MENI" << endl;
	cout << "===========" << endl;
	cout << "1) Navadni avtomatski nacin" << endl;
	cout << "2) Napredni (Covid-19) nacin" << endl;
	cout << "*) Pomoc" << endl;
	cout << "0) Izhod" << endl;
	char rezim;
	cin >> rezim;
	return rezim;
}


char Izpis::vpisAliBranje() {
	cout << "1) Vpis ambientalnih lastnosti" << endl;
	cout << "2) Branje ambientalnih lastnosti iz datoteke" << endl;
	cout << "*) Pomoc" << endl;
	cout << "0) Izhod" << endl;
	char rezim;
	cin >> rezim;
	return rezim;
}


VpisaneALastnosti Izpis::vpisiALastnosti() {
	VpisaneALastnosti rezultat;
	cout << "Vpisite ambientalne lastnosti prostora:" << endl;
	cout << "Vpisite temperaturo prostora [°C ali °F ali K]: ";
	cin >> rezultat.temperatura;
	cout << "Vpisite vlažnost prostora[%]: ";
	cin >> rezultat.vlaznost;
	cout << "Vpisite osvetljenost prostora [lx]: ";
	cin >> rezultat.osvetljenost;
	return rezultat;
}

string Izpis::imeDatoteke() {
	string ime;
	cout << "Datoteka z opisom ambientalnih lastnosti naj se nahaja v isti mapi kot se bo nahajala izvrsilna datoteka programa." << endl;
	cout << "Vpisite ime datoteke." << endl;
	cin >> ime;
	return ime;
}

LastnostiSimulacije Izpis::lastnostiSimulacije() {
	LastnostiSimulacije rezultat;
	cout << "Vpisite lastnosti simulacije." << endl;
	cout << "vpisite stevilo meritev : " << endl;
	cin >> rezultat.stevilo;
	cout << "Vpisite casovni interval med meritvami [ms] : " << endl;
	cin >> rezultat.zakasnitev;
	return rezultat;
}