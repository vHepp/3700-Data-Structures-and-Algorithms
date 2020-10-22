#include <iostream>
#include <queue.h>
#include <stack.h>

using namespace std;

string tasks[] = {"Read news","Easy coding practice","Hard coding practice"};

int main() {
  Queue<string> q;
  Stack<string> s;
  string actionS,actionQ;

  for (int i=0;i<3;i++) {
    s.push(tasks[i]);
    q.enqueue(tasks[i]);
  }

  for (int i=0;i<20;i++) {
    actionS = s.pop();
    actionQ = q.dequeue();

    cout << "Time " << i << ": stack action: " << actionS << "    queue action: "
         << actionQ << endl;

    s.push(actionS);
    q.enqueue(actionQ);
  }

  return 0;
}

