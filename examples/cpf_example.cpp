#include <iostream>

#include "brdoc/CPF.hpp"

int main() {
    try {
        brdoc::CPF cpf("529.982.247-25");

        std::cout << "CPF bruto: " << cpf.value() << "\n";
        std::cout << "CPF formatado: " << cpf.formatted() << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
}
