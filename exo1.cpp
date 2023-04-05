#include <iostream>

class C {
private:
	int i;
public:
	C(int _i) : i{_i} { std::cout << "I" << i << " "; }
	C(const C& c) : i{c.i} { std::cout << i << " "; }
	C& operator=(const C& c) { i = c.i; std::cout << "A" << i << " "; return *this; }
	~C() { std::cout << "D" << i << " "; }
};

void f() {
	std::cout << "F1 ";
	static C c{1};
	std::cout << "F2 ";
}

int main() {
	std::cout << "M1 ";
	f();
	std::cout << "M2 ";
	f();
	std::cout << "M3 ";
	return 0;
}
