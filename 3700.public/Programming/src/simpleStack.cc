#include "simpleStack.h"

void SimpleStack::push(StackType d) {

  if (top == STACK_SIZE)
    throw std::overflow_error("Stack is full");

  data[top] = d;
  top++;		// data[top++] does both
}

StackType SimpleStack::pop() {

  if (top == 0)
    throw std::underflow_error("Stack is empty");

  top--;
  return data[top];	// data[--top] does both
}

StackType SimpleStack::peek() {

  if (top == 0)
    throw std::underflow_error("Stack is empty");

  return data[top-1];
}

