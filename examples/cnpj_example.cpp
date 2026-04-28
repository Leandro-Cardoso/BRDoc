#include <iostream>

#include "brdoc/CNPJ.hpp"

int main() {
    try {
        brdoc::CNPJ cnpj("04.252.011/0001-10");

        std::cout << "CNPJ bruto: " << cnpj.value() << "\n";
        std::cout << "CNPJ formatado: " << cnpj.formatted() << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
}
