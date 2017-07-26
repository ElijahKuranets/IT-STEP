#include "Kuranets_Triangle.h"
#include <iostream>
#include <cmath>
#include <exception>

#define PI 3.14

Triangle::Triangle(const double a, const double b, const double c, size_t x) {

	if (a <= 0 || b <= 0 || c <= 0) {
		std::cout << "Triangle error.Triangle doesn't exist\n";
	}

	if (x == 1) {
		if (b < 180 && c < 180) {
			sideAB = a;
			angleABC = b;
			angleBCA = c;
			angleBAC = 180 - (b + c);
			sideBC = (a * sin(b * PI / 180)) / sin(angleBAC * PI / 180);
			sideAC = sideBC * sin(c * PI / 180) / sin(b * PI / 180);
		}
		else {
			std::cout << "Triangle error.Triangle doesn't exist\n";
			sideAB = 0;
			sideBC = 0;
			sideAC = 0;
			angleBAC = 0;
			angleABC = 0;
			angleBCA = 0;
		}
	}

	if (x == 2) {
		if (c < 180) {
			sideAB = a;
			sideBC = b;
			angleBCA = c;
			sideAC = a * a + b * b - 2 * a * b * cos(c * PI / 180);
			angleABC = b * sin(c * PI / 180) / sideAC;
			angleBAC = a * sin(angleABC * PI / 180) / b;
			test(sideAB, sideAB, sideAB);
		}
		else {
			std::cout << "Triangle error.Triangle doesn't exist\n";
			sideAB = 0;
			sideBC = 0;
			sideAC = 0;
			angleBAC = 0;
			angleABC = 0;
			angleBCA = 0;
		}
	}

	if (x == 3) {
		sideAB = a;
		sideBC = b;
		sideAC = c;
		angleBAC = acos((b * b + c * c - a * a) / 2 * b * c);
		angleABC = acos((a * a + c * c - b * b) / 2 * a * c);
		angleBCA = 180 - (angleBAC + angleABC);
	}

	if (test(sideAB, sideBC, sideAC) != true) {
		std::cout << "Triangle error.Triangle doesn't exist\n";
		sideAB = 0;
		sideBC = 0;
		sideAC = 0;
		angleBAC = 0;
		angleABC = 0;
		angleBCA = 0;
	}
}

bool Triangle::test(double sideA, double sideB, double sideC) {
	return sideA <= sideB + sideC;
}

double Triangle::getSideAB() const {
	return sideAB;
}

void Triangle::setSideAB(const double newSideA) {
	sideAB = newSideA;
}

double Triangle::getSideBC() const {
	return sideBC;
}

void Triangle::setSideBC(const double newSideB) {
	sideBC = newSideB;
}

double Triangle::getSideAC() const {
	return sideAC;
}

void Triangle::setSideAC(const double newSideC) {
	sideAC = newSideC;
}

double Triangle::getAngleBAC() const {
	return angleBAC;
}

void Triangle::setAngleBAC(const double newAngleA) {
	angleBAC = newAngleA;
}

double Triangle::getAngleABC() const {
	return angleABC;
}

void Triangle::setAngleABC(const double newAngleB) {
	angleABC = newAngleB;
}

double Triangle::getAngleBCA() const {
	return angleBCA;
}

void Triangle::setAngleBCA(const double newAngleC) {
	angleBCA = newAngleC;
}

double Triangle::getArea() {
	double p = (sideAB + sideBC + sideAC) / 2;
	double S = sqrt(p * (p - sideAB) * (p - sideBC) * (p - sideAC));
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь несуществующего треугольника");
	return S;
}
