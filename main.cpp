#include "pch.h"

struct Data {
    double X;
    double T;
    double U;
};

std::vector<Data> readDataFromFile(const std::string& filename) {
    std::vector<Data> data;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Data d;
        if (iss >> d.X >> d.T >> d.U) {
            data.push_back(d);
        }
    }
    return data;
}

double fun(double x, double y, double z, const std::vector<Data>& table1, const std::vector<Data>& table2, const std::vector<Data>& table3) {
    // Пример алгоритма вычисления функции fun(x, y, z) с приоритетами
    // Примерный псевдокод:
    // if (condition1)
    //     return результат по таблице 1
    // else if (condition2)
    //     return результат по таблице 2
    // else
    //     return результат по таблице 3

    // Для примера вернем значение T из таблицы 1 для первого элемента
    return table1[0].T;
}

int main() {
    std::vector<Data> table1 = readDataFromFile("dat_X_1_1.dat");
    std::vector<Data> table2 = readDataFromFile("dat_X1_00.dat");
    std::vector<Data> table3 = readDataFromFile("dat_X00_1.dat");

    double x, y, z;
    std::cout << "Enter x, y and z: ";
    std::cin >> x >> y >> z;

    double result = fun(x, y, z, table1, table2, table3);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
