#include <iostream>
#include "simpleStack.h"

using namespace std;

int main() {
  SimpleStack
    s;
  char
    ch;

  while (true) {
    cin >> ch;

    if (!cin)
      break;

    if (ch == '(')
      s.push(ch);
    else if (ch == ')')
      try {
        s.pop();
      } catch (std::underflow_error(e)) {
        cout << "Too many )" << endl;
        return 0;
      }
  }

  if (s.isEmpty())
    cout << "Parens are balanced" << endl;
  else
    cout << "Too many (" << endl;

  return 0;
}

