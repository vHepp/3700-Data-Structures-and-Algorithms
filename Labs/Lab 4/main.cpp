#include <iostream>
using namespace std;

void showBits(unsigned int n) {
	
	for (int i = 31; i >= 0; i--) {
		if (n & (1 << i))
			cout << '1';
		else
			cout << '0';
	}
		
		cout << endl;
}

int countBits(unsigned int n) {
	int count = 0;
	
	while (n != 0){
		count++;
		n &= n - 1;
	}
	
	return count;
}
	
int main(void) {
	unsigned int a,b,c;
	
	cout << "Enter 2 nonnegative integers: ";
	cin >> a >> b;
	cout << "a: " << a << " b: " << b << endl << endl;
	
	c = a & b;
	cout << "a & b:  ";
	showBits(c);
	
	c = a | b;
	cout << "\na | b:  ";
	showBits(c);
	
	c = ~a;
	cout << "\n~a:     ";
	showBits(c);
	
	c = a ^ b;
	cout << "\na ^ b:  ";
	showBits(c);
	
	cout << "\na:      ";
	showBits(a);
	
	cout << "\na << 1: ";
	a = a << 1;
	showBits(a);

	cout << "\na >> 1: ";
	a = a >> 2;
	showBits(a);
	
	return 0;
}
