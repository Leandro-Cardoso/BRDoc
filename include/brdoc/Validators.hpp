#pragma once

#include <string>

namespace brdoc::validators {

// Mantem apenas números:
std::string onlyDigits(const std::string& input);

// CPF:
bool isValidCPF(const std::string& cpf);

// CNPJ:
bool isValidCNPJ(const std::string& cnpj);

}
