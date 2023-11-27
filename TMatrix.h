#pragma once
#include <iostream>
#include <locale.h>
#include "TVector.h"
using namespace std;

template<typename Type>
class TMatrix : private TVector<TVector<Type>> {
	using TVector<TVector<Type>>::size;
	using TVector<TVector<Type>>::val;
public:
	TMatrix(int size = 1) : TVector<TVector<Type>>(size) {
		for (int i = 0; i < size; i++) {
			val[i] = TVector<Type>(size);
		}
	};
	TMatrix(const TMatrix& mat) :TVector<TVector<Type>>(mat) {};
	bool operator==(const TMatrix& mat) {
		bool answer = true;
		if (size == mat.size) {
			for (int i = 0; i < size; i++) {
				if (!(val[i] == mat.val[i])) {
					answer = 0;
					break;
				}
			}
		}
		else answer = false;
		if (answer) cout << "������� �����." << endl;
		else cout << "������� �� �����." << endl;
		return answer;
	};
	TMatrix& operator=(const TMatrix& mat) {
		size = mat.size;
		for (int i = 0; i < size; i++) {
			val[i] = mat.val[i];
		}
		return *this;
	};
	TMatrix operator+(const TMatrix& mat) {
		TMatrix Res(size);
		if (size == mat.size) {
			for (int i = 0; i < size; i++) {
				Res.val[i] = val[i] + mat.val[i];
			}
		}
		else cout << "������� ����� ������ �����������. �������� ����������." << endl;
		return Res;
	};
	TMatrix operator-(const TMatrix& mat) {
		TMatrix Res(size);
		if (size == mat.size) {
			for (int i = 0; i < size; i++) {
				Res.val[i] = val[i] - mat.val[i];
			}
		}
		else cout << "������� ����� ������ �����������. ��������� ����������." << endl;
		return Res;
	};
	TMatrix operator+(Type num) {
		TMatrix Res(size);
		for (int i = 0; i < size; i++) {
			Res.val[i] = val[i] + num;
		}
		return Res;
	};
	TMatrix operator-(Type num) {
		TMatrix Res(size);
		for (int i = 0; i < size; i++) {
			Res.val[i] = val[i] - num;
		}
		return Res;
	};
	TMatrix operator*(Type num) {
		TMatrix Res(size);
		for (int i = 0; i < size; i++) {
			Res.val[i] = val[i] * num;
		}
		return Res;
	};
	TMatrix operator*(const TMatrix& mat) {
		TMatrix result(size);
		if (size != mat.size) {
			cout << "������������� ������� ������ ��� ���������. ���������� ������� �������." << endl;
		}
		else {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					Type sum = 0;
					for (int k = 0; k < size; k++) {
						sum += val[i][k] * mat.val[k][j];
					}
					result.val[i][j] = sum;
				}		
			}
		}
		return result;
	};
	TVector<Type>& operator[](int index) {
		if (index < 0 || index >= size) {
			cout << "������� ��������� � ������������� ������� �������. ���������� ������ ������ �������." << endl;
			return val[0];
		}
		return val[index];
	};
	void Input() {
		for (int i = 0; i < size; i++) {
			val[i].Input();
		}
	};
	void Print() {
		cout << endl;
		for (int i = 0; i < size; i++) {
			val[i].Print();
		}
	};

};