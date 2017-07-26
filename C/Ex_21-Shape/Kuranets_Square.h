#pragma once
#include "Kuranets_Rectangle.h"

class Square : public Rectangle
{
public:
	Square(const double a);

	double getSideAB() const;
	void setSideAB(const double);

	double getArea();

	~Square() {}
};
