#include "RationalFraction.h"

using namespace std;

#define fract RationalFraction

int main() {
	fract f1, f2;
	cout << "Input Fraction: " << endl;
	cin >> f1 >> f2;


	cout << endl << "Your fraction: " << endl;
	cout << f1 << endl;
	cout << f2 << endl;

	cout << endl << f1 << " + " << f2 << " -> " << f1 + f2 << endl;
	cout << endl << f1 << " - " << f2 << " -> " << f1 - f2 << endl;
	cout << endl << f1 << " += " << f2 << " -> " << (f1 += f2) << endl;
	cout << endl << f1 << " -= " << f2 << " -> " << (f1 -= f2) << endl;
	cout << endl << f1 << " > " << f2 << " -> " << (f1 > f2) << endl;
	cout << endl << "+" << f1 << " -> " << +f1 << endl;
	cout << endl << "-" << f1 << " -> " << -f1 << endl;
	cout << endl << "++" << f1 << " -> " << ++f1  << endl; // prefix
	cout << endl << f1 << "++" << " Before -> ";
	fract f3 = f1++;
	cout << f3 << " After -> " << f1 << endl;
	cout << endl << f1 << " = " << f2 << " -> "; f1 = f2; cout << f1 << endl;

}