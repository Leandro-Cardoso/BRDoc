#include <iostream>

#include "brdoc/Validators.hpp"

int main() {
    using namespace brdoc::validators;

    std::string cpf = "529.982.247-25";
    std::string cnpj = "04.252.011/0001-10";

    std::cout << "CPF válido? " << (isValidCPF(cpf) ? "Sim" : "Não") << "\n";
    std::cout << "CNPJ válido? " << (isValidCNPJ(cnpj) ? "Sim" : "Não") << "\n";

    std::string raw = "abc123.456-78";
    std::cout << "Somente dígitos: " << onlyDigits(raw) << "\n";
}
