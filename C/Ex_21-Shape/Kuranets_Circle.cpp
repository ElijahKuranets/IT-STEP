#include "Kuranets_Circle.h"
#include <iostream>
#include <exception>

#define PI 3.14

Circle::Circle(const double a, const double b, const double c) {
	if (a > 0) {
		radius = a;
		centerX = b;
		centerY = c;
	}
	else std::cout << "Circle error.This Circle does'n exist\n";
}

double Circle::getSideA() const {
	return radius;
}

void Circle::setSideA(const double newRadius) {
	radius = newRadius;
}

double Circle::getCenterX() const {
	return centerX;
}

void Circle::setCenterX(const double newCenterX) {
	centerX = newCenterX;
}

double Circle::getCenterY() const {
	return centerY;
}

void Circle::setCenterY(const double newCenterY) {
	centerY = newCenterY;
}

double Circle::getArea() {
	double S = PI * pow(radius, 2);
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь не существующего круга");
	return S;
}
