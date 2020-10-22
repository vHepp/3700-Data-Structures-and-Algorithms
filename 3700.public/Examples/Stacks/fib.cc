#include <iostream>
#include <cmath>

using namespace std;

const double FUDGE_FACTOR = 1.0 / sqrt(5.0);
const double PHI = (1.0 + sqrt(5.0)) / 2.0;

int rFib(int n) {

  if (n > 1)
    return rFib(n-1) + rFib(n-2);
  return n;
}

int dFib(int n) {

  return FUDGE_FACTOR * pow(PHI,n) + 0.5;
}

int main() {
  int
    i,f1,f2;

  for (i=0;i<50;i++) {
    f1 = dFib(i);
//    f2 = rFib(i);
    cout << i << '\t' << f1 << '\t' << f2 << endl;
  }

  return 0;
}

