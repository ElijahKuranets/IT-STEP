#include "Kuranets_Parallelogram.h"
#include <iostream>
#include <cmath>
#include <exception>

#define PI 3.14

Parallelogram::Parallelogram(const double a, const double b, const double c) {

	if (a > 0 && b > 0 && c > 0 && c < 180) {
		sideAB = a;
		sideBC = b;
		angleBAD = c;
	}
	else std::cout << "Parallelogram error.Parallelogram doesn't exist\n";
}

double Parallelogram::getSideAB() const {
	return sideAB;
}

void Parallelogram::setSideAB(const double newSideA) {
	sideAB = newSideA;
}

double Parallelogram::getSideBC() const {
	return sideBC;
}

void Parallelogram::setSideBC(const double newSideB) {
	sideBC = newSideB;
}

double Parallelogram::getAngleBAD() const {
	return angleBAD;
}

void Parallelogram::setAngleBAD(const double newAngleA) {
	angleBAD = newAngleA;
}

double Parallelogram::getArea() {
	double S = sideAB * sideBC * sin(angleBAD * PI / 180);
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь несуществующего параллелограмма");
	return S;
}
