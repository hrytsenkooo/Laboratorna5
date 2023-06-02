#include "header.h"

TMatrix::TMatrix(int rows, int columns) : rows(rows), columns(columns) {
    data = new int* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[columns];
    }
}

int TMatrix::getDeterminant() { return 0; }

TMatrix::~TMatrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

int TMatrix::getSum() {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += data[i][j];
        }
    }
    return sum;
}

void TMatrix::inputMatrix() {
    std::cout << "\n¬вед≥ть елементи дл€ " << rows << "x" << columns << " матриц≥" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << "≈лемент матриц≥ [" << i << "][" << j << "]: ";
            std::cin >> data[i][j];
        }
    }
}

void TMatrix::randomMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            data[i][j] = rand() % 51;
        }
    }
}

void TMatrix::outputMatrix() {
    std::cout << "\n----¬аша матриц€ " << rows << "x" << columns << "----\n\n";
    for (int i = 0; i < rows; i++) {
        std::cout << '\t';
        for (int j = 0; j < columns; j++) {
            std::cout << std::setw(2) << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n—ума елемент≥в матриц≥: " << this->getSum() << std::endl;
    std::cout << "ƒетерм≥нант: " << this->getDeterminant() << std::endl;
}

Matrix2::Matrix2() : TMatrix(2, 2) {}

int Matrix2::getDeterminant() {
    return (data[0][0] * data[1][1] - (data[0][1] * data[1][0]));
}

Matrix3::Matrix3() : TMatrix(3, 3) {}

int Matrix3::getDeterminant() {
    int det = 0;
    det += data[0][0] * (data[1][1] * data[2][2] - data[2][1] * data[1][2]);
    det -= data[0][1] * (data[1][0] * data[2][2] - data[2][0] * data[1][2]);
    det += data[0][2] * (data[1][0] * data[2][1] - data[2][0] * data[1][1]);
    return det;
}

int option() {
    int choice;
    std::cout << "як ¬и хочете отримати матриц≥?\n" << std::endl;
    while (true) {
        std::cout << "1. ¬вести вручну\n2. —генерувати\n\n¬аш виб≥р: ";
        if (std::cin >> choice) {
            if (choice == 1 || choice == 2) {
                break;
            }
            else {
                std::cout << "\nЅудь ласка, обер≥ть м≥ж 1 та 2 вар≥антом\n" << std::endl;
            }
        }
    }
    return choice;
}
