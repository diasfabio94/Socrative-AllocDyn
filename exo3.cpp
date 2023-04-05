#include <iostream>
using namespace std;

class C {
	int i;
public:
	C(int _i) : i{_i} { cout << "I" << i << " "; }
	C(const C& c) : i{c.i} { cout << "" << i << " "; }
	C& operator=(const C& c) { i = c.i; cout << "A" << i << " "; return *this; }
	~C() { cout << "D" << i << " "; }
};

C* f() {
	cout << "F1 ";
	C* p = new C(7);
	cout << "F2 ";
	return p;
}

int main() {
	cout << "M1 ";
	C* q = f();
	cout << "M2 ";
	delete q;
	cout << "M3 ";
}
