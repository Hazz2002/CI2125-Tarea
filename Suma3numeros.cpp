#include <iostream>

int main() {
    double num1, num2, num3, suma;

    std::cout << "Ingrese el primer número: ";
    std::cin >> num1;

    std::cout << "Ingrese el segundo número: ";
    std::cin >> num2;

    std::cout << "Ingrese el tercer número: ";
    std::cin >> num3;

    suma = num1 + num2 + num3;

    std::cout << "La suma de los tres números es: " << suma << std::endl;

    return 0;
}