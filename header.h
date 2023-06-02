#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>

class TMatrix {
protected:
	int rows;
	int columns;
	int** data;

public:

	TMatrix(int rows, int columns);

	virtual int getDeterminant();

	~TMatrix();

	int getSum();

	void inputMatrix();

	void randomMatrix();

	void outputMatrix();
};

class Matrix2 : public TMatrix {
public:
	Matrix2();

	int getDeterminant() override;
};

class Matrix3 : public TMatrix {
public:
	Matrix3();

	int getDeterminant() override;
};

int option();