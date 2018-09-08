#include <iostream>
#include <ctime>
using namespace std;


void wypelnijMacierz(int** t1, int n, int minv, int maxv) {
	time_t t;
	srand(time(&t));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(*(t1 + i) + j) = rand() % (2 * maxv - 1) + minv + 1;
		}
	}
}


void wypiszMacierz(int** t1, int n) {
	const int p = 4;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(p);
			cout << *(*(t1 + i) + j) << " ";
		}
		cout << endl;
	}
}


double sredniaPodPrzekatna(int** t1, int n) {
	double suma = 0.0;
	int ile = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			suma += *(*(t1 + j) + i);
			ile++;
		}
	}

	if (ile)
		return suma / ile;
	else
		return suma;
}


//Obliczyc srednia arytmetyczna elementow znajdujacych sie "pod" przekatna glowna macierzy.
void Zadanie1(void) {
	const int N = 30;
	int n = 0;
	int** t1 = NULL;
	const int minv = -3;
	const int maxv = 3;

	do {
		cout << "Podaj liczbe naturalna n (1<=n<=" << N << ") : ";
		cin >> n;
	} while (n < 1 || n > N);

	t1 = new int*[n];
	for (int i = 0; i < n; i++) {
		*(t1 + i) = new int[n];
	}

	wypelnijMacierz(t1, n, minv, maxv);
	cout << endl << "Macierz liczb calkowitych o wymiarze " << n << " x " << n << ":" << endl;
	wypiszMacierz(t1, n);

	cout << endl << "Srednia arytmetyczna elementow 'spod przekatnej' macierzy: "
		<< sredniaPodPrzekatna(t1, n) << endl;

	for (int i = 0; i < n; i++) {
		delete[] * (t1 + i);
	}
	delete[] t1;
	t1 = NULL;
}