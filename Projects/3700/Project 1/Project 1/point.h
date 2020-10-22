#include "fraction.h"

#ifndef _POINT_H
#define _POINT_H

class Point {
	public:
		Point(Fraction x = Fraction(0,1),Fraction y = Fraction(0,1));
		~Point(void);

		Point operator+(Point rhs);
		Point operator-(Point rhs);
	
		Point operator=(Point rhs);

		Fraction operator*(Point rhs); //Crossproduct
		Point operator*(Fraction rhs);

		Fraction getX() { return x; } //getter for x value
		Fraction getY() { return y; } //getter for y value
	
		bool operator==(Point rhs);
		bool operator!=(Point rhs);
	
		friend class Polygon;

	private:
		Fraction x, y;

};

class Polygon {
	public:
		Polygon(int32_t);
		~Polygon(void);
		
		
		Point FindOutsidePoint(Polygon, Point);
		bool Intersect(Point, Point, Point, Point);
	
		Point getP1() { return p1; };
		Point getP2() { return p2; };
		Point getPoint(int32_t i) { return list[i]; };
	
		Point list [100];

	private:
		Point p1, p2;
		int32_t size;
};


	istream &operator>>(std::istream &,Point &);
	ostream &operator<<(std::ostream &,Point );


#endif
