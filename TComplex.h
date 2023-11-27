#pragma once
class TComplex {
	double Re;
	double Im;
public:
	void Input(double re, double im);
	void Input(double re);
	TComplex(double re, double im); //инициализирующий конструктор
	TComplex(double re); //конструктор преобразования типа
	void Print(); //вывод на экран
	TComplex(); //конструктор по умолчанию
	~TComplex(); //деструктор
	TComplex(const TComplex& Complex); //конструктор копирования

	TComplex operator+(const TComplex& Complex);
	TComplex operator-(const TComplex& Complex);
	TComplex operator*(const TComplex& Complex);
	TComplex operator/(const TComplex& Complex);
	TComplex& operator=(const TComplex& Complex);
	bool operator==(const TComplex& Complex);
	TComplex& operator+=(const TComplex& Complex);
	TComplex& operator-=(const TComplex& Complex);
	TComplex& operator*=(const TComplex& Complex);
	TComplex& operator/=(const TComplex& Complex);

	TComplex operator+(double number);
	TComplex operator-(double number);
	TComplex operator*(double number);
	TComplex operator/(double number);
	TComplex& operator=(double re);
	bool operator==(double number);
	TComplex& operator+=(double number);
	TComplex& operator-=(double number);
	TComplex& operator*=(double number);
	TComplex& operator/=(double number);
};

TComplex operator+(double number, TComplex& Complex);
TComplex operator-(double number, TComplex& Complex);
TComplex operator*(double number, TComplex& Complex);
TComplex operator/(double number, TComplex& Complex);
