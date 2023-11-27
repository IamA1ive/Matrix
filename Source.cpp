#include <iostream>
#include <locale.h>
#include "TComplex.h"
#include "TVector.h"
#include "TMatrix.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	TMatrix<int> M1(3);
	TMatrix<int> M2(3);
	M1.Input();
	M1.Print();
	M2.Input();
	M2.Print();
	M1 = M1 * M2;
	M1.Print();
	M1[3].Print();

	return 0;
}