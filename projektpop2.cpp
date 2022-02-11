//POP_2020_01_15_projekt_2_Betka_Szymon_EIT_3_180067 Visual Studio 2019
#include<fstream>
#include <iostream>
#include<iomanip>
#include<string>
#include<cstdlib>

using namespace std;


void kopia(string, string);
void wyswietlanie(string);
void edycja(string, string);
void usuwanie(string, string);
void szukanie(string, string);
void wyswietlanie_frag(string);
void nowe(string, string);


struct pomocnik {
	string linijka;
	string szukanko;
};


const int MAX_N = 1000;


void kopia(string nazwa,string nazwa_doc)        //FUNKCJA KOPIUJE ORYGINALNY PLIK W CELU ZACHOWANIA ORYGINALU
{
	string linia;
	fstream wejscie;
	ofstream wyjscie;
	wejscie.open(nazwa);                        
	wyjscie.open(nazwa_doc);
	while (!wejscie.eof())
	{
		getline(wejscie, linia);
		wyjscie << linia << endl;

	}
	wejscie.close();
	wyjscie.close();
}


void wyswietlanie(string nazwa_doc)             //FUNKCJA DO WYSWIETLANIA CALEGO PLIKU
{
	string linia;
	fstream wejscie;
	wejscie.open(nazwa_doc);
	int i = 1; 
	cout << endl;
	while (!wejscie.eof())
	{
		getline(wejscie, linia);
		if (linia.size() >= 1)
		{
			cout << i << ". " << linia << endl;
		}
		
		i++;
	}
	wejscie.close();
	
}


void edycja(string nazwa_doc,string pomocniczy_xml)   //FUNKCJA ZASTEPUJE CALY WIERSZY NOWO WPROWADZONYM WIERSZEM
{
	int numer_wiersza;
	string linia;
	ifstream wejscie;
	ofstream wyjscie;

	cout << "PODAJ NUMER WIERSZA KTORY CHCESZ ZAMIENIC: "<<endl;

	cin >> numer_wiersza;

	wyjscie.open(pomocniczy_xml);
	wejscie.open(nazwa_doc);
	int i = 1;
	while (!wejscie.eof())
	{
		getline(wejscie, linia);

		if(i == numer_wiersza)
		{
			int k = 0;
			while (linia[k] == ' '&& k<linia.size())
			{
				k++;
			}
			string ilosc_spacji_przed(k, ' ');
			cout << "WPISZ NOWA ZAWARTOSC LINII: " << endl;
			string nowa_linia;
			cin.ignore();
			getline(cin, nowa_linia);
			linia =ilosc_spacji_przed+ nowa_linia;
		}
		i++;

		wyjscie << linia << endl;
			
	}
	wejscie.close();
	wyjscie.close();
	kopia(pomocniczy_xml, nazwa_doc);

}


void usuwanie(string nazwa_doc,string pomocniczy_xml)    //FUNKCJA USUWA WYBRANA LINIE
{
	ifstream wejscie;
	ofstream wyjscie;
	string linia;


	wejscie.open(nazwa_doc);
	wyjscie.open(pomocniczy_xml);
	cout << "PODAJ NR LINII DO USUNIECIA: ";
	int nr_linii;
	cin >> nr_linii;

	int i = 1;
	while (getline(wejscie, linia))
	{
		if (i != nr_linii)                     
		{
			wyjscie << linia << endl;
		}
		i++;


	}
	wyjscie.close();
	wejscie.close();

	kopia(pomocniczy_xml,nazwa_doc);      //po zakonczonej operacji na pliku pomocniczym dane zapisuja sie na pliku docelowym
}


void szukanie(string nazwa)        //SZUKANIE PO ZADANEJ FRAZIE
{
	fstream wejscie;
	string linia;
	wejscie.open(nazwa,ios::in);

	string szukane;
	cout << "WPISZ SZUKANA FRAZE(NP.(jajco)): ";
	cin >> szukane;
	int licznik = 1;
	while (!wejscie.eof())
	{
	
		//getline(wejscie, linia);
		getline(wejscie, linia);

		size_t znalezionaPozycja = linia.find(szukane);
		if (znalezionaPozycja != std::string::npos)
		{
			cout <<"ZNALEZIONO W LINII NR: "<< licznik << endl;
		}
		licznik++;

	}

	wejscie.close();
}

void instrukcja()
{
	cout << "*----------INSTRUKCJA OBSLUGI----------*" << endl;
	cout << "1.ABY POPRAWNIE KORZYSTAC Z PROGRAMU    " << endl;
	cout << "  NALEZY NAJPIERW ZAPOZNAC SIE Z PLIKAMI" << endl;
	cout << "  XML(JAK DZIALAJA ITP,POLECAM w3.com   " << endl;
	cout << "2.PODCZAS WYBIERANIA OPCJI NIE NALEZY   " << endl;
	cout << "  WPISYWAC NIEPOZADANYCH ZNAKOW NP      " << endl;
	cout << "  ODZIELONYCH SPACJA CYFR PONIEWAZ MOZE " << endl;
	cout << "  TO SKUTKOWAC NIEPOZADANYM DZIALANIEM  " << endl;
	cout << "  PROGRAMU                              " << endl;
}


void wyswietlanie_frag(string nazwa_doc)                //WYSWIETLANIE FRAGMENTU PLIKU
{
	fstream wejscie;
	wejscie.open(nazwa_doc);
	string linia;
	int poczatek,koniec;
	int i=0;

	cout << "PODAJ NR LINII OD KTOREJ POKAZAC PLIK: ";
	cin >> poczatek;
	cout << "PODAJ NR LINII DO KTOREJ POKAZAC PLIK: ";
	cin >> koniec;
	if (poczatek > koniec)
	{
		cout << endl << "NIEPOPRAWNE DANE! KONIEC NIE MOZE BYC MNIEJSZY NIZ POCZATEK!" << endl;
	}
	else
	{
		pomocnik tab[MAX_N];

		while (!wejscie.eof())
		{
			getline(wejscie, linia);
			tab[i].linijka = linia;
			i++;
		}

		cout << endl;

		for (int i = (poczatek - 1); i <= (koniec - 1); i++)
		{
			cout << i + 1 << ". " << tab[i].linijka << endl;
		}
	}

	wejscie.close();
}

void nowe(string nazwa_doc, string pomocniczy_xml)
{
	ifstream wejscie;
	ofstream wyjscie;
	string linia;
	string nowa;


	wejscie.open(nazwa_doc);
	wyjscie.open(pomocniczy_xml);
	cout << "PODAJ NR LINII W KTOREJ CHCESZ COS WPISAC: ";
	int nr_linii;
	cin >> nr_linii;
	cout << endl << "PODAJ ZAWARTOSC NOWEJ LINII: ";
	cin >> nowa;

	int i = 1;
	while (getline(wejscie, linia))
	{
		if (i != nr_linii)
		{
			wyjscie << linia << endl;
		}
		else if (i = nr_linii)
		{
			wyjscie << nowa << endl;
		}
		i++;


	}
	wyjscie.close();
	wejscie.close();

	kopia(pomocniczy_xml, nazwa_doc);

}

int main()
{
	string nazwa;
	string nazwa_doc;
	string pomocniczy_xml = "pomocniczy.xml";
	string wybor;
	while (wybor != "1")
	{
		cout << "*----------WITAJ UZYTKOWNIKU----------*" << endl;
		cout << "| PROGRAM SLUZY DO OBSLUGI PLIKOW XML |" << endl;
		cout << "| WYBIERZ OPCJE I ROZPOCZNIJ PRACE:   |" << endl;
		cout << "| 1=START                             |" << endl;
		cout << "| 2=MENU                              |" << endl;
		cout << "| 0=WYJSCIE                           |" << endl;
		cout << "*-------------------------------------*" << endl;
	
		cin >> wybor;

		if (wybor == "0")
		{
			exit(0);
		}
		else if (wybor == "2")
		{
			system("cls");

			instrukcja();
		}
		else
		{
			system("cls");

			cout << "NIE MA TAKIEJ OPCJI! WPISZ CYFRE(1, 2 lub 0)" << endl;
		}
	}
	system("cls");

	cout << "PODAJ NAZWE PLIKU((nazwa pliku).xml): ";
	cin >> nazwa;

	system("cls");

	cout << "PODAJ NAZWE PLIKU KTORY SIE UTWORZY((twoja nazwa pliku).xml): ";
	cin >> nazwa_doc;

	kopia(nazwa, nazwa_doc);
	
	int wybor2;

	do
	{
		cout << "*-------------------------------------*" << endl;
		cout << "| OPCJE PRACY:                        |" << endl;
		cout << "| 0.WYSWIETLANIE                      |" << endl;
		cout << "| 1.DODANIE NOWEJ LINII               |" << endl;
		cout << "| 2.SZUKANIE                          |" << endl;
		cout << "| 3.EDYTOWANIE                        |" << endl;
		cout << "| 4.USUWANIE                          |" << endl;
		cout << "| 5.WYSWIETLANIE FRAGMENTU            |" << endl;
		cout << "| 6.CZYSZCZENIE OKNA KONSOLI          |" << endl;
		cout << "| 7.ZAKONCZ                           |" << endl;
		cout << "*-------------------------------------*" << endl;

		string opcja;
		cin >> opcja;
		if (opcja == "1")
		{
			nowe(nazwa_doc, pomocniczy_xml);
			wybor2 = 1;
		}
		else if (opcja == "0")
		{
			wyswietlanie(nazwa_doc);

			wybor2 = 1;
		}
		else if (opcja == "2")
		{
			szukanie(nazwa_doc);

			wybor2 = 1;
		}
		else if (opcja == "3")
		{
			edycja(nazwa_doc, pomocniczy_xml);

			wybor2 = 1;
		}
		else if (opcja == "4")
		{
			usuwanie(nazwa_doc, pomocniczy_xml);

			wybor2 = 1;
		}
		else if (opcja == "5")
		{
			wyswietlanie_frag(nazwa_doc);

			wybor2 = 1;
		}
		else if (opcja == "6")
		{
			system("cls");

			wybor2 = 1;
		}
		else if (opcja == "7")
		{
			exit(0);
		}
		else
		{
			system("cls");

			cout << "NIE MA TAKIEJ OPCJI! WPISZ CYFRE (1-7)" << endl;

			wybor2 = 1;
		}
		
	} while (wybor2 == 1);


		return 0;
}