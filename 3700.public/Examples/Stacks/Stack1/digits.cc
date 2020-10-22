#include <iostream>
#include "simpleStack.h"

using namespace std;

int main() {
  int
    n,d;
  SimpleStack
    s;

  cout << "Enter a number: ";
  cin >> n;

  while (n != 0) {
    d = n % 10;
    n = n / 10;

    s.push(d);
  }

  while (!s.isEmpty()) {
    d = s.pop();

    cout << d << endl;
  }

  return 0;
}

