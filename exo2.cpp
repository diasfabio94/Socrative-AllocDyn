#include <iostream>
using namespace std;

class C {
	int i;
public:
	C(int _i) : i{_i} { cout << "I" << i << " "; }
	C(const C& c) : i{c.i} { cout << "" << i << " "; }
	C& operator=(const C& c) { i = c.i; cout << "A" << i << " "; return *this; }
	C() { cout << "D" << i << " "; }
};

void f() {
	cout << "F1 ";
	C c{2};
	cout << "F2 ";
}

int main() {
	cout << "M1 ";
	C c{1};
	cout << "M2 ";
	f();
	cout << "M3 ";
	return 0;
}
