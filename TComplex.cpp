#include <iostream>
#include "TComplex.h"
using namespace std;

void TComplex::Input(double re, double im) {
	Re = re;
	Im = im;
}
TComplex::TComplex(double re, double im) {
	Re = re;
	Im = im;
	//cout << "Сработал конструктор инициализации." << endl;
}
void TComplex::Print() {
	if (Re != 0) {
		cout << Re;
		if (Im > 0) {
			cout << " + ";
		}
		else if (Im < 0) {
			cout << " - ";
			Im = -Im;
		}
		if (Im != 0) {
			if (Im == 1) {
				cout << "i";
			}
			else {
				cout << Im << "i";
			}
		}
		cout << endl;
	}
	else if (Im != 0) {
		if (Im == 1) {
			cout << "i" << endl;
		}
		else if (Im == -1) {
			cout << "-i" << endl;
		}
		else {
			cout << Im << "i" << endl;
		}
	}
	else {
		cout << 0 << endl;
	}

}
TComplex::TComplex() {
	Re = 0;
	Im = 0;
	//cout << "Сработал конструктор по умолчанию." << endl;
}
TComplex::~TComplex() {
	//cout << "Сработал деструктор." << endl;
}
TComplex::TComplex(const TComplex& Complex) {
	Re = Complex.Re;
	Im = Complex.Im;
	//cout << "Сработал конструктор копирования." << endl;
}
TComplex TComplex::operator+(const TComplex& Complex) {
	TComplex Result;
	Result.Re = Re + Complex.Re;
	Result.Im = Im + Complex.Im;
	return Result;
}
TComplex TComplex::operator-(const TComplex& Complex) {
	TComplex Result;
	Result.Re = Re - Complex.Re;
	Result.Im = Im - Complex.Im;
	return Result;
}
TComplex TComplex::operator*(const TComplex& Complex) {
	TComplex Result;
	Result.Re = Re * Complex.Re - Im * Complex.Im;
	Result.Im = Re * Complex.Im + Complex.Re * Im;
	return Result;
}
TComplex TComplex::operator/(const TComplex& Complex) {
	TComplex Result(Re, Im);
	if ((Complex.Re != 0) && (Complex.Im != 0)) {
		Result.Re = (Re * Complex.Re + Im * Complex.Im) / (Complex.Re * Complex.Re + Complex.Im * Complex.Im);
		Result.Im = (Im * Complex.Re - Re * Complex.Im) / (Complex.Re * Complex.Re + Complex.Im * Complex.Im);
	}
	else cout << "Деление на ноль невозможно. Возвращено значение первого комплексного числа." << endl;
	return Result;
}
bool TComplex::operator==(const TComplex& Complex) {
	if ((Re == Complex.Re) && (Im == Complex.Im)) return true;
	else return false;
}
TComplex& TComplex::operator=(const TComplex& Complex) {
	if (this == &Complex) return *this;
	else {
		Re = Complex.Re;
		Im = Complex.Im;
	}
	return *this;
}
TComplex TComplex::operator+(double number) {
	TComplex Result;
	Result.Re = Re + number;
	Result.Im = Im;
	return Result;
}
TComplex TComplex::operator-(double number) {
	TComplex Result;
	Result.Re = Re - number;
	Result.Im = Im;
	return Result;
}
TComplex TComplex::operator*(double number) {
	TComplex Result;
	Result.Re = Re * number;
	Result.Im = Im * number;
	return Result;
}
TComplex TComplex::operator/(double number) {
	TComplex Result(Re, Im);
	if (number != 0) {
		Result.Re = Re / number;
		Result.Im = Im / number;
	}
	else cout << "Деление на ноль невозможно. Возвращено значение комплексного числа." << endl;
	return Result;
}
bool TComplex::operator==(double number) {
	if ((Re == number) && (Im == 0)) return true;
	else return false;
}
TComplex::TComplex(double re) {
	Re = re;
	Im = 0;
	//cout << "Сработал конструктор инициализации." << endl;
}
void TComplex::Input(double re) {
	Re = re;
	Im = 0;
}
TComplex& TComplex::operator=(double re) {
	Re = re;
	Im = 0;
	return *this;
}
TComplex& TComplex::operator+=(const TComplex& Complex) {
	Re += Complex.Re;
	Im += Complex.Im;
	return *this;
}
TComplex& TComplex::operator-=(const TComplex& Complex) {
	Re -= Complex.Re;
	Im -= Complex.Im;
	return *this;
}
TComplex& TComplex::operator*=(const TComplex& Complex) {
	double tmpRe = Re, tmpIm = Im;
	Re = tmpRe * Complex.Re - tmpIm * Complex.Im;
	Im = tmpRe * Complex.Im + Complex.Re * tmpIm;
	return *this;
}
TComplex& TComplex::operator/=(const TComplex& Complex) {
	if ((Complex.Re != 0) && (Complex.Im != 0)) {
		double tmpRe = Re, tmpIm = Im;
		Re = (tmpRe * Complex.Re + tmpIm * Complex.Im) / (Complex.Re * Complex.Re + Complex.Im * Complex.Im);
		Im = (tmpIm * Complex.Re - tmpRe * Complex.Im) / (Complex.Re * Complex.Re + Complex.Im * Complex.Im);
	}
	else cout << "Деление на ноль невозможно. Возвращено значение комплексного числа." << endl;
	return *this;
}
TComplex& TComplex::operator+=(double number) {
	Re += number;
	return *this;
}
TComplex& TComplex::operator-=(double number) {
	Re -= number;
	return *this;
}
TComplex& TComplex::operator*=(double number) {
	Re *= number;
	Im *= number;
	return *this;
}
TComplex& TComplex::operator/=(double number) {
	if (number != 0) {
		Re /= number;
		Im /= number;
	}
	else cout << "Деление на ноль невозможно. Возвращено значение комплексного числа." << endl;
	return *this;
}
TComplex operator+(double number, TComplex& Complex) {
	return (Complex + number);
}
TComplex operator-(double number, TComplex& Complex) {
	return ((-1) * Complex + number);
}
TComplex operator*(double number, TComplex& Complex) {
	return (Complex * number);
}
TComplex operator/(double number, TComplex& Complex) {
	TComplex tmp(number);
	return (tmp / Complex);
}