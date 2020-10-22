#include <iostream>

using namespace std;

int iFact(int n) {
  int
    f,
    ans=1;

  for (f=2;f<=n;f++)
    ans *= f;

  return ans;
}

int rFact(int n) {

  if (n > 0)
    return n * rFact(n-1);
  return 1;
}

int main() {
  int n,f;

  cout << "Enter an integer: ";
  cin >> n;

  f = iFact(n);
  cout << "Looping: " << f << endl;

  f = rFact(n);
  cout << "Recursion: " << f << endl;

  return 0;
}

