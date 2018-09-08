#include <iostream>
using namespace std;


class Robot {
private:
	int wymiary[3]; //szerokosc, dlugosc, wysokosc
	int mobilny; // 1 lub 0
	float predkosc;
public:
	Robot();
	Robot(int* wym, int mob = 0, float pred = 0.0);
	Robot(Robot&);
	bool operator==(const Robot&) const;
	Robot operator+(const Robot&) const;
	friend ostream& operator<<(ostream& outs, const Robot& robot);
};


Robot::Robot() {
	for (int i = 0; i < 3; i++) {
		wymiary[i] = 10;
	}

	mobilny = 0;
	predkosc = 0.0;
}


Robot::Robot(Robot &robot) {
	for (int i = 0; i < 3; i++) {
		wymiary[i] = robot.wymiary[i];
	}
	mobilny = robot.mobilny;
	predkosc = robot.predkosc;
}


Robot::Robot(int* wym, int mob, float pred) {
	for (int i = 0; i < 3; i++) {
		wymiary[i] = wym[i];
	}

	mobilny = mob;
	predkosc = pred;
}


bool Robot::operator==(const Robot& robot) const {

	if (wymiary[0] != robot.wymiary[0]) {
		return false;
	}

	if (wymiary[1] != robot.wymiary[1]) {
		return false;
	}

	if (wymiary[1] != robot.wymiary[1]) {
		return false;
	}

	if (mobilny != robot.mobilny) {
		return true;
	}
	else {
		if (mobilny == 0 && robot.mobilny == 0) {
			return true;
		}
		else {
			if (predkosc == robot.predkosc) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}


Robot Robot::operator+(const Robot& robot) const {
	int maxwymiary[3];
	int mob = 0;
	float pred = 0.0;

	if (wymiary[0] > robot.wymiary[0]) {
		maxwymiary[0] = wymiary[0];
	}
	else {
		maxwymiary[0] = robot.wymiary[0];
	}

	if (wymiary[1] > robot.wymiary[1]) {
		maxwymiary[1] = wymiary[1];
	}
	else {
		maxwymiary[1] = robot.wymiary[1];
	}

	maxwymiary[2] = wymiary[2] + robot.wymiary[2];

	if (mobilny == 1 || robot.mobilny == 1) {
		mob = 1;
		pred = predkosc + robot.predkosc;
	}

	Robot w(maxwymiary, mob, pred);
	return w;
}


ostream& operator<<(ostream& outs, const Robot& robot) {
	outs << "Szerokosc robota: " << robot.wymiary[0] << endl;
	outs << "Dlugosc robota: " << robot.wymiary[1] << endl;
	outs << "Wysokosc robota: " << robot.wymiary[2] << endl;
	outs << "Mobilnosc robota: " << robot.mobilny << endl;
	outs << "Predkosc robota: " << robot.predkosc;
	return outs;
}


void porownanie(const Robot& r1, const Robot& r2) {
	if (r1 == r2) {
		cout << "rowne";
	}
	else {
		cout << "rozne";
	}
}

void Zadanie5(void) {
	Robot r0;
	Robot r1(r0);
	int r2wym[3] = { 20, 5, 60 };
	Robot r2(r2wym, 1, 5.5);

	cout << "Robot r0 ('domyslny'):" << endl;
	cout << r0;
	cout << endl << endl;

	cout << "Robot r1 ('sklonowany'):" << endl;
	cout << r1;
	cout << endl << endl;

	cout << "Robot r2 ('sparametryzowany'):" << endl;
	cout << r2;
	cout << endl << endl;

	cout << "Porownanie robotow r0 i r1: ";
	porownanie(r0, r1);
	cout << endl << endl;

	cout << "Porownanie robotow r0 i r2: ";
	porownanie(r0, r2);
	cout << endl << endl;

	cout << "'Suma' robotow r0 i r2: " << endl;
	cout << (r0 + r2);
	cout << endl << endl;
}