#include <iostream>

#include "brdoc/RG.hpp"

int main() {
    try {
        brdoc::RG rg("12.345.678-X");

        std::cout << "RG bruto: " << rg.value() << "\n";
        std::cout << "RG formatado: " << rg.formatted() << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
}
