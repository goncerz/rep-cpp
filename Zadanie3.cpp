#include <iostream>
#include <cctype>
#include <conio.h>
using namespace std;


void Zadanie3(void) {
	const int ile = 26;
	const int kodA = 65;
	const int kodEnter = 13;

	int litery[ile] = { 0 };
	char c = 0;

	cout << "Prosze wpisac jakis tekst:" << endl << endl;
	while (1) {
		c = _getch();

		if (c == kodEnter) {
			cout << endl;
			break;
		}
		else {
			cout << c;

			if (isalpha(c)) {
				litery[toupper(c) - kodA]++;
			}
		}
	}
	cout << endl << endl << "W podanym tekscie wystapily nastepujace litery:" << endl << endl;

	for (int i = 0; i < ile; i++) {
		if (litery[i]) {
			cout << char(kodA + i) << " | " << litery[i] << " razy" << endl;
		}
	}
	cout << endl;
}