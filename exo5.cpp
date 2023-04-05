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
	new(p) C(6); // Placement new: construit un objet C en mémoire pré-allouée à l'adresse p
	cout << "F2 ";
}

int main() {
	cout << "M1 ";
	C* p = reinterpret_cast<C*>(::operator new(sizeof(C))); // Allocation mémoire brute
	cout << "M2 ";
	f(p);
	cout << "M3 ";
	p->~C(); // Destruction explicite de l'objet construit par placement new
	cout << "M4 ";
	::operator delete(p); // Libération de la mémoire brute allouée
	cout << "M5 ";
}
