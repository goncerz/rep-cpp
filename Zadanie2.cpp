#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


bool palindrom(char *tekst) {
	bool p = 0;
	char *a, *z;
	a = tekst;
	z = tekst + strlen(tekst) - 1;

	while (a < z) {
		while (!isalnum(*a))
			a++;

		while (!isalnum(*z))
			z--;

		if (tolower(*a) != tolower(*z)) {
			p++;
			break;
		}
		a++, z--;
	}


	return p;
}


void wypiszwspak(char *tekst) {
	char *w = tekst;

	while (*w) {
		w++;
	}
	w--;

	while (w >= tekst) {
		//char c = *w;
		cout << *w;
		w--;
	}
}


void Zadanie2(void) {
	char tekst[1000];
	cout << "Prosze wprowadzic jakis tekst:" << endl;
	cin.getline(tekst, sizeof(tekst), '\n');

	cout << endl << "Wprowadzony tekst ";

	if (palindrom(tekst) == 0)
		cout << "jest palindromem." << endl;
	else {
		cout << "nie jest palindromem." << endl << endl;
		cout << "Ten tekst jest palindromem:" << endl;

		cout << tekst;
		wypiszwspak(tekst);
		cout << endl;
	}
}
