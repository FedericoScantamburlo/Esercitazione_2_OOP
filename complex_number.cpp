#include<iostream>
#include "complex_number.hpp"

int main() {
	complex_number<float> z1 (1, 4);
	cout << "z1 = " << z1 << endl;
	cout << "Re(z1) = " << z1.re() << ", Im(z1) = " << z1.im() << endl;
	complex_number<float> z2 (2);
	cout << "z2 = " << z2 << endl;
	complex_number<float> z3 (-5, 1);
	cout << "z3 = " << z3 << endl;
	cout << "Coniug(z3) = " << z3.coniug() << endl;
	z1 += z2;
	complex_number z5 = z1 + z3;
	cout << "z4 = z1 + z2 = " << z1 << endl;
	cout << "z5 = z3 + z4 = " << z5 << endl;
	z1 *= z2;
	complex_number z7 = z3 * z1;
	cout << "z6 = z4 * z2 = " << z1 << endl;
	cout << "z7 = z3 * z6 = " << z7 << endl;
	complex_number<float> z8;
	cout << "z8 = " << z8 << endl;
	float r1 = 4;
	cout << "r1 = " << r1 << endl;
	z1 += r1;
	complex_number z10 = z3 + r1;
	complex_number z10_c = r1 + z3;
	cout << "z9 = z6 + r1 = " << z1 << endl;
	cout << "z10 = z3 + r1 = " << z10 << endl;
	cout << "z10 = r1 + z3 = " << z10_c << endl;
	float r2 = 3;
	cout << "r2 = " << r2 << endl;
	z10 *= r2;
	complex_number z12 = z10 * r2;
	complex_number z12_c = r2 * z10;
	cout << "z11 = z10 * r2 = " << z10 << endl;
	cout << "z12 = z11 * r2 = " << z12 << endl;
	cout << "z12 = r2 * z11 = " << z12_c << endl;
	complex_number<float> a (0, 1);
	complex_number<float> b (0, -1);
	cout << "prova" << a << b << z12.coniug() << endl;
	return 0;
}