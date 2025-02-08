#include <iostream>

int main() {
    double num1, num2, num3;

    std::cout << "Ingrese tres números: ";
    std::cin >> num1 >> num2 >> num3;

    double suma = num1 + num2 + num3;

    std::cout << "La suma de los tres números es: " << suma << std::endl;

    return 0;
}