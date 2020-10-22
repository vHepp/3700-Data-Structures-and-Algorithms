#include "point.h"

Point::Point(Fraction x,Fraction y) {

	this -> x = x;
	this -> y = y;

}

Point::~Point(void) { }

Point Point::operator+(Point rhs) {
	Fraction tempX, tempY;

	tempX = x + rhs.x;
	tempY = y + rhs.y;

	return Point(tempX,tempY);

}

Point Point::operator-(Point rhs) {

	Fraction tempX, tempY;

	tempX = x - rhs.x;
	tempY = y - rhs.y;

	return Point(tempX,tempY);

}

Fraction Point::operator*(Point rhs) {

	Fraction xProduct;

	xProduct = (x * rhs.y) - (y * rhs.x);

	return xProduct;

} //Cross product

Point Point::operator*(Fraction rhs) { 

	Fraction tempX, tempY;

	tempX = x * rhs;
	tempY = y * rhs;

	return Point(tempX,tempY);

}

Point Point::operator=(Point rhs){
	x = rhs.x;
	y = rhs.y;

	return *this;
}

bool Point::operator==(Point rhs){
	
	return (x == rhs.x && y == rhs.y);
}

bool Point::operator!=(Point rhs){
	
	return (x != rhs.x || y != rhs.y);
}


//Polygon class functions
Polygon::Polygon(int32_t k){
	Point temp;
	
	for (int32_t i = 0; i < k; i++)
	{
		cin >> temp;
		list[i] = temp;
	}
	size = k;
	
}

Polygon::~Polygon(void) { }

Point Polygon::FindOutsidePoint(Polygon Q, Point p1){
	Fraction increment(1,1);
	Fraction x(0,1);
	Fraction yMax = list[0].getY();
	bool good;
	
	for (int32_t i = 1; i < size; i++){
		if (list[i].getY() > yMax)
			yMax = list[i].getY();
	}
	
	yMax = yMax + increment;	
	
	do {
		x = x + increment;
		p2 = Point(x,yMax);
		good = true;
		for (int32_t i = 0; i < size; i++){
			if (((list[i] - p1)*(p2-p1)) == 0) {
				good = false;
			}
		}
	}
	while (good == false);

	return Point(x,yMax);
}

bool Polygon::Intersect(Point p1, Point p2, Point q1, Point q2){
	
	Point r = (p2 - p1);
	Point s = (q2 - q1);
	
	
	Point v (q1 - p1);
	
	Fraction d = r*s;
	
	if (d == Fraction(0))
		return false;
	else {
		Fraction one(1,1);
		Fraction zero(0,1);
		
		Fraction t = (v*s)/d;
		Fraction u = (v*r)/d;
		
		if ((zero <= t && t <= one) && (zero <= u && u <= one))
			return true;
		else
			return false;
	}
}

// I/O
istream &operator>>(istream &is, Point &p) {

	Fraction x,y;
	char lp, rp, comma;

	is >> lp >> x >> comma >> y >> rp;


	p = Point(x,y);

	return is;
}

ostream &operator<<(ostream &os, Point p) {

	os << '(' << p.getX() << ',' << p.getY() << ')';

	return os;
}
