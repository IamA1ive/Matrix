#include <iostream>
#include <locale.h>
#include "TComplex.h"
#include "TVector.h"
#include "TMatrix.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	TMatrix<int> M1(3);
	M1.Input();
	TMatrix<int> M2(3);
	M2.Input();
	TMatrix<int> M3(3);
	M3 = M1 + M2;
	M3.Print();
	M3 = M1 * M2;
	M3.Print();
	M3[2][2] = 200;
	M3[3][3] = 200;

	cout << endl << endl;
	M3.Print();

	return 0;
}