#include "Kuranets_Rectangle.h"
#include <iostream>
#include <exception>

Rectangle::Rectangle(const double a, const double b) {
	if (a > 0 && b > 0) {
		Parallelogram::setSideAB(a);
		Parallelogram::setSideBC(b);
		Parallelogram::setAngleBAD(90);
	}
	else std::cout << "Rectangle error\n";
}

double Rectangle::getSideAB() const {
	return Parallelogram::getSideAB();
}

void Rectangle::setSideAB(const double newSideA) {
	Parallelogram::setSideAB(newSideA);
}

double Rectangle::getSideBC() const {
	return Parallelogram::getSideBC();
}

void Rectangle::setSideBC(const double newSideB) {
	Parallelogram::setSideBC(newSideB);
}

double Rectangle::getArea() {
	double S = Parallelogram::getSideAB() * Parallelogram::getSideBC();
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь несуществующего  прямоугольника");
	return S;
}
