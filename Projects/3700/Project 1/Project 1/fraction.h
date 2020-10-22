#include <cstdint>
#include <iostream>
using namespace std;


#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction {
	public:
		Fraction(int32_t num=0,int32_t den=1);
		~Fraction(void);

		Fraction operator+(Fraction rhs);
		Fraction operator-(Fraction rhs);
		Fraction operator*(Fraction rhs);
		Fraction operator/(Fraction rhs);
		Fraction operator=(Fraction rhs);

		bool operator==(Fraction rhs);
		bool operator<(Fraction rhs);
		bool operator>(Fraction rhs);
		bool operator>=(Fraction rhs);
		bool operator<=(Fraction rhs);
		bool operator!=(Fraction rhs);

		int32_t getNum() { return num; } //getter for numerator
		int32_t getDen() { return den; } //getter for denominator

	private:
		int32_t num, den;

	};

	istream &operator>>(std::istream &,Fraction &);
	ostream &operator<<(std::ostream &,Fraction );

#endif
