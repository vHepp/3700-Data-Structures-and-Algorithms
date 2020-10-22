#ifndef _SIMPLESTACK_H
#define _SIMPLESTACK_H

#include <stdexcept>

typedef char StackType;

const int STACK_SIZE = 16;

class SimpleStack {
 public:
  SimpleStack() { top = 0; }
  ~SimpleStack() { }

  int size() { return top; }
  bool isEmpty() { return top == 0; }
  void clear() { top = 0; }

  void push(StackType d);
  StackType pop();
  StackType peek();

 private:
  StackType
    data[STACK_SIZE];
  int
    top;
};

#endif

