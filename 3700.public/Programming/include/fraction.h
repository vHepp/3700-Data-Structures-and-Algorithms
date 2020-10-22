#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>

class Fraction {
 public:
  Fraction(int n=0,int d=1);
  ~Fraction(void);

  Fraction operator+(Fraction rhs);
  Fraction operator-(Fraction rhs);
  Fraction operator*(Fraction rhs);
  Fraction operator/(Fraction rhs);
  Fraction operator=(Fraction rhs);

  bool operator==(Fraction rhs);
  bool operator!=(Fraction rhs);
  bool operator<(Fraction rhs);
  bool operator>(Fraction rhs);
  bool operator<=(Fraction rhs);
  bool operator>=(Fraction rhs);

  int32_t getNum() { return num; }
  int32_t getDen() { return den; }

 private:
  int32_t
    num,	// numerator
    den;	// denominator
};

std::istream &operator>>(std::istream &,Fraction &);
std::ostream &operator<<(std::ostream &,Fraction);

#endif
