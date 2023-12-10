#pragma once
#include <iostream>
#include "TComplex.h"
using namespace std;


template <typename Type>
class TVector {
protected:
	int size;
	Type* val;
public:
	explicit TVector(int n) {
		size = n;
		val = new Type[size];
		//if (size > 0) cout << "Значения компонент по умолчанию равны нулю." << endl;
		for (int i = 0; i < size; i++) {
			val[i] = 0;
		}
	};
	TVector(int n, Type* p) {
		size = n;
		val = new Type[size];
		for (int i = 0; i < size; i++) {
			val[i] = p[i];
		}
	};
	TVector(const TVector<Type>& vec) {
		size = vec.size;
		val = new Type[size];
		for (int i = 0; i < size; i++) {
			val[i] = vec.val[i];
		}
	};
	~TVector() {
		delete[] val;
		size = 0;
	};
	TVector() {
		size = 1;
		val = new Type[size];
	};
	void Print() {
		cout << "| ";
		for (int i = 0; i < size; i++) {
			cout << val[i] << " ";
		}
		cout << "|" << endl;
	};
	TVector& operator=(const TVector& vec) {
		delete[] val;
		size = vec.size;
		val = new Type[size];
		for (int i = 0; i < size; i++) {
			val[i] = vec.val[i];
		}
		return *this;
	};
	TVector& operator=(Type num) {
		for (int i = 0; i < size; i++) {
			val[i] = num;
		}
		return *this;
	};
	TVector operator+(const TVector& vec) {
		TVector result(vec.size);
		if (size == vec.size) {
			for (int i = 0; i < size; i++) {
				result.val[i] = val[i] + vec.val[i];
			}
		}
		else cout << "Векторы имеют разную размерность. Сложение невозможно." << endl << "Возвращён нулевой вектор." << endl;
		return result;
	};
	TVector operator-(const TVector& vec) {
		TVector result(vec.size);
		if (size == vec.size) {
			for (int i = 0; i < size; i++) {
				result.val[i] = val[i] - vec.val[i];
			}
		}
		else cout << "Векторы имеют разную размерность. Вычитание невозможно." << endl << "Возвращён нулевой вектор." << endl;
		return result;
	};
	TVector operator+(Type num) {
		TVector result(size);
		for (int i = 0; i < size; i++) {
			result.val[i] = val[i] + num;
		}
		return result;
	};
	TVector operator-(Type num) {
		TVector result(size);
		for (int i = 0; i < size; i++) {
			result.val[i] = val[i] - num;
		}
		return result;
	};
	TVector& operator++() {
		for (int i = 0; i < size; i++) {
			val[i] = val[i] + 1;
		}
		return *this;
	};
	TVector operator++(int) {
		TVector res(*this);
		for (int i = 0; i < size; i++) {
			val[i] = val[i] + 1;
		}
		return res;
	};
	bool operator==(const TVector& vec) {
		if (size == vec.size) {
			for (int i = 0; i < size; i++) {
				if (val[i] != vec.val[i]) return false;
			}
		}
		else {
			return false;
		}
		return true;
	};
	TVector operator*(double num) {
		TVector res(*this);
		for (int i = 0; i < size; i++) {
			res.val[i] *= num;
		}
		return res;
	};
	double operator*(const TVector& vec) {
		double res = 0;
		if (size == vec.size) {
			for (int i = 0; i < size; i++) {
				res += val[i] * vec.val[i];
			}
		}
		else cout << "Векторы имеют разную размерность. Скалярное" << endl << "произведение невозможно. Возвращён ноль." << endl;
		return res;
	};
	Type& operator[](int index) {
		while (index >= size || index < 0) {
			cout << "Ошибка: попытка взять значение по несуществующему индексу. Введите корректное значение." << endl;
			cin >> index;
		}
		return val[index];
	};
	Type& operator[](int index) const {
		while (index >= size || index < 0) {
			cout << "Ошибка: попытка взять значение по несуществующему индексу. Введите корректное значение." << endl;
			cin >> index;
		}
		return val[index];
	};
	int GetSize() {
		return size;
	};
	void Input() {
		for (int i = 0; i < size; i++) {
			cin >> val[i];
		}
	};
};

template<>
class TVector<TComplex> {
	int size;
	TComplex* val;
public:
	explicit TVector(int n) {
		size = n;
		val = new TComplex[size];
		//if (size > 0) cout << "Значения компонент по умолчанию равны нулю." << endl;
		for (int i = 0; i < size; i++) {
			val[i] = 0;
		}
	};
	TVector(int n, TComplex* p) {
		size = n;
		val = new TComplex[size];
		for (int i = 0; i < size; i++) {
			val[i] = p[i];
		}
	};
	TVector(const TVector& vec) {
		size = vec.size;
		val = new TComplex[size];
		for (int i = 0; i < size; i++) {
			val[i] = vec.val[i];
		}
	};
	~TVector() {
		delete[] val;
		size = 0;
	};
	TVector() {
		size = 0;
		val = nullptr;
	};
	void Print() {
		cout << "( ";
		for (int i = 0; i < size; i++) {
			val[i].Print();
		}
		cout << ")" << endl;
	};
	TVector& operator=(const TVector& vec) {
		if (this == &vec) {
		}
		else {
			delete[] val;
			size = vec.size;
			val = new TComplex[size];
			for (int i = 0; i < size; i++) {
				val[i] = vec.val[i];
			}
		}
		return *this;
	};
	TVector operator+(const TVector& vec) {
		TVector result(vec.size);
		if (size == vec.size) {
			for (int i = 0; i < size; i++) {
				result.val[i] = val[i] + vec.val[i];
			}
		}
		else cout << "Векторы имеют разную размерность. Сложение невозможно." << endl << "Возвращён нулевой вектор." << endl;
		return result;
	};
	TVector& operator++() {
		for (int i = 0; i < size; i++) {
			val[i] = val[i] + 1;
		}
		return *this;
	};
	TVector operator++(int) {
		TVector res(*this);
		for (int i = 0; i < size; i++) {
			val[i] = val[i] + 1;
		}
		return res;
	};
	bool operator==(const TVector& vec) {
		if (size == vec.size) {
			for (int i = 0; i < size; i++) {
				if (val[i] == vec.val[i]) return true;
			}
		}
		else {
			return false;
		}
	};
	TVector operator*(double num) {
		TVector res(*this);
		for (int i = 0; i < size; i++) {
			res.val[i] *= num;
		}
		return res;
	};
	TComplex operator*(const TVector& vec) {
		TComplex res = 0;
		if (size == vec.size) {
			for (int i = 0; i < size; i++) {
				res = (val[i] * vec.val[i]) + res;
			}
		}
		else cout << "Векторы имеют разную размерность. Скалярное" << endl << "произведение невозможно. Возвращён ноль." << endl;
		return res;
	};
	TComplex& operator[](int index) {
		if (index <= size && index > 0) {
			return val[index];
		}
		else {
			cout << "Попытка взять значение по несуществующему индексу." << endl << "Возвращено значение первой компоненты." << endl;
			return val[0];
		};
	};
	TComplex& operator[](int index) const {
		if (index <= size && index > 0) {
			return val[index];
		}
		else {
			cout << "Попытка взять значение по несуществующему индексу." << endl << "Возвращено значение первой компоненты." << endl;
			return val[0];
		};
	};
};