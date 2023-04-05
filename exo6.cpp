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

void f(C* p) {
	cout << "F1 ";
	for(int i : { 0, 1 })
		new(p+i) C(i*5);
	cout << "F2 ";
}

int main() {
	cout << "M1 ";
	C* p = reinterpret_cast<C*>(::operator new(2 * sizeof(C)));
	cout << "M2 ";
	f(p);
	cout << "M3 ";
	new(p) C(1);
	cout << "M4 ";
	new(p+1) C(2);
	cout << "M5 ";
	p->~C();
	(p+1)->~C();
	::operator delete(p);
	cout << "M6 ";
}
