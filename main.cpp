#include "header.h"

int main() {

	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int SIZE = 3;
	TMatrix* maxtrix[SIZE];
	int optionValue = option();

	Matrix2 matrix2;
	Matrix3 matrix3;

	if (optionValue == 1) {
		matrix2.inputMatrix();
		matrix3.inputMatrix();
	}
	else if (optionValue == 2) {
		matrix2.randomMatrix();
		matrix3.randomMatrix();
	}
	else {
		std::cout << "Будь ласка, оберіть між 1 та 2 варіантом\n" << std::endl;
		return 0;
	}

	matrix2.outputMatrix();
	matrix3.outputMatrix();

	int expression = matrix3.getSum() + std::abs(matrix3.getDeterminant()) + std::abs(matrix2.getDeterminant());
	std::cout << "\nРезультат обчислення виразу: " << expression << std::endl;
	return 0;
}

