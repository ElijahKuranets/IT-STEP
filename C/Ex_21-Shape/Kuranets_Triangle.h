#pragma once
#include "Shape.h"

class Triangle : public Shape
{
	double sideAB = 0;
	double sideBC = 0;
	double sideAC = 0;
	double angleBAC = 0;
	double angleABC = 0;
	double angleBCA = 0;
public:
	Triangle(const double, const double, const double, const size_t);
	bool test(double, double, double);

	double getSideAB()const;
	void setSideAB(const double);

	double getSideBC() const;
	void setSideBC(const double);

	double getSideAC() const;
	void setSideAC(const double);

	double getAngleBAC() const;
	void setAngleBAC(const double);

	double getAngleABC() const;
	void setAngleABC(const double);

	double getAngleBCA() const;
	void setAngleBCA(const double);

	double getArea();

	~Triangle() {}
};
