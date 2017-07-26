#include "Kuranets_Square.h"
#include <iostream>
#include <exception>

Square::Square(const double a) {
	if (a > 0) {
		Rectangle::setSideAB(a);
	}
	else std::cout << "Square error.This square doesn't exist\n";
}

double Square::getSideAB() const {
	return Rectangle::getSideAB();
}

void Square::setSideAB(const double newSideA) {
	Rectangle::setSideAB(newSideA);
}

double Square::getArea() {
	double S = pow(Rectangle::getSideAB(), 2);
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь несуществующего  квадрата");
	return S;
}
