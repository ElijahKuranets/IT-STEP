#pragma once
#include "Kuranets_Parallelogram.h"

class Rectangle : public Parallelogram
{
public:
	Rectangle() {}
	Rectangle(const double, const double);

	double getSideAB() const;
	void setSideAB(const double);

	double getSideBC() const;
	void setSideBC(const double);

	double getArea();

	virtual ~Rectangle() {}
};
